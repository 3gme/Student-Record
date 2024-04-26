#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include "admin.c"

int check_pass_admin();

void ADD_new_record(FILE *file);

void Remove_record(FILE *file , char* id);

void Show_record(FILE *file ,char* id);

void Show_all_records(FILE *file);

void Edit_pass_admin();

void Edit_grade(FILE *file , char* id );


#endif


