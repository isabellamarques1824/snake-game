#include <stdio.h>
#include <conio.h>

#define cols 50
#define rows 20

int isGameOver = 0;

char board[cols * rows];

void fill_board()
{
    int y,x;

    for(y = 0; y < rows; y++)
    {
        for(x =0; x < cols; x++)
        {
            if(y == 0 || x == 0 || y == rows - 1 || x == cols - 1  )
            {
                board[y * cols + x] = '#';
            }
            else
            {
                board[y * cols + x] = ' ';
            }
        }   
    }
}

void print_board()
{
    int y,x;

    for(y = 0; y < rows; y++)
    {
        for(x =0; x < cols; x++)
        {
            putch(board[y * cols + x]);
        }   
        putch('\n');
    }
}

#define SNAKE_MAX_LEN 256

struct SnakePart 
{
    int x,y;
};

struct Snake
{
    int length;
    struct SnakePart part[SNAKE_MAX_LEN]; 
};

struct Snake snake;

void draw_snake()
{
    int i;

    for(i = snake.length; i > 0; i--)
    {
        board[snake.part[i].y * cols + snake.part[i].x] = '*';
    }
    board[snake.part[0].y * cols + snake.part[0].x] = '@';
}

void move_snake(int deltaX , int deltaY)
{
    int i; 

    for(i = snake.length-1; i > 0; i--)
    {
        snake.part[i] = snake.part[i -1];
    }
    snake.part[0].x += deltaX;
    snake.part[0].y += deltaY;
}

void read_keyboard()
{

    int ch = getch();

    switch (ch)
    {
    case 'w': move_snake(0, -1); break;
    case 's': move_snake(0, 1); break;
    case 'a': move_snake(-1, 0); break;
    case 'd': move_snake(1, 0); break;
    }
}

int main(int argc, char **argv)
{

    snake.length = 2;
    snake.part[0].x = 5;
    snake.part[0].y = 5;
    snake.part[1].x = 5;
    snake.part[1].y = 6;
    
    while (!isGameOver)
    {
        fill_board();
        draw_snake();
        print_board();
        read_keyboard();
    }

    return 0; 
}