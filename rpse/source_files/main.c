/*
Rpse, a rock paper scissors game for Linux systems.

Copyright (C) 2024 Wojciech Zduniak

This file is part of rpse.

Rpse is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, 
either version 3 of the License, or (at your option) any later version.
Rpse is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with rpse. If not, see <https://www.gnu.org/licenses/>.
*/

#include <rpsecore-util.h>
#include <rpsecore-g1.h>
#include <rpsecore-g2.h>
#include <stdio.h>


int main(int argc, char **argv) {

    fprintf(stderr, "// main // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    printf("RPSE Development Build v0.4.\n\n");
    printf("Rpse is released under license GNU General Public License v3.0.\n");
    printf("Rpse, a rock paper scissors game for Linux systems.\n\n");
    printf("Copyright (C) 2024 Wojciech Zduniak\n");
    printf("Rpse is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published\n");
    printf("by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n");
    printf("Rpse is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
    printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n");
    printf("You should have received a copy of the GNU General Public License along with rpse. If not, see <https://www.gnu.org/licenses/>.\n\n");
    
    printf("Press enter to continue.\n");
    getchar();

    (gamemode_selection() == 1) ? gamemode_1() : gamemode_2();

    fprintf(stderr, "// main // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

    return 0;
}