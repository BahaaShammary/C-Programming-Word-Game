#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "word_game.h"
#include <stdbool.h>

int main()
{
    char current_letters[] = {'b', 'e', 'l', 'l'};
    char target_letters[] = {'c', 'o', 'a', 't'};
    const int NUMBER_OF_LETTERS = 4;

    int position_of_cursor = 0;
    bool game_finished = false;
    int number_of_letter_changes = 0;

    printf("----- WORD GAME -----\n####################################\nRULES:\n1. Enter a letter to change the word\n2. Enter > to shift one position to the right");
    printf("\n3. Enter < to shift one position to the left\n4. You have 8 attempts to reach the target word\n####################################\n");
    start_game(current_letters,  target_letters, NUMBER_OF_LETTERS);
    return 0;
}
