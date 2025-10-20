#include <stdio.h>

// Base Functions
// Remove if you don't use them in Main
unsigned long long SetBit(unsigned long long num,  int index);
unsigned long long ClearBit(unsigned long long num,  int index);
unsigned long long ToggleBit(unsigned long long num,  int index);
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
unsigned long long SetBoard();
unsigned long long SetRedPieces();
unsigned long long SetBlackPieces();

int main(void) {
    // Bitboards to track the main board and each player's pieces
    unsigned long long board = 0;
    unsigned long long redPieces = 0;
    unsigned long long redKings = 0;
    unsigned long long blackPieces = 0;
    unsigned long long blackKings = 0;

    board = SetBoard();
    redPieces = SetRedPieces();
    blackPieces = SetBlackPieces();

    // board = SetBit(board,  0);
    // board = SetBit(board,  63);

    // PrintBinary(board);

    // if (GetBit(board, 63)) {
    //     printf("Got it");
    // }

    // redPieces = SetBit(redPieces,  0);
    // blackPieces = SetBit(blackPieces,  63);
    //

    PrintBoardIndex();
    PrintBoard(board, redPieces, redKings, blackPieces, blackKings);

    printf("Board: ");
    PrintBinary(board);

    printf("\nRed Pieces: ");
    PrintBinary(redPieces);

    printf("\nRed Kings: ");
    PrintBinary(redKings);

    printf("\nBlack Pieces: ");
    PrintBinary(blackPieces);

    printf("\nBlack Kings: ");
    PrintBinary(blackKings);
}