#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

bool isLoShu(int square[SIZE][SIZE]) {
    int magicSum = 15;
    int sumRow, sumCol;

    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        sumRow = 0;
        sumCol = 0;
        for (int j = 0; j < SIZE; j++) {
            sumRow += square[i][j];
            sumCol += square[j][i];
        }
        if (sumRow != magicSum || sumCol != magicSum)
            return false;
    }

    // Check diagonals
    if (square[0][0] + square[1][1] + square[2][2] != magicSum ||
        square[0][2] + square[1][1] + square[2][0] != magicSum)
        return false;

    // Check for numbers 1-9
    bool numbers[10] = {false};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = square[i][j];
            if (num < 1 || num > 9 || numbers[num])
                return false;
            numbers[num] = true;
        }
    }
    return true;
}

int main() {
    int square[SIZE][SIZE] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    if (isLoShu(square))
        printf("The given square is a Lo Shu Magic Square.\n");
    else
        printf("The given square is not a Lo Shu Magic Square.\n");

    return 0;
}