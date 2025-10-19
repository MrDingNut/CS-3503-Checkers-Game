// Created by Mitch Walker on 10/14/2025.

#ifndef BITMANIPULATION_C
#define BITMANIPULATION_C
#include <stdio.h>
#include <string.h>

// ********** Basic bit operations **********
unsigned int SetBits(unsigned int num,  int index) {    // Set bit to 1
    if (index <= 31 && index >= 0) { // Verifies index is valid
        return num | (1 << index);
    }
    return num; // Does nothing if the index is invalid
}

unsigned int ClearBit(unsigned int num,  int index) {   // Set bit to 0
    if (index <= 31 && index >= 0) { // Verifies index is valid
        return num & ~(1 << index);
    }
    return num; // Does nothing if the index is invalid
}

unsigned int ToggleBit(unsigned int num,  int index) {  // Flip bit
    if (index > 31 || index < 0) { // Checks if index is invalid
        return -1; // Returns bad value if the index is invalid
    }

    return num ^ (1 << index);

    // if (num & (1 << index)) { // Returns true if the bit at index is 1
    //     return ClearBit(num, index);
    // }
    //
    // return SetBits(num, index);
}

int GetBit(unsigned int num,  int index) {  // Get bit value
    if (index > 31 || index < 0) { // Checks if index is invalid
        return -1; // Returns bad value if the index is invalid
    }

    if (num & (1 << index)) { // Returns true if the bit at index is 1
        return 1;
    }

    return 0;
}

// ********** Counting and finding **********
int CountBits(unsigned int num) {   // Count 1s
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (GetBit(num, i)) {
            count++;
        }
    }
    return count;
}

// ********** Display Functions **********
void PrintBinary(unsigned int num) {  // Show in bits
    // Most of this code was yoinked from Assignment 2
    char bin[33];

    for (int i = 31; i >= 0; i--) { // Convert to 32 bit binary
        bin[31-i] = ((num >> i) & 1) ? '1' : '0';
    }

    bin[32] = '\0'; // Null terminate the string

    printf("%d in binary is %s", num, bin);
}

void PrintHex(unsigned int num) {   // Show in hex
    // Most of this code was yoinked from Assignment 1
    char hex[33];
    int base = 16;

    char temp[65];      // Temporary buffer
    int pos = 0;

    // Handle zero case
    if (num == 0) {
        strcpy(hex, "0");
        return;
    }

    // Extract digits from right to left
    while (num > 0) {
        int remainder = num % base;
        num = num / base;

        // Convert digit to character
        if (remainder < 10) {
            temp[pos++] = '0' + remainder;
        } else {
            temp[pos++] = 'A' + (remainder - 10);
        }
    }

    int j = pos - 1; // j is the index of the last character that isn't '\0' in the output. This will move left/forwards through the output string
    for (int i = 0; i < pos; i++) { // i is the index of the first character of temp. This will move right/backwards through the temp string
        hex[j] = temp[i];   // Sets the last digit of the output to the first digit of temp
        j--; // Decrement j
    }
    hex[pos] = '\0'; // Set the last character to the null terminator

    printf("%d in hexadecimal is %s", num, hex);
}

#endif