#include <move_definition.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct move_4 move_definition(void) {
    printf("// move_definition // BEGIN FUNCTION.\n"); // INFO FOR DEBUGGING

    printf("When playing you'll be able to play either rock, paper, scissors or a custom move.\n");
    printf("A custom move must be created at the start of each gamemode.\n");
    printf("Since you have not configured your custom move yet, you'll have to do so now.\n");
    struct move_4 m4;
    char string_input[101]; char char_input;
    int char_in_input;
    printf("What should this custom move be named: ");
    fgets(string_input, sizeof(string_input), stdin);
    string_input[strcspn(string_input, "\n")] = '\0';  // Making input easier to use v2.0
    m4.name = (char*)malloc((strlen(string_input)+1)*sizeof(char));
    if (m4.name == NULL) {
        printf("\n// ERROR // MEMORY ALLOCATION FAILURE FOR m4.name.\n");
        printf("Exit code 1.\n");
        exit(1);
    }
    strcpy(m4.name, string_input);
    printf("// m4 // MEMORY ALLOCATION SUCCESS FOR m4.name.\n"); // INFO FOR DEBUGGING
    
    do {
        printf("Can %s beat rock? (Y/N):  ", m4.name);
        scanf(" %c", &char_input);
        while ((char_in_input=getchar()) != '\n' && char_in_input != EOF); // Clearing the input stream.
        char_input = tolower(char_input);
        if (char_input != 'y' && char_input != 'n') {
            printf("Invalid input! Please try again.\n\n");
        }
    }
    while(char_input != 'y' && char_input != 'n');
    m4.beats_rock = (char_input == 'y');
    printf("// m4 // Status of m4.beatsRock is: %d.\n", m4.beats_rock); // INFO FOR DEBUGGING

    do {
        printf("Can %s beat paper? (Y/N): ", m4.name);
        scanf(" %c", &char_input);
        while ((char_in_input=getchar()) != '\n' && char_in_input != EOF); // Clearing the input stream.
        char_input = tolower(char_input);
        if (char_input != 'y' && char_input != 'n') {
            printf("Invalid input! Please try again.\n\n");
        }
    }
    while(char_input != 'y' && char_input != 'n');
    m4.beats_paper = (char_input == 'y');
    printf("// m4 // Status of m4.beatsPaper is: %d.\n", m4.beats_paper); // INFO FOR DEBUGGING

    do {
        printf("Can %s beat scissors? (Y/N): ", m4.name);
        scanf(" %c", &char_input);
        while ((char_in_input=getchar()) != '\n' && char_in_input != EOF); // Clearing the input stream.
        char_input = tolower(char_input);
        if (char_input != 'y' && char_input != 'n') {
            printf("Invalid input! Please try again.\n\n");
        }
    }
    while(char_input != 'y' && char_input != 'n');
    m4.beats_sci = (char_input == 'y');
    printf("// m4 // Status of m4.beatsSci is: %d.\n", m4.beats_sci); // INFO FOR DEBUGGING
    
    printf("// move_definition // END FUNCTION.\n"); // INFO FOR DEBUGGING
    return m4;
}