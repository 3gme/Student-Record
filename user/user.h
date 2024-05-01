#ifndef USER_H
#define USER_H

#include <stdio.h>
#include "user.c"


#define bool int 
#define true 1
#define false 0

struct student;

void Show_record_user(int line_num);

void Edit_pass_User(FILE *file ,int line_num ,char* new_pass);

void Edit_name(FILE *file , int line_num , char* name[3]);

#endif