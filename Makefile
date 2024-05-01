# RPSe, a rock paper scissors game for Linux systems.
#
# Copyright (C) 2024 Wojciech Zduniak
#
# This file is part of RPSe.
#
# RPSe is free software: you can redistribute it and/or modify it under the terms of
# the GNU General Public License as published by the Free Software Foundation, 
# either version 3 of the License, or (at your option) any later version.
# RPSe is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
# You should have received a copy of the GNU General Public License along with RPSe.
# If not, see <https://www.gnu.org/licenses/>.

CC = gcc
CFLAGS = -Wall -g -Wextra -Werror
RED_FG=`tput setaf 1`
GREEN_FG=`tput setaf 2`
RESET=`tput sgr0`

all: bin_dir_check bin/RPSe
.PHONY: clean

bin_dir_check:
	@scripts/internal/check_bin_dir_existance.sh

bin/objects/rpsecore-io.o: src/rpsecore-io.c include/rpsecore-io.h
	@echo "${GREEN_FG}Compiling rpsecore-io...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

bin/objects/rpsecore-setup.o: src/rpsecore-setup.c include/rpsecore-setup.h
	@echo "${GREEN_FG}Compiling rpsecore-setup...${RESET}"	
	@$(CC) $(CFLAGS) -c $< -o $@

bin/objects/rpsecore-logic.o: src/rpsecore-logic.c include/rpsecore-logic.h
	@echo "${GREEN_FG}Compiling rpsecore-logic...${RESET}"	
	@$(CC) $(CFLAGS) -c $< -o $@

bin/objects/rpsecore-g1.o: src/rpsecore-g1.c include/rpsecore-g1.h
	@echo "${GREEN_FG}Compiling rpsecore-g1...${RESET}"	
	@$(CC) $(CFLAGS) -c $< -o $@

bin/objects/rpsecore-g2.o: src/rpsecore-g2.c include/rpsecore-g2.h
	@echo "${GREEN_FG}Compiling rpsecore-g2...${RESET}"	
	@$(CC) $(CFLAGS) -c $< -o $@

bin/objects/main.o: src/main.c include/rpsecore-io.h include/rpsecore-setup.h include/rpsecore-logic.h \
include/rpsecore-g1.h include/rpsecore-g2.h
	@echo "${GREEN_FG}Compiling main...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@
	
bin/RPSe: bin/objects/main.o bin/objects/rpsecore-io.o bin/objects/rpsecore-setup.o bin/objects/rpsecore-logic.o \
bin/objects/rpsecore-g1.o bin/objects/rpsecore-g2.o
	@echo "${GREEN_FG}Compiling RPSe...${RESET}"	
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${GREEN_FG}Compilation finished!${RESET}"
		
clean:
	@rm -rf bin/
	@echo "${GREEN_FG}All contents of directory bin/ have been removed!${RESET}"
