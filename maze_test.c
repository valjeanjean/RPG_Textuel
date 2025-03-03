#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define UPWARDS 1
#define RIGHT 2
#define BACKWARDS 3
#define LEFT 4
#define PLAYER_MAZE_LINES 5
#define PLAYER_MAZE_COLUMNS 12
#define MAZE_LINES 14
#define MAZE_COLUMNS 32
#define MAZE_SIZE 512
#define MAZE_LINES 14
#define TAB_STOCK 255

int player_move_check(){

    int move_stock = -1;
    char tab[TAB_STOCK];
    fgets(tab, sizeof(TAB_STOCK), stdin);
    move_stock = atoi(tab);

    switch (move_stock)
    {
    case UPWARDS:
        /* code */
        return 1;
    
    case RIGHT:

        return 2;

    case BACKWARDS:

        return 3;

    case LEFT:

        return 4;

    default:
        break;
    }

}


int main(){

    int i = 0;
    int j = 0;
    int player_move_stock;
    /* printf les 5 premières lignes et 12 premières colonnes */
    // 32 colonnes, 14 lignes //

    char maze[MAZE_SIZE][MAZE_SIZE] = {
        "###   ##########################",
        "#### ###########################",
        "##### ##########################",
        "#####       ####################",
        "#####   ########################",
        "####### #### ###################",
        "#######      ###################",
        "######### ######################",
        "######### ######################",
        "#########      #################",
        "############## #################",
        "##############      ############",
        "################### ############",
        "################### ############"
        };

    

    for(i = 0; i < PLAYER_MAZE_LINES; i++) {

        for(j = 0; j < PLAYER_MAZE_COLUMNS; j++) {
            printf("%c", maze[i][j]);  // Affiche un caractère à la fois
        }
        printf("\n");  // Ajouter un saut de ligne après chaque ligne du labyrinthe
    }
    
    
    
    
    
    /*for(i = 0; i < MAZE_LINES; i++){

        printf("%s\n", maze[i]);
    }*/
    

    return 0;
}