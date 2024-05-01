#include <stdio.h>
#include <stdlib.h>
#include "..\methods\method.h"

#define bool int 
#define true 1
#define false 0


void Show_record_user(int line_num)
{
    FILE *f = fopen("file.txt","r");
    char* buffer = (char*) malloc(Max_line);
    fscanf(f,"%199[^\n]",buffer);               // skip line
    fgetc(f);       

    while(--line_num)                           // skip untill the wanted line
    {
        fscanf(f,"%199[^\n]",buffer);          
        fgetc(f);       
    }

    student s;
    s.fullname[0] = (char*) malloc(Max_string);
    s.fullname[1] = (char*) malloc(Max_string);
    s.fullname[2] = (char*) malloc(Max_string);
    fscanf(f,"%d %s %s %s %s %d %s %d",&s.id , s.pass , s.fullname[0] , s.fullname[1] , s.fullname[2] , &s.age , s.gender , &s.total_grade);
    printf("\n\n\t\t===========================================================\n\n");
    printf("\t\t\t\t\tYOUR RECORD\n");
    printf("\t\t\t\tName        : %s %s %s\n",s.fullname[0],s.fullname[1],s.fullname[2]);
    printf("\t\t\t\tID          : %s\n",s.id);
    printf("\t\t\t\tGender      : %s\n",s.gender);
    printf("\t\t\t\tAge         : %d\n",s.age);
    printf("\t\t\t\tTotal Grade : %d\n",s.total_grade);
    printf("\n\t\t==============================================================\n");

    free(s.fullname[0]);
    free(s.fullname[1]);
    free(s.fullname[2]);
    fclose(f);
    return;

}

void Edit_pass_User(FILE *f ,int line_num ,char* new_pass)
{
    student s;
    s.fullname[0] = (char*) malloc (Max_string);
    s.fullname[1] = (char*) malloc (Max_string);
    s.fullname[2] = (char*) malloc (Max_string);
    f = fopen("file.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    
    if (f == NULL || tempFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

        
    char* adminpass = (char*) malloc (Max_string);
    fscanf(f,"%29[^\n]",adminpass);
    fgetc(f);
    fprintf(tempFile,"%s\n",adminpass);


    int currentLine = 0;

    while (fscanf(f, "%d %s %s %s %s %d %s %d", &s.id, s.pass , s.fullname[0] , s.fullname[1] , s.fullname[2] , &s.age , s.gender , &s.total_grade )!= EOF) 
    {
        fgetc(f);
        currentLine++;

        if (currentLine == line_num) {
            fprintf(tempFile,"%d %s %s %s %s %d %s %d\n", s.id, new_pass , s.fullname[0] , s.fullname[1] , s.fullname[2] , s.age , s.gender , s.total_grade);
        }
        else fprintf(tempFile,"%d %s %s %s %s %d %s %d\n", s.id, s.pass , s.fullname[0] , s.fullname[1] , s.fullname[2] , s.age , s.gender , s.total_grade);

    }

    printf("\n\t\t===============Password editted successfulley===============\n");

    free(s.fullname[0]);
    free(s.fullname[1]);
    free(s.fullname[2]);
    fclose(f);
    fclose(tempFile);

    remove("file.txt");

    // Rename the temp file to the original "filename"
    if (rename("temp.txt", "file.txt") != 0) {
        perror("Error renaming file");
        exit(EXIT_FAILURE);
    }
}

void Edit_name(FILE *f , int line_num, char* name[3])
{
    student s;
    s.fullname[0] = (char*) malloc (Max_string);
    s.fullname[1] = (char*) malloc (Max_string);
    s.fullname[2] = (char*) malloc (Max_string);
    f = fopen("file.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    
    if (f == NULL || tempFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // to get and print the first line cintainting the admin pass
    char* adminpass = (char*) malloc (Max_string);
    fscanf(f,"%29[^\n]",adminpass);
    fgetc(f);
    fprintf(tempFile,"%s\n",adminpass);

    int currentLine = 0;

    while (fscanf(f, "%d %s %s %s %s %d %s %d", &s.id, s.pass , s.fullname[0] , s.fullname[1] , s.fullname[2] , &s.age , s.gender , &s.total_grade )!= EOF) 
    {
        fgetc(f);
        currentLine++;

        if (currentLine == line_num) {
            fprintf(tempFile,"%d %s %s %s %s %d %s %d\n", s.id, s.pass , name[0] , name[1] , name[2] , s.age , s.gender , s.total_grade);
        }
        else fprintf(tempFile,"%d %s %s %s %s %d %s %d\n", s.id, s.pass , s.fullname[0] , s.fullname[1] , s.fullname[2] , s.age , s.gender , s.total_grade);

    }


    free(s.fullname[0]);
    free(s.fullname[1]);
    free(s.fullname[2]);
    fclose(f);
    fclose(tempFile);

    remove("file.txt");

    if (rename("temp.txt", "file.txt") != 0) {
        perror("Error renaming file");
        exit(EXIT_FAILURE);
    }
}