#include<stdio.h>    
#include<stdbool.h>


typedef struct board
{
    char row1[3];
    char row2[3];
    char row3[3];
}board_t;

void create_board(board_t* boardptr)
{
    int i;
    for(i=0; i<3; i++)
    {
        boardptr->row1[i]='-';
        boardptr->row2[i]='-';
        boardptr->row3[i]='-';
    }
    return;
}

board_t* update_board(board_t* boardptr, const char symbol/* X or O */)
{
    printf("Enter '\\' to exit or any other key to continue: \n");
    char key; // '>', '<', 'm', ' ' or '\'
    char enter[3];
    unsigned int i = 0, j = 0;
    do 
    {
        fgets(&key, 1, stdin);
        switch (key) 
        {
            case '>':
                i++;
                break;
            case '<':
                i--;
                break;
            case ' ':
                j++;
                break;
            case 'm':
                j--;
                break;
            default:
                break;
        }
        if(i > 2)
        {
            i = 2;
        }

        if(j > 2)
        {
            j = 2;
        }
        
    } while (key != '\\');
   if(symbol == 'X')
   {

        
        if(i==0)
        {
            boardptr->row1[j] = 'X';
        }
        if(i==1)
        {
            boardptr->row2[j] = 'X';
        }
        if(i==2)
        {
            boardptr->row3[j] = 'X';
        }
   }
   if(symbol == 'O')
   {

        
        if(i==0)
        {
            boardptr->row1[j] = 'O';
        }
        if(i==1)
        {
            boardptr->row2[j] = 'O';
        }
        if(i==2)
        {
            boardptr->row3[j] = 'O';
        }
   }
    return boardptr;
}

void print_board(board_t* boardptr)
{
    "                    |                    |\n"
"              %c        |       %c           |         %c        \n"
"                        |                    |\n"
"       _________________|____________________|___________________\n"
"                        |                    |\n"
"              %c        |       %c           |         %c\n"
"                        |                    |\n"
"       _________________|____________________|___________________\n"
"                        |                    |                   \n"
"                        |                    |\n"
"              %c        |       %c           |         %c\n"
"                        |                    |\n"
"                        |                    |\n"

        boardptr->row1[0], boardptr->row1[1], boardptr->row1[2],
        boardptr->row2[0], boardptr->row2[1], boardptr->row2[2],
        boardptr->row3[0], boardptr->row3[1], boardptr->row3[2]                                                                         
    );
    

}




bool win_check_function(board_t* boardptr, const char symbol)
{
    if  (boardptr->row1[0] == symbol && boardptr->row1[1] == symbol && boardptr->row1[2] == symbol) ||
        (boardptr->row2[0] == symbol && boardptr->row2[1] == symbol && boardptr->row2[2] == symbol) ||
        (boardptr->row3[0] == symbol && boardptr->row3[1] == symbol && boardptr->row3[2] == symbol) ||
        (boardptr->row1[0] == symbol && boardptr->row2[0] == symbol && boardptr->row3[0] == symbol) ||
        (boardptr->row1[1] == symbol && boardptr->row2[1] == symbol && boardptr->row3[1] == symbol) ||
        (boardptr->row1[2] == symbol && boardptr->row2[2] == symbol && boardptr->row3[2] == symbol) ||
        (boardptr->row1[0] == symbol && boardptr->row2[1] == symbol && boardptr->row3[2] == symbol) ||
        (boardptr->row1[2] == symbol && boardptr->row2[1] == symbol && boardptr->row3[0] == symbol)
        {
            return true;
        }
    return false;
}



int main(void)
{
    
    return 0;
}
