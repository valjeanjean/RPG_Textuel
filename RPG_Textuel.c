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
#define MAX_LINES 12
#define IS_QUEST 1
#define IS_ENIGME 2
#define PLAYER_CHOICE_TAB 1

struct player{

    int pv;
    int stamina;
    int coins;
    int events;

};

/* FONCTION AFFICHAGE DÉBUT DE JEU */
void start_display(){

    printf("|-------------------------------------|\n");
    printf("|-------------RPG Textuel-------------|\n\n");
}

/* GAME OVER */
void gameOver_display(){

    printf("Vous avez perdu ! Soyez plus concentré(s) la prochaine fois!\n\n");
    printf("|----------------------------------|\n");
    printf("              GAME OVER\n");
    printf("|----------------------------------|\n");
    printf("|----------------------------------|\n");
}

void getReady_display(){

    printf("Vous vous apprêtez à rentrer!\n\n");
}

/* FONCTION DÉTERMINANT SI LE JOUEUR VA VOIR S'AFFICHER UNE QUÊTE OU UNE ÉNIGME*/
int quests_or_enigmes(){

    int random_array[ARRAY];
    int quests_randomizer;
    int seed = 0;

    srand(time(NULL));

/* Contient la valeur aléatoire entre 0 & 5 */

    quests_randomizer = rand() % 6;

    if(quests_randomizer < 3){

        return IS_QUEST;

    }else if(quests_randomizer > 2){

        return IS_ENIGME;
    }
}

int player_answer(){

    char tab[5];
    int answer_stock = 0;

    fgets(tab, sizeof(tab), stdin);
    answer_stock = atoi(tab);
    printf("La réponse du joueur est %d\n", answer_stock);
    return answer_stock;


}

/* FONCTION GÉNÉRANT UNE VALEUR ALÉATOIRE */
int random_value(){

    int random_array[ARRAY];
    int quests_randomizer;
    int seed = 0;

    srand(time(NULL));

    /* Contient la valeur aléatoire entre 1 & 10 */

    quests_randomizer = rand() % 10;

    return quests_randomizer;
}

/* FONCTION QUI VÉRIFIE LA RÉPONSE PAR RAPPORT À LA VALEUR ALÉATOIRE ET LE CHOIX DE RÉPONSE DU JOUEUR */
int isCorrect(int random_value){

    int stock_answer = 0;
    stock_answer = player_answer();

    switch (random_value)
    {
    case 1:
    
        if(1);

        return 1;
    
    case 2:
        
        return 2;
    
    case 3:
        
        return 3;
    
    case 4:
        
        return 4;
        
    case 5:
        
        return 5;
        
    case 6:
        
        return 6;
        
    case 7:
        
        return 7;
        
    case 8:
        
        return 8;
        
    case 9:
        
        return 9;
        
    case 10:
        
        return 10;
        
        
    default:
        break;
    }

}

/* FONCTION ENREGISTREMENT DES QUÊTES DANS UN TABLEAU */
void load_Quests(const char *quest_file, int rand_quest_value){

    int i = 0;

    FILE *reading_quests = fopen(quest_file, "r");

    char quests_array[TAB_SIZE][TAB_SIZE];

    /* readLine(reading_quests,questsChoices_array,[TAB_SIZE],rand_quest_value); */
    /* Nécessite sûrement une deuxième fonction car il faut un deuxième FILE * car c'est un autre fichier */

    while(fgets(quests_array[i], TAB_SIZE, reading_quests) != NULL){

        i++;

        if(i > MAX_LINES){

            break;
        }
        
        
        quests_array[i][strcspn(quests_array[i], "\n")] = '\0';
        
    }

    printf("%s\n", quests_array[rand_quest_value]);
    fclose(reading_quests);
}

