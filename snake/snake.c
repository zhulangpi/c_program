#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "snake.h"

struct snake{
    char *space;
    int h;
    int w;
    int head_y;
    int head_x;
    int tail_y;
    int tail_x;
    void (*paint_body)(int y, int x);
    void (*paint_food)(int y, int x);
    void (*erase)(int y, int x);
};

struct snake *psnake;

#define snake(y,x)   ( psnake->space[(y)*(psnake->w) + (x)] )


int is_ok(int y, int x)
{
    //过界
    if( (y<0) || (x<0) ||  (y>=psnake->h) || (x>=psnake->w) )
        return 0;
    //蛇身
    if(snake(y,x)!=0 && snake(y,x)!=FOOD)
        return 0;
    return 1;
}

void new_food(void)
{
    int y,x;

    do{
        y = rand()%psnake->h;     // [2, h-2]
        x = rand()%psnake->w;     // [2, w-2]
    }while(!is_ok(y,x));
    snake(y,x) = FOOD;
    psnake->paint_food(y,x);
}


//贪吃蛇是一个高h，宽w的空间
void init_snake(int h, int w, void (*paint_body)(int, int), void (*paint_food)(int, int), void (*erase)(int, int))
{
    int y,x;
    int direction;

    if(h<6 || w<6)
        return ;

    psnake = (struct snake*)malloc(sizeof(struct snake));
    psnake->space = (char*)malloc(w*h);
    psnake->h = h;
    psnake->w = w;
    psnake->paint_body = paint_body;
    psnake->paint_food = paint_food;
    psnake->erase = erase;
    memset(psnake->space, 0, w*h);

    //确定蛇头位置
    y = rand()%(h-4)+2;     // [2, h-2]
    x = rand()%(w-4)+2;     // [2, w-2]
    psnake->head_y = y;
    psnake->head_x = x;

    //固定初始长度为3，方向随机
    srand((unsigned)time(NULL));
    direction = rand()%4 + 1;
    snake(y,x) = direction;
    paint_body(y,x);

    if(direction==UP){
        snake(y+1,x) = UP;
        snake(y+2,x) = UP;
        paint_body(y+1,x);
        paint_body(y+2,x);
        psnake->tail_y = y+2;
        psnake->tail_x = x;
    }else if(direction==DOWN){
        snake(y-1,x) = DOWN;
        snake(y-2,x) = DOWN;
        paint_body(y-1,x);
        paint_body(y-2,x);
        psnake->tail_y = y-2;
        psnake->tail_x = x;
    }else if(direction==LEFT){
        snake(y,x+1) = LEFT;
        snake(y,x+2) = LEFT;
        paint_body(y,x+1);
        paint_body(y,x+2);
        psnake->tail_y = y;
        psnake->tail_x = x+2;
    }else if(direction==RIGHT){
        snake(y,x-1) = RIGHT;
        snake(y,x-2) = RIGHT;
        paint_body(y,x-1);
        paint_body(y,x-2);
        psnake->tail_y = y;
        psnake->tail_x = x-2;
    }else{
        printf("init error direction\n");
    }

    new_food();
}



//1-up 2-down 3-left 4-right
//往对应方向前进，蛇头前进，蛇尾消失
int walk(int direction)
{
    int y,x;
    int old_y, old_x;
    int head_direction;
    int tail_direction;
    int not_erase=0;
    int ret = 0;

    y = psnake->head_y;
    x = psnake->head_x;

    head_direction = snake(psnake->head_y, psnake->head_x);

    if( (direction<UP) || (direction>RIGHT) ){
        direction = head_direction;
    }else if( abs(direction-head_direction)==2 )
        direction = head_direction;

    old_y = y;
    old_x = x;

    if(direction==UP){
        y--;
    }else if(direction==DOWN){
        y++;
    }else if(direction==LEFT){
        x--;
    }else if(direction==RIGHT){
        x++;
    }

    //不能前进
    if(!is_ok(y,x)){
        printf("game over!\n");
        return -1;//game over
    }
    if(snake(y,x)==FOOD){   //吃到了食物，尾巴不消失
        new_food();
        not_erase = 1 ;
        ret = 1;
    }

    snake(old_y, old_x) = direction;
    snake(y,x) = direction;
    psnake->paint_body(y, x);
    psnake->head_y = y;
    psnake->head_x = x;

    if(not_erase)
        return ret;

    tail_direction = snake(psnake->tail_y, psnake->tail_x);
    snake(psnake->tail_y, psnake->tail_x) = 0;
    psnake->erase(psnake->tail_y, psnake->tail_x);

    if(tail_direction==UP){
        psnake->tail_y--;
    }else if(tail_direction==DOWN){
        psnake->tail_y++;
    }else if(tail_direction==LEFT){
        psnake->tail_x--;
    }else if(tail_direction==RIGHT){
        psnake->tail_x++;
    }else{
        printf("erase error\n");
    }

    return ret;
}


void free_snake(void)
{
    free(psnake->space);
    free(psnake);
}

