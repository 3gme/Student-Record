#include "Methods\method.h"


/*---------------------START OF MAIN---------------------*/
int main()
{
    FILE *file;
    char ch = Case();
    printf("\n");
    /*--------------------------------START OF ADMIN--------------------------------*/
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
            if (1/*Check_id( file ,id)*/)      
            //ADD_new_record( file )                     (admin.h)  
            break;
        }
            // ------------- //

        case 2: // Remove a student record
        {
            int id = Get_id();
            if (1/*Check_id( file ,id)*/)      
            //Remove_record( file , int id)               (admin.h)  
            break;
        }    
            // ------------- //

        case 3: // view student record
        {
            int id = Get_id();
            if (1/*Check_id( file  , id)*/)
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
            if(1/*Check_id(file,id)*/)
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
    /*--------------------------------END OF ADMIN--------------------------------*/



    /*--------------------------------START OF USER--------------------------------*/
    else if(ch == 'u')
    {
        int line_num;
        if(!Log_in(file,&line_num)) return 1;
        printf("%d\n",line_num);
        
        int option = Show_option_User();
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
                //Edit_pass(file,id,pass);          (user.c)
                break;
            }
        
        case 3:
            {
                char* new_name ;
                //Edit_name(file,id,new_name)           (user.c)
            }
            
            break;
        
        default:
            //wrong data.
            break;
        }
    }
    /*--------------------------------END OF USER--------------------------------*/



    /*--------------------------------START OF MISSING DATA--------------------------------*/
    else
    {
        printf("wrong data try agian");
    }
    /*--------------------------------END OF MISSING DATA--------------------------------*/
    
}
/*---------------------END OF MAIN---------------------*/
