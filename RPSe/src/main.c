/*
 * RPSe, a rock paper scissors game for Linux systems.
 *
 * Copyright (C) 2024 Wojciech Zduniak
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

static void license_statement() {
	printf("RPSe is released under license GNU General Public License v3.0.\n");
	printf("RPSe (Rock Paper Scissors expanded), a rock paper scissors game for Linux systems.\n\n");
	printf("Copyright (C) 2024 Wojciech Zduniak\n");
	printf("RPSe is free software: you can redistribute it and/or modify it under the terms of the ");
	printf("GNU General Public License as published\n");
	printf("by the Free Software Foundation, either version 3 of the License, or (at your option) ");
	printf("any later version.\n");
	printf("RPSe is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; ");
	printf("without even the implied warranty of\nMERCHANTABILITY or FITNESS ");
	printf("FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n");
	printf("You should have received a copy of the GNU General Public License along with RPSe.");
	printf("If not, see <https://www.gnu.org/licenses/>.\n\n");
	enter_to_continue_prompt();
}

int main(void) {
	union user_input usr_in;
	usr_in.int_in=0;
	union user_input *p_usr_in=&usr_in;
	printf("RPSe Open Beta 1.\n\n");
	license_statement();
	while (((gamemode_selection(p_usr_in)==1) ? gamemode_1() : gamemode_2(p_usr_in))!=1);
	return 0;
}
