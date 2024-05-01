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
RED_FG=`tput setaf 1`
GREEN_FG=`tput setaf 2`

cd bin > /dev/null 2>&1
if [ $? -ne 0 ]; then
	echo "${RED_FG}Directory bin/ not found!${RESET}"
	mkdir bin/
	echo "${GREEN_FG}Directory bin/ has been created!${RESET}"
	mkdir bin/objects/
	echo "${GREEN_FG}Directory bin/objects/ has been created!${RESET}"
else
	mkdir objects/ > /dev/null 2>&1 # For good measure
	echo "Directory bin/ found, no further action needed."
	cd ..
	echo "Returned to root dir RPSe/"
fi
