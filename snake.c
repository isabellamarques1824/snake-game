#include <stdio.h>

#define cols 20 
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
        }   
    }
}

int main(int argc, char **argv)
{

    return 0; 
}