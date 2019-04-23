#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 3

enum {
    HUMAN,
    COMPUTER
};

void board_init(char board[][BOARD_SIZE], int size);
void board_display(char board[][BOARD_SIZE], int size);
bool board_check_match(char bo[][BOARD_SIZE], char le);
bool board_full(char board[][BOARD_SIZE]);

int main(int argc, char* argv[]){
    srand(time(NULL));
    puts("\t*** TIC TAC TOE ***\n");
    char board[BOARD_SIZE][BOARD_SIZE] = {};
    board_init(board, BOARD_SIZE);
    board_display(board, BOARD_SIZE);

    bool running = true;
    int turn = HUMAN;
    while(running){
        if(turn == HUMAN){
            int x = -1, y = -1;
            do {
                printf("Your turn: (x y): ");
                scanf("%d%d", &x, &y);
            } while(board[x][y] != ' ');
            
            board[x][y] = 'X';

            /* test to see if there is a game over */
            bool full = board_full(board);
            if((board_check_match(board, 'X') || board_check_match(board, 'O') || full)){
                running = false;
            }
            

            turn = COMPUTER;
        } else {
            printf("Computer's Turn:\n");

            /* Computer makes a random move */    
            bool found_empty = board_full(board);
            while(!found_empty) {
                int ai_rand_row = rand() % BOARD_SIZE;
                int ai_rand_col = rand() % BOARD_SIZE;      

                if(board[ai_rand_row][ai_rand_col] != 'X' && 
                   board[ai_rand_row][ai_rand_col] != 'O') {
                    board[ai_rand_row][ai_rand_col] = 'O';
                    found_empty = true;
                }
            }
            
            /* test to see if there is a game over */
            bool full = board_full(board);
            if((board_check_match(board, 'X') || board_check_match(board, 'O') || full)){
                running = false;
            }
            turn = HUMAN;
        }
    
        board_display(board, BOARD_SIZE);
    }

    puts("Game Over!");
    return 0;
}

void board_init(char board[][BOARD_SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = ' ';
        }
    }
}

void board_display(char board[][BOARD_SIZE], int size){
    printf("\t   0    1   2\n\n");
    printf("\t0|  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t | -----------\n");
    printf("\t1|  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t | -----------\n");
    printf("\t2|  %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

bool board_check_match(char bo[][BOARD_SIZE], char le){
    return ((bo[0][0] == le && bo[0][1] == le && bo[0][2] == le) || // across the top
            (bo[1][0] == le && bo[1][1] == le && bo[1][2] == le) || // across the middle
            (bo[2][0] == le && bo[2][1] == le && bo[2][2] == le) || // across the bottom
            (bo[0][0] == le && bo[1][0] == le && bo[2][0] == le) || // down the left side
            (bo[0][1] == le && bo[1][1] == le && bo[2][1] == le) || // down the middle
            (bo[0][2] == le && bo[1][2] == le && bo[2][2] == le) || // down the right side
            (bo[0][0] == le && bo[1][1] == le && bo[2][2] == le) || // diagonal
            (bo[0][2] == le && bo[1][1] == le && bo[2][0] == le));  // diagonal
}

bool board_full(char board[][BOARD_SIZE]){
    int board_full = true;
    for(int row = 0; row < BOARD_SIZE; ++row) {
        for(int col = 0; col < BOARD_SIZE; ++col) {
            if(board[row][col] != 'X' && board[row][col] != 'O')  {
                board_full = false;
            }
        }
    }
    return board_full;
}
