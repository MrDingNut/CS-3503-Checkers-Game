// Created by Mitch Walker on 10/19/2025.

#ifndef GAMEFUNCTIONS_C
#define GAMEFUNCTIONS_C

#include <stdio.h>

void SetBit(unsigned long long *num,  int index);
void ClearBit(unsigned long long *num,  int index);
void ToggleBit(unsigned long long *num,  int index);
int GetBit(unsigned long long num,  int index);
int CountBits(unsigned long long num);
void PrintBinary(unsigned long long num);
void PrintHex(unsigned long long num);

// Debugging function to remind me how the board is indexed
void PrintBoardIndex() {
    // {"[w] [ ] [w] [ ] [w] [ ] [w] [ ]"}
    // {"[ ] [w] [ ] [w] [ ] [w] [ ] [w]"}
    // {"[w] [ ] [w] [ ] [w] [ ] [w] [ ]"}
    // {"[ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]"}
    // {"[ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]"}
    // {"[ ] [m] [ ] [m] [ ] [m] [ ] [m]"}
    // {"[m] [ ] [m] [ ] [m] [ ] [m] [ ]"}
    // {"[ ] [m] [ ] [m] [ ] [m] [ ] [m]"}

    printf("[63] [62] [61] [60] [59] [58] [57] [56]\n");
    printf("[55] [54] [53] [52] [51] [50] [49] [48]\n");
    printf("[47] [46] [45] [44] [43] [42] [41] [40]\n");
    printf("[39] [38] [37] [36] [35] [34] [33] [32]\n");
    printf("[31] [30] [29] [28] [27] [26] [25] [24]\n");
    printf("[23] [22] [21] [20] [19] [18] [17] [16]\n");
    printf("[15] [14] [13] [12] [11] [10] [09] [08]\n");
    printf("[07] [06] [05] [04] [03] [02] [01] [00]\n\n");
}

// Print the current piece to the console
// I intentionally used multiple if statements instead of if else statements
// This way, if multiple bitboards have pieces in the same space, they will
// both be printed which will hopefully make debugging
void PrintPiece(int idx, unsigned long long redPieces,
    unsigned long long redKings,
    unsigned long long blackPieces,
    unsigned long long blackKings) {
    if (GetBit(redPieces, idx)) {
        printf("m");
    } if (GetBit(redKings, idx)) {
        printf("M");
    } if (GetBit(blackPieces, idx)) {
        printf("w");
    } if (GetBit(blackKings, idx)) {
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
        // printf("i=%d", i);

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

void SetBoard(unsigned long long *board) {
    // Set red pieces
   SetBit(board,  1);
   SetBit(board,  3);
   SetBit(board,  5);
   SetBit(board,  7);
   SetBit(board,  8);
   SetBit(board,  10);
   SetBit(board,  12);
   SetBit(board,  14);
   SetBit(board,  17);
   SetBit(board,  19);
   SetBit(board,  21);
   SetBit(board,  23);

    // Set black pieces
   SetBit(board,  62);
   SetBit(board,  60);
   SetBit(board,  58);
   SetBit(board,  56);
   SetBit(board,  55);
   SetBit(board,  53);
   SetBit(board,  51);
   SetBit(board,  49);
   SetBit(board,  46);
   SetBit(board,  44);
   SetBit(board,  42);
   SetBit(board,  40);
}

void SetRedPieces(unsigned long long *redPieces) {
    // Set red pieces
   SetBit(redPieces,  1);
   SetBit(redPieces,  3);
   SetBit(redPieces,  5);
   SetBit(redPieces,  7);
   SetBit(redPieces,  8);
   SetBit(redPieces,  10);
   SetBit(redPieces,  12);
   SetBit(redPieces,  14);
   SetBit(redPieces,  17);
   SetBit(redPieces,  19);
   SetBit(redPieces,  21);
   SetBit(redPieces,  23);
}

void SetBlackPieces(unsigned long long *blackPieces) {

    // Set black pieces
   SetBit(blackPieces,  62);
   SetBit(blackPieces,  60);
   SetBit(blackPieces,  58);
   SetBit(blackPieces,  56);
   SetBit(blackPieces,  55);
   SetBit(blackPieces,  53);
   SetBit(blackPieces,  51);
   SetBit(blackPieces,  49);
   SetBit(blackPieces,  46);
   SetBit(blackPieces,  44);
   SetBit(blackPieces,  42);
   SetBit(blackPieces,  40);
}

// moveRedPiece

#endif
