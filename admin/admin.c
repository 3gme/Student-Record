#include <stdio.h>
#include <string.h>
#include "..\methods\method.h"



typedef struct student_
{
    char id[Max_string];
    char fullname[3][Max_string];
    char pass[Max_string];
    int age;
    char gender[Max_string];
    int total_grade;
}student_;

bool Check_id_admin(char* id)     
{
    //returns true if the id isn't there in the file before  .
    //used to check the id in admins operations ..
    //every time the admin change the id the check starts from the first student again.

    char admin_pass[Max_string] , current_id[Max_string];
        
    FILE* file = fopen("file.txt", "r");
    
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return false;
    }

    fscanf(file,"%s",admin_pass);

    while(fscanf(file,"%s",current_id) != EOF)
    {
        if(!strcmp(id,current_id))
        {
            printf("\t\t\tID already exits try again\n\t\t\tID :");
            scanf("%s",id);
            rewind(file);           //to reread the file from the beginning
            fscanf(file,"%s",admin_pass); //skip the first line in the file 
        }
        else    // go the next line to check
        {                
            char* buffer = (char*) malloc(Max_line);
            fscanf(file,"%199[^\n]",buffer);
            fgetc(file);
        }
    }
    fclose(file);
    return true;
}

bool check_pass_admin() 
{
    char pass    [Max_string]; 
    char password[Max_string];
    int count = 3;
    FILE *file = fopen("file.txt","r");
    if (file == NULL) 
    {
        printf("Error opening file here.\n");
        return false;
    }

    while (fscanf(file, "%s", pass) != EOF) 
    {
        while(count) 
        {
            printf("\t\tpassword : ");
            scanf("%s", password);
            if (!strcmp(pass, password)) 
            {
                printf("\t\t\t\t    Welcome .^_^.\n");
                return true;
            } else 
            {
                count--;
                if(count)
                printf("\t\t\aSorry, password is wrong! Try again\n");
            }
        } 
    }
    printf("Sorry _, No more tries ...\n");
    
    return false;
}

void ADD_new_record() 
{
    student_ new_student;
    FILE* file = fopen("file.txt", "a");
    
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
        
    printf("\t\t================ Enter student information ================\n\n");
    bool flag = true;
    while(flag)
    {
        printf("\t\t\tID          : ");
        scanf("%s", new_student.id);
        if(Check_id_admin(new_student.id))
        flag = false;
    }
    printf("\t\t\tPassword    : ");
    scanf("%s", new_student.pass);
    printf("\t\t\tFull Name   : ");
    for (int i = 0; i < 3; i++) 
    {
        scanf("%s",new_student.fullname[i]);
    }
    printf("\t\t\tAge         : ");
    scanf("%d", & new_student.age);
    printf("\t\t\tGender      : ");
    scanf(" %s", new_student.gender);
    printf("\t\t\tTotal Grade : ");
    scanf("%d", &new_student.total_grade);

    fprintf(file, "%s %s %s %s %s %d %s %d\n", new_student.id ,new_student.pass ,new_student.fullname[0], new_student. fullname[1],new_student. fullname[2],new_student. age,new_student. gender,new_student.total_grade);

    printf("\t\t============== New student added successfully =============\n");
    fclose(file);
}

