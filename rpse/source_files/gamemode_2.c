#include <move_definition.h>
#include <stdio.h>
#include <stdlib.h>

void gamemode_2(void) { // PvP - WIP
    printf("// gamemode_2 // BEGIN FUNCTION.\n"); // INFO FOR DEBUGGING
    printf("// WARNING // This gamemode is a work in progress. Bugs may (will definitely*) occur.\n"); // Temporary warning
    struct move_4 m4 = move_definition();

    // Blah, blah, blah starts

    //Blah, blah, blah ends

    free(m4.name);
    printf("// gamemode_2 // END FUNCTION.\n"); // INFO FOR DEBUGGING
}