#ifndef WORD_GAME_H_INCLUDED
#define WORD_GAME_H_INCLUDED
#include <stdbool.h>


#endif // WORD_GAME_H_INCLUDED
//STEP1:
void display_game_state(char* pCurrent_letters, char* pTargett_letters,const int NUMBER_OF_LETTERS, const int cursor_position, const int number_of_letter_changes);

char get_user_char();

//STEP 2.1:
void move_cursor_right(int* pPosition_of_cursor, const int max);

//STEP 2.2:
void move_cursor_left(int* pPosition_of_cursor, const int max);

//STEP 3:
void change_letter(char* pLetters, int position, char new_letter, int max);

// COMPARE LETTERS
bool compare_letters(char* pStart_letters, char* pTarget_letters, int size_of_array);

void start_game(char * pCurrent,  char* pTarget, const int size_of_word);

void add_letters(char pTarget, char newList, int* index);

int matching_letters(char* pStart_letters, char* pTarget_letters, int size_of_array);


