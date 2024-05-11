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
#include "../include/rpsecore-io.h"
#include "../include/rpsecore-setup.h"
#include "../include/rpsecore-g1.h"
#include "../include/rpsecore-g2.h"

#define license_statement() { \
	printf("RPSe is released under license GNU General Public License v3.0.\n" \
			"RPSe (Rock Paper Scissors expanded), a rock paper scissors game for Linux systems.\n\n" \
			"Copyright (C) 2024 Wojciech Zduniak, Marcin Zduniak\n" \
			"RPSe is free software: you can redistribute it and/or modify it under the terms of the " \
			"GNU General Public License as published\n" \
			"by the Free Software Foundation, either version 3 of the License, or (at your option) " \
			"any later version.\n" \
			"RPSe is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; " \
			"without even the implied warranty of\n" \
			"MERCHANTABILITY or FITNESS " \
			"FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n" \
			"You should have received a copy of the GNU General Public License along with RPSe." \
			"If not, see <https://www.gnu.org/licenses/>.\n\n"); \
}

int main(void) {
	union user_input usr_in;
	usr_in.int_in=0;
	union user_input *p_usr_in=&usr_in;
	printf("RPSe Open Beta 1.\n\n");
	license_statement();
	enter_to_continue_prompt();
	while (((gamemode_selection(p_usr_in)==1) ? gamemode_1() : gamemode_2(p_usr_in))!=1);
	return 0;
}
