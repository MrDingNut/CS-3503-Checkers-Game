#include <stdio.h>
#include <string.h>

// Base Functions
// Remove if you don't use them in Main
void SetBit(unsigned long long *num,  int index);
void ClearBit(unsigned long long *num,  int index);
void ToggleBit(unsigned long long *num,  int index);
int GetBit(unsigned long long num,  int index);
int CountBits(unsigned long long num);
void PrintBinary(unsigned long long num);
void PrintHex(unsigned long long num);

// Game functions
void PrintBoardIndex();
void PrintBoard(unsigned long long board,
    unsigned long long redPieces,
    unsigned long long redKings,
    unsigned long long blackPieces,
    unsigned long long blackKings);
void SetBoard(unsigned long long *board);
void SetRedPieces(unsigned long long *redPieces);
void SetBlackPieces(unsigned long long *blackPieces);
int Space2Index(char space[]);
int IsValidSpace(char space[]);
int MovePiece(char oldSpace[], char newSpace[],
    int isRed,
    unsigned long long *board,
    unsigned long long *friendlyPieces,
    unsigned long long *friendlyKings,
    unsigned long long *opponentPieces,
    unsigned long long *opponentKings);

int main(void) {
    // Bitboards to track the main board and each player's pieces
    unsigned long long board = 0;
    unsigned long long redPieces = 0;
    unsigned long long redKings = 0;
    unsigned long long blackPieces = 0;
    unsigned long long blackKings = 0;

    // Set up the board
    // SetBoard(&board);
    // SetRedPieces(&redPieces);
    // SetBlackPieces(&blackPieces);

    SetBit(&board, 19);
    SetBit(&blackPieces, 19);

    SetBit(&board, 54);
    SetBit(&redPieces, 54);
    // SetBit(&redKings, 28);

    PrintBoardIndex();
    PrintBoard(board, redPieces, redKings, blackPieces, blackKings);

    char oldSpace[50] = "b7\0";
    char newSpace[50] = "a8\0";

    printf("Trying to move piece from %s to %s\n", oldSpace, newSpace);
    MovePiece(oldSpace, newSpace, 0, &board, &redPieces, &redKings, &blackPieces, &blackKings);
    PrintBoard(board, redPieces, redKings, blackPieces, blackKings);

    strcpy(oldSpace, "b4\0");
    strcpy(newSpace, "c3\0");

    printf("Trying to move piece from %s to %s\n", oldSpace, newSpace);
    MovePiece(oldSpace, newSpace, 1, &board, &redPieces, &redKings, &blackPieces, &blackKings);
    PrintBoard(board, redPieces, redKings, blackPieces, blackKings);

}