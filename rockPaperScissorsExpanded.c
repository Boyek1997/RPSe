#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void clearInputStream()
{
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
    printf("// clearInputStream // INPUT BUFFER CLEARED DURING FUNCTION.\n"); //INFO FOR DEBUGGING
}

int gamemodeSelection()
{
    printf("// gamemodeSelection // BEGIN FUNCTION.\n"); //INFO FOR DEBUGGING

    int i; int userInput;
    const char* GAMEMODEMENU[3] = {"Please select a gamemode with its number:", "1. Player vs Player", "2. Player vs Bot"};
    do
    {
        for (i=0; i<3; i++)
        {
            printf("%s\n", GAMEMODEMENU[i]);
        }
        scanf("%d", &userInput);
        clearInputStream();
        if (userInput != 1 && userInput != 2)
        {
            printf("Invalid input!\n\n");
        }
    }
    while (userInput != 1 && userInput != 2);

    printf("// gamemodeSelection // END FUNCTION.\n"); //INFO FOR DEBUGGING
    return userInput;
}

struct rock
{
    bool beatsRock;
    bool beatsPaper;
    bool beatsSci;
    bool beatsMove4;
};
struct paper
{
    bool beatsRock;
    bool beatsPaper;
    bool beatsSci;
    bool beatsMove4;
};
struct sci
{
    bool beatsRock;
    bool beatsPaper;
    bool beatsSci;
    bool beatsMove4;
};
struct move4
{
    char* name;
    bool beatsRock;
    bool beatsPaper;
    bool beatsSci;
    bool beatsMove4;
};

struct move4 moveDefinition()
{
    printf("// moveDefinition // BEGIN FUNCTION.\n"); //INFO FOR DEBUGGING

    printf("When playing you'll be able to play either rock, paper, scissors or a custom move.\n");
    printf("A custom move must be created at the start of each gamemode.\n");
    printf("Since you have not configured your custom move yet, you'll have to do so now.\n");
    struct move4 m4;
    char charInput[101];
    printf("What should this custom move be named: ");
    fgets(charInput, sizeof(charInput), stdin);
    char* newline = strchr(charInput, '\n');  // Making input easier to use x1
    if (newline) *newline = '\0'; // Making input easier to use x2
    m4.name = (char*)malloc((strlen(charInput)+1)*sizeof(char));
    if (m4.name == NULL)
    {
        printf("\n// ERROR // MEMORY ALLOCATION FAILURE FOR m4.name.\n");
        printf("Exit code 1.\n");
        exit(1);
    }
    strcpy(m4.name, charInput);
    
    do
    {
        printf("Can %s beat rock? Insert 1 for yes and 0 for no: ", m4.name);
        scanf("%d", &m4.beatsRock);
        clearInputStream();
        if (m4.beatsRock != 0 && m4.beatsRock != 1)
        {
            printf("Invalid input! Please try again.\n");
        }
        
    }
    while (m4.beatsRock != 0 && m4.beatsRock != 1);
    printf("// m4 // Status of m4.beatsRock is: %d.\n", m4.beatsRock); //INFO FOR DEBUGGING

    do
    {
        printf("Can %s beat paper? Insert 1 for yes and 0 for no: ", m4.name);
        scanf("%d", &m4.beatsPaper);
        clearInputStream();
        if (m4.beatsPaper != 0 && m4.beatsPaper != 1)
        {
            printf("Invalid input! Please try again.\n");
        }
    }
    while (m4.beatsPaper != 0 && m4.beatsPaper != 1);
    printf("// m4 // Status of m4.beatsPaper is: %d.\n", m4.beatsPaper); //INFO FOR DEBUGGING

    do
    {
        printf("Can %s beat scissors? Insert 1 for yes and 0 for no: ", m4.name);
        scanf("%d", &m4.beatsSci);
        clearInputStream();
        if (m4.beatsSci != 0 && m4.beatsSci != 1)
        {
            printf("Invalid input! Please try again.\n");
        }
    }
    while (m4.beatsSci != 0 && m4.beatsSci != 1);
    printf("// m4 // Status of m4.beatsSci is: %d.\n", m4.beatsSci); //INFO FOR DEBUGGING
    
    printf("// moveDefinition // END FUNCTION.\n"); //INFO FOR DEBUGGING
    return m4;
}


int main(int argc, char** argv)
{
    printf("// main // BEGIN FUNCTION.\n"); //INFO FOR DEBUGGING

    gamemodeSelection();
    struct move4 m4 = moveDefinition();
    printf("// m4 // MEMORY ALLOCATION SUCCESS FOR m4.name.\n"); //INFO FOR DEBUGGING
    free(m4.name); // Temporary until gamemodes have been developed.
    printf("// m4 // MEMORY DEALLOCATION SUCCESS FOR m4.name.\n"); //INFO FOR DEBUGGING
    printf("// main // END FUNCTION.\n"); //INFO FOR DEBUGGING
    return 0;
}