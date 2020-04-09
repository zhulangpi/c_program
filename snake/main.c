#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "snake.h"


#define POINT   ('*')
#define BLANK   (' ')

#define Y_OFFSET    (0)
#define X_OFFSET    (0)
#define Y_LEN       (18)
#define X_LEN       (30)

#define swap(m,n)   do{ m += n; n = m-n; m = m-n;}while(0)
#define fresh()     do{ move(LINES-1,COLS-1);refresh();}while(0);


void drawline(int y0, int x0, int y1, int x1);
void drawframe(int y0, int x0, int y1, int x1);

void paint_body(int y, int x);
void paint_food(int y, int x);
void erase_ch(int y, int x);
void* scan_input(void*);


char input;


int main(int argc, char* argv[])
{
    int x,y;        //光标坐标
    int ret;
    int speed;
    int scores;

    pthread_t ntid;
    
    initscr(); /*初始化屏幕*/
 
    /*开启颜色*/
    if(start_color() != OK){
        endwin();
        printf("can't init start_color!\n");
        return -1;
    }

    init_pair(1, COLOR_RED, COLOR_BLACK); /*建立一个颜色对*/
    init_pair(2, COLOR_YELLOW, COLOR_BLACK); /*建立一个颜色对*/
    init_pair(3, COLOR_BLUE, COLOR_BLACK); /*建立一个颜色对*/
    
restart:
    speed = 5000;
    scores = 0;
    clear();
    attron(COLOR_PAIR(1)); /*开启字符输出颜色*/
    
    mvprintw(LINES/2, COLS/2, "enjoy the game!");
    
    mvprintw(LINES-4, 0, " scores: %d ", scores);
    mvprintw(LINES-3, 0, " speed: %d, 'I'-faster, 'O'-slower ", speed);
    mvprintw(LINES-2, 0, " control: 'W'-up, 'S'-down, 'A'-left, 'D'-right ");
    mvprintw(LINES-1, 0, " 'P'-pause, 'Q'-quit ");
    
    drawframe(Y_OFFSET, X_OFFSET, Y_OFFSET + Y_LEN + 1, X_OFFSET + X_LEN + 1);

    attroff(COLOR_PAIR(1)); /*关闭颜色显示*/
    attron(COLOR_PAIR(2)); /*开启字符输出颜色*/
    
    keypad(stdscr,true);
    noecho();

    init_snake(Y_LEN, X_LEN, paint_body, paint_food, erase_ch);
    fresh();
    pthread_create(&ntid, NULL, scan_input, NULL);
    
    while(1){
        //getyx(stdscr,y,x);
        ret = 0;
        switch(input){
            case 'W': case 'w':
                ret = walk(UP);
                break;
            case 'S': case 's':
                ret = walk(DOWN);
                break;
            case 'A': case 'a':
                ret = walk(LEFT);
                break;
            case 'D': case 'd':
                ret = walk(RIGHT);
                break;
            case 'P': case 'p':
                break;
            case 'I': case 'i':
                speed *= 1.2;
                attron(COLOR_PAIR(2)); /*开启字符输出颜色*/
                mvprintw(LINES-3, 0, " speed: %d, 'I'-faster, 'O'-slower ", speed);
                input = 0;
                break;
            case 'O': case 'o':
                speed *= 0.8;
                attron(COLOR_PAIR(2)); /*开启字符输出颜色*/
                mvprintw(LINES-3, 0, " speed: %d, 'I'-faster, 'O'-slower ", speed);
                input = 0;
                break;
            case 'Q': case 'q':
                goto quit;
                break;
            default:
                break;
        }
        if(ret == 1){
            scores+=speed;
            attron(COLOR_PAIR(2)); /*开启字符输出颜色*/
            mvprintw(LINES-4, 0, " scores: %d ", scores);
        }
        //beep();
        if(ret == -1){
            free_snake();
            clear();
            mvprintw(LINES/2, COLS/2, "GAME OVER! The final scores: %d", scores);
            refresh();
            sleep(2);
            goto restart;
        }
        fresh();
        usleep(1000*1000*1000/speed);
    }

quit:
    endwin(); /*关闭curses状态*/
    
    return 0;
}


void* scan_input(void *arg)
{
    (void)arg;
    while(1){
        input = getch();
        usleep(10*1000);
    }
    return NULL;
}


//不考虑斜线
void drawline(int y0, int x0, int y1, int x1)
{
    int len,i;
    if( y0<0 || x0<0 || y1<0 || x1<0 )
        return ;

    if(y0 == y1){
        if(x1<x0)
            swap(x0,x1);
        len = x1-x0;
        for(i = 0; i<=len; i++){
            mvaddch(y0, x0 + i, POINT );
            refresh();
        }
    }else if(x0 == x1){
        if(y1<y0)
            swap(y0,y1);
        len = y1-y0;
        for(i = 0; i<=len; i++){
            mvaddch(y0 + i, x0, POINT );
            refresh();
        }
    }
    refresh();
}


//  (x0,y0)
//
//
//                  (x1,y1)
void drawframe(int y0, int x0, int y1, int x1)
{
    drawline(y0, x0, y0, x1);
    drawline(y1, x0, y1, x1);
    drawline(y0, x0, y1, x0);
    drawline(y0, x1, y1, x1);
    refresh();
}

/*
void clean_frame(int y0, int x0, int y1, int x1)
{

}
*/

void paint_body(int y, int x)
{
    attron(COLOR_PAIR(2)); /*开启字符输出颜色*/
    mvaddch(Y_OFFSET + 1 + y, X_OFFSET + 1 + x, POINT);
    fresh();
}

void paint_food(int y, int x)
{
    attron(COLOR_PAIR(3)); /*开启字符输出颜色*/
    mvaddch(Y_OFFSET + 1 + y, X_OFFSET + 1 + x, POINT);
    fresh();
}

void erase_ch(int y, int x)
{
    mvaddch(Y_OFFSET + 1 + y, X_OFFSET + 1 + x, BLANK);
    fresh();
}

