#include "Methods\method.h"
#include "user.h"


/*
1234
1000263279 10203040mahmoud first_name second_name third_name 19 male 98
1000263278 10203040 first_name second_name third_name 19 male 98
1000263277 10203040 first_name second_name third_name 19 male 98
1000263276 10203040 first_name second_name third_name 19 male 98
1000263275 10203040 first_name second_name third_name 19 male 98
1 1 m e z 19 female 90
*/

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
        int option = Show_option_User();
        
        switch (option)
        {
        case 1:                   // show your record
        Show_record(file ,line_num);          
            break;
         // -------------- //

        case 2:             // edit pass
            {
                char* pass = (char*) malloc(30);
                printf("enter the new ");
                Get_pass(pass);
                Edit_pass(file,line_num,pass);          
                break;
            }
        
        case 3:             // edit name
            {
                char* new_name[3] ;
                Get_name(new_name);
                Edit_name(file , line_num , new_name);
                free(new_name[0]);
                free(new_name[1]);
                free(new_name[2]);
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
