#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define LARGEUR 10
#define HAUTEUR 10

// Représentation du labyrinthe
char labyrinthe[HAUTEUR][LARGEUR] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Position du joueur
int joueur_x = 1, joueur_y = 1;

// Fonction pour afficher le labyrinthe
void afficher_labyrinthe() {
    clear();  // Efface l'écran

    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            if (i == joueur_y && j == joueur_x)
                printw("P");  // Affiche le joueur
            else
                printw("%c", labyrinthe[i][j]);
        }
        printw("\n");
    }
    refresh();  // Actualise l'écran
}

// Fonction pour déplacer le joueur
void deplacer_joueur(char direction) {
    int nouvelle_x = joueur_x;
    int nouvelle_y = joueur_y;

    switch (direction) {
        case 'z':  // Haut
            nouvelle_y--;
            break;
        case 's':  // Bas
            nouvelle_y++;
            break;
        case 'q':  // Gauche
            nouvelle_x--;
            break;
        case 'd':  // Droite
            nouvelle_x++;
            break;
        default:
            return;
    }

    // Vérifie si la nouvelle position est valide (pas un mur)
    if (labyrinthe[nouvelle_y][nouvelle_x] == ' ') {
        joueur_x = nouvelle_x;
        joueur_y = nouvelle_y;
    }
}

int main() {
    initscr();  // Initialisation de ncurses
    cbreak();   // Désactive le buffer d'entrée (permet de lire chaque touche sans attendre Entrée)
    noecho();   // Empêche l'affichage des caractères saisis
    keypad(stdscr, TRUE);  // Active les touches spéciales

    char direction;

    while (1) {
        afficher_labyrinthe();  // Affiche le labyrinthe
        direction = getch();    // Lit la touche sans attendre la touche Entrée

        // Quitte le programme si 'q' est pressé (vous pouvez changer cette logique)
        if (direction == 'q') {
            break;
        }

        deplacer_joueur(direction);  // Déplace le joueur
    }

    endwin();  // Ferme ncurses et nettoie la mémoire
    return 0;
}
