#ifndef MOVE_DEFINITION_H
#define MOVE_DEFINITION_H
#include <stdbool.h>

struct move_4 {
    char* name;
    bool beats_rock;
    bool beats_paper;
    bool beats_sci;
    bool beats_move_4;
};

struct move_4 move_definition(void);

#endif