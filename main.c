#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define Brows 5    //boardRows
#define Bcols 20   //boardColumns

//These 2 vars are global cuz we may change theri values
int asteriskRow= Brows-1;
int asteriskCol= 10;
int lost= 0;

int getKeyPressed();
void shiftRight(int board[Brows][Bcols], int row);
void shiftLeft(int board[Brows][Bcols], int row);
void printBoard(int board[Brows][Bcols]);
void move(int board[Brows][Bcols]);

int main()
{
    int board[Brows][Bcols]={
    {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
    {254, 254, 32, 32, 32, 32, 254, 254, 254, 254, 254, 32, 32, 32, 32, 254, 254, 32, 32, 254},
    {254, 254, 254, 254, 32, 32, 254, 254, 254, 32, 32, 32, 32, 32, 254, 254, 254, 32, 32, 254},
    {254, 254, 32, 32, 32, 32, 254, 254, 254, 254, 254, 32, 32, 32, 254, 254, 254, 32, 32, 254},
    {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 42, 32, 32, 32, 32, 32, 32, 32, 32, 32}
    }; //Ascii codes of the board characters.
       //Using integers, no need to care about the null terminator or the terminal encoding issues caused by the compiler.

    //The loop for tiles movement
    while(!lost){
        shiftRight(board, 1);
        shiftLeft(board, 2);
        shiftRight(board,3);
        move(board);

        printBoard(board);

        Sleep(150);
        system("cls");
    }

    return 0;
}


//Print updated board after movement
void printBoard(int board[Brows][Bcols]){
    for(int i=0; i<Brows; i++){
        for(int j=0; j<Bcols; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

//Shift Right:
void shiftRight(int board[Brows][Bcols], int row) {
    int lastElement;
    if(board[row][Bcols-1]==42){
        lastElement=32;
    }
    else
        lastElement= board[row][Bcols-1];
        //We need this early check to avoid shiting the asterisk which is special to the player.


    for (int col = Bcols-1; col > 0; col--) {
        if(board[row][col-1]==42)
            board[row][col] = 32; //We already got the value in the last column and shifted it, so if value in index before the current is *, then current is empty => ' '
        else if(board[row][col]==42){ //This statement is different from the first cuz if board[row][col-1] is the asterisk, then board[row][col] can't be the asterisk as well.
            if(board[row][col-1]==32){
                continue;
            }
            else {
                printf("You Died!");
                lost= 1;
                return;
            }

        }
        else
            board[row][col]= board[row][col-1];
    }
    board[row][0] = lastElement;
}

//Shift Left:
void shiftLeft(int board[Brows][Bcols], int row) {
    int firstElement;
    if(board[row][0]==42){
        firstElement=32;
    }
    else
        firstElement= board[row][0];



    for (int col = 0; col < Bcols-1; col++) {
        if(board[row][col+1]==42){
            board[row][col]=32;
        }
        else if(board[row][col]==42){
            if(board[row][col+1]==32){
                continue;
            }
            else{
                printf("You Died!");
                lost= 1;
                return;
            }
        }
        else
            board[row][col]= board[row][col+1];
    }
    board[row][Bcols-1] = firstElement;
}

//For getting user input to reflect movement
int getKeyPressed() {
    if (kbhit()) {
        int ch = getch();

        if (ch == 0 || ch == 224) {
            ch = getch();
        }
        return ch;
    }
    return -1;
}

//Move
void move(int board[Brows][Bcols]){
    int key= getKeyPressed();
    switch(key){
        case 'w':
        case 'W':
        case 72:
            if(board[asteriskRow-1][asteriskCol]==32){
                board[asteriskRow][asteriskCol]=32;
                asteriskRow--;
                board[asteriskRow][asteriskCol]=42;
            }
            else{
                printf("You Died!");
                lost= 1;
            }
            break;

        case 's':
        case 'S':
        case 80:
            if(board[asteriskRow+1][asteriskCol]==32){
                board[asteriskRow][asteriskCol]=32;
                asteriskRow++;
                board[asteriskRow][asteriskCol]=42;
            }
            else{
                printf("You Died!");
                lost= 1;
            }
            break;

        case 'd':
        case 'D':
        case 77:
            if(board[asteriskRow][asteriskCol+1]==32){
                board[asteriskRow][asteriskCol]=32;
                asteriskCol++;
                board[asteriskRow][asteriskCol]=42;
            }
            else{
                printf("You Died!");
                lost= 1;
            }
            break;

        case 'a':
        case 'A':
        case 75:
            if(board[asteriskRow][asteriskCol-1]==32){
                board[asteriskRow][asteriskCol]=32;
                asteriskCol--;
                board[asteriskRow][asteriskCol]=42;
            }
            else{
                printf("%d", board[asteriskRow][asteriskCol-1]);
                printf("You Died!");
                lost= 1;
            }
            break;

        default:
            ; //Do Nothing...
    }
}
