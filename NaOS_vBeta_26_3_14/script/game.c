#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void Cursorhide();
void Cursorshow();

void updown(){
	int num, inp;
	int turns = 0;
	num = rand() % 100 + 1;
	system("cls");
	while (1){
		printf("guess number : ");
		if(scanf("%d", &inp) != 1){
    		printf("Invalid input\n");
    		while(getchar() != '\n');Sleep(1500);
    		continue;
		}
		while(getchar() != '\n');
		
		if (inp == num){
			printf("Correct!!\n");
			printf("Turns : %d\n", turns);
			system("pause");
			return;
		} else if (inp < num){
			printf("up\n");
			turns++;
		} else if (inp > num){
			printf("down\n");
			turns++;
		}
	}
}

void memory(){
	int num, i;
	int inp;
	int s[10] = {3000, 3000, 2000, 2000, 1000, 1000, 500, 500, 250, 250};
	for (i = 0; i < 10; i++){
		num = rand() % 1000 + 1;
		system("cls");
		printf("level %d (%.2f second)\n", i + 1, s[i] / 1000.0);Sleep(1000);
		printf("%d", num);
		Sleep(s[i]);
		system("cls");
		printf("number : ");
		if(scanf("%d", &inp) != 1){
    		printf("failed!!\n");
    		while(getchar() != '\n');Sleep(1500);
    		system("pause");
    		return;
		}
		while(getchar() != '\n');
		
		if (inp == num){
			printf("Correct!\n");
			Sleep(3000);
		} else {
			printf("failed!!\n");
			system("pause");
			return;
		}
	}
	system("pause");
}

void adventure(){

    int choice;
    
	system("cls");
    printf("You wake up in a strange forest.\n");
    printf("Your device shows one message:\n");
    printf("\"FIND THE SIGNAL\"\n\n");

    printf("1 Look around\n");
    printf("2 Walk forward\n");
    printf("Choose: ");
    if(scanf("%d", &choice) != 1){
    	printf("Invalid input\n");
    	while(getchar() != '\n');Sleep(1500);
    	return;
	}

    if(choice == 1){

        printf("\nYou see an old radio tower in the distance.\n");

        printf("1 Go to the tower\n");
        printf("2 Ignore it\n");
        printf("Choose: ");
        if(scanf("%d", &choice) != 1){
    		printf("Invalid input\n");
    		while(getchar() != '\n');Sleep(1500);
    		return;
		}

        if(choice == 1){

            printf("\nThe tower door is locked.\n");

            printf("1 Break the door\n");
            printf("2 Search another way\n");
            printf("Choose: ");
            if(scanf("%d", &choice) != 1){
    			printf("Invalid input\n");
    			while(getchar() != '\n');Sleep(1500);
    			return;
			}

            if(choice == 1){

                printf("\nThe door breaks open.\n");
                printf("Inside the tower a terminal lights up.\n");
                printf("TRANSMISSION RESTORED\n");
                printf("YOU ESCAPED\n");
                system("pause");

            }else{

                printf("\nYou find a trapdoor.\n");
                printf("Something moves in the dark...\n");
                printf("GAME OVER\n");
                system("pause");

            }

        }else{

            printf("\nYou walk deeper into the forest.\n");
            printf("The signal disappears.\n");
            printf("You are lost forever.\n");
            printf("GAME OVER\n");
            system("pause");

        }

    }else{

        printf("\nYou find a strange device.\n");

        printf("1 Press the button\n");
        printf("2 Leave it\n");
        printf("Choose: ");
        if(scanf("%d", &choice) != 1){
    		printf("Invalid input\n");
    		while(getchar() != '\n');Sleep(1500);
    		return;
		}

        if(choice == 1){

            printf("\nA loud alarm rings.\n");
            printf("A rescue drone appears.\n");
            printf("YOU SURVIVED\n");
            system("pause");

        }else{

            printf("\nThe device explodes.\n");
            printf("GAME OVER\n");
            system("pause");

        }

    }

}

void game_menu(){
	int choice;
	
	while(1){
		Cursorhide();
		system("cls");
		printf("\n=====[Game menu]=====\n");
		printf("1 Up down game\n");
		printf("2 Memory number\n");
		printf("3 Text adventure\n");
		printf("0 Back\n");
		
		choice = getch();
		Cursorshow();
		switch(choice){
			case '1':updown();break;
			case '2':memory();break;
			case '3':adventure();break;
			case '0':return;
			default:break;
		}
	}
}
