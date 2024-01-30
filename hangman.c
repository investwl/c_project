#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int life = 3;
char preset_words[10][20] = {"elephant", "mountain", "computer", "chocolate", "calendar", "deployment", "visual", "frustration", "running", "swimming"};

void rip(){
    printf("--------\n|      |\n|      O\n|     /|\\\n|     / \\\n|\n|\n");
}

void first_mistake(){
    printf("--------\n|      |\n|      O\n|\n|\n|\n|\n");
}

void second_mistake(){
    printf("--------\n|      |\n|      O\n|     /|\\\n|\n|\n|\n");
}

void full_hp(){
    printf("--------\n|\n|\n|\n|\n|\n|\n");
}

int check_life(){
    switch (life){
        case 0:
            printf("You lost.\n");
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
    }
}

void show_hangman(){
    switch (life){
        case 0:
            rip();
            return;
        case 1:
            second_mistake();
            return;
        case 2:
            first_mistake();
            return;
        case 3:
            full_hp();
            return;
    }
}

void game_begin(){
    if (check_life() < 0){
        return;
    }
    int take_word = rand() % 10;
    int len_word = strlen(preset_words[take_word]);
    char to_be_guessed[len_word];
    strcpy(to_be_guessed, preset_words[take_word]);
    char display_letters[strlen(to_be_guessed)];
    for (int i = 0 ; i < len_word; i++){
        display_letters[i] = '_';
    }
    display_letters[len_word] = '\0';
    while (check_life() > 0){
        show_hangman();
        printf("\n");
        for (int i = 0 ; i < len_word; i++){
            printf("%c ", display_letters[i]);
        }
        printf("\n%d chances, insert your letter guess! (only 1 letter at one time)\n>> ", check_life());
        char user_guess;
        scanf("%c", &user_guess); getchar();
        printf("\n");
        int flag = 1;
        for (int i = 0 ; i < len_word; i++){
            if (to_be_guessed[i] == user_guess){
                display_letters[i] = user_guess;
                flag = 0;
            }
        }
        if (flag){
            life--;
            if (check_life() == 0){
                show_hangman();
                printf("The sentence was %s\n", to_be_guessed);
                return;
            }
        }

        if (strcmp(display_letters, to_be_guessed) == 0){
            printf("YOU WON!!!");
            return;
        }


        printf("\n\n\n");
    }
}

void main_menu(){
    printf("Welcome to Hangman Game!\nWrite \"Start\" to play the game!\n");
    while (1){
        printf(">> ");
        char writestart[10];
        scanf("%s", writestart);
        getchar();
        if (strcmp(writestart, "start") == 0 || strcmp(writestart, "Start") == 0) break;
        printf("Please write it properly.\n\n");
    }
}


int main(){
    srand(time(NULL));
    main_menu();
    game_begin();
}