/* FONCTION ENREGISTREMENT DES CHOIX DE QUÊTES DANS UN TABLEAU */
void load_questsChoices(const char *quest_file, int rand_quest_value){

    int i = 0;

    FILE *reading_questsChoices = fopen(quest_file, "r");

    char questsChoices_array[TAB_SIZE][TAB_SIZE];

    /* readLine(reading_quests,questsChoices_array,[TAB_SIZE],rand_quest_value); */
    /* Nécessite sûrement une deuxième fonction car il faut un deuxième FILE * car c'est un autre fichier */

    while(fgets(questsChoices_array[i], TAB_SIZE, reading_questsChoices) != NULL){

        i++;

        if(i > MAX_LINES){

            break;
        }
        
        
        questsChoices_array[i][strcspn(questsChoices_array[i], "\n")] = '\0';
        
    }

    printf("%s\n", questsChoices_array[rand_quest_value]);
    fclose(reading_questsChoices);
}

/* FONCTION ENREGISTRANT LES ÉNIGMES DANS UN TABLEAU */
void load_enigmes(const char *quest_file, int rand_quest_value){

    int i = 0;

    FILE *reading_enigmes = fopen(quest_file, "r");

    char enigmes_array[TAB_SIZE][TAB_SIZE];

    /* readLine(reading_quests,questsChoices_array,[TAB_SIZE],rand_quest_value); */
    /* Nécessite sûrement une deuxième fonction car il faut un deuxième FILE * car c'est un autre fichier */

    while(fgets(enigmes_array[i], TAB_SIZE, reading_enigmes) != NULL){

        i++;

        if(i > MAX_LINES){

            break;
        }

        enigmes_array[i][strcspn(enigmes_array[i], "\n")] = '\0';
    }
    
    printf("%s\n", enigmes_array[rand_quest_value]);
    fclose(reading_enigmes);
}

/* FONCTION ENREGISTRANT LES CHOIX DE RÉPONSES AUX ÉNIGMES DANS UN TABLEAU */
void load_enigmesChoices(const char *quest_file, int rand_quest_value){

    int i = 0;

    FILE *reading_enigmesChoices = fopen(quest_file, "r");

    char enigmesChoices_array[TAB_SIZE][TAB_SIZE];

    /* readLine(reading_quests,questsChoices_array,[TAB_SIZE],rand_quest_value); */
    /* Nécessite sûrement une deuxième fonction car il faut un deuxième FILE * car c'est un autre fichier */

    while(fgets(enigmesChoices_array[i], TAB_SIZE, reading_enigmesChoices) != NULL){

        i++;

        if(i > MAX_LINES){

            break;
        }
        
        enigmesChoices_array[i][strcspn(enigmesChoices_array[i], "\n")] = '\0';
    }

    printf("%s\n", enigmesChoices_array[rand_quest_value]);
    fclose(reading_enigmesChoices);
}

/* FONCTION QUI INITIALISE LES STATS DU JOUEUR EN FONCTION DE CELLES ENREGISTRÉES DANS LE FICHIER */
struct player load_player(const char *file_name){  
    
    struct player player_who;
    player_who.pv = 0;
    player_who.stamina = 0;
    player_who.coins = 0;
    player_who.events = 0;

    /* Au lieu d'intialiser à 0 à la main, possibilité de faire memset de struct player sizeof(struct) */

    FILE *first_score_read = fopen(file_name, "r");
    
    char tab[255];
    fgets(tab, TAB_SIZE, first_score_read);
    tab[strcspn(tab, "\n")] = '\0';
    sscanf(tab, "HP : %d STAMINA : %d COINS : %d EVENTS : %d", &player_who.pv, &player_who.stamina, &player_who.coins, &player_who.events);
    /* Possible de faire pareil pour enregistrer les énigmes dans un tableau de char 2D puis sscanf(tab, "%s %s", &tab[0], &tab[1] PAR EXEMPLE) */

    fclose(first_score_read);
    
    return player_who;
}

