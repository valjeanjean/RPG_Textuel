#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 128

int main(){
    
    int i = 0;

    char PvE_answer_array[TAB_SIZE][TAB_SIZE] = {
    
        "Combattre",
        "Fuir",
        "Mourrir"
    };

    for(i = 0; i < 3; i++){

        printf("%s\n", PvE_answer_array[i]);
    }

    return 0;
}










