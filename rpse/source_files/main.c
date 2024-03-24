#include <rpsecore-util.h>
#include <rpsecore-g1.h>
#include <rpsecore-g2.h>
#include <stdio.h>


int main(int argc, char **argv) {

    fprintf(stderr, "// main // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    printf("RPSE Development Build v0.4.\n\n");

    (gamemode_selection() == 1) ? gamemode_1() : gamemode_2();

    fprintf(stderr, "// main // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

    return 0;
}