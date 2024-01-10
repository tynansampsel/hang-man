#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getCorrectLettersArray(char arr[], int length, int *correctLettersLength) {

	char* correctLetters = (char*)malloc((length + 1) * sizeof(char));  // +1 for null terminator

	int cllength = 0;

	for (int i = 0; i < 27; i++) {
		//loop through answer and if the letter doesnt exist, add it.
		int hasLetter = 0;

		for (int j = 0; j < length; j++) {
			if (correctLetters[j] == arr[i]) {
				hasLetter = 1;
			}
		}

		if (hasLetter == 0) {
			correctLetters[cllength] = arr[i];
			cllength++;
		}
	}
	printf("correct:%d %s \n", cllength, correctLetters);


	*correctLettersLength = cllength;
	correctLetters[cllength] = '\0';


	return correctLetters;
}