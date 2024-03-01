#include <move_definition.h>
#include <stdio.h>
#include <stdlib.h>

void gamemode_1(void) { // PvP - WIP
    printf("// gamemode_1 // BEGIN FUNCTION.\n"); // INFO FOR DEBUGGING
    printf("// WARNING // This gamemode is a work in progress. Bugs may (will definitely*) occur.\n"); // Temporary warning
    struct move_4 m4 = move_definition();

    // Blah, blah, blah starts

    //Blah, blah, blah ends

    free(m4.name);
    printf("// gamemode_1 // END FUNCTION.\n"); // INFO FOR DEBUGGING
}