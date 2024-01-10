#include <stdio.h>
/*
char* GetCorrectLettersArrayOld(char arr[], int length) {
	char correctLetters[27];
	int correctLettersLength = 0;

	for (int i = 0; i < 27; i++) {
		//loop through answer and if the letter doesnt exist, add it.
		int hasLetter = 0;
		for (int j = 0; j < 27; j++) {
			if (correctLetters[j] == arr[i]) {
				hasLetter = 1;
			}
		}
		if (hasLetter == 0) {
			correctLetters[correctLettersLength] = arr[i];
			correctLettersLength++;
		}
	}

	return correctLetters;
}*/