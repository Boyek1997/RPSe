#ifndef RPSECORE_UTIL_H
#define RPSECORE_UTIL_H

struct move_4_combinations {
    int beats_rock;
    int beats_paper;
    int beats_scissors;
    int beaten_by_rock;
    int beaten_by_paper;
    int beaten_by_scissors;
};

union user_input {
    int int_input;
    char* str_input;
    char char_input;
};

char* lower_str(char* str);
char* capitalise_str(char* str);
union user_input request_input(int operating_mode, int buffer_size, int min_int, int max_int);
int gamemode_selection(void);
char** move_name_creation(void);
void move_4_combination_creation(struct move_4_combinations *move_4_combinations);
#endif