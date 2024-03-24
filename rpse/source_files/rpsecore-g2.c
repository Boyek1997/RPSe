#include <rpsecore-util.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void gamemode_2(void) {

    fprintf(stderr, "// gamemode_2 // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    char **moves = move_name_creation();
    struct move_4_combinations mov_4_com;
    move_4_combination_creation(&mov_4_com);

    int bot_wins=0; int player_wins=0; union user_input user_input; int bot_move; char *victory[7];

    while (1) {
        fprintf(stderr, "// gamemode_2 // BEGIN GAME.\n"); /* INFO FOR DEBUGGING */
        while (bot_wins!=3 && player_wins !=3) {

            fprintf(stderr, "// gamemode_2 // BEGIN ROUND.\n"); /* INFO FOR DEBUGGING */

            printf("[PLAYER'S TURN]\n");
            printf("Please choose a move by its number:\n");
            for (int i=0; i<4; i++) {
                printf("%d. %s.\n", i+1, moves[i]);
            }
            user_input = request_input(0, 0, 1, 4);
            user_input.int_input--;

            fprintf(stderr, "// gamemode_2 // CONTINUE FUNCTION.\n"); /* INFO FOR DEBUGGING */
    
            printf("[PLAYER HAS CHOSEN A MOVE]\n\n");

            printf("[BOT'S TURN]\n");
            srand(time(NULL));
            bot_move = rand() % 4;
            printf("[BOT HAS CHOSEN A MOVE]\n\n");

            switch (user_input.int_input) {
            case 0:
                if (bot_move == 1){
                    bot_wins++; /* PLAYER: ROCK & BOT: PAPER */
                    *victory = "BOT";
                }

                else if (bot_move == 2) {
                    player_wins++; /* PLAYER: ROCK & BOT: SCISSORS */
                    *victory = "PLAYER";
                }

                else if (bot_move == 3 && mov_4_com.beats_rock == 1) {
                    bot_wins++;
                    *victory = "BOT"; /* PLAYER: ROCK & BOT: CUSTOM MOVE THAT CAN BEAT ROCK */
                }

                else {
                    *victory = "NOBODY"; /* TIE */
                }

                break;
            case 1:
                if (bot_move == 2) {
                    bot_wins++; /* PLAYER: PAPER & BOT: SCISSORS */
                    *victory = "BOT";
                }

                else if (bot_move == 0) {
                    player_wins++; /* PLAYER: PAPER & BOT: ROCK */
                    *victory = "PLAYER";
                }

                else if (bot_move == 3 && mov_4_com.beats_paper == 1) {
                    bot_wins++;
                    *victory = "BOT"; /* PLAYER: PAPER & BOT: CUSTOM MOVE THAT CAN BEAT PAPER */
                }

                else {
                    *victory = "NOBODY"; /* TIE */
                }

                break;
            case 2:
                if (bot_move == 0) {
                    bot_wins++; /* PLAYER: SCISSORS & BOT: ROCK */
                    *victory = "BOT";
                }

                else if (bot_move == 1) {
                    player_wins++; /* PLAYER: SCISSORS & BOT: PAPER */
                    *victory = "PLAYER";
                }

                else if (bot_move == 3 && mov_4_com.beats_scissors == 1) {
                    bot_wins++;
                    *victory = "BOT"; /* PLAYER: SCISSORS & BOT: CUSTOM MOVE THAT CAN BEAT SCISSORS */
                }

                else {
                    *victory = "NOBODY"; /* TIE */
                }

                break;

            case 3:
                if (mov_4_com.beats_rock == 1 && bot_move == 0) {
                    player_wins++; /* PLAYER: CUSTOM MOVE & BOT: ROCK */
                    *victory = "PLAYER";
                }

                else if (mov_4_com.beats_paper == 1 && bot_move == 1) {
                    player_wins++; /* PLAYER: CUSTOM MOVE & BOT: PAPER */
                    *victory = "PLAYER";
                }

                else if (mov_4_com.beats_scissors == 1 && bot_move == 2) {
                    player_wins++; /* PLAYER: CUSTOM MOVE & BOT: SCISSORS */
                    *victory = "PLAYER";
                }

                if (mov_4_com.beaten_by_rock == 1 && bot_move == 0) {
                    bot_wins++; /* PLAYER: CUSTOM MOVE & BOT: ROCK */
                    *victory = "BOT";
                }

                else if (mov_4_com.beaten_by_paper == 1 && bot_move == 1) {
                    bot_wins++; /* PLAYER: CUSTOM MOVE & BOT: PAPER */
                    *victory = "BOT";
                }

                else if (mov_4_com.beaten_by_scissors == 1 && bot_move == 2) {
                    bot_wins++; /* PLAYER: CUSTOM MOVE & BOT: SCISSORS */
                    *victory = "BOT";
                }

                if (bot_move == 3) {
                    *victory = "NOBODY";
                }

                break;
            }

            printf("[ROUND RESULTS]\n");
            printf("Winner: %s.\n", *victory);

            switch (user_input.int_input) {
            case 0:
                printf("Player's move: ROCK.\n");
                break;
            
            case 1:
                printf("Player's move: PAPER.\n");
                break;

            case 2:
                printf("Player's move: SCISSORS.\n");
                break;
            case 3:
                printf("Player's move: %s.\n", capitalise_str(moves[3]));
                lower_str(moves[3]);
                break;
            }

            switch (bot_move) {
            case 0:
                printf("Bot's move: ROCK.\n");
                break;
            
            case 1:
                printf("Bot's move: PAPER.\n");
                break;

            case 2:
                printf("Bot's move: SCISSORS.\n");
                break;
            case 3:
                printf("Bot's move: %s.\n", capitalise_str(moves[3]));
                lower_str(moves[3]);
                break;
            }

            printf("Player wins: %d.\n", player_wins);
            printf("Bot wins: %d.\n", bot_wins);

            getchar();
            printf("Press enter to continue.\n");
            getchar();

            fprintf(stderr, "// gamemode_2 // END ROUND.\n"); /* INFO FOR DEBUGGING */
        }

        fprintf(stderr, "// gamemode_2 // END GAME.\n"); /* INFO FOR DEBUGGING */
        fprintf(stderr, "// gamemode_2 // ENTER END-OF-GAME MENU.\n"); /* INFO FOR DEBUGGING */

        (player_wins == 3) ? printf("You won, congrats!\n\n") : printf("You lost, better luck next time!\n\n");

        printf("[END-OF-GAME MENU]\n");
        printf("1. Replay.\n");
        printf("2. Edit custom move and replay.\n");
        printf("3. Exit game.\n");

        user_input = request_input(0, 0, 1, 3);

        switch (user_input.int_input) {
        case 1:
            player_wins = 0; bot_wins = 0;
            continue;
        
        case 2:

            printf("[1/4] What should your custom move be renamed to (30 char limit): ");
            user_input = request_input(1, 30, 0 , 0);
            user_input.str_input[strlen(user_input.str_input)-1] = '\0';
            moves[3] = (char*)realloc(moves[3], strlen(user_input.str_input)+1);
            if (moves[3] == NULL) {
                fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");

                fprintf(stderr, "// rename_custom_move // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */
                for (int i=0; i<4; i++) {
                    free(moves[i]);
                }

                free(moves);

                fprintf(stderr, "// rename_custom_move // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

                exit(1);
            }
            
            strcpy(moves[3], user_input.str_input);

            fprintf(stderr, "// rename_custom_move // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */

            free(user_input.str_input);

            fprintf(stderr, "// rename_custom_move // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

            move_4_combination_creation(&mov_4_com);

            player_wins = 0; bot_wins = 0;
            continue;

        case 3:
            break;
        }
        
        break;
    }

    fprintf(stderr, "// gamemode_2 // FREEING MEMORY.\n"); /* INFO FOR DEBUGGING */

    for (int i=0; i<4; i++) {
        free(moves[i]);
    }
    free(moves);

    fprintf(stderr, "// gamemode_2 // MEMORY HAS BEEN FREED.\n"); /* INFO FOR DEBUGGING */

    fprintf(stderr, "// gamemode_2 // END FUNCTION.\n"); /* INFO FOR DEBUGGING */
}