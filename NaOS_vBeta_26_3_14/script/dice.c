#include <stdio.h>
#include <stdlib.h>

void dice(){
    int r = rand()%6 + 1;
    
    system("cls");
    printf("Dice: %d\n", r);
    system("pause");
}
