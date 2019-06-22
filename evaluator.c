#include <stdio.h>

#define BOARD_SIZE 3

int evaluate(char bo[][BOARD_SIZE]);

int main(){
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'X', 'O', ' '},
        {' ', ' ', ' '},
        {' ', 'O', 'X'}
    };

    int value = evaluate(board);
    printf("The value of this board is %d\n", value);
    return 0;
}

int evaluate(char bo[][BOARD_SIZE]){
    char le = 'X';
    /* match for X */
    if  ((bo[0][0] == le && bo[0][1] == le && bo[0][2] == le) || // across the top
        (bo[1][0] == le && bo[1][1] == le && bo[1][2] == le) || // across the middle
        (bo[2][0] == le && bo[2][1] == le && bo[2][2] == le) || // across the bottom
        (bo[0][0] == le && bo[1][0] == le && bo[2][0] == le) || // down the left side
        (bo[0][1] == le && bo[1][1] == le && bo[2][1] == le) || // down the middle
        (bo[0][2] == le && bo[1][2] == le && bo[2][2] == le) || // down the right side
        (bo[0][0] == le && bo[1][1] == le && bo[2][2] == le) || // diagonal
        (bo[0][2] == le && bo[1][1] == le && bo[2][0] == le)){  // diagonal
        return 10;
    }
  
    le = 'O'; 
    if  ((bo[0][0] == le && bo[0][1] == le && bo[0][2] == le) || // across the top
        (bo[1][0] == le && bo[1][1] == le && bo[1][2] == le) || // across the middle
        (bo[2][0] == le && bo[2][1] == le && bo[2][2] == le) || // across the bottom
        (bo[0][0] == le && bo[1][0] == le && bo[2][0] == le) || // down the left side
        (bo[0][1] == le && bo[1][1] == le && bo[2][1] == le) || // down the middle
        (bo[0][2] == le && bo[1][2] == le && bo[2][2] == le) || // down the right side
        (bo[0][0] == le && bo[1][1] == le && bo[2][2] == le) || // diagonal
        (bo[0][2] == le && bo[1][1] == le && bo[2][0] == le)){  // diagonal
        return -10;
    }

    return 0;
}
