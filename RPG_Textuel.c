#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <unistd.h>
#include <time.h>

#define MAX_LENGTH 512
#define MAZE_SIZE 512

void start_display(){

    printf("|----------------------------------|\n");
    printf("|-------------RPG Textuel----------|\n\n");
}

void rules(){

    printf("Bienvenue dans ///, un jeu de ///!\n");
    printf("Vous avez plusieurs choix dans ce jeu :\n");
    printf("//////////////////////////\n");

}

int is_addQuest(){

    char array_stock[MAX_LENGTH];
    int atoi_stock = -1;

    printf("Si vous le désirez, vous pouvez choisir d'ajouter des missions/quêtes?\n");
    printf("Tapez 5 pour cela!\n");
    fgets(array_stock, sizeof(array_stock), stdin);
    atoi_stock = atoi(array_stock);

    if(atoi_stock == 5){

        return 1;

    }else{

        return 0;
    }
}

void addQuest(char quest_idea[], int taille){

    printf("Veuillez décrire explicitement votre mission :\n");
    fgets(quest_idea, taille, stdin);
    quest_idea[strcspn(quest_idea, "\n")] = '\0';
    

}

void player_stats_display(int player_tab[]){

    printf("HP : %d\n", player_tab[0]);
    printf("STAMINA : %d\n", player_tab[1]);
    printf("MONNAIE : %d\n", player_tab[2]);
    printf("ÉVÈNEMENTS : %d\n\n", player_tab[3]);

}

struct player{

    int pv;
    int stamina;
    int coins;
    int events;

};

int main(){

    int addQuest_checkValue = -1;
    int p1_score_stock[MAX_LENGTH];
    int p2_score_stock[MAX_LENGTH];
    char player_added_quests[MAX_LENGTH][MAX_LENGTH];
    char maze[MAZE_SIZE][MAZE_SIZE] = {
    "###   ##################################",
    "#### ###################################",
    "##### ##################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################",
    "########################################"
    };

    printf("%s\n", maze[0]);

    FILE * first_score_read = fopen("inventaire.save", "r");
    fscanf(first_score_read,"%d %d %d %d", &p1_score_stock[0], &p1_score_stock[1], &p1_score_stock[2], &p1_score_stock[3]);
    fscanf(first_score_read,"%d %d %d %d", &p2_score_stock[0], &p2_score_stock[1], &p2_score_stock[2], &p2_score_stock[3]);
    fclose(first_score_read);

    struct player player_one;
    player_one.pv = p1_score_stock[0];
    player_one.stamina = p1_score_stock[1];
    player_one.coins = p1_score_stock[2];
    player_one.events = p1_score_stock[3];
    
    struct player player_two;
    player_two.pv = p2_score_stock[0];
    player_two.stamina = p2_score_stock[1];
    player_two.coins = p2_score_stock[2];
    player_two.events = p2_score_stock[3];

    start_display();
    rules();

    if(is_addQuest() == 1){

        printf("Vous avez choisi de créer de nouvelles missions.\n");
        printf("Vous pouvez en ajouter autant que vous voulez, entrez q pour quitter.\n");
        
        while(getchar() != 'q'){
            
            addQuest(player_added_quests[0], MAX_LENGTH);
            FILE *print_quests = fopen("quests.save", "a");
            fprintf(print_quests, "%s\n", player_added_quests[0]);
            fclose(print_quests);
        }

    }else{

        printf("Tu ne choisis pas de rajouter de missions!\n");
    }



    printf("Joueur 1, voici vos statistiques :\n\n");
    player_stats_display(p1_score_stock);
    sleep(2);
    printf("Joueur 2, voici vos statistiques :\n\n");
    player_stats_display(p2_score_stock);
    sleep(1);

    FILE *score_update = fopen("inventaire.save", "w");
    fprintf(score_update, "%d %d %d %d\n", player_one.pv, player_one.stamina, player_one.coins, player_one.events);
    fprintf(score_update, "%d %d %d %d\n", player_two.pv, player_two.stamina, player_two.coins, player_two.events);
    fclose(score_update);


    return 0;
}