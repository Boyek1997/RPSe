# RPSE (Rock Paper Scissors Expanded) - WIP ##

## Copyright and license statement ##
Rpse is released under license GNU General Public License v3.0

Rpse, a rock paper scissors game for Linux systems.

Copyright (C) 2024 Wojciech Zduniak

This file is part of rpse.

Rpse is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Rpse is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with rpse. If not, see <https://www.gnu.org/licenses/>.

## General information ##
  * This is rock paper scissors but with an extra move to play with. Basically, you can play either rock, paper, scissors or x, which you can fully customise by naming it and specifying whether you could have it beat rock, paper and/or scissors.
  * For now, you can only play against a bot.
  * Current version: v0.4 (24/03/2024).

## User guide ##
  * This project automatically comes with all required object and executable files necessary for running the code.
  * The file that you should run is found here: ```executable_files/rpse```.
  * Run ```make all``` in your terminal to get the .o files and the core executable file.
  * Run ```make clean``` in your terminal to remove any .o files and the core executable file.
## Dependencies ##
Note that the newest versions for these dependencies are recommended.
  * Make.
  * GCC.
  * Bash.

## Dependency installation guide ##
Note that Bash isn't included as it automatically comes with any Linux system but GCC and Make should but might not, so guides for those two are included.
### Make ###
#### Using the APT package manager ####
  * Intended for Debian-based systems.
  * Run this in a terminal:
    * ```sudo apt update```
    * ```sudo apt upgrade```
    * ```sudo apt install make```
#### Using the DNF package manager ####
  * Intended for Fedora-based systems.
  * Run this in a terminal:
    * ```sudo dnf check-update```
    * ```sudo dnf upgrade```
    * ```sudo dnf install make```
#### Using the Pacman package manager ####
  * Intended for Arch-based systems.
  * Run this in a terminal:
    * ```sudo pacman -Syu```
    * ```sudo pacman -S make```
### GCC ###
#### Using the APT package ####
  * Intended for Debian-based systems.
  * Run this in a terminal:
    * ```sudo apt update```
    * ```sudo apt upgrade```
    * ```sudo apt install gcc```
#### Using the DNF package manager ####
  * Intended for Fedora-based systems.
  * Run this in a terminal:
    * ```sudo dnf check-update```
    * ```sudo dnf upgrade```
    * ```sudo dnf install gcc```
#### Using the Pacman package manager ####
  * Intended for Arch-based systems.
  * Run this in a terminal:
    * ```sudo pacman -Syu```
    * ```sudo pacman install -S gcc```

## Contributors ##
  * Boyek1997 for:
    * Makefile.
    * README file.
    * Development and testing of C code.
## Testing tools used ##
  * Valgrind.
  * GDB (GNU Debugger).