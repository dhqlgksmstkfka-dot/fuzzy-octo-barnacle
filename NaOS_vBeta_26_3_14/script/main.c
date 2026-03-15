#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <dirent.h>
#include <conio.h>

void typeprintf(char *);
void Cursorhide();
void Cursorshow();

void calculation();
void random_number();
void squareroot();
void calculation_menu();

void reverse_string();
void str_length();
void convert(int);
void show_ascii();
void string_menu();
int invalid_char(char *);

void list_files();
void read_file();
void create_file();
void write_file();
void delete_file();
void rename_file();
void note_menu();

void dice();

void updown();
void memory();
void adventure();
void game_menu();

void ascii_art();
void info();
void current_time();
void others();

int main(){
	char choice;
	srand(time(NULL));
	Cursorhide();
	
	typeprintf("Welcome to NaOS!\n");
	printf("Loading system");
	printf(".");Sleep(500);
	printf(".");Sleep(500);
	printf(".");Sleep(500);
	
	while(1){
		system("cls");
		printf("\n=====[Main menu]=====\n");
		printf("1 Calculation\n");
		printf("2 String\n");
		printf("3 Note/file\n");
		printf("4 Dice\n");
		printf("5 Game\n");
		printf("6 Others\n");
		printf("0 Exit\n");
		choice = getch();
		switch(choice){
			case '1' : calculation_menu();break;
			case '2' : string_menu();break;
			case '3' : note_menu();break;
			case '4' : dice();break;
			case '5' : game_menu();break;
			case '6' : others();break;
			case '0' :
				system("cls");
				printf("Goodbye!\n");
				printf("Shutting down");Sleep(500);
				printf(".");Sleep(500);
				printf(".");Sleep(500);
				printf(".");Sleep(500);
				exit(0);
			default : break;
		}
	}
	
    return 0;
}