/* FONCTION QUI VERIFIE SI LE JOUEUR A 0 PV OU 0 PIÈCES, SI OUI GAME OVER */
int isGameOver(struct player player_who){
    
    if(player_who.pv < 1 || player_who.coins >= 1000){
    
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
    
    printf("Bienvenue dans CLI Adventure, un jeu de quêtes et d'énigmes!\n");
    sleep(1.5);
    printf("Vous devrez réaliser des 'missions', pour augmenter vos stats et gagner des objets!\n");
    sleep(2);
    printf("Vous devrez parfois répondre à des énigmes, avec des récompenses à la clé!\n\n");
    sleep(2);
    printf("Attention, des bêtes défendent souvent les artefacts, soyez prudent.\n\n");
    sleep(2);
}


/* FONCTION AFFICHAGE STATS JOUEUR */
void player_stats_display(struct player first_player){
    
    printf("HP : %d\n", first_player.pv);
    printf("STAMINA : %d\n", first_player.stamina);
    printf("MONNAIE : %d\n", first_player.coins);
    printf("ÉVÈNEMENTS : %d\n\n", first_player.events);
}

int main(){
    
    int is_gameOver = -1, lost_stats = -1;
    int p1_score_stock[TAB_SIZE];
    int p2_score_stock[TAB_SIZE];
    int i = 0;
    char score_infos[TAB_SIZE];
    int randomValue_stock = -1;
    int quest_or_enigme = 0;
    
    /* FONCTION AFFICHAGE DÉBUT DE JEU & RÈGLES */
    start_display();
    rules();

    struct player player_one = load_player("player_one.save");
    struct player player_two = load_player("player_two.save");

    is_gameOver = isGameOver(player_one);

    getReady_display();

    /* FONCTION & BOUCLE DU JEU */
    while(is_gameOver){       /* Faire une autre fonction pour quitter le jeu s'il appuie sur q ? while(isGameOver || isLeaving) ? */

        is_gameOver = isGameOver(player_one);
        
        /* SECTION ALÉATOIRE */
        //randomValue_stock = random_value();
        //printf("Valeur aléatoire est : %d\n", randomValue_stock);
        
        printf("Joueur 1, voici vos statistiques :\n\n");
        player_stats_display(player_one);
        sleep(2);

        /* METTRE UN IF MULTIJOUEUR */
        printf("Joueur 2, voici vos statistiques :\n\n");
        player_stats_display(player_two);
        sleep(1);
        
        randomValue_stock = random_value();

        quest_or_enigme = quests_or_enigmes();

        if(quest_or_enigme == IS_ENIGME){

            load_enigmes("enigmes.save", randomValue_stock);
            sleep(1);
            load_enigmesChoices("enigmes_choices.save", randomValue_stock);
            player_answer();

        }else if(quest_or_enigme == IS_QUEST){

            /* Pourrait faire un if(randomValue_stock == 9), alors ça veut dire qu'il sera print la dernière ligne des quêtes */
            /* On peut donc assigner une variable à la valeur correspondante, qui donne les récompenses, peut être utilisé un switch */
            /* Faire une fonction avec un switch avec un paramètre (randomValue_stock), qui renvoie une valeur entre 1 et 10 */

            load_Quests("quests.save", randomValue_stock);
            sleep(1);
            load_questsChoices("quests_choice.save", randomValue_stock);
            sleep(1);
            player_answer();
        }

        if(isLostStats(player_one) == 1){
            
            player_one.pv--;
            player_one.pv--;
            player_one.stamina--;
            player_one.stamina--;   
        }
        
        if(isLostStats(player_two) == 1){

            player_two.pv--;
            player_two.pv--;
            player_two.stamina--;
            player_two.stamina--;
        }

        //system("clear"); Gêne le printf de vérif de ma fonction loadQuests
        
        /* Actualisation stats joueur 1 fin de jeu */
        FILE *p1_score_update = fopen("player_one.save", "w");
        fprintf(p1_score_update, "HP : %d STAMINA : %d COINS : %d EVENTS : %d\n", player_one.pv, player_one.stamina, player_one.coins, player_one.events);
        fclose(p1_score_update); 
        
        /* Actualisation stats joueur 2 fin de jeu */
        
        FILE *p2_score_update = fopen("player_two.save", "w");
        fprintf(p2_score_update, "HP : %d STAMINA : %d COINS : %d EVENTS : %d\n", player_two.pv, player_two.stamina, player_two.coins, player_two.events);
        fclose(p2_score_update); 
    }
        
    gameOver_display();

    return 0;
}

