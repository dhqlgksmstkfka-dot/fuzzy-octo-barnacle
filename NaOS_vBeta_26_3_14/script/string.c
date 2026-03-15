#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void Cursorhide();
void Cursorshow();

void reverse_string(){
	char str[80];
	int i = 0;
	int j;
	char temp;
	
	system("cls");
	
	while (1){
		printf("Enter string : ");
		if(fgets(str, 80, stdin) == NULL) break;
		if (strchr(str, '\n') != NULL)
    		str[strcspn(str,"\n")] = '\0';
		else
   			while (getchar() != '\n');
		if(strlen(str) == 0) continue;
		i = 0;
		j = strlen(str) - 1;
		
		while (i < j){
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
			j--;
		}
		printf("%s\n", str);
	}
}

void str_length(){
	char str[80];
	system("cls");
	while(1){
		printf("Enter string : ");
		if (fgets(str, 80, stdin) == NULL) break;
		if (strchr(str, '\n') != NULL)
    		str[strcspn(str,"\n")] = '\0';
		else
   			while (getchar() != '\n');
		printf("%d\n", strlen(str));
	}
}

void convert(int cond){
	char str[80];
	int i;
	system("cls");
	if (cond){
		while (1){
			printf("Enter string : ");
			if (fgets(str, 80, stdin) == NULL) return;
			if (strchr(str, '\n') != NULL)
    			str[strcspn(str,"\n")] = '\0';
			else
   				while (getchar() != '\n');
			for (i = 0; i < strlen(str); i++){
				if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
			}
			printf("%s\n", str);
		}
	} else {
		while (1){
			printf("Enter string : ");
			if (fgets(str, 80, stdin) == NULL) return;
			if (strchr(str, '\n') != NULL)
    			str[strcspn(str,"\n")] = '\0';
			else
   				while (getchar() != '\n');
			for (i = 0; i < strlen(str); i++){
				if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 'a' - 'A';
			}
			printf("%s\n", str);
		}
	}
}

void show_ascii(){
	char str[80];
	int i;
	system("cls");
	while (1){
		printf("Enter string : ");
		if (fgets(str, 80, stdin) == NULL) return;
		
		if (strchr(str, '\n') != NULL)
			str[strcspn(str,"\n")] = '\0';
		else
			while (getchar() != '\n');
		for (i = 0; i < strlen(str); i++){
			printf("%d ", str[i]);
		}
		printf("\n");
	}
}

void string_menu(){
	int choice;
	
	while (1){
		Cursorhide();
		system("cls");
		printf("\n=====[String menu]=====\n");
		printf("1 String length\n");
		printf("2 Reverse string\n");
		printf("3 Convert to uppercase\n");
		printf("4 Convert to lowercase\n");
		printf("5 Show ASCII code\n");
		printf("0 Back\n");
		
		choice = getch();
		Cursorshow();
		switch(choice){
			case '1':str_length();break;
			case '2':reverse_string();break;
			case '3':convert(0);break;
			case '4':convert(1);break;
			case '5':show_ascii();break;
			case '0':return;
			default:break;
		}
	}
}

