#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>
#include <conio.h>

void Cursorhide();
void Cursorshow();

int invalid_char(char *name){

    char bad[]="\\/:*?\"<>|";

    for(int i=0; name[i]; i++){

        for(int j=0; bad[j]; j++){

            if(name[i]==bad[j])
                return 1;
        }
    }

    return 0;
}

void list_files(){
    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    if(d == NULL){
        printf("Directory open failed\n");
        system("pause");
        return;
    }

    printf("==== File List ====\n");

    while((dir = readdir(d)) != NULL){
        if(strstr(dir->d_name,".txt") != NULL){
            printf("%s\n",dir->d_name);
        }

    }

    closedir(d);
}

void read_file(){
    FILE *fp;
    char name[100];
    char str[512];

    list_files();

    while (1){
    	printf("File name: ");

    	if(fgets(name,100,stdin) == NULL) return;
    	name[strcspn(name,"\n")] = '\0';

    	if(strstr(name,".txt") == NULL)
        	strcat(name,".txt");

    	fp = fopen(name,"r");

    	if(fp == NULL){
        	printf("File not found\n");
        	continue;
    	}
    	
    	printf("\n==== File content ====\n");
    	while(fgets(str,256,fp)){
        	printf("%s",str);
    	}
    	printf("\n==== End ====\n");

    	fclose(fp);
	}
}

void create_file(){
    FILE *fp;
    char name[100];
    
    list_files();
    while (1){
    	printf("File name: ");

    	if(fgets(name,100,stdin) == NULL) return;
    	name[strcspn(name,"\n")] = '\0';
    	if(invalid_char(name)){
			printf("Invalid file name\n");
			continue;
		}
		
   		if(strstr(name,".txt") == NULL)
        	strcat(name,".txt");

    	fp = fopen(name,"w");

    	if(fp == NULL){
        	printf("File creation failed\n");
       		continue;
    	}

    	fclose(fp);

    	printf("File created\n");
	}
}

void write_file(){
    FILE *fp;
    char name[100];
    char str[256];

    list_files();

    while (1){
    	printf("File name: ");

    	if(fgets(name,100,stdin) == NULL) break;
    	name[strcspn(name,"\n")] = '\0';

    	if(strstr(name,".txt") == NULL)
        strcat(name,".txt");

    	fp = fopen(name,"a");

    	if(fp == NULL){
        	printf("File open failed\n");
        	continue;
    	}

    	printf("Enter text (emtpy line to finish)\n");

    	while(1){

        	fgets(str,256,stdin);

        	if(strcmp(str,"\n") == 0)
            	break;

        	fputs(str,fp);
    	}

    	fclose(fp);
	}
}

void delete_file(){
    char name[100];
    
    list_files();
    while (1){
    	printf("File name: ");
    	
    	if(fgets(name,100,stdin) == NULL) return;
    	name[strcspn(name,"\n")] = '\0';
   		if(strstr(name,".txt") == NULL)
        	strcat(name,".txt");
        	
    	if(remove(name) == 0)
        	printf("File deleted\n");
    	else
        	printf("Delete failed\n");
	}
}

void rename_file(){
    char oldname[100];
    char newname[100];

    list_files();

    printf("Old file name: ");

    fgets(oldname,100,stdin);
    oldname[strcspn(oldname,"\n")] = '\0';

    if(strstr(oldname,".txt") == NULL)
        strcat(oldname,".txt");

    printf("New file name: ");

    fgets(newname,100,stdin);
    newname[strcspn(newname,"\n")] = '\0';
    if(invalid_char(newname)){
		printf("Invalid file name\n");
		system("pause");
		return;
	}

    if(strstr(newname,".txt") == NULL)
        strcat(newname,".txt");

    if(rename(oldname,newname) == 0)
        printf("Rename success\n");
    else
        printf("Rename failed\n");
}

void note_menu(){
	int choice;
	
	while (1){
		Cursorhide();
		system("cls");
		printf("\n=====[Note/file menu]=====\n");
		printf("1 List files\n");
		printf("2 Read file\n");
		printf("3 Create file\n");
		printf("4 Write file\n");
		printf("5 Delete file\n");
		printf("6 Rename file\n");
		printf("0 Back\n");
		
		choice = getch();
		Cursorshow();
		switch(choice){
			case '1':system("cls");list_files();system("pause");break;
			case '2':system("cls");read_file();break;
			case '3':system("cls");create_file();break;
			case '4':system("cls");write_file();break;
			case '5':system("cls");delete_file();break;
			case '6':system("cls");rename_file();break;
			case '0':return;
			default:break;
		}
	}
}

