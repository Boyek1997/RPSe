union user_input request_input(int operating_mode, int buffer_size, int min_num, int max_num) {

    fprintf(stderr, "// request_input // BEGIN FUNCTION.\n"); /* INFO FOR DEBUGGING */

    if (operating_mode == 0) { /* INT INPUT*/

        fprintf(stderr, "// request_input // OPERATING MODE == 0.\n"); /* INFO FOR DEBUGGING */

        union user_input user_input; user_input.int_input = -99999; int temp = -99999;

        temp = scanf(" %d", &user_input.int_input);

        while (temp != 1 || user_input.int_input < min_num || user_input.int_input > max_num) {
            while (getchar() != '\n');
            printf("Invalid input! Please try again.\n");
            temp = scanf(" %d", &user_input.int_input);
        }

        fprintf(stderr, "// request_input // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

        return (user_input);
    }
    
    else if (operating_mode == 1) { /* STRING INPUT */

        fprintf(stderr, "// request_input // OPERATING MODE == 1.\n"); /* INFO FOR DEBUGGING */

        union user_input user_input;

        getchar();

        user_input.str_input = malloc(buffer_size*sizeof(char));
        if (user_input.str_input == NULL) {
            fprintf(stderr, "// ERROR // MEMORY ALLOCATION FAILURE");
            exit(1);
        }

        fgets(user_input.str_input, buffer_size, stdin);

        fprintf(stderr, "// request_input // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

        return (user_input);
    }

    else if (operating_mode == 2) { /* YES/NO INPUT */
        
        fprintf(stderr, "// request_input // OPERATING MODE == 2.\n"); /* INFO FOR DEBUGGING */

        union user_input user_input; user_input.char_input = 'a';
        while (user_input.char_input != 'y' && user_input.char_input != 'n') {
            scanf(" %c", &user_input.char_input);
            user_input.char_input = (user_input.char_input);
            if (user_input.char_input != 'y' && user_input.char_input != 'n') {
                printf("Invalid input! Please try again.\n");
            }
        }

        fprintf(stderr, "// request_input // END FUNCTION.\n"); /* INFO FOR DEBUGGING */

        return user_input;
    }

    else {
        fprintf(stderr, "// request_input // INVALID OPERATING MODE.\n");
        exit(1);
    } 
}










