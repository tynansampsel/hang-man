#include <stdio.h>
#include <stdlib.h>


//char* testFunc(char* inputArray, int size);

int main() {
	game();
	return 0;
}


int game() {
	int gameOver = 0;
	char answer[] = "hangman";
	int answerLength = sizeof(answer) / sizeof(answer[0]);

	char guessedLetters[27];
	int guessedLettersLength = 0;

	char correctlyGuessedLetters[27];
	int correctlyGuessedLettersLength = 0;

	//this is an array of characters so i can get the /n and /0. otherwise they will be read in by the next fgets.
	char guessedLetter[3];

	//build the correct letter array
	char correctLetters[27];
	int correctLettersLength = 0;

	for (int i = 0; i < answerLength-1; i++) {
		//loop through answer and if the letter doesnt exist, add it.
		int hasLetter = 0;
		if (i > 0) {
			for (int j = 0; j < 27; j++) {
				if (correctLetters[j] == answer[i]) {
					hasLetter = 1;
				}
			}
		}

		if (hasLetter == 0) {
			correctLetters[correctLettersLength] = answer[i];
			correctLettersLength++;
		}
	}
	correctLetters[correctLettersLength] = '\0';

	//printf("[ %s ] %d\n", correctLetters, correctLettersLength);


	do {

		// ----- [ DISPLAY HANGMAN ]
		printf("/////////////////////////////////////////\n");
		printf("      _________  ");

		//display correct letters
		printf("  ");
		for (int i = 0; i < answerLength-1; i++) {
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

		printf("      |       |  ");

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
		printf("\n");

		printf( "      |       0  \n"
				"      |      /|\\  \n"
				"      |      / \\  \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");


		// ----- []


		// ----- [ GET INPUT ]
		int correctGuess = 0;

		printf("Guess a letter: ");
		fgets(guessedLetter, 3, stdin);
		// ----- []


		// ----- [ ADD INPUT INTO GUESSED ARRAY ]
		//inputs
			//gussed array
			//guessed array length
			//gussedLetter
			//correctletters
			//correctlettersLength
			//

		int hasBeenGuessedAlready = 0;
		if (guessedLettersLength < 1) {
			//printf("currentUsedLength is 0 so adding\n");

			//add letter to array
			guessedLetters[guessedLettersLength] = guessedLetter[0];
			guessedLetters[guessedLettersLength + 1] = '\0';
			//printf("added: %c\n", guessedLetter[0]);
			guessedLettersLength++;

			//check if this is a correct letter
			for (int j = 0; j < correctLettersLength; j++) {
				if (correctLetters[j] == guessedLetter[0]) {
					correctGuess = 1;
				}
			}
			//printf("[ %s ]\n", guessedLetters);


		}
		else {
			//check every letter in the guessed array. if this letter is not already in this array, add it.
			for (int i = 0; i < (guessedLettersLength +1); i++) {
				//printf("[  %d  ] [ %c ] \n", i, guessedLetters[i]);

				if (guessedLetters[i] == guessedLetter[0]) {
					printf("%c already guessed!\n", guessedLetter[0]);
					hasBeenGuessedAlready = 1;
				}
			}
			if (hasBeenGuessedAlready == 0) {
				guessedLetters[guessedLettersLength] = guessedLetter[0];
				guessedLetters[guessedLettersLength + 1] = '\0';
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
		// ----- []

		// ----- [ DISPLAY IF CORRECT ]
		printf("\n");

		if (correctGuess == 1) {
			printf("%c is correct!\n", guessedLetter[0]);
		}
		else {
			printf("%c is incorrect.\n", guessedLetter[0]);
		}
		printf("correct:%d %s \n", correctLettersLength, correctLetters);
		printf("guessed:%d %s \n", guessedLettersLength, guessedLetters);
		// ----- []

		
		// ----- [ CHECK FOR VICTORY ]
		//check for victory
		//i = correctLetters
		//j = guessedLetters
		//loop through answer and if the letter doesnt exist, add it.
		int allCorrect = 1;
		for (int i = 0; i < correctLettersLength; i++) {
			
			int hasLetter = 0;

			for (int j = 0; j < guessedLettersLength; j++) {
				if (correctLetters[i] == guessedLetters[j]) {
					hasLetter = 1;
				}
			}

			if (hasLetter == 0) {
				allCorrect = 0;
			}
		}
		// ----- []

		printf("\n");

		// ----- [ END GAME IF VICTORIOUS ]
		if (allCorrect == 1) {
			printf("\nWinner!\n\n");
			gameOver = 1;
		}
		// ----- []

	} while (gameOver == 0);

	printf("\n\n\n game over!");

	return 0;
}