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
#include <stdio.h>


void lan_client(void) {
    fprintf(stderr, "// lan_client // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    fprintf(stderr, "// lan_client // END FUNCTION.\n"); /* INFO FOR DEBUGGING */
}


void lan_server(void) {
    fprintf(stderr, "// lan_server // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    fprintf(stderr, "// lan_server // END FUNCTION.\n"); /* INFO FOR DEBUGGING */
}


void gamemode_1(void) { /* PvP - WIP */
    fprintf(stderr, "// gamemode_1 // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    union user_input user_input;

    printf("Would you like to host a match or join one?\n");
    printf("1. Host.\n");
    printf("2. Join.\n");
    user_input = request_input(0, 2, 1, 2);
    (user_input.int_input == 1) ? lan_server() : lan_client();

    fprintf(stderr, "// gamemode_1 // END FUNCTION.\n"); /* INFO FOR DEBUGGING */
}