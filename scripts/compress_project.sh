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
COMPRESSION_MODE=-1
RED_FG=`tput setaf 1`
GREEN_FG=`tput setaf 2`
RESET=`tput sgr0`
MENU=("Select target tarball:" "\t1. tar.gz" "\t\t- Moderate compression." \
	"\t\t- Fast speed." "\t2. tar.bz2" "\t\t- OK compression." "\t\t- Moderate speed." \
"\t3. tar.xz" "\t\t- Excellent compression." "\t\t- Slow speed.")

while ! [[ $COMPRESSION_MODE =~ ^[1-3]$ ]]; do
	for element in "${MENU[@]}"; do
		echo -e $element
	done
	read -p "Your choice is: " COMPRESSION_MODE
	if ! [[ $COMPRESSION_MODE =~ ^[1-3]$ ]]; then
		echo -e "Invalid input, please try again!\n"
		sleep .5
	fi
done

cd ../../
TARGET_DIR=$PWD
cp -rf RPSe/ tmp/
rm -rf tmp/.git
case $COMPRESSION_MODE in
	1)
		tar -czf RPSe.tar.gz tmp/
		;;
	2)
		tar -cjf RPSe.tar.bz2 tmp/
		;;
	3)
		tar -cJf RPSe.tar.xz tmp/
		;;
esac
if [ $? -ne 0 ]; then
	echo "${RED_FG}Compression failed!${RESET}"
	rm -rf tmp/
	cd RPSe/scripts/
	exit 1
fi
rm -rf tmp/
cd RPSe/scripts
echo "${GREEN_FG}Compression finished!${RESET}"
echo "The compressed file can be found in the ${GREEN_FG}$TARGET_DIR/${RESET} directory."
