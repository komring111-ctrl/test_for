#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

#define W 60
#define H 20

struct POINT
{
    int x, y;
};
typedef struct POINT point;

point snake[W * H];
int head, tail;
point food;
int score, dx, dy;

/*初始化 蛇、食物位置、初始运动方向*/
void init()
{
    srand(time(NULL));
    head = 2;
    tail = 0;
    snake[0] = (point){W / 2 - 2, H / 2};
    snake[1] = (point){W / 2 - 1, H / 2};
    snake[2] = (point){W / 2, H / 2};
    food = (point){rand() % W, rand() % H};
    score = 0;
    dx = 1;
    dy = 0;
}

/*碰撞检测*/
int collision(point h)
{
    if (h.x < 0 || h.x >= W || h.y < 0 || h.y >= H)
    {
        return 1;
    } // 碰到墙
    for (int i = tail; i != head; i = (i + 1) % (W * H))
    {
        if (snake[i].x == h.x && snake[i].y == h.y)
        {
            return 1;
        }
    } // 碰到蛇身
    return 0;
}

/*方向控制*/
int update_direction(void)
{
    int ch = getch();
    switch (ch)
    {
    case KEY_UP:
        if (dy != 1)
        {
            dx = 0;
            dy = -1;
        }
        break;
    case KEY_DOWN:
        if (dy != -1)
        {
            dx = 0;
            dy = 1;
        }
        break;
    case KEY_LEFT:
        if (dx != 1)
        {
            dx = -1;
            dy = 0;
        }
        break;
    case KEY_RIGHT:
        if (dx != -1)
        {
            dx = 1;
            dy = 0;
        }
        break;
    case 'q':
        return 1;
    default:
        break;
    }
    return 0;
}

/*主循环*/
void loop()
{
    keypad(stdscr, TRUE);  // 启用 功能键（方向键、F1~F12、Home、End 等） 的捕获
    nodelay(stdscr, TRUE); // 让 getch() 变成非阻塞调用
    clear();
    while (1)
    {
        if (update_direction())
            break; // 检测键盘输入
        point h = snake[head];
        h.x += dx;
        h.y += dy;        // 计算新蛇头坐标
        if (collision(h)) // 碰没碰到
            break;
        if (h.x == food.x && h.y == food.y)
        {
            score++;
            food = (point){rand() % W, rand() % H};
        } // 吃到食物，尾巴位置不变
        else
        {
            tail = (tail + 1) % (W * H);
        } // 没吃到食物，尾巴往前挪
        head = (head + 1) % (W * H); // 无论吃没吃到食物，蛇头都往前进一格
        snake[head] = h;
        /*绘制页面*/
        clear();
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                char ch = '.';
                for (int i = tail; i < head; i = (i + 1) % (W * H))
                {
                    if (x == snake[i].x && y == snake[i].y)
                        ch = '*';
                }
                if (x == snake[head].x && y == snake[head].y)
                {
                    ch = '@';
                }
                if (x == food.x && y == food.y)
                    ch = '$';
                mvaddch(y, x, ch);
            }
        }
        mvprintw(H, 0, "Score: %d(q to quit)", score);
        refresh();//ncurses 有“双缓冲”机制,refresh()把整块缓冲一次性搬到真实终端
        usleep(120000);
    }
    clear();
    mvprintw(H+2,0,"Game Over!Final Score: %d",score);
    refresh();
    nodelay(stdscr,FALSE);//让 getch() 重新变成阻塞模式
    getch();
}

int main(){
    initscr();//启动ncurses
    curs_set(0);//隐藏光标
    init();//初始化
    loop();//主循环
    endwin();//释放终端
    return 0;
}