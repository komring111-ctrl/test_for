#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

/* 非阻塞读 1 个字符，无键返回 0 */
char getKey(void)
{
    char ch = 0;
    struct termios old, new;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO); /* 关缓冲、不回显 */
    new.c_cc[VMIN] = 0;              /* 0 字节就返回 */
    new.c_cc[VTIME] = 0;             /* 不等待 */
    tcsetattr(0, TCSANOW, &new);
    read(0, &ch, 1); /* 无键则返回 0 */
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

/*初始化游戏*/
#define W 10
#define H 20

int field[H][W] = {0};
int score = 0;
int px, py;
int current[4][4], next[4][4];
const int SHAPES[7][4][4] = {
    {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
    {{0, 1, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
    {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
    {{0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
};

/*检测是否碰撞或越界*/
int checkCollision(int a[4][4], int x, int y)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j])
            {
                int nx = x + j, ny = y + i;
                if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                    return 1;
                if (field[ny][nx])
                    return 1;
            }
        }
    return 0;
}

/*固定方块*/
void mergeToField(int a[4][4], int x, int y)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j])
                field[y + i][x + j] = 1;
}

/*顺时针旋转90°*/
void rotate(int src[4][4], int dst[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            dst[j][3 - i] = src[i][j];
}

/*生成新方块*/
void generate(int out[4][4])
{
    int id = rand() % 7;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            out[i][j] = SHAPES[id][i][j];
}

/*消行并计分*/
void clearLines()
{
    int lines = 0;
    for (int y = H - 1; y >= 0; y--)
    {
        int full = 1;
        for (int x = 0; x < W; x++)
            if (!field[y][x])
            {
                full = 0;
                break; // 一旦发现当前行还没满，就立即终止对当前行的继续检查，直接跳到外层循环去处理上一行
            }
        if (full)
        {
            for (int yy = y; yy > 0; yy--)
            {
                for (int x = 0; x < W; x++)
                    field[yy][x] = field[yy - 1][x];
            }
            for (int x = 0; x < W; x++)
                field[0][x] = 0;
            lines++;
            y++;
        }
    }
    score += lines * 100;
}

/*画场地*/
void draw()
{
    system("clear");
    printf("Score : %d\n", score);
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            int here = field[y][x];
            if (!here && x >= px && x < px + 4 && y >= py && y < py + 4)
                here = current[y - py][x - px];
            printf(here ? "* " : "  ");
        }
        printf("\n");
    }
}

/*主函数*/
int main()
{
    srand((unsigned)time(NULL));
    generate(next);
    while (1)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                current[i][j] = next[i][j];
        generate(next);
        px = W / 2 - 2;
        py = 0;
        if (checkCollision(current, px, py))
            break;
        /*当前方块循环*/
        int fall_counter = 0;
        while (1)
        {
            draw();
            printf("A左 D右 W转 S下 Q退\n");
            char key;
            key = getKey();
            int moved = 0;
            /*左*/
            if (key == 'A' || key == 'a')
            {
                px--;
                if (checkCollision(current, px, py))
                    px++;
                moved = 1;
            }
            /*右*/
            else if (key == 'D' || key == 'd')
            {
                px++;
                if (checkCollision(current, px, py))
                    px--;
                moved = 1;
            }
            /*旋转*/
            else if (key == 'W' || key == 'w')
            {
                int tmp[4][4];
                rotate(current, tmp);
                if (!checkCollision(tmp, px, py))
                {
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 4; j++)
                            current[i][j] = tmp[i][j];
                }
                moved = 1;
            }
            /*硬降*/
            else if (key == 'S' || key == 's')
            {
                while (!checkCollision(current, px, py + 1))
                    py++; // 往下落直到碰到已下落的方块
                mergeToField(current, px, py);
                clearLines();
                break;
            }
            /*退出*/
            else if (key == 'Q' || key == 'q')
                return 0;
            /*自由下落*/
            fall_counter++;
            if (fall_counter >= 10 || moved)
            {
                py++;
                if (checkCollision(current, px, py))
                {
                    py--;
                    mergeToField(current, px, py);
                    clearLines();
                    int gameOver = 0;
                    for (int x = 0; x < W; x++)
                        if (field[0][x])
                        {
                            gameOver = 1;
                            break;
                        }
                    if (gameOver)//碰顶游戏结束
                    {
                        draw();
                        printf("Game Over! Final Score: %d\n", score);
                        return 0;
                    }
                    break;//正常结束当前方块，准备生成下一个
                }
                fall_counter = 0;
            }
            usleep(50000); // 0.05s
        }
    }
    draw();
    printf("Game Over! Final Score:%d\n", score);
    return 0;
}
