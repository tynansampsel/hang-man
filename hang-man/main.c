#include <stdio.h>

int main() {

	printf("hi!\n");

	//char arr[] = "abcde";
	//int length = sizeof(arr) / sizeof(arr[0]);


	//testFunc(arr, length);

	game();
	return 0;
}

int testFunc(char arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%c", arr[i]);
	}

	return 0;
}


char* getCorrectLetterArray(char arr[], int length) {
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
}

int game() {
	int gameOver = 0;
	char answer[] = "epass";

	

	char guessedLetters[27];
	int guessedLettersLength = 0;

	char correctlyGuessedLetters[27];
	int correctlyGuessedLettersLength = 0;

	//this is an array of characters so i can get the /n and /0. otherwise they will be read in by the next fgets.
	char guessedLetter[3];

	//build the correct letter array
	char correctLetters[27];
	//char* correctLetters = getCorrectLetterArray(answer, 27);
	int correctLettersLength = 0;

	
	for (int i = 0; i < 27; i++) {
		//loop through answer and if the letter doesnt exist, add it.
		int hasLetter = 0;
		for (int j = 0; j < 27; j++) {
			if (correctLetters[j] == answer[i]) {
				hasLetter = 1;
			}
		}
		if (hasLetter == 0) {
			correctLetters[correctLettersLength] = answer[i];
			correctLettersLength++;
		}
	}

	printf("[ %s ]\n", correctLetters);

	do {
		printf("/////////////////////////////////////////\n");
		printf("      _________  ");

		//display correct letters
		printf("  ");
		for (int i = 0; i < 5; i++) {
			int hasLetter = 0;
			for (int j = 0; j < guessedLettersLength; j++) {
				if (answer[i] == guessedLetters[j]) {
					hasLetter = 1;
				}
			}
			if (hasLetter == 0) {
				printf("_ ");
			}
			else {
				printf("%c ", answer[i]);
			}
		}
		printf("  \n");

		printf("      |       |  \n");

		//display guessed letters
		for (int i = 0; i < guessedLettersLength; i++) {
			int isCorrect = 0;

			for (int j = 0; j < correctLettersLength; j++) {
				if (guessedLetters[i] == correctLetters[j]) {
					isCorrect = 1;
				}
			}

			if (isCorrect == 0) {
				printf("%c ", guessedLetters[i]);
			}
		}

		printf( "      |       0  \n"
				"      |      /|\\  \n"
				"      |      / \\  \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");


		int correctGuess = 0;
		printf("Guess a letter: ");
		fgets(guessedLetter, 3, stdin);
		//printf("guessed: %c\n",guessedLetter[0]);

		int hasBeenGuessedAlready = 0;

		if (guessedLettersLength < 1) {
			//printf("currentUsedLength is 0 so adding\n");

			guessedLetters[guessedLettersLength] = guessedLetter[0];
			guessedLetters[guessedLettersLength + 1] = "\0";
			//printf("added: %c\n", guessedLetter[0]);
			guessedLettersLength++;


			for (int j = 0; j < correctLettersLength; j++) {
				if (correctLetters[j] == guessedLetter[0]) {
					correctGuess = 1;
				}
			}

			//printf("[ %s ]\n", guessedLetters);

		}
		else {


			for (int i = 0; i < (guessedLettersLength +1); i++) {
				//printf("[  %d  ] [ %c ] \n", i, guessedLetters[i]);

				if (guessedLetters[i] == guessedLetter[0]) {
					printf("%c already guessed!\n", guessedLetter[0]);
					hasBeenGuessedAlready = 1;
				}
			}

			if (hasBeenGuessedAlready == 0) {
				guessedLetters[guessedLettersLength] = guessedLetter[0];
				guessedLetters[guessedLettersLength + 1] = "\0";
				//printf("added: %c\n", guessedLetter[0]);
				guessedLettersLength++;

				for (int j = 0; j < correctLettersLength; j++) {
					if (correctLetters[j] == guessedLetter[0]) {
						correctGuess = 1;
					}
				}
			
			}

			//printf("[ %s ]\n", guessedLetters);
		}
		printf("\n");

		if (correctGuess == 1) {
			printf("%c is correct!\n", guessedLetter[0]);
		}
		else {
			printf("%c is incorrect.\n", guessedLetter[0]);
		}
		

		int allCorrect = 1;
		//check for victory

		//i = correctLetters
		//j = guessedLetters
		for (int i = 0; i < correctLettersLength-1; i++) {
			//loop through answer and if the letter doesnt exist, add it.
			int hasLetter = 0;

			for (int j = 0; j < guessedLettersLength; j++) {
				if (correctLetters[i] == guessedLetters[j]) {
					//printf("%c == %c\n", correctLetters[i], guessedLetters[j]);
					hasLetter = 1;
				}
				else {
					//printf("%c // %c\n", correctLetters[i], guessedLetters[j]);
				}
			}

			if (hasLetter == 0) {
				allCorrect = 0;
			}
		}

		printf("\n");


		if (allCorrect == 1) {
			printf("\nWinner!\n\n");

			gameOver = 1;
		}
	} while (gameOver == 0);

	printf("\n\n\n game over!!!");

	return 0;
}