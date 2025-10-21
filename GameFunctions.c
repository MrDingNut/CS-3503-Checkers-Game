// Created by Mitch Walker on 10/19/2025.

#ifndef GAMEFUNCTIONS_C
#define GAMEFUNCTIONS_C

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void SetBit(unsigned long long *num,  int index);
void ClearBit(unsigned long long *num,  int index);
void ToggleBit(unsigned long long *num,  int index);
int GetBit(unsigned long long num,  int index);
int CountBits(unsigned long long num);
void PrintBinary(unsigned long long num);
void PrintHex(unsigned long long num);

// Debugging function to remind me how the board is indexed
void PrintBoardIndex() {
    //    a   b   c   d   e   f   g   h
    // 8 [m] [ ] [m] [ ] [m] [ ] [m] [ ]
    // 7 [ ] [m] [ ] [m] [ ] [m] [ ] [m]
    // 6 [m] [ ] [m] [ ] [m] [ ] [m] [ ]
    // 5 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
    // 4 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
    // 3 [ ] [w] [ ] [w] [ ] [w] [ ] [w]
    // 2 [w] [ ] [w] [ ] [w] [ ] [w] [ ]
    // 1 [ ] [w] [ ] [w] [ ] [w] [ ] [w]

    printf("   a    b    c    d    e    f    g    h\n");
    printf("8 [63] [62] [61] [60] [59] [58] [57] [56]\n");
    printf("7 [55] [54] [53] [52] [51] [50] [49] [48]\n");
    printf("6 [47] [46] [45] [44] [43] [42] [41] [40]\n");
    printf("5 [39] [38] [37] [36] [35] [34] [33] [32]\n");
    printf("4 [31] [30] [29] [28] [27] [26] [25] [24]\n");
    printf("3 [23] [22] [21] [20] [19] [18] [17] [16]\n");
    printf("2 [15] [14] [13] [12] [11] [10] [09] [08]\n");
    printf("1 [07] [06] [05] [04] [03] [02] [01] [00]\n\n");
}

// Print the current piece to the console
// I intentionally used multiple if statements instead of if else statements
// This way, if multiple bitboards have pieces in the same space, they will
// both be printed which will hopefully make debugging easier
void PrintPiece(int idx, unsigned long long redPieces,
    unsigned long long redKings,
    unsigned long long blackPieces,
    unsigned long long blackKings) {
    if (GetBit(redPieces, idx)) {
        if (GetBit(redKings, idx)) {
            printf("W");
        } else {
            printf("w");
        }
    }  if (GetBit(blackPieces, idx)) {
            if (GetBit(blackKings, idx)) {
            printf("M");
        } else {
            printf("m");
        }
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
    //    a   b   c   d   e   f   g   h
    // 8 [w] [ ] [w] [ ] [w] [ ] [w] [ ]
    // 7 [ ] [w] [ ] [w] [ ] [w] [ ] [w]
    // 6 [w] [ ] [w] [ ] [w] [ ] [w] [ ]
    // 5 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
    // 4 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
    // 3 [ ] [m] [ ] [m] [ ] [m] [ ] [m]
    // 2 [m] [ ] [m] [ ] [m] [ ] [m] [ ]
    // 1 [ ] [m] [ ] [m] [ ] [m] [ ] [m]

    printf("   a   b   c   d   e   f   g   h\n8 ");
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
            if (i/8) {
                printf("%d ", i/8);
            }
        }
    }
    printf("\n");
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

// Converts space name (e.g. C7) to the index of the corresponding bit for the bitboards
int Space2Index(char space[]) {
    char letter = space[0];         // Gets the letter from the space name
    letter      = toupper(letter);  // Forces the letter to be uppercase. Allows the input to be case independent
    int num     = space[1] - '0';   // Gets the number from the space name and converts it to an integer
    return (7 + ((num-1) * 8)) - (letter - 'A'); // Converts the letter and number to the corresponding index
    // The first set of parenthesis convert the number to the number of the left most index on the appropriate row
    // Ex, 2 turns to 15, 5, turns to 39, etc.
    // The second set of parenthesis moves the index to the proper space on the appropriate row
    // Ex, A leaves the index where it is, E moves the index to the right 4, etc.
}

// Verifies the space is valid
int IsValidSpace(char space[]) {
    char letter = space[0];         // Gets the letter from the space name
    int num     = space[1] - '0';   // Gets the number from the space name and converts it to an integer
      // Checks if letter is from 'A' to 'H'         Checks if letter is from 'a' to 'h'
    if ((letter - 'A' >= 0 && letter - 'A' <= 7) || (letter - 'a' >= 0 && letter - 'a' <= 7)) { // Verifies the letter is valid
        if (num >= 1 && num <= 8) { // Varifies the number is valid
            return 1;
        }
    }
    return 0;
}

// Returns 1 if idx is equal to any of the valid space indexes
int IsValidLocation(int idx) {
    int validIndex[] = {1,3,5,7,8,10,12,14,17,19,21,23,24,26,28,30,33,35,37,39,40,42,44,46,49,51,53,55,56,58,60,62};

    int length = sizeof(validIndex) / sizeof(validIndex[0]);
    for (int i = 0; i < length; i++) {
        if (idx == validIndex[i]) {
            return 1;
        }
    }
    return 0;
}

