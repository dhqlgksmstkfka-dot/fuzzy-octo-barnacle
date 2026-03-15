#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void Cursorhide();
void Cursorshow();

void ascii_art(){
	FILE *fp = fopen("sys\\ascii.txt","r");
	char line[256];

	while(fgets(line,256,fp)){
    	printf("%s",line);
	}
	system("pause");
}

void info(){
	printf("NaOS consol system\n");
	printf("Version Beta 26.3.14 (v0.7)\n");
	printf("Flatfrom : windows\n");
	printf("Language : English\n");
	system("pause");
}

void current_time(){

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    printf("Time: %02d:%02d:%02d\n",
           tm_info->tm_hour,
           tm_info->tm_min,
           tm_info->tm_sec);
    system("pause");
}

void others(){
	int choice;
	
	while (1){
		Cursorhide();
		system("cls");
		printf("\n=====[Others]=====\n");
		printf("1 ASCII art\n");
		printf("2 System info\n");
		printf("3 Current time\n");
		printf("0 Back\n");
		
		choice = getch();
		Cursorshow();
		switch(choice){
			case '1':system("cls");ascii_art();break;
			case '2':system("cls");info();break;
			case '3':system("cls");current_time();break;
			case '0':return;
			default:break;
		}
	}
}
