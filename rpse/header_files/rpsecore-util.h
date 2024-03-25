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