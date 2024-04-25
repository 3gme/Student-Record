#include "Student-Record-main.c\Methods\method.h"
#include "Student-Record-main.c\user.h"



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


int main() {
    FILE *file;
    char ch;

    // Prompt the user to choose mode (admin or user)
    int attempts = 3;
    do {
        printf("Will you go user or admin ('u' for user, 'a' for admin): ");
        scanf(" %c", &ch);
        if (ch == 'a' || ch == 'u') {
            break; // Break the loop if a valid input is provided
        } else {
            attempts--;
            if (attempts == 0) {
                printf("You've exceeded the maximum number of attempts. Exiting...\n");
                return 1; // Exit the program
            } else {
                printf("Invalid input. Please enter 'u' for user mode or 'a' for admin mode.\n");
            }
        }
    } while (attempts > 0);

    // Process user choice
    if (ch == 'a') {
        int pass;
        printf("Enter admin password: ");
        scanf("%d", &pass);
        // Validate admin password (to be implemented)
        // if(check_pass(file, pass)) {
        //     // Admin authenticated
        //     // Implement admin actions here
        // } else {
        //     printf("Incorrect password. Exiting...\n");
        // }
    } else if (ch == 'u') {
        // User mode
        int line_num;
        if (!Log_in(file, &line_num)) {
            printf("Login failed. Exiting...\n");
            return 1;
        }

        char choice;
        do {
            // Show user options
            int option = Show_option_User();
            switch (option) {
                case 1: // Show record
                    Show_record(file, line_num);
                    break;
                case 2: // Edit password
                {
                    char *pass = (char *)malloc(30);
                    printf("Enter the new password: ");
                    Get_pass(pass);
                    Edit_pass(file, line_num, pass);
                    free(pass);
                    break;
                }
                case 3: // Edit name
                {
                    char *new_name[3];
                    Get_name(new_name);
                    Edit_name(file, line_num, new_name);
                    free(new_name[0]);
                    free(new_name[1]);
                    free(new_name[2]);
                    break;
                }
                default:
                    printf("Invalid option.\n");
                    break;
            }

            // Ask if the user wants to perform another action
            printf("Do you want to perform another action? (Y/N): ");
            scanf(" %c", &choice);
        } while (choice == 'Y' || choice == 'y');
    }

    return 0;
}
