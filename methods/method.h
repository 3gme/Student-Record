#ifndef METHODS_H           // Guard
#define METHODS_H  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "method.c"
#define bool int
#define true 1
#define false 0
#define tries 3


struct student;


void Case();                                                       // determin if the user will go admin mode or user mode 
int Get_id();                                                      // get the id fron the user or the admin
void Get_pass(char* pass);                                         // get the pass from the user 
bool Check_id(FILE *f,int id,int* line_num);                       // check if the inserted id is in the file or not 
int Get_grade();                                    // gets the grade to send it to the admin
int Show_option_User();                             // display the options for the user and return his choise 
int Show_option_Admin();                            // display the optoins for the admin and return his choise 
bool Check_user_pass(FILE *f , char* pass ,int line_num);     // check if the pass the user entered match the id(true) or not(false) 
bool Log_in(FILE* f,int* line_num);                           // handles the whole login operatoin 
void Get_name(char* name[3]);

#endif