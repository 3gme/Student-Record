#include <stdio.h>
#define bool int 
#define true 1
#define false 0


void Show_record(FILE *file ,int id);

void Edit_pass(FILE *file ,int id ,int pass);

void Edit_name(FILE *file , int id , char* name);
