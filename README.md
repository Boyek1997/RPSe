# RPSe (Rock Paper Scissors expanded) - Open Beta 1 #

## Copyright and license statement ##
RPSe is released under license **GNU General Public License v3.0**

RPSe, a rock paper scissors game for Linux systems.

Copyright (C) 2024 Wojciech Zduniak, Marcin Zduniak

This file is part of RPSe.

RPSe is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

RPSe is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with RPSe. If not, see <https://www.gnu.org/licenses/>.

## General information ##
  * This is rock paper scissors but with an extra move to play with. Basically, you can play either rock, paper, scissors or x, which you can fully customise by naming it and specifying whether you could have it beat rock, paper and/or scissors.
  * For now, you can only play against a bot.
  * Current version: Open Beta 1 (28/04/2024).

## User guide ##
  * In order to run RPSe, you need to:
    * Download all [dependencies](#dependencies) using the [guide](#dependency-installation-and-setup-guide).
    * Run ```make all``` in the ```RPSe/``` directory.
    * The ```bin/``` directory is auto-generated, so don't worry if you can't find it.
    * Run ```./RPSe``` in the ```RPSe/bin/``` directory.
  * In order to uninstall RPSe, you need to:
    * Run ```make clean``` in the ```RPSe/``` directory to remove the entire ```bin/``` directory, consisting of:
      * Object files in the ```RPSe/bin/objects/``` directory.
      * The executable file named ```RPSe``` in the ```RPSe/bin/``` directory.

## Dependencies ##
Note that the newest versions for these dependencies are recommended.
### Required dependencies ###
These are the dependencies that you need to run and compile RPSe.
  * Bash.
  * Make.
  * GNU Compiler Collection (GCC).
### Optional dependencies ###
These are the dependencies that you need to run ```debug.sh``` in the ```scripts/``` directory.
  * GNU Debugger (GDB).
  * Valgrind (memory leak checker).
  * Time.
  * xz-utils.

### Dependency installation and setup guide ###
Note that the following dependencies aren't included as they are expected to come with any Linux distribution:
  * Bash.
  * Time.

In order to install the dependencies, you need to:
  1. Go to the ```scripts/``` directory.
  2. Run ```./dependency-install.sh```.
  3. Select which dependencies you want by inputting 1 for required, 2 for optional and 3 for all.
  4. Allow ```sudo``` to run. Yes, I know it sounds sketchy but the script only does that so it can donwload packages with either:
     - APT.
     - DNF.
     - PACMAN.

That's it! All the dependencies should automatically install then. If you still don't trust the use of elevated priviliges in the script,
feel free to inspect it.

## Contributors ##
  * Boyek1997
    * Makefile.
    * Scripts.
    * C code.
    * Documentation.
    * Licensing.
    * Currrent .gitignore file.
    * Repository maintenance.
  * mz7mz7mz7
    * Pre-licensing .gitignore file.

## Testing tools used ##
  * Valgrind.
  * GDB (GNU Debugger).
  * Time.
