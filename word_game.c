#include <stdio.h >
#include <stdbool.h>

char get_user_char() { // This method gets an input from the user
    //1. Create the output variable with the value the user has input by keyboard
    printf("Enter a command > ");
    char res = getchar();
    //2. Discard any extra character the user has input by keyboard
    bool finish = false;
    char dummy_char = ' ';

    while (finish == false) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = true;
    }

    //3. Return the output variable
    return res;
}

    bool compare_letters(char* pStart_letters, char* pTarget_letters, int size_of_array) { // COMPARE METHOD - Compare two lists of characters and see if they fully match
	bool match = false;
    int i = 0;
    for (i; i<size_of_array;i++) {
        if (*pStart_letters == *pTarget_letters) {
            match = true;

        }
        else {
            match = false;
            break; // Whenever there is one letter that does not match, we break from the loop and return false
        }
        pStart_letters = pStart_letters + 1; // Get the address of the next character
        pTarget_letters = pTarget_letters + 1; // Get the address of the next character
    }
	return match;
    }

int matching_letters(char* pStart_letters, char* pTarget_letters, int size_of_array) { // This method counts how many letters are matching between two lists of characters
	int match = 0;
    int i = 0;
    for (i; i<size_of_array;i++) {
        if (*pStart_letters == *pTarget_letters) {
            match++; // If a letter matches from one list to the other, we increment a variable which is returned later
        }
        pStart_letters = pStart_letters + 1; // Get address of next character in the list
        pTarget_letters = pTarget_letters + 1; // Get address of next character in the list
    }
	return match;
    }

void start_game(char* pCurrent,  char* pTarget, const int size_of_word){ // This method starts the game manages and calls all other functions
    int i = 0;
    int position_of_cursor = 0;
    bool game_finished = false;
    int number_of_letter_changes = 0;
    int limit = size_of_word*2; // The maximum number of goes is equal to twice the length of the word
    int attempt = 1; // To count user keystrokes
    char list_of_words[size_of_word*limit];
    int index = 0;
    int* pIndex = &index;

    while (i == 0) { // Loop until the two lists of characters
    if (attempt > limit) {
        printf("\nYOU LOSE! You had 8 attempts!\n");
        break;

    }
    printf("\nATTEMPT #%d\n", attempt);
    display_game_state (pCurrent, pTarget, size_of_word, position_of_cursor, number_of_letter_changes);
    int match_letters = matching_letters(pCurrent, pTarget, size_of_word);
    printf("Matching Letters: %d\n", match_letters);

    char input = get_user_char();
    if (input == '>') {
        move_cursor_right(&position_of_cursor, size_of_word);
    }
    else if (input == '<') {
        move_cursor_left(&position_of_cursor, size_of_word);
    }
    else if ((input>='a' && input<='z') || (input>='A' && input<='Z')) {
        change_letter(pCurrent, &position_of_cursor, input, size_of_word);
        number_of_letter_changes++; // Once the user enters a letter and the change_letter method is called, then increase number of letter changes
        add_letters(pCurrent, list_of_words, pIndex, size_of_word); // Each time one letter is changed in the list, then add this new list of characters to the long list that stores all words
    }

    bool x = compare_letters(pCurrent, pTarget, size_of_word);
    if (x == true) {
        printf("\nYOU WIN! The two words are a match\n");
        i = 1;
    }
    attempt++; // Increase the number of attempts - Game ends if attempts = 8
    }

    int k = 0;
    printf("\nThe list of words used: [");
    for (k; k < index; k++) {
        printf("%c", list_of_words[k]);

    }
    printf("]\n");
}

void display_game_state(char* pCurrent_letters, char* pTarget_letters, const int NUMBER_OF_LETTERS, const int cursor_position, const int number_of_letter_changes){ // This method displays the two words after each play
    int j = 0;
    printf("Target: ");
    for (j; j<NUMBER_OF_LETTERS;j++) { // Loop through the target list and print the characters as a complete word
            printf ("%c", *pTarget_letters);
            pTarget_letters = pTarget_letters + 1;
    }
    printf("\n-----------\n");
    int i = 0;
    for (i; i<NUMBER_OF_LETTERS;i++) { // Loop through the current list and print the characters as a complete word
            printf ("%c", *pCurrent_letters);
            pCurrent_letters = pCurrent_letters + 1;
    }
    char DASH = '-';
    char SPACE = ' ';
    printf ("\n");// Space between the previous line and next one
    int k = 0;
    for (k; k<cursor_position;k++) {
            printf ("%c", SPACE); // print spaces for as many as the value of cursor position passed to the method
    }
    printf ("%c", DASH); // print the dash after the spaces have been printed
    printf("\nChanges: %d\n", number_of_letter_changes); // Display number of changes that have been done to the original word.
}

void move_cursor_right(int* pPosition_of_cursor, const int max){
        if ((*pPosition_of_cursor+1) < max && *pPosition_of_cursor > -1) { // Check if going right is valid
            *pPosition_of_cursor = *pPosition_of_cursor+1; // If valid, we shift to the right
        }
        else {
            printf("\nYou can't shift to the right\n");
        }

        }

void move_cursor_left(int* pPosition_of_cursor, const int max){
        if ((*pPosition_of_cursor-1) > -1 && (*pPosition_of_cursor-1) < max) { //Check if going left is valid
            *pPosition_of_cursor = *pPosition_of_cursor-1; // If valid, we shift to the left
        }
        else {
            printf("\nYou can't shift to the left\n");
        }
        }

void change_letter(char* pLetters, int* position, char new_letter, int max) {
    if (*position < max ) {
        char* plocation_of_letter_to_change = pLetters + *position;
        *plocation_of_letter_to_change = new_letter;
    }
    else {
        printf("You cannot make those changes");
    }
}

void add_letters(char* pCurrent, char* newList, int* pIndex, const int size_of_word) { // This method adds each word changed to the long list of words
    int j = 0;
    char new_letter;
    int index = *pIndex; // This allows to keep track of the index of the long list
    for (j; j<size_of_word;j++) {
            new_letter = pCurrent[j];
            newList[index] = new_letter;
            index = index + 1;
            *pIndex = *pIndex + 1;

            if ((j+1) == size_of_word) { // if it is the end of the word, then add a comma
                new_letter = ',';
                newList[index] = new_letter;
                index = index + 1;
                *pIndex = *pIndex + 1;
            }
    }
}


