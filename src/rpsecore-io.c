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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/rpsecore-io.h"

void enter_to_continue_prompt(void) {
	printf("Press enter to continue . . . ");
	getchar();
	printf("\n");
}

void str_input_prompt(union user_input *p_usr_in, int str_size) {
	if (str_size<0) {
		fprintf(stderr, "Code error detected. Variable \"str_size\" of type \"int\" is less than 0.\n");
		exit(1);
	}
	p_usr_in->str_in=malloc(str_size+1);
	if (p_usr_in->str_in==NULL) {
		fprintf(stderr, "Malloc() fail for member \"str_in\" of \"usr_in\" of type \"union\".\n");
		exit(1);
	}
	getchar();
	fgets(p_usr_in->str_in, str_size+1, stdin);
	p_usr_in->str_in[strcspn(p_usr_in->str_in, "\n")]=0;
	p_usr_in->str_in = realloc(p_usr_in->str_in, str_size+1);
}

void int_input_prompt(union user_input *p_usr_in, int min, int max) {
	if (max<min) {
	       fprintf(stderr, "Code error detected. Variable \"max\" of type \"int\" is less than\n" \
			       "variable \"min\" of type \"int\".\n");
	       exit(1);
	}
	scanf(" %d", &p_usr_in->int_in);
	while (p_usr_in->int_in>max || p_usr_in->int_in<min) {
		getchar();
		fprintf(stderr, "Invalid input! Your input must be in a range from %d to %d.\n", min, max);
		scanf(" %d", &p_usr_in->int_in);
	}
}

void yes_no_prompt(union user_input *p_usr_in) {
	scanf(" %c", &p_usr_in->char_in);
	p_usr_in->char_in=tolower(p_usr_in->char_in);
	while (p_usr_in->char_in!='y' && p_usr_in->char_in!='n') {
		fprintf(stderr, "Invalid input! Insert \"y\" for yes or \"n\" for no.\n");
		scanf(" %c", &p_usr_in->char_in);
	}
	int c;
	while ((c=getchar())!='\n' && c!=EOF) {};
}