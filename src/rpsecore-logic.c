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

#include <string.h>
#include "../include/rpsecore-logic.h"

static void std_calc_winner(struct round_status *p_rnd_stat, struct round_results **p_rnd_res, int winning_move_num) {
	(*p_rnd_res)->winner=(p_rnd_stat->p2_move==winning_move_num) ? "P2" : "P1";
	(strcmp((*p_rnd_res)->winner, "P2")==0) ? (*p_rnd_res)->p2_wins++ : (*p_rnd_res)->p1_wins++;
}

void check_round_winner(struct round_status *p_rnd_stat, struct move_4_combinations *p_m4_com, \
		struct round_results **p_rnd_res) {
	// Checking if it's a tie
	if ((p_rnd_stat->p1_move==p_rnd_stat->p2_move) || (p_rnd_stat->p2_move==3 && \
				((p_rnd_stat->p1_move==0 && !p_m4_com->beats_rock) || \
				 (p_rnd_stat->p1_move==1 && !p_m4_com->beats_paper) || \
				 (p_rnd_stat->p1_move==2 && !p_m4_com->beats_scissors)))) {
		(*p_rnd_res)->winner="NOBODY";
		return;
	}

	// If player 1 chose custom move
	else if (p_rnd_stat->p1_move==3) {
		(*p_rnd_res)->winner=\
				     ((p_rnd_stat->p2_move==0 && p_m4_com->beats_rock) || \
				      (p_rnd_stat->p2_move==1 && p_m4_com->beats_paper) || \
				      (p_rnd_stat->p2_move==2 && p_m4_com->beats_scissors)) ? \
				     "P1" : "P2";
		(strcmp((*p_rnd_res)->winner, "P1")==0) ? \
			(*p_rnd_res)->p1_wins++ : (*p_rnd_res)->p2_wins++;
		return;
	}

	// If player 2 chose custom move
	else if (p_rnd_stat->p2_move==3) {
		(*p_rnd_res)->winner=((p_rnd_stat->p1_move==0 && p_m4_com->beats_rock) || \
				(p_rnd_stat->p1_move==1 && p_m4_com->beats_paper) || \
				(p_rnd_stat->p1_move==2 && p_m4_com->beats_scissors)) ? \
				     "P2" : "P1";
		(strcmp((*p_rnd_res)->winner, "P1")==0) ? (*p_rnd_res)->p1_wins++ : (*p_rnd_res)->p2_wins++;
		return;
	}

	// If player 1 chose standard moves
	(p_rnd_stat->p1_move==0) ? std_calc_winner(p_rnd_stat, p_rnd_res, 1) : \
			     ((p_rnd_stat->p1_move==1) ? std_calc_winner(p_rnd_stat, p_rnd_res, 2) : \
			      std_calc_winner(p_rnd_stat, p_rnd_res, 0));
}
