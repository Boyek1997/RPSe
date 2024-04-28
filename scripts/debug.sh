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

#! /bin/bash
case $1 in
	1)
		SETTING=1
		;;
	2)
		SETTING=2
		;;
	3)
		SETTING=3
		;;
	4)
		SETTING=4
		;;
	5)
		exit 0
		;;
	*)
		SETTING=0
		;;
esac

GREEN_FG=`tput setaf 2`
RED_FG=`tput setaf 1`
RESET=`tput sgr0`

echo "Changing dir to root dir RPSe/"
cd ..
echo "Dir changed to root dir RPSe/"
echo "Running make clean..."
make clean
echo "Running make all..."
make all
if [ $? -ne 0  ]; then
	echo "${RED_FG}Compilation proccess has failed!${RESET}"
	echo "${RED_FG}Exit code 1 for test_RPSe.sh${RESET}"
	exit 1 
fi

echo "Changing dir to bin/"
cd bin
echo "Dir changed to bin/"

while ! [[ $SETTING =~ ^[1-5]$ ]]; do
	echo "Choose one of the following functions by their number:"
	echo "    1. Test with Valgrind."
	echo "    2. Test with GDB."
	echo "    3. Time execution."
	echo "    4. Run without testing tools."
	echo "    5. Do not run/test."
	read SETTING
done

if [ $SETTING -eq 1 ]; then
	echo "${GREEN_FG}Valgrind testing has been selected.${RESET}"
	sleep .25
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./RPSe
elif [ $SETTING -eq 2 ]; then
	echo "${GREEN_FG}GDB testing has been selected.${RESET}"
	sleep .25
	gdb ./RPSe
elif [ $SETTING -eq 3 ]; then
	echo "${GREEN_FG}Timing testing has been selected${RESET}"
	sleep .25
	time ./RPSe
elif [ $SETTING -eq 4 ]; then
	echo "${GREEN_FG}Regular execution has been selected${RESET}"
	./RPSe
else
	echo "${GREEN_FG}No testing has been selected.${RESET}"
fi

echo "Returning to root dir RPSe/"
cd ..
echo "Returned to root dir RPSe/"
echo "Running make clean..."
make clean
echo "Returning to origin dir scripts/"
cd scripts/
echo "Returned to origin dir scripts/"
