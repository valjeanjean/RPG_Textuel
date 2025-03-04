#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <unistd.h>
#include <time.h>

#define MAX_LENGTH 512
#define MAZE_SIZE 512
#define PLAYER_ADD_QUEST 5
#define TAB_SIZE 128
#define ARRAY 255

struct player{

    int pv;
    int stamina;
    int coins;
    int events;

};

/* FONCTION AFFICHAGE DÉBUT DE JEU */
void start_display(){

    printf("|----------------------------------|\n");
    printf("|-------------RPG Textuel----------|\n\n");
    
}

struct player load_player(const char *file_name){  
    
    struct player player_who;
    player_who.pv = 0;
    player_who.stamina = 0;
    player_who.coins = 0;
    player_who.events = 0;

    /* Au lieu d'intialiser à 0 à la main, possibilité de faire memset de struct player sizeof(struct) */

    FILE * first_score_read = fopen(file_name, "r");
    
    char tab[255];
    fgets(tab, TAB_SIZE, first_score_read);
    tab[strcspn(tab, "\n")] = '\0';
    sscanf(tab, "HP : %d STAMINA : %d COINS : %d EVENTS : %d", &player_who.pv, &player_who.stamina, &player_who.coins, &player_who.events);
    
    fclose(first_score_read);
    
    return player_who;
    
}

/* FONCTION QUI VERIFIE SI LE JOUEUR A 0 PV OU 0 PIÈCES, SI OUI GAME OVER */
int isGameOver(struct player player_who){
    
    if(player_who.pv <= 0 || player_who.coins >= 1000){
    
        return 0;

    }else{

        return 1;
    }

}

/* FONCTION MALUS SI JOUEUR TOMBE À 0 PIÈCES OU 0 DE STAMINA */
int isLostStats(struct player player_who){

    if(player_who.coins <= 0){
        
        return 1;
    
    }else if(player_who.stamina <= 0){
        
        return 2;
    }
    
}

/* FONCTION RAPPEL RÈGLES */
void rules(){
    
    printf("Bienvenue dans ///, un jeu de ///!\n");
    printf("Vous avez plusieurs choix dans ce jeu :\n");
    printf("//////////////////////////\n");
    
}


/* FONCTION AFFICHAGE STATS JOUEUR */
void player_stats_display(struct player first_player){
    
    printf("HP : %d\n", first_player.pv);
    printf("STAMINA : %d\n", first_player.stamina);
    printf("MONNAIE : %d\n", first_player.coins);
    printf("ÉVÈNEMENTS : %d\n\n", first_player.events);
}

int main(){
    
    int addQuest_checkValue = -1, lost_stats = -1;
    int p1_score_stock[TAB_SIZE];
    int p2_score_stock[TAB_SIZE];
    int i = 0;
    char score_infos[TAB_SIZE];
    
    char maze[MAZE_SIZE][MAZE_SIZE] = {
        "###   ##################################",
        "#### ###################################",
        "##### ##################################",
        "#####  #################################",
        "###### ##    ###########################",
        "######    ##  ##########################",
        "############# ##########################",
        "#############        ###################",
        "############### ####      ##############",
        "############    ######### ##############",
        "############ ############     ##########",
        "############   ############## ##########",
        "##############      #         ##########",
        "###################   ##################"
    };
    
    /* SECTION ALÉATOIRE */

    int random_array[ARRAY];
    int quests_randomizer;
    int seed = 0;

    /*getentropy(random_array, sizeof(random_array));
    for(i = 0; i < ARRAY; i++){

        seed = seed + random_array[i];
    }*/

    srand(time(NULL));

/* Contient la valeur aléatoire entre 1 & 10 */
    quests_randomizer = rand() % 10 + 1;


    /*while(isGameOver){
        
    
    }*/
   
   
   start_display();
   rules();
   
   /* Assignation des valeurs statistiques pour chaque joueur de leur fichier respectifs */
   struct player player_one = load_player("player_one.save");
   struct player player_two = load_player("player_two.save");
   
   printf("Joueur 1, voici vos statistiques :\n\n");
   player_stats_display(player_one);
   sleep(2);
   printf("Joueur 2, voici vos statistiques :\n\n");
   player_stats_display(player_two);
   sleep(1);
   
   //lost_stats = isLostStats(player_one);
   if(isLostStats(player_one) == 1){


   }
   // system("clear");
   
   
   
   /* Actualisation stats joueur 1 fin de jeu */
   
   FILE *p1_score_update = fopen("player_one.save", "w");
   fprintf(p1_score_update, "HP : %d STAMINA : %d COINS : %d EVENTS : %d\n", player_one.pv, player_one.stamina, player_one.coins, player_one.events);
   fclose(p1_score_update); 
   
   /* Actualisation stats joueur 2 fin de jeu */
   
   FILE *p2_score_update = fopen("player_two.save", "w");
   fprintf(p2_score_update, "HP : %d STAMINA : %d COINS : %d EVENTS : %d\n", player_two.pv, player_two.stamina, player_two.coins, player_two.events);
   fclose(p2_score_update); 
   
   return 0;
}

