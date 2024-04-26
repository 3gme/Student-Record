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





bool Check_id_admin(FILE* file,char* id)                        //returns true if the id isn't there in the file before
{
    char admin_pass[Max_string] , current_id[Max_string];
    while(true)
    {
        
        file = fopen("file.txt", "r");
        
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
                rewind(file);
            }
            else 
            {                
                char* buffer = (char*) malloc(Max_line);
                fscanf(file,"%200[^\n]",buffer);
                fgetc(file);
            }
        }
            fclose(file);
            return true;
    }
    fclose(file);
}

bool check_pass_admin(FILE *file) 
{
    char pass    [Max_string]; 
    char password[Max_string];
    int count = 3;
    file = fopen("file.txt","r");
    if (file == NULL) 
    {
        printf("Error opening file here.\n");
        return false;
    }

    while (fscanf(file, "%s", pass) != EOF) 
    {
        while(count) 
        {
            printf("password : ");
            scanf("%s", password);
            if (!strcmp(pass, password)) 
            {
                printf("Welcome .^_^.\n");
                return true;
            } else 
            {
                count--;
                if(count)
                printf("Sorry, password is wrong! Try again\n");
            }
        } 
    }
    printf("Sorry _, No more tries ...\n");
    
    return false;
}


void ADD_new_record(FILE *file) 
{
    student_ new_student;
    file = fopen("file.txt", "a");
    
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
        if(Check_id_admin(file,new_student.id))
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

void Remove_record(FILE* file, char* id) {
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
        printf("Wrong ID try again: ");
        scanf("%s",id);
        counter ++;
    }

    }

    file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int max_students = 10;
    int num_students = 0;
    student_ *students = (student_ *)malloc(max_students * sizeof(student_));

    char* admin_pass = (char*)malloc(Max_string);
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

    file = fopen("file.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", admin_pass); // Print admin pass in the first line

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) != 0) {
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

void Show_record(FILE* file, char* id) 
{
    student_ new_student;
    file =fopen("file.txt","r");
    char* buffer = (char*) malloc(101);
    fscanf(file,"%50[^\n]",buffer);          // to skip the first line.
    fgetc(file);
    
    

    while(fscanf(file,"%s",new_student.id)!= EOF)
    {

        fscanf(file, "%s %s %s %s %d %s %d", new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        
        if (!strcmp(id, new_student.id)) 
        {
        printf("\n\n\t==================================================================\n\n");
        printf("\t\t\t\t\tYOUR RECORD\n");
        printf("\t\t\t\tName        : %s %s %s\n",new_student.fullname[0],new_student.fullname[1],new_student.fullname[2]);
        printf("\t\t\t\tGender      : %s\n",new_student.gender);
        printf("\t\t\t\tAge         : %d\n",new_student.age);
        printf("\t\t\t\tTotal Grade : %d\n",new_student.total_grade);
        printf("\n\t====================================================================\n");
        break;
        }
    }
    fclose(file);
}

void Show_all_records(FILE* file) 
{
    printf("here");
    student_ new_student;
    file =fopen("file.txt","r");
    char* buffer = (char*) malloc(101);
    fscanf(file,"%50[^\n]",buffer);          // to skip the first line.
    fgetc(file);
    int i = 1 ;
    while(fscanf(file,"%s",new_student.id)!= EOF)
    {

        fscanf(file, "%s %s %s %s %d %s %d", new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        
        printf("\n\n\t===============================ROLL %d================================\n\n",i++);
        printf("\t\t\t\t\tYOUR RECORD\n");
        printf("\t\t\t\tName        : %s %s %s\n",new_student.fullname[0],new_student.fullname[1],new_student.fullname[2]);
        printf("\t\t\t\tID          : %s\n",new_student.gender);
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
    printf("Enter the new pass: ");
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

    fclose(file);
    free(students);
}


void Edit_grade(FILE *file, char* id, int newgrade) {
    // Open the file for reading and writing
    file = fopen("file.txt", "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int max_students = 10;
    int num_students = 0;
    student_ *students = (student_*)malloc(max_students * sizeof(student_));

    // Read admin pass
    char* admin_pass = (char*)malloc(Max_string);
    fscanf(file, "%s", admin_pass);

    // Read student records
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

        // Resize array if necessary
        if (num_students >= max_students) {
            max_students *= 2;
            students = (student_*)realloc(students, max_students * sizeof(student_));
            if (students == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    rewind(file); // Reset file pointer to beginning

    // Write admin pass
    fprintf(file, "%s\n", admin_pass);

    // Write student records with updated grade
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            students[i].total_grade = newgrade;
        }
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
    free(admin_pass);
    free(students);
}
 
