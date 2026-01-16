#include <stdio.h>
#include <conio.h>

#define cols 50
#define rows 20

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
    fill_board();
    print_board();

    read_keyboard();

    return 0; 
}