void Remove_record(char* id) {
    FILE* file = fopen("file.txt","r");
    if (file == NULL) 
    {
    perror("Error opening file");
    exit(EXIT_FAILURE);
    }

    bool flag = true;
    int counter =  1;           // counter is one cause we get the id once in the main.
    while(flag)
    {
    int num = atoi(id), line = 0;       // convert the id type to id to be usable in Check_id.
    if(Check_id(file , num ,&line ))    // true if the id already in the file
    flag = false ;

    if(counter == 3 && flag)            // if the admin used the 3 tries and keep entering wrong id
    {
        printf("\n\t===Sorry invalid data===\n");
        break;
    }

    if(flag)
    {
        printf("Wrong ID try again: ");
        scanf("%s",id);
        counter ++;
    }

    }

    if(flag) return;            // return if can't get a right id

    // file = fopen("file.txt", "r");     ///////////////////////////////

    // dinamically allocation to the array we will save the students in.
    int max_students = 10;
    int num_students = 0;
    student_ *students = (student_ *)malloc(max_students * sizeof(student_));

    char* admin_pass = (char*)malloc(Max_string);
    fscanf(file, "%s", admin_pass);         // Read admin pass

    while (fscanf(file, "%s", students[num_students].id) == 1) {
        fscanf(file, "%s %s %s %s %d %s %d",
               students[num_students].pass,
               students[num_students].fullname[0],
               students[num_students].fullname[1],
               students[num_students].fullname[2],
               &students[num_students].age,
               students[num_students].gender,
               &students[num_students].total_grade);
        num_students++;

        if (num_students >= max_students) {
            max_students *= 2;
            students = (student_ *)realloc(students, max_students * sizeof(student_));
            if (students == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);

    // repoen the file in writing mode to replace the editted date with the old data
    file = fopen("file.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", admin_pass); // Print admin pass in the first line

    for (int i = 0; i < num_students; i++) 
    {
        if (strcmp(students[i].id, id) != 0)        // check the wanted id to be removed
        {           
            fprintf(file, "%s %s %s %s %s %d %s %d\n",
                    students[i].id,
                    students[i].pass,
                    students[i].fullname[0],
                    students[i].fullname[1],
                    students[i].fullname[2],
                    students[i].age,
                    students[i].gender,
                    students[i].total_grade);
        }
    }

    fclose(file);
    free(admin_pass);
    free(students);
}

void allowFileDeletion(){
    return;
}

void Show_record(char* id) 
{
    student_ new_student;
    FILE* file =fopen("file.txt","r");
    char* buffer = (char*) malloc(101);
    fscanf(file,"%50[^\n]",buffer);          // to skip the first line.
    fgetc(file);
    bool flag = true;
    int counter =  1;           // counter is one cause we get the id once in the main.
    while(flag)
    {
    int num = atoi(id), line = 0;
    if(Check_id(file , num ,&line ))
    flag = false ;

    if(counter == 3 && flag)
    {
        printf("\n\t===Sorry invalid data===\n");
        break;
    }

    if(flag)
    {
        printf("\t\t\tWrong ID try again: ");
        scanf("%s",id);
        counter ++;
    }

    }

    if(flag) return;

    

    while(fscanf(file,"%s",new_student.id)!= EOF)
    {

        fscanf(file, "%s %s %s %s %d %s %d", new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        
        if (!strcmp(id, new_student.id)) 
        {
        printf("\n\n\t==================================================================\n\n");
        printf("\t\t\t\t\tYOUR RECORD\n");
        printf("\t\t\t\tName        : %s %s %s\n",new_student.fullname[0],new_student.fullname[1],new_student.fullname[2]);
        printf("\t\t\t\tID          : %s\n",new_student.id);
        printf("\t\t\t\tGender      : %s\n",new_student.gender);
        printf("\t\t\t\tAge         : %d\n",new_student.age);
        printf("\t\t\t\tTotal Grade : %d\n",new_student.total_grade);
        printf("\n\t====================================================================\n");
        break;
        }
    }
    fclose(file);
}

void Show_all_records() 
{
    printf("here");
    student_ new_student;
    FILE *file =fopen("file.txt","r");
    char* buffer = (char*) malloc(Max_line);
    fscanf(file,"%199[^\n]",buffer);          // to skip the first line.
    fgetc(file);
    int i = 1 ;
    while(fscanf(file,"%s",new_student.id)!= EOF)
    {

        fscanf(file, "%s %s %s %s %d %s %d", new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        
        printf("\n\n\t===============================ROLL %d================================\n\n",i++);
        printf("\t\t\t\t\tYOUR RECORD\n");
        printf("\t\t\t\tName        : %s %s %s\n",new_student.fullname[0],new_student.fullname[1],new_student.fullname[2]);
        printf("\t\t\t\tID          : %s\n",new_student.id);
        printf("\t\t\t\tGender      : %s\n",new_student.gender);
        printf("\t\t\t\tAge         : %d\n",new_student.age);
        printf("\t\t\t\tTotal Grade : %d\n",new_student.total_grade);
        printf("\n\t====================================================================\n");
       
    }
    fclose(file);

}

void Edit_pass_admin() 
{
    FILE* file = fopen("file.txt","r+");
    int max_students = 10;
    int num_students = 0;
    student_ *students = (student_*)malloc(max_students * sizeof(student_));

    
    char* admin_pass= (char*) malloc (Max_string);
    fscanf(file, "%s", admin_pass); // Read admin pass
    while (fscanf(file, "%s", students[num_students].id) == 1) {
        fscanf(file, "%s %s %s %s %d %s %d",
               students[num_students].pass,
               students[num_students].fullname[0],
               students[num_students].fullname[1],
               students[num_students].fullname[2],
               &students[num_students].age,
               students[num_students].gender,
               &students[num_students].total_grade);
        num_students++;

        if (num_students >= max_students)           // if the array is full add a place for 10 more
        {
            max_students *= 2;
            students = (student_ *)realloc(students, max_students * sizeof(student_));
            if (students == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    rewind(file);       // make the pointer points to the 
    printf("\t\t\t============================================================");
    printf("\n\t\t\tEnter the new password: ");

    scanf("%s",admin_pass);
    fprintf(file, "%s\n", admin_pass);          // print the admin pass in the first line 

    for (int i = 0; i < num_students; i++) {
        {
            fprintf(file, "%s %s %s %s %s %d %s %d\n",
                    students[i].id,
                    students[i].pass,
                    students[i].fullname[0],
                    students[i].fullname[1],
                    students[i].fullname[2],
                    students[i].age,
                    students[i].gender,
                    students[i].total_grade);
        }
    }
    printf("\n\t\t\t=================New password edited successfully===============\n\n");

    fclose(file);
    free(students);
}

void Edit_grade(char* id) 
{
    FILE* file = fopen("file.txt","r");
    bool flag = true;
    int counter = 1 ;
    while(flag)
    {
    int num = atoi(id), line = 0;
    if(Check_id(file , num ,&line ))
    flag = false ;

    if(counter == 3 && flag)
    {
        printf("\t===Sorry invalid data===\n");
        break;
    }

    if(flag)
    {
        printf("\t\t\tWrong ID try again: ");
        scanf("%s",id);
        counter ++;
    }

    }
    file = fopen("file.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int max_students = 10;
    int num_students = 0;
    student_ *students = (student_ *)malloc(max_students * sizeof(student_));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    char admin_pass[Max_string];
    fscanf(file, "%s", admin_pass); // Read admin pass

    while (fscanf(file, "%s", students[num_students].id) == 1) {
        fscanf(file, "%s %s %s %s %d %s %d",
               students[num_students].pass,
               students[num_students].fullname[0],
               students[num_students].fullname[1],
               students[num_students].fullname[2],
               &students[num_students].age,
               students[num_students].gender,
               &students[num_students].total_grade);
        num_students++;

        if (num_students >= max_students) {
            max_students *= 2;
            students = (student_ *)realloc(students, max_students * sizeof(student_));
            if (students == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
    }


    fclose(file);


    int new_grade,  count = 3;
     printf("\t\t\t============================================================");
    while(count--) 
    {
        printf("\n\t\t\tEnter the new grade: ");
        scanf("%d", &new_grade);

        if (new_grade>=0&&new_grade<=100)  break;

        else
        printf("\n\n\t\t\t\t\t--------invalid data------\n\n");
    }

    fopen("file.txt","w");
    fprintf(file, "%s\n", admin_pass);
    for (int i = 0; i < num_students; i++) {

        if (strcmp(students[i].id, id) == 0) {
            students[i].total_grade = new_grade;
            printf("\n\t\t\t=================New grade edited successfully===============\n\n");
           
            break; 
        }
 
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s %s %s %s %s %d %s %d\n",
                students[i].id,
                students[i].pass,
                students[i].fullname[0],
                students[i].fullname[1],
                students[i].fullname[2],
                students[i].age,
                students[i].gender,
                students[i].total_grade);
    }

    fclose(file);
    free(students);
}