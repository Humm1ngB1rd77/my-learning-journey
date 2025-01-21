#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int maxRange, int maxAttempts);

int main() {
    int choice;

    printf("Choose difficulty:\n");
    printf("1. Easy (1-50)\n2. Medium (1-100)\n3. Hard (1-200)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: playGame(50, 10); break;
        case 2: playGame(100, 7); break;
        case 3: playGame(200, 5); break;
        default: printf("Invalid choice!\n"); return 1;
    }

    return 0;
}

void playGame(int maxRange, int maxAttempts) {
    srand(time(0));
    int number = (rand() % maxRange) + 1;
    int guess, attempts = 0;

    printf("I have picked a number between 1 and %d. Can you guess it?\n", maxRange);

    while (attempts < maxAttempts) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high!\n");
        } else if (guess < number) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            return;
        }
    }
    printf("Sorry, you've run out of attempts. The number was %d.\n", number);
}

