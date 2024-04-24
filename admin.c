#include <stdio.h>
#define bool int 
#define true 1
#define false 0


int Show_option_Admin() 
{
    int option;
    printf("1: Add record of the student.\n");
    printf("2: Remove record of the student.\n");
    printf("3: Show record of the student.\n");
    printf("4: Show all records of the student.\n");
    printf("5: Edit password of the student.\n");
    printf("6: Edit grade of the student.\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}


bool check_pass(FILE *file, const char *pass) 
{
    char Password[20];
    int count = 3;
    while (count != 0) 
    {
        if (fscanf(file, "%s", Password) == 1) 
        {
            if (strcmp(pass, Password) == 0) 
            {
                printf("Welcome .^_^.\n");
                return true;
            } else 
            {
                count--;
                printf("Sorry, password is wrong! Try again\n");
            }
        } else 
        {
            printf("Error reading password from file\n");
            return false;
        }
    }
    printf("Sorry *_*, No more tries ...\n");
    return false;
}


void ADD_new_record(FILE *file)
{
    file = fopen("file.txt", "a");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    char id[20];
    char pass[100];
    char fullname[3][100];
    int age;
    char gender[8];
    int total_grade;
    
    printf("Enter student information:\n");
    printf("Full Name : ");
    for (int i = 0; i < 3; i++) 
    {
        scanf("%s", fullname[i]);
    }
    printf("Password: ");
    scanf("%s", pass);
    printf("ID: ");
    scanf("%s", &id);
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender: ");
    scanf(" %s", &gender);
    printf("Total Grade: ");
    scanf("%d", &total_grade);

    fprintf(file, "%s %s %s %s %s %d %s %d\n",fullname[0], fullname[1], fullname[2], pass, id, age, gender, total_grade);

    printf("New student added successfully.\n");
    fclose(file);
}

void Remove_record(FILE *file, char* id) 
{
    file = fopen("file.txt", "w");
    char current_id[20];
    char fullname[3][100];
    char pass[100];
    int age;
    char gender;
    int total_grade;
    while (fscanf(file, "%s %s %s %s %s %s %d", fullname[0], fullname[1], fullname[2], pass, current_id, &age ,gender, &total_grade) == 8) 
    {
        if (!strcmp(id, current_id)) 
        {
            for (int i = 0; i < 3; i++)
            {
                remove(fullname[i]);
            }
            remove(pass);
            remove(current_id);
            remove(age);
            remove(gender);
            remove(total_grade);
            printf("successfully removed");
        }
    }
    fclose(file);
}

void Show_record(FILE *file ,char* id)
{
    file = fopen("file.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    char _id[20];
    char fullname[3][100];
    char pass[100];
    int age;
    char gender[7];
    int total_grade;

    while (fscanf(file, "%s %s %s %s %s %d %s %d", fullname[0], fullname[1], fullname[2], pass, _id, &age, gender, &total_grade) == 8) 
    {
        if (strcmp(id, _id)==0) 
        {
            printf("Full Name: %s %s %s\n", fullname[0], fullname[1], fullname[2]);
            printf("Password: %s\n", pass);
            printf("ID: %s\n", _id);
            fclose(file);
            return;
        }
    }
    printf("Record not found for ID: %s\n", id);
    fclose(file);
}


void Show_all_records(FILE *file,char* id) 
{
    file = fopen("file.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    char _id[20];
    char fullname[3][100];
    char pass[100];
    int age;
    char gender[7];
    int total_grade;

    while (fscanf(file, "%s %s %s %s %s %d %s %d", fullname[0], fullname[1], fullname[2], pass, _id, &age, gender, &total_grade) == 8) 
    {
        if (strcmp(id, _id)==0) 
        {
            printf("Full Name: %s %s %s\n", fullname[0], fullname[1], fullname[2]);
            printf("Password: %s\n", pass);
            printf("ID: %s\n", _id);
            printf("Age: %d\n", age);
            printf("Gender: %s\n", gender);
            printf("Total Grade: %d\n", total_grade);
            fclose(file);
            return;
        }
    }
    printf("Record not found for ID: %s\n", id);
    fclose(file);
}

void Edit_pass(FILE *file, char* id) 
{
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    char line[300]; // Assuming each line has at most 300 characters
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        fprintf(temp_file, "%s", line);
    }

    fclose(temp_file);
    fclose(file);

    // Reopen the original file for reading
    file = fopen("file.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }

    char _id[20];
    char fullname[3][100];
    char pass[100];
    int age;
    char gender[7];
    int total_grade;

    while (fscanf(file, "%s %s %s %s %s %d %s %d", fullname[0], fullname[1], fullname[2], pass, _id, &age, gender, &total_grade) == 8) 
    {
        if (!strcmp(id, _id)) 
        {
            char newpass[100];
            printf("Enter new password: ");
            scanf("%s", newpass);
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", fullname[0], fullname[1], fullname[2], newpass, _id, age, gender, total_grade);
            printf("Password updated successfully.\n");
        } 
        else 
        {
            // If the ID is not the one to edit, write the record as is to the temp file
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", fullname[0], fullname[1], fullname[2], pass, _id, age, gender, total_grade);
        }
    }

    fclose(temp_file);
    fclose(file);

    remove("file.txt"); 
    rename("temp.txt", "file.txt"); 
}




void Edit_grade(FILE *file, char* id) 
{
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    char line[300]; // Assuming each line has at most 300 characters
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        fprintf(temp_file, "%s", line);
    }

    fclose(temp_file);
    fclose(file);

    // Reopen the original file for reading
    file = fopen("file.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }

    char _id[20];
    char fullname[3][100];
    char pass[100];
    int age;
    char gender[7];
    int total_grade;

    while (fscanf(file, "%s %s %s %s %s %d %s %d", fullname[0], fullname[1], fullname[2], pass, _id, &age, gender, &total_grade) == 8) 
    {
        if (strcmp(id, _id) == 0) 
        {
            int new_grade;
            printf("Enter new grade: ");
            scanf("%d", &new_grade);
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", fullname[0], fullname[1], fullname[2], pass, _id, age, gender, new_grade);
            printf("Grade updated successfully.\n");
        } 
        else 
        {
            // If the ID is not the one to edit, write the record as is to the temp file
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", fullname[0], fullname[1], fullname[2], pass, _id, age, gender, total_grade);
        }
    }

    fclose(temp_file);
    fclose(file);

    remove("file.txt"); 
    rename("temp.txt", "file.txt"); 
}