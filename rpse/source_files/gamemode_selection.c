#include <gamemode_selection.h>
#include <stdio.h>

int gamemode_selection(void) {
    printf("// gamemode_selection // BEGIN FUNCTION.\n"); // INFO FOR DEBUGGING

    int char_in_input; int user_input;
    do {
        printf("Please select a gamemode with its number:\n");
        printf("1. Player vs Player.\n");
        printf("2. Player vs Bot.\n");
        scanf(" %d", &user_input);
        while ((char_in_input=getchar()) != '\n' && char_in_input != EOF); // Clearing the input stream.
        if (user_input != 1 && user_input != 2) {
            printf("Invalid input! Please try again.\n\n");
        }
    }
    while (user_input != 1 && user_input != 2);

    printf("// gamemode_selection // END FUNCTION.\n"); // INFO FOR DEBUGGING
    return user_input;
}