# RPSe, a rock paper scissors game for Linux systems.
#
# Copyright (C) 2024 Wojciech Zduniak, Marcin Zduniak
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

# Variable & array definitions.
GREEN_FG=`tput setaf 2`
RESET=`tput sgr0`
MODE=0
SUPPORTED_PCK_MNGRS=("apt" "dnf" "pacman")
AVAILABLE_PCK_MNGRS=()
INITIAL_NMBR_PCK_MNGRS=0
NMBR_PCK_MNGRS=0
PCK_MNGR=0

# Getting number of supported package managers.
for ((i=0; i<3; i++)); do
	${SUPPORTED_PCK_MNGRS[$i]} --version > /dev/null 2>&1
	if [ $? -eq 0 ]; then
		AVAILABLE_PCK_MNGRS+=(${SUPPORTED_PCK_MNGRS[$i]})
	else
		NMBR_PCK_MNGRS=$((INITIAL_NMBR_PCK_MNGRS--))
	fi
done

# Confirming number of supported package managers.
if [ $NMBR_PCK_MNGRS -eq 0 ]; then
	echo "[ERROR] No supported package manager found!"
	echo "Manual installation required."
	echo "For dependency list, refer to: ${GREEN_FG}RPSe/README.md${RESET}."
	exit 1
elif [ ${AVAILABLE_PCK_MNGRS[0]} == "apt" ]; then
	PCK_MNGR=1
elif [ ${AVAILABLE_PCK_MNGRS[0]} == "dnf" ]; then
	PCK_MNGR=2
else
	PCK_MNGR=3
fi

# Requesting choice.
while ! [[ $MODE =~ ^[1-3]$ ]]; do
	echo "Here are the available installation options:"
	echo "    1. Install required dependencies (for RPSe functionality/compilation)."
	echo "    2. Install optional dependencies (used for testing scripts)."
	echo "    3. Install required and optional dependencies."
	read -p "Select your option's number here: " MODE
	echo
done

# Installation.
if [ $MODE -eq 1 ]; then
	COMMANDS=("sudo apt update" "sudo apt upgrade -y" "sudo apt install gcc make -y" \
		"sudo apt install valgrind gdb xz-utils -y")
elif [ $MODE -eq 2 ]; then
	COMMANDS=("sudo dnf check-update" "sudo dnf upgrade -y" "sudo dnf install gcc make -y" \
		"sudo dnf install valgrind gdb xz -y")
else
	COMMANDS=("sudo pacman -Sy" "sudo pacman -Su" "sudo pacman -Sy gcc make" \
		"sudo pacman -Sy valgrind gdb xz")
fi
echo "${GREEN_FG}Running \"${COMMANDS[0]}\"${RESET}"
${COMMANDS[0]}
echo "${GREEN_FG}Running \"${COMMANDS[1]}\"${RESET}"
${COMMANDS[1]}
case $2 in
	1)
		echo "${GREEN_FG}Running \"${COMMANDS[2]}\"${RESET}"
		${COMMANDS[2]}
		;;
	2)
		echo "${GREEN_FG}Running \"${COMMANDS[3]}\"${RESET}"
		${COMMANDS[3]}
		;;
	3)
		echo "${GREEN_FG}Running \"${COMMANDS[2]}\"${RESET}"
		${COMMANDS[2]}
		echo "${GREEN_FG}Running \"${COMMANDS[3]}\"${RESET}"
		${COMMANDS[3]}
		;;
esac
echo "${GREEN_FG}Installation completed!${RESET}"