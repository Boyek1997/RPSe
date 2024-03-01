#include <gamemode_selection.h>
#include <move_definition.h>
#include <gamemode_1.h>
#include <gamemode_2.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct rock {
    bool beats_rock;
    bool beats_paper;
    bool beats_sci;
    bool beats_move_4;
};
struct paper {
    bool beats_rock;
    bool beats_paper;
    bool beats_sci;
    bool beats_move_4;
};
struct sci {
    bool beats_rock;
    bool beats_paper;
    bool beats_sci;
    bool beats_move_4;
};

int main(void) {
    printf("// main // BEGIN FUNCTION.\n"); // INFO FOR DEBUGGING
    (gamemode_selection() == 1) ? gamemode_1() : gamemode_2();
    printf("// main // END FUNCTION.\n"); // INFO FOR DEBUGGING
    return 0;
}