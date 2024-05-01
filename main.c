#include "methods\method.h"
#include "user\user.h"
#include "admin\admin.h"


/*---------------------START OF MAIN---------------------*/
int main()
{
    FILE *file = fopen("file.txt","r");
    fclose(file);
    int attempt =0 ;
    Case() ;                // determine if user of admin
    char ch;
    for(int i = 3 ; i > 0 ;i--)
    {
        scanf("%c",&ch);
        getchar();
        if(ch == 'a' || ch == 'u') break;       //in case of right data skip the for loop
        attempt++;
        if(attempt == 3) printf("\t----sorry invalid data----\n");
        else
        {
            printf("\twrong data try again: ");
        }
    }

    /*--------------------------------START OF ADMIN--------------------------------*/
    if(ch == 'a' )
    {
        // char* pass = (char*) malloc(Max_string);

        if(!check_pass_admin())             //admin.c
        return 1;
        fclose(file);
        bool flag1 = true,flag2 = true;
        while(flag1)
        {

            int option = Show_option_Admin();
            printf("\n");
            switch (option)
            {
            case 1:                                         // add a student record
            {
                ADD_new_record();                     
                break;
            }
                // -------------------- //

            case 2:                  // Remove a student record
            {
                char* id = (char*) malloc(Max_string);
                printf("\t\tID : ");
                scanf("%s",id);
                Remove_record(id);
                break;
            }    
                // -------------------- //

            case 3:                  // view student record
            {
                char* id = (char*) malloc(Max_string);
                printf("\t\t\tID : ");
                scanf("%s",id);
                Show_record(id) ;                  
                break;
            }
                // -------------------- //
            
            case 4:                  // show all records
            {
                Show_all_records() ;
                break;
            }
                // -------------------- //

            case 5:                  // Edit admin pass  
            {
                Edit_pass_admin();  
                break;
            }
                // -------------------- //


            case 6:                  // Edit grade for 
            {
                char id[100];
                printf("\t\t\t\t\tStudent ID : ");
                scanf("%s", id);
                Edit_grade(id);
                break;
            }
                // -------------------- //            
            }
            printf("\nDo you want to do another operation[y/n]: ");
            char ifdo;
            int i =0 ; 
            while(flag2)
            {
                if(i) printf("Invalid option..[y/n]: ");
                else i++;
                getchar();
                scanf("%c",&ifdo);
                if(ifdo == 'n') 
                {
                    flag1 = false;
                    printf("\n\n\t\t  ____THANKS FOR USING OUR STUDENT RECORD SYSTEM____\n\n");
                    break;
                }
                else if (ifdo == 'y') break;
            }
            
        }
    }
    /*-------------------------------- END OF ADMIN --------------------------------*/



    /*--------------------------------START OF USER--------------------------------*/
    else if(ch == 'u')
    {
        int line_num;               // we got the line_num from the login() and use it in the other functoins
        if(!Log_in(file,&line_num)) return 1;       
        bool flag1 = true,flag2 = true;
        while(flag1)
        {

            int option = Show_option_User();
            printf("\n");
            
            switch (option)
            {
            case 1:                   // show your record
                Show_record_user(line_num);          
                break;
            // -------------------------------- //

            case 2:             // edit pass
                {
                    char* pass = (char*) malloc(30);
                    printf("\t\t============================================================\n");
                    printf("\t\t\tEnter the new ");
                    Get_pass(pass);
                    Edit_pass_User(file,line_num,pass);          
                    break;
                }
            // -------------------------------- //
            
            case 3:             // edit name
                {
                    char* new_name[3] ;
                    Get_name(new_name);                         // methods.c
                    Edit_name(file , line_num , new_name);      // user.c
                    free(new_name[0]);
                    free(new_name[1]);
                    free(new_name[2]);
                }
                
                break;
            // -------------------------------- //
            }

            printf("\nDo you want to do another operation[y/n]: ");
            char ifdo;
            int i =0 ; 
            while(flag2)
            {
                if(i) printf("Invalid option..[y/n]: ");
                else i++;
                getchar();              // to consume the new line character
                scanf("%c",&ifdo);      
                if(ifdo == 'n') 
                {
                    flag1 = false;
                    printf("\n\n\t\t\t  ____THANKS FOR USING OUR STUDENT RECORD SYSTEM____\n\n");
                    break;
                }
                else if (ifdo == 'y') break;
            }
        }
    }

    /*-------------------------------- END OF USER --------------------------------*/

    
}
