/*
Rpse, a rock paper scissors game.

Copyright (C) 2024 Wojciech Zduniak

This file is part of rpse.

Rpse is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, 
either version 3 of the License, or (at your option) any later version.
Rpse is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with rpse. If not, see <https://www.gnu.org/licenses/>.
*/

#include <rpsecore-util.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* lower_str(char *str) {
    for (int i=0; i<(int)strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}


char* capitalise_str(char *str) {
    for (int i=0; i<(int)strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}


union user_input request_input(int operating_mode, int buffer_size, int min_num, int max_num) {

    fprintf(stderr, "// request_input // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    if (operating_mode == 0) { /* INT INPUT*/

        fprintf(stderr, "// request_input // OPERATING MODE == 0.\n"); /* INFO FOR DEBUGGING */

        union user_input user_input; user_input.int_input = -99999; int temp = -99999;

        temp = scanf(" %d", &user_input.int_input);

        while (temp != 1 || user_input.int_input < min_num || user_input.int_input > max_num) {
            while (getchar() != '\n');
            printf("Invalid input! Please try again.\n");
            temp = scanf(" %d", &user_input.int_input);
        }

        fprintf(stderr, "// request_input // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

        return (user_input);
    }
    
    else if (operating_mode == 1) { /* STRING INPUT */

        fprintf(stderr, "// request_input // OPERATING MODE == 1.\n"); /* INFO FOR DEBUGGING */

        union user_input user_input;

        getchar();

        user_input.str_input = malloc(buffer_size*sizeof(char));
        if (user_input.str_input == NULL) {
            fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");
            exit(1);
        }

        fgets(user_input.str_input, buffer_size, stdin);

        fprintf(stderr, "// request_input // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

        return (user_input);
    }

    else if (operating_mode == 2) { /* YES/NO INPUT */
        
        fprintf(stderr, "// request_input // OPERATING MODE == 2.\n"); /* INFO FOR DEBUGGING */

        union user_input user_input; user_input.char_input = 'a';
        while (user_input.char_input != 'y' && user_input.char_input != 'n') {
            scanf(" %c", &user_input.char_input);
            user_input.char_input = (user_input.char_input);
            if (user_input.char_input != 'y' && user_input.char_input != 'n') {
                printf("Invalid input! Please try again.\n");
            }
        }

        fprintf(stderr, "// request_input // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

        return user_input;
    }

    else {
        fprintf(stderr, "// request_input // INVALID OPERATING MODE.\n");
        exit(1);
    } 
}


int gamemode_selection(void) {

    fprintf(stderr, "// gamemode_selection // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    union user_input user_input; user_input.int_input = -9999999;

    while (user_input.int_input != 1 && user_input.int_input != 2) {
        printf("Please select a gamemode by its number:\n");
        printf("1. Player vs Player.\n");
        printf("2. Player vs Bot.\n");
        user_input = request_input(0, 0, 1, 2);
    }

    fprintf(stderr, "// gamemode_selection // CONTINUE FUNCTION.\n"); /* INFO FOR DEBUGGING */

    fprintf(stderr, "// gamemode_selection // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

    return user_input.int_input;
}


char** move_name_creation(void) {

    fprintf(stderr, "// move_name_creation // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    char **moves = malloc(4*sizeof(char*));
    if (moves == NULL) {
        fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");
        exit(1);
    }

    printf("\nWhen playing, you'l be able to play rock, paper, scissors or something else.\n");
    printf("Since you haven't done so earlier, you'll configure this \"something else\" now.\n");

    moves[0] = malloc(5); strcpy(moves[0], "Rock");
    if (moves[0] == NULL) {
        fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");

        fprintf(stderr, "// move_name_creation // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */
        for (int i=0; i<4; i++) {
            free(moves[i]);
        }

        free(moves);

        fprintf(stderr, "// move_name_creation // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

        exit(1);
    }
    
    moves[1] = malloc(6); strcpy(moves[1], "Paper");
    if (moves[1] == NULL) {
        fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");

        fprintf(stderr, "// move_name_creation // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */
        for (int i=0; i<4; i++) {
            free(moves[i]);
        }

        free(moves);

        fprintf(stderr, "// move_name_creation // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

        exit(1);
    }

    moves[2] = malloc(10); strcpy(moves[2], "Scissors");
    if (moves[2] == NULL) {
        fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");

        fprintf(stderr, "// move_name_creation // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */
        for (int i=0; i<4; i++) {
            free(moves[i]);
        }

        free(moves);

        fprintf(stderr, "// move_name_creation // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

        exit(1);
    }

    printf("[1/4] What should this custom move be named (30 char limit): ");

    union user_input user_input;
    user_input = request_input(1, 30, 0 , 0);
    user_input.str_input[strlen(user_input.str_input)-1] = '\0';

    moves[3] = malloc(strlen(user_input.str_input)+1);
    if (moves[3] == NULL) {
    fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");

    fprintf(stderr, "// move_name_creation // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */
        for (int i=0; i<4; i++) {
            free(moves[i]);
        }

        free(moves);

        fprintf(stderr, "// move_name_creation // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

        exit(1);
    }

    strcpy(moves[3], user_input.str_input);

    fprintf(stderr, "// move_name_creation // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */

    free(user_input.str_input);

    fprintf(stderr, "// move_name_creation // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

    fprintf(stderr, "// move_name_creation // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

    return moves;
}


void move_4_combination_creation(struct move_4_combinations *move_4_combinations) {

    fprintf(stderr, "// move_4_combination_creation // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    union user_input user_input; char *moves[3] = {"rock", "paper", "scissors"};
    for (int i=0; i<3; i++) {
        printf("[%d/4] Can your custom move beat %s? (Y/N).\n", i+2, moves[i]);
        user_input = request_input(2, 0, 0, 0);
        if (i==0) {
            move_4_combinations->beats_rock = (user_input.char_input == 'y') ? 1 : 0;
            move_4_combinations->beaten_by_rock = (user_input.char_input == 'y') ? 0 : 1;
        }
        else if (i==1) {
            move_4_combinations->beats_paper = (user_input.char_input == 'y') ? 1 : 0;
            move_4_combinations->beaten_by_paper = (user_input.char_input == 'y') ? 0 : 1;
        }
        else {
            move_4_combinations->beats_scissors = (user_input.char_input == 'y') ? 1 : 0;
            move_4_combinations->beaten_by_scissors = (user_input.char_input == 'y') ? 0 : 1;
        }
    }
}