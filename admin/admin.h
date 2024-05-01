#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include "admin.c"

int check_pass_admin();

void ADD_new_record();

void Remove_record(char* id);

void Show_record(char* id);

void Show_all_records();

void Edit_pass_admin();

void Edit_grade(char* id );


#endif


