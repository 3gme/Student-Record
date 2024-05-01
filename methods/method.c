/*---------------------START OF HASHS---------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define Max_string  30
#define Max_line  200
#define bool int
#define true 1
#define false 0
#define tries 3
/*---------------------END OF HASHS---------------------*/


/*---------------------START OF STRUCTS---------------------*/
typedef struct student{
int id;
char pass[Max_string];
char* fullname[3];
int age;
char gender[Max_string];
int total_grade;
}student;
/*---------------------END OF STRUCTS---------------------*/



/*---------------------START OF FUNCTOINS---------------------*/
void Case()                                         // determin if the user will go admin mode or user mode 
{
    printf("\t\t---------Welcome to our Student Record system---------\n");
    printf("\t\tWill you go user or admin ('u' for user,'a' for admin): ");
}

int Get_id()                                        // get the id fron the user or the admin
{
    int id;
    printf("\t\t\tID: ");
    scanf("%d",&id);
    return id;
}

void Get_pass(char* pass)                           // get the pass from the user 
{
   printf("Password: ");
   scanf("%s",pass);
}

// check if the inserted id is in the file or not and return true in case of the id is in the file. 
bool Check_id(FILE *f,int id,int* line_num)         
{
    f =fopen("file.txt","r");
    char* buffer = (char*) malloc(Max_line);
    fscanf(f,"%199[^\n]",buffer);          // to skip the first line.
    int _id , current_line = 1;
    while(fscanf(f,"%d",&_id) != EOF)
    {
        if(_id == id)   
        {
            *line_num = current_line;
            fclose(f);
            return true;
        }
        else
        {
            fscanf(f,"%199[^\n]",buffer);          // to skip the rest of the line.
        }
        current_line++;
    }
    fclose(f);
    return false;
}

int Get_grade()                                     // gets the grade to send it to the admin
{
    int grade;
    scanf("%d",&grade);
    return grade;
}

int Show_option_User()                              // display the options for the user and return his choise 
{
    int option ;
    bool flag = true;
    int counter = 0  ; 
    printf("\n\n\t\t\t ______________________________________\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       1. View your record            |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       2. Edit your password          |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       3. Edit your name              |\n");
    printf("\t\t\t|______________________________________|\n");
    printf("\n\n\t\tEnter the option's number : ");
    while(flag && counter != tries)
    {
        if(counter != 0 ) printf("\t\tinvalid option try again: ");    
        scanf("%d",&option);
        if(option > 0 && option < 4) flag = false;
        else counter ++ ;
    }
    if(counter == tries)
    {
        printf("\n\t\t---SORRY WRONG DATA---");
        return -1;
    }
    return option; 
}

int Show_option_Admin()                             // display the optoins for the admin and return his choise 
{
    int option ;
    bool flag = true;
    int counter = 0  ; 
    printf("\t\t\t ______________________________________\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       1. Add student record          |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       2. Remove student record       |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       3. View student record         |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       4. View all records            |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       5. Edit admin password         |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       6. Edit student grade          |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|______________________________________|\n");
    printf("\n\n\t\tEnter the option's number : ");
    while(flag && counter != tries)
    {
        if(counter != 0 ) printf("\t\tinvalid option try again: ");    
        scanf("%d",&option);
        if(option > 0 && option < 7) flag = false;
        else counter ++ ;
    }
    if(counter == tries)
    {
        printf("\n\t\t---SORRY WRONG DATA---");
        return -1;
    }
    return option; 
}

bool Check_user_pass(FILE *f , char* pass)          // check if the pass the user entered match the id(true) or not(false) 
{

    f =fopen("file.txt","r");
    char* buffer = (char*) malloc(101);
    fscanf(f,"%200[^\n]",buffer);          // to skip the first line.
    char* _pass = (char*) malloc(20);
    int id;
    while(fscanf(f,"%d",&id)!= EOF)
    {
        fscanf(f," %s",_pass);
        if(!strcmp(_pass,pass))  
        {
            fclose(f);
            return true;
        } 
        else
        {
            fscanf(f,"%200[^\n]",buffer);          // to skip the rest of the line.

        }
    }
    fclose(f);
    return false;
}

bool Log_in(FILE* f,int *line_num)                                // handles the whole login operatoin 
{
    char* pass = (char*) malloc(Max_string);
    int counter = 3;
    bool flag = false;                    // control getting pass part

    while(counter --)                   
    {
        int id = Get_id();
        if(Check_id(f ,id,line_num))       // check the id and determine which line too.
        {
            flag = true;
            break;
        }
        else 
        {   
            if(counter)
                printf("\t\t\tInvalid ID try again \n");
        }
    }

    if(flag) 
    {
        counter = 3 ;
        while(counter--)
        {
            printf("\t\t\t");
            Get_pass(pass);
            if(Check_user_pass(f,pass)) 
            {
                free(pass);
                return true;                
            }
            else if(counter)
            {
                printf("\a\t\t\twrong password try again\n");
            }
        }
    }
        if(counter == -1)                   // checking by -1 cuz when the while's postfix decrement     ...
        {
            printf("\a\t\t\tsorry wrong data");
            free(pass);
            return false;
        }
    return false;
}

void Get_name(char* name[3])            
{
    name[0] = (char*) malloc(50);
    name[1] = (char*) malloc(50);
    name[2] = (char*) malloc(50);
    printf("\t\t================Enter you new name================\n");
    printf("\n\t\t\t\tFirst Name  : ");
    scanf("%s",name[0]);
    printf("\t\t\t\tSecond Name : ");
    scanf("%s",name[1]);
    printf("\t\t\t\tThird Name  : ");
    scanf("%s",name[2]);
    printf("\n\t\t============Name changed successfully===========\n");

}
/*---------------------END OF FUNCTOINS---------------------*/


