#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

void Cursorhide();
void Cursorshow();

void calculation(){
	double a, b;
	char op;
	while(1){
		printf("Enter calculation(ex : 5 + 3, -, *, /, ^, e to exit) : ");
		if(scanf("%lf %c %lf", &a, &op, &b) != 3){
    		printf("Invalid input\n");
    		while(getchar()!='\n');
			continue;
		}
		while(getchar() != '\n');
	
		switch(op){
			case '+':printf("%.2lf\n", a + b);break;
			case '-':printf("%.2lf\n", a - b);break;
			case '*':printf("%.2lf\n", a * b);break;
			case '/':
				if (b == 0){
					printf("Cannot divide zero!\n");break;
				}
				printf("%.2lf\n", a / b);break;
			case '%':
				if (b == 0){
					printf("Cannot divide zero!\n");break;
				}
				printf("%.2lf\n", (int)a % (int)b);break;
			case '^':printf("%.2lf\n", pow(a, b));break;
			case 'e':return;
			default:printf("Wrong operator\n");
		}
	}
}

void random_number(){
	int max, min;
	Cursorshow();
	printf("Enter range(ex : 1 100) : ");
	if(scanf("%d %d", &min, &max) != 2){
    	printf("Invalid input\n");
    	while(getchar() != '\n');system("pause");
    	return;
	}
	while(getchar() != '\n');
	printf("%d", rand() % max + min);system("pause");
}

void squareroot(){
	double a;
	printf("Enter number : ");
	if(scanf("%lf", &a) != 1){
    	printf("Invalid input\n");
    	while(getchar() != '\n');system("pause");
    	return;
	}
	if (a < 0){
		printf("Impossible");
	}
	while(getchar() != '\n');
	printf("%lf", sqrt(a));system("pause");
}

void calculation_menu(){
	char choice;
	while (1){
		Cursorhide();
		system("cls");
		printf("\n=====[Calculation]=====\n");
		printf("1 Basic calculation\n");
		printf("2 Random number\n");
		printf("3 Square root\n");
		printf("0 Back\n");
		
		choice = getch();
		Cursorshow();
		switch(choice){
			case '1':system("cls");calculation();break;
			case '2':system("cls");random_number();break;
			case '3':system("cls");squareroot();break;
			case '0':return;
			default:break;
		}
	}
}

