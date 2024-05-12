/*
 * RPSe, a rock paper scissors game for Linux systems.
 *
 * Copyright (C) 2024 Wojciech Zduniak, Marcin Zduniak
 *
 * This file is part of RPSe.
 *
 * RPSe is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation, 
 * either version 3 of the License, or (at your option) any later version.
 * RPSe is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with RPSe.
 * If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef RPSECORE_IO_H
#define RPSECORE_IO_H

union user_input {
    int int_in;
    char* str_in;
    char char_in;
};

void enter_to_continue_prompt(void);
void str_input_prompt(union user_input *p_usr_in, int str_size);
void int_input_prompt(union user_input *p_usr_in, int min, int max);
void yes_no_prompt(union user_input *p_usr_in);

#endif