// Moves the piece
/* NOTE:
 * The if statements were used instead of nested if statements for readability
 *
 * I'm not a fan of how long this method is though
 *
 * Is there another way you would recommend doing this?
 * The only way I could think of was having the function check for every possible invalid move before moving the piece
 */
int MovePiece(char oldSpace[], char newSpace[],
    int isRed,
    unsigned long long *board,
    unsigned long long *friendlyPieces,
    unsigned long long *friendlyKings,
    unsigned long long *opponentPieces,
    unsigned long long *opponentKings) {

    int oldIdx = Space2Index(oldSpace);
    int newIdx = Space2Index(newSpace);

    int moveDistance = newIdx - oldIdx;

    // Set the direction multiplier for the separate pieces
    int direction = -1;
    if (isRed) {
        direction = 1;
    }

    moveDistance = moveDistance * direction;

    // Returns 0 if the old space name is invalid
    if (!IsValidSpace(oldSpace)) {
        printf("%s is not a valid space name\n", oldSpace);
        return 0; }

    // Returns 0 if the new space name is invalid
    if (!IsValidSpace(newSpace)) {
        printf("%s is not a valid space name\n", newSpace);
        return 0; }

    // Returns 0 if there's not a piece on the old space
    if (!GetBit(*board, oldIdx)) {
        printf("There's no piece on space %s\n", oldSpace);
        return 0; }

    // Returns 0 if the piece being moved isn't the current player's
    if (!GetBit(*friendlyPieces, oldIdx)) {
        printf("The piece on %s isn't yours\n", oldSpace);
        return 0;
    }

    // Returns 0 if the new space is not valid
    if (!IsValidLocation(newIdx)) {
        printf("Moving from %s to %s is an invalid move\n", oldSpace, newSpace);
        return 0; }

    // Returns 0 if the piece isn't a king and is moving in the wrong direction
    if (!GetBit(*friendlyKings, oldIdx)) { // Fires if the piece isn't a king
        if (moveDistance < 0) { // Fires if the piece is moving in the wrong direction (red must move up, black must move down)
            printf("The piece on space %s cannot move in that direction\n", oldSpace);
            return 0;
        }
    }

    // Returns 0 if the piece cannot move to the new space
    if (!(abs(moveDistance) == 9 || abs(moveDistance) == 7 || abs(moveDistance) == 18 || abs(moveDistance) == 14)) {
        printf("The piece on %s cannot move to %s\n", oldSpace, newSpace);
        return 0;
    }

    // Returns 0 if the new space is taken
    if (GetBit(*board, newIdx)) {
        printf("%s is not an open space\n", newSpace);
        return 0;
    }

    // Capture protocol
    if (moveDistance > 9) {
        int midIdx = (newIdx + oldIdx) / 2;

        // Returns 0 if the space being jumped isn't occupied by the opponent
        if (!GetBit(*opponentPieces, midIdx)) {
            printf("You cannot move to %s because you aren't jumping over your opponent's piece\n", newSpace);
            return 0;
        }

        // Move and remove the appropriate pieces
        SetBit(board, newIdx);
        SetBit(friendlyPieces, newIdx);

        // Moves king if the moved piece was a king
        if (GetBit(*friendlyKings, oldIdx)) {
            SetBit(friendlyKings, newIdx);
            ClearBit(friendlyKings, oldIdx);
        }

        ClearBit(board, oldIdx);
        ClearBit(friendlyPieces, oldIdx);
        ClearBit(board, midIdx);
        ClearBit(opponentPieces, midIdx);
        ClearBit(opponentPieces, midIdx);
        ClearBit(opponentKings, midIdx);
    }

    // Regular move
    if (moveDistance <= 9) {
        // Move the appropriate pieces
        SetBit(board, newIdx);
        SetBit(friendlyPieces, newIdx);

        ClearBit(board, oldIdx);
        ClearBit(friendlyPieces, oldIdx);

        // Moves king if the moved piece was a king
        if (GetBit(*friendlyKings, oldIdx)) {
            SetBit(friendlyKings, newIdx);
            ClearBit(friendlyKings, oldIdx);
        }
    }
    return 1;
}

// Checks if there's a piece on a promotion space and promotes it if applicable
void PromoteKings(unsigned long long *redPieces,
    unsigned long long *redKings,
    unsigned long long *blackPieces,
    unsigned long long *blackKings) {

    // Indexes of promotion spaces
    int redIdx[] = {63, 61, 59, 57};
    int blackIdx[] = {0, 2, 4, 6};

    // Check and set red kings
    for (int i = 0; i < 4; i++) {
        if (GetBit(*redPieces, redIdx[i])) {
            SetBit(redKings, redIdx[i]);
        }
    }

    // Check and set black kings
    for (int i = 0; i < 4; i++) {
        if (GetBit(*blackPieces, blackIdx[i])) {
            SetBit(blackKings, blackIdx[i]);
        }
    }
}

// Checks if a player has won by checking
int CheckWin(unsigned long long redPieces, unsigned long long blackPieces) {
    if (CountBits(blackPieces) == 0) {
        printf("\n**************************\n");
        printf("     PLAYER W WINS!\n");
        printf("**************************");
        return 1;
    }

    if (CountBits(redPieces) == 0) {
        printf("\n**************************\n");
        printf("     PLAYER M WINS!\n");
        printf("**************************");
        return 2;
    }

    return 0;
}

#endif
