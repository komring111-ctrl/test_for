#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define W 60
#define H 20

struct POINT
{
    int x;
    int y;
};
typedef struct POINT point;

point snake[W * H];
int tail = 0;
int head = 2;
point food;
int score, dx, dy;

/*终端控制部分*/
static struct termios oldt;

void restore_terminal(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void init_terminal(void)
{
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO); // 关缓冲、不回显
    newt.c_cc[VMIN] = 0;              // 没数据也立刻返回
    newt.c_cc[VTIME] = 0;             // 不等待
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

/* 非阻塞读：有数据就返回，否则立即给 0 */
int get_char_nb(void)
{
    char ch = 0;
    if (read(STDIN_FILENO, &ch, 1) == 1)
    {
        return (unsigned char)ch;
    }
    return 0;
}

// 初始化游戏
void init()
{
    srand(time(NULL));
    snake[0] = (point){W / 2 - 1, H / 2};
    snake[1] = (point){W / 2, H / 2};
    snake[2] = (point){W / 2 + 1, H / 2};
    food = (point){rand() % W, rand() % H};
    score = 0;
    dx = 1;
    dy = 0;
}

// 碰撞检测
int collision(point h)
{
    if (h.x < 0 || h.x >= W || h.y < 0 || h.y >= H)
        return 1;
    for (int i = tail; i != head; i = (i + 1) % (W * H))
    {
        if (h.x == snake[i].x && h.y == snake[i].y)
            return 1;
    }
    return 0;
}

// 检测键盘输入
int update_direction(void)
{
    int ch = get_char_nb();
    if (!ch)
        return 0;

    switch (ch)
    {
    case 'w':
    case 'W':
        if (dy != 1)
        {
            dx = 0;
            dy = -1;
        }
        break;
    case 's':
    case 'S':
        if (dy != -1)
        {
            dx = 0;
            dy = 1;
        }
        break;
    case 'd':
    case 'D':
        if (dx != -1)
        {
            dx = 1;
            dy = 0;
        }
        break;
    case 'a':
    case 'A':
        if (dx != 1)
        {
            dx = -1;
            dy = 0;
        }
        break;
    case 'q':
    case 'Q':
        return 1; /* 退出 */
    }
    return 0;
}
// 游戏主循环
void loop()
{
    while (1)
    {
        int quit = 0;
        for (int i = 0; i < 5; i++)
        {
            if (update_direction())
            {
                quit = 1;
                break;
            }
            usleep(20000);
        }
        if (quit)
            break;
        point h = snake[head];
        h.x += dx;
        h.y += dy;
        if (collision(h))
            break;
        if (h.x == food.x && h.y == food.y)
        {
            score++;
            do
            {
                food = (point){rand() % W, rand() % H};
            } while (collision(food));
        }
        else
        {
            tail = (tail + 1) % (W * H);
        }
        head = (head + 1) % (W * H);
        snake[head] = h;
        // 绘制页面
        system("clear");
        char map[H][W];
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                map[y][x] = '.';
            }
        }
        for (int i = tail; i < head; i = (i + 1) % (W * H))
            map[snake[i].y][snake[i].x] = '*';
        map[snake[head].y][snake[head].x] = '@';
        map[food.y][food.x] = '$';
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
                putchar(map[y][x]);
            putchar('\n');
        }
        printf("Score: %d (q to quit)\n", score);
        fflush(stdout);
        usleep(80000);
    }
    printf("\nGame Over! Fonal Score: %d\n", score);
}

int main()
{
    init_terminal();
    init();
    loop();
    return 0;
}