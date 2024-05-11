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

#ifndef RPSECORE_LOGIC_H
#define RPSECORE_LOGIC_H

#include "rpsecore-setup.h"

struct round_results {
	int p1_wins;
	int p2_wins;
	int replay_chosen;
	char *winner;
};

struct round_status {
	int p1_move;
	int p2_move;
	int round_num;
};

void check_round_winner(struct round_status *p_rnd_stat, struct move_4_combinations *p_m4_com, struct round_results **p_rnd_res);

#endif
