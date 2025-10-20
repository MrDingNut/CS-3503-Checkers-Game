// Created by Mitch Walker on 10/19/2025.

#ifndef GAMEFUNCTIONS_C
#define GAMEFUNCTIONS_C

#include <stdio.h>

unsigned long long SetBit(unsigned long long num,  int index);
unsigned long long ClearBit(unsigned long long num,  int index);
unsigned long long ToggleBit(unsigned long long num,  int index);
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

unsigned long long SetBoard() {
    unsigned long long board = 0;
    // Set red pieces
   board = SetBit(board,  1);
   board = SetBit(board,  3);
   board = SetBit(board,  5);
   board = SetBit(board,  7);
   board = SetBit(board,  8);
   board = SetBit(board,  10);
   board = SetBit(board,  12);
   board = SetBit(board,  14);
   board = SetBit(board,  17);
   board = SetBit(board,  19);
   board = SetBit(board,  21);
   board = SetBit(board,  23);

    // Set black pieces
   board = SetBit(board,  62);
   board = SetBit(board,  60);
   board = SetBit(board,  58);
   board = SetBit(board,  56);
   board = SetBit(board,  55);
   board = SetBit(board,  53);
   board = SetBit(board,  51);
   board = SetBit(board,  49);
   board = SetBit(board,  46);
   board = SetBit(board,  44);
   board = SetBit(board,  42);
   board = SetBit(board,  40);

    return board;
}

unsigned long long SetRedPieces() {
    unsigned long long redPieces = 0;
    // Set red pieces
   redPieces = SetBit(redPieces,  1);
   redPieces = SetBit(redPieces,  3);
   redPieces = SetBit(redPieces,  5);
   redPieces = SetBit(redPieces,  7);
   redPieces = SetBit(redPieces,  8);
   redPieces = SetBit(redPieces,  10);
   redPieces = SetBit(redPieces,  12);
   redPieces = SetBit(redPieces,  14);
   redPieces = SetBit(redPieces,  17);
   redPieces = SetBit(redPieces,  19);
   redPieces = SetBit(redPieces,  21);
   redPieces = SetBit(redPieces,  23);

    return redPieces;
}

unsigned long long SetBlackPieces() {
    unsigned long long blackPieces = 0;

    // Set black pieces
   blackPieces = SetBit(blackPieces,  62);
   blackPieces = SetBit(blackPieces,  60);
   blackPieces = SetBit(blackPieces,  58);
   blackPieces = SetBit(blackPieces,  56);
   blackPieces = SetBit(blackPieces,  55);
   blackPieces = SetBit(blackPieces,  53);
   blackPieces = SetBit(blackPieces,  51);
   blackPieces = SetBit(blackPieces,  49);
   blackPieces = SetBit(blackPieces,  46);
   blackPieces = SetBit(blackPieces,  44);
   blackPieces = SetBit(blackPieces,  42);
   blackPieces = SetBit(blackPieces,  40);

    return blackPieces;
}


#endif
