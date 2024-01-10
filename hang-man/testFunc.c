#include <stdio.h>

// Function that takes an array of characters and returns another array of chars
char* testFunc(char* inputArray, int size) {
    // Modify the array (e.g., convert to uppercase)
    for (int i = 0; i < size; i++) {
        if (inputArray[i] >= 'a' && inputArray[i] <= 'z') {
            inputArray[i] = inputArray[i] - 'a' + 'A';
        }
    }

    return inputArray;
}