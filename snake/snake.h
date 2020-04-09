#ifndef _SNAKE_H
#define _SNAKE_H

enum {
    UP = 1,
    LEFT,
    DOWN,
    RIGHT,
    FOOD
};


void init_snake(int h, int w, void (*paint_body)(int, int), void (*paint_food)(int, int),  void (*erase)(int, int));
int walk(int direction);
void free_snake(void);

#endif
