// Created by Mitch Walker on 10/19/2025.

#ifndef GAMEFUNCTIONS_C
#define GAMEFUNCTIONS_C

#include <stdio.h>

unsigned int SetBit(unsigned int num,  int index);
unsigned int ClearBit(unsigned int num,  int index);
unsigned int ToggleBit(unsigned int num,  int index);
int GetBit(unsigned int num,  int index);
int CountBits(unsigned int num);
void PrintBinary(unsigned int num);
void PrintHex(unsigned int num);

void PrintPiece(int idx, unsigned long long redPieces,
    unsigned long long redKings,
    unsigned long long blackPieces,
    unsigned long long blackKings) {
    if (GetBit(redPieces, idx)) {
        printf("m");
    } else if (GetBit(redKings, idx)) {
        printf("M");
    } else if (GetBit(blackPieces, idx)) {
        printf("w");
    } else if (GetBit(blackKings, idx)) {
        printf("W");
    }
}

// Function prints the board with the current pieces
void PrintBoard(unsigned long long board,
    unsigned long long redPieces,
    unsigned long long redKings,
    unsigned long long blackPieces,
    unsigned long long blackKings) {

    // w pieces are black
    // m pieces are red
    // Capitol pieces are kings
    // {"[w] [ ] [w] [ ] [w] [ ] [w] [ ]"}
    // {"[ ] [w] [ ] [w] [ ] [w] [ ] [w]"}
    // {"[w] [ ] [w] [ ] [w] [ ] [w] [ ]"}
    // {"[ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]"}
    // {"[ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]"}
    // {"[ ] [m] [ ] [m] [ ] [m] [ ] [m]"}
    // {"[m] [ ] [m] [ ] [m] [ ] [m] [ ]"}
    // {"[ ] [m] [ ] [m] [ ] [m] [ ] [m]"}

    for (int i = 63; i >= 0 ; i--) {
        printf("[");

        if (GetBit(board, i)) { // Print the appropriate piece if the current space is occupied
            // printf("Printing Piece at i = %d", i);
            PrintPiece(i, redPieces, redKings, blackPieces, blackKings);
        } else {
            printf(" ");
        }

        printf("] ");

        if ((i) % 8 == 0 && i != 63) {
            printf("\n");
        }
    }
}


#endif
