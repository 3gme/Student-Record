#include <stdio.h>
#define bool int
#define true 1
#define flase 0

typedef struct student
{
    /* data */
}student;

int Get_id()
{
    int id;
    //get the id
    return id;
}

int Get_grade()
{
    int grade;
    //
    return grade;
}

bool Check_id(FILE *f,int id) 
{
    //check if the id exists before
    //true if not and flase if it exists
}

char Case()
{
    //determine if user or admin
    //return char 'u' for user , 'a' for admin
}

int Show_option_Admin()
{
    int option ;
    // show the admin options 
    // take the option number in option and return it
    return option; 
}

int Show_option_User()
{
    int option ;
    // show the user options 
    // take the option number in option and return it
    return option; 
}


int main()
{
    FILE *file;
    char ch = Case();
    if(ch == 'a' )
    {
        int pass ;
        scanf("%d",&pass);
        // if(check_pass(file,pass))                         (admin.h)
        // do ... 

        // show options for the admin to choose what to do
        int option = Show_option_Admin();
        switch (option)
        {
        case 1: // add a student record
        {
            int id = Get_id();
            if (check_id( file ,id))      
            //ADD_new_record( file )                     (admin.h)  
            break;
        }
            // ------------- //

        case 2: // Remove a student record
        {
            int id = Get_id();
            if (!check_id( file ,id))      
            //Remove_record( file , int id)               (admin.h)  
            break;
        }    
            // ------------- //

        case 3: // view student record
        {
            int id = Get_id();
            if (!ckeck_id( file  , id))
            //Show_record(file , id)                   (admin.h)  
            break;
        }
            // ------------- //
        
        case 4: // show all records
        {
            //Show_all_records(file) 

            break;
        }
            // ------------ //

        case 5: // Edit admin pass   ... admin bass will be in the first line of the file
        {
            // ask to get the new pass in int pass 
            //Edit_pass(file,pass)                        (admin.h)

            break;
        }
            // ------------ //

        case 6: // Edit studint grade
        {
            int id = Get_id();
            if(!Check_id(file,id))
            {
            
            int new_grade = Get_grade();
            //Edit_grade(file,new_grade)                  (admin.h)
            }

                break;
        }
            // ------------ //

        
        default:
            // wrong data
            break;
        }
    }
    else if(ch == 'u')
    {
        int option = Show_option_User();
        int id ; 
        // get id
        if(!Check_id(file ,id)) 
        {
            //int pass
            //Get_pass 
            //check_pass(pass)
        }
        
        switch (option)
        {
        case 1: // show your record
        //Show_record(file ,id)          (user.c)
            break;
         // -------------- //
        case 2:
            {
                int pass;
                //get the new pass 
                //Edit_pass(file,id,pass);
                break;
            }
        
        case 3:
            {
                char* new_name ;
                //Edit_name(file,id,new_name)
            }
            
            break;
        
        default:
            //wrong data.
            break;
        }
    }
    else printf("wrong data try agian");
    
}
