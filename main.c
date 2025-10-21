#include <stdio.h>
#include <string.h>

// Red   is W/w
// Black is M/m

// Game functions
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
void PromoteKings(unsigned long long *redPieces,
    unsigned long long *redKings,
    unsigned long long *blackPieces,
    unsigned long long *blackKings);
int CheckWin(unsigned long long redPieces, unsigned long long blackPieces);

void SetTestBoard(unsigned long long *board);
void SetTestPieces(unsigned long long *redPieces, unsigned long long *blackPieces);

int main(void) {

    // Bitboards to track the main board and each player's pieces
    unsigned long long board = 0;
    unsigned long long redPieces = 0;
    unsigned long long redKings = 0;
    unsigned long long blackPieces = 0;
    unsigned long long blackKings = 0;

    // Set up the board
    SetBoard(&board);
    SetRedPieces(&redPieces);
    SetBlackPieces(&blackPieces);

    // Set up test board for debugging
    // SetTestBoard(&board);
    // SetTestPieces(&redPieces, &blackPieces);

    int gameWon = 0;
    int validMove = 0;
    int wonGame = 0;
    char userInput[50];
    char oldSpace[50];
    char newSpace[50];

    PrintBoard(board, redPieces, redKings, blackPieces, blackKings);
    printf("Welcome to Checkers!\n");
    printf("Here are the house rules:\n");
    printf("1. Jumping is optional\n");
    printf("2. Pieces are called by the space they occupy\n");
    printf("3. Double jumps are not allowed\n");
    printf("4. No complaining about the lack of double jumps...\n");
    printf("5. No double jumps was a *creative* decision\n");
    printf("6. Player W goes first\n");
    printf("7. This is a two player game\n");
    printf("8. Capitol letters are kings\n");
    printf("9. Enter \"Ready\" when you're ready to begin!\n");
    fflush(stdout);
    fgets(userInput, 50, stdin);
    userInput[strcspn(userInput, "\n")] = 0;


    while (!gameWon) {
        // **************** Red Player's Turn ****************
        while (!validMove) {
            PromoteKings(&redPieces, &redKings, &blackPieces, &blackKings);
            PrintBoard(board, redPieces, redKings, blackPieces, blackKings);
            gameWon = CheckWin(redPieces, blackPieces);
            if (gameWon) {
                break;
            }

            printf("Player W, what piece would you like to move?: ");
            fflush(stdout);
            fgets(userInput, 50, stdin);
            userInput[strcspn(userInput, "\n")] = 0;
            strcpy(oldSpace, userInput);

            printf("Player W, where would you like to move %s to?: ", oldSpace);
            fflush(stdout);
            fgets(userInput, 50, stdin);
            userInput[strcspn(userInput, "\n")] = 0;
            strcpy(newSpace, userInput);

            printf("Moving %s to %s\n", oldSpace, newSpace);
            validMove = MovePiece(oldSpace, newSpace, 1, &board, &redPieces, &redKings, &blackPieces, &blackKings);
        }
        validMove = 0;

        // **************** Black Player's Turn ****************
        while (!validMove) {
            PromoteKings(&redPieces, &redKings, &blackPieces, &blackKings);
            PrintBoard(board, redPieces, redKings, blackPieces, blackKings);
            gameWon = CheckWin(redPieces, blackPieces);
            if (gameWon) {
                break;
            }
            printf("Player M, what piece would you like to move?: ");
            fflush(stdout);
            fgets(userInput, 50, stdin);
            userInput[strcspn(userInput, "\n")] = 0;
            strcpy(oldSpace, userInput);

            printf("Player M, where would you like to move %s to?: ", oldSpace);
            fflush(stdout);
            fgets(userInput, 50, stdin);
            userInput[strcspn(userInput, "\n")] = 0;
            strcpy(newSpace, userInput);

            printf("Moving %s to %s\n", oldSpace, newSpace);
            validMove = MovePiece(oldSpace, newSpace, 0, &board, &blackPieces, &blackKings, &redPieces, &redKings);
        }
        validMove = 0;
        PromoteKings(&redPieces, &redKings, &blackPieces, &blackKings);
    }
}