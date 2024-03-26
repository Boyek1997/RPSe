#!/bin/bash

# Rpse, a rock paper scissors game for Linux systems.

# Copyright (C) 2024 Wojciech Zduniak

# This file is part of rpse.

# Rpse is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, 
# either version 3 of the License, or (at your option) any later version.
# Rpse is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
# You should have received a copy of the GNU General Public License along with rpse. If not, see <https://www.gnu.org/licenses/>.

CC = gcc
CFLAGS = -Wall -g -Wextra -Iheader_files

all: executable_files/rpse

object_files/rpsecore-util.o: source_files/rpsecore-util.c header_files/rpsecore-util.h
	$(CC) $(CFLAGS) -c $< -o $@

object_files/rpsecore-g1.o: source_files/rpsecore-g1.c header_files/rpsecore-g1.h
	$(CC) $(CFLAGS) -c $< -o $@

object_files/rpsecore-g2.o: source_files/rpsecore-g2.c header_files/rpsecore-g2.h
	$(CC) $(CFLAGS) -c $< -o $@

object_files/main.o: source_files/main.c header_files/rpsecore-util.h header_files/rpsecore-g1.h header_files/rpsecore-g2.h
	$(CC) $(CFLAGS) -c $< -o $@

executable_files/rpse: object_files/main.o object_files/rpsecore-util.o object_files/rpsecore-g1.o object_files/rpsecore-g2.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f object_files/*.o executable_files/rpse