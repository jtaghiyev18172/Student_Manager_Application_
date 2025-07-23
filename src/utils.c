#include "utils.h"

void About_Us(){
    char temp[100];
    int first_try = 1;
    

    system("cls");
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t             Who are We?                    |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    Sleep(700);
    printf("We are a team of passionate programmers who turn complex problems into elegant solutions.\n");
    printf("\tTogether, we build smart, efficient code that speaks louder than words.");

    Sleep(1500);
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t        Members of the Team                 |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    Sleep(800);
    printf("\tMember 1:\n");
    printf("\t------------------------\n");
    printf("\tName: Nihat Shukurov\n");
    printf("\tFaculty: BSIT-2028\n");
    printf("\tSkills: Cybersecurity, Python, C, C++\n");
    printf("\tContact: shukurov20465@ada.edu.az\n\n\n\n\n\n");

    Sleep(800);
    printf("\tMember 2:\n");
    printf("\t------------------------\n");
    printf("\tName: Omar Mustafayev\n");
    printf("\tFaculty: BAIS-2026\n");
    printf("\tSkills: Cybersecurity, Cloud Computing, Python, C, Golang\n");
    printf("\tContact: omustafayev11265@ada.edu.az\n\n\n\n\n\n");

    Sleep(800);
    printf("\tMember 3:\n");
    printf("\t------------------------\n");
    printf("\tName: Javad Taghiyev\n");
    printf("\tFaculty: BSCS-2026\n");
    printf("\tSkills: Machine Learning, Python, C\n");
    printf("\tContact: jtaghiyev18172@ada.edu.az@ada.edu.az\n\n\n\n\n\n");
     
        while (1) {
        if (!first_try) {
            printf("\033[A\033[2K");
            printf("\033[A\033[2K");
        }

        printf("\t\t\t\t Please enter 'b' for going to back: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try = 0;
            continue;
        }

        // Remove newline
        temp[strcspn(temp, "\n")] = 0;

        // Check if input is exactly one character and it is 'b'
        if (strlen(temp) != 1 || temp[0] != 'b') {
            printf("Invalid input! Please enter only the letter 'b'.\n");
            first_try = 0;
            continue;
        }
        break;
    }

        for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K");
            }
    return;

}

void Exit_Program(const char* filename) {
    Student current_data[MAX_STUDENTS];
    int current_count = 0;

    LoadData(filename, current_data, &current_count);

    if (CompareData(original_data, original_count, current_data, current_count) == 0) {
        system("cls");
        printf("\t\t\t-----------------------------------------------------\n");
        printf("\t\t\t|       No Changing Detected Existing....            |\n");
        printf("\t\t\t-----------------------------------------------------\n");
        Sleep(2000);
        for (int i = 3; i >= 1; i--) {
            system("cls");
            printf("\n\t\t\t\t\t\tExisting Program %d...\n", i);
            fflush(stdout);
            Sleep(1000);
            printf("\033[A\033[2K"); // Move up and clear the entire line
            }
        exit(0);
    } else {

        system("cls");
        printf("\t\t\t-----------------------------------------------------\n");
        printf("\t\t\t|               Changing Detected.....              |\n");
        printf("\t\t\t-----------------------------------------------------\n\n\n");

        char temp[100];
        char choice;
        int first_try = 1;

        while (1) {
            if (!first_try) {
                printf("\033[A\033[2K"); // Clear error message
                printf("\033[A\033[2K"); // Clear prompt line
            }

            printf("Do you want to save changes in database? (y/n): ");
            fflush(stdout);

            if (!fgets(temp, sizeof(temp), stdin)) {
                printf("Input error. Try again.\n");
                first_try = 0;
                continue;
            }

            temp[strcspn(temp, "\n")] = 0; // Remove newline

            if (strlen(temp) == 1 && (temp[0] == 'Y' || temp[0] == 'y' || temp[0] == 'N' || temp[0] == 'n')) {
                choice = temp[0];
                break; // Valid input
            } else {
                printf("Invalid input! Please enter only Y or N.\n");
                first_try = 0;
            }
        }



        if (choice == 'Y' || choice == 'y') {
            printf("Changes saved. Exiting...\n");
            Sleep(1500);
            for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\t\t\tExisting Program %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K"); // Move up and clear the entire line
                }
            exit(0);

        } else {
            SaveData(filename, original_data, original_count);
            printf("Changes discarded. Exiting...\n");
            Sleep(1500);
            for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\t\t\tExisting Program %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K"); // Move up and clear the entire line
                }
            exit(0);
        }
    }
}

int Letter_Checker(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha((unsigned char)str[i])) {
            return 0;  // Found non-letter character
        }
    }
    return 1;
}

void Main_Menu(int *pMenu_Choose){

    int number;
    int debug_menu;
    int wrong_input = 0;
    printf("\n");
    printf("\t\t\t\t***Student Management System Using C***\n\n\n");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|\t\t     Main Menu                      |\n");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|\t\t[1] Students' Records               |\n\n");
    printf("\t\t\t|\t\t[2] User Guideline                  |\n\n");
    printf("\t\t\t|\t\t[3] About Us                        |\n\n");
    printf("\t\t\t|\t\t[4] Exit The Program                |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    while (1) {

        if (wrong_input) {
            printf("\033[A\033[2K"); // it is just deleting the current line not all of them.
            printf("\t\t\tPlease choose the RIGHT section!!!: ");
        } else {
            printf("\t\t\tPlease the section you want to enter: ");
        }

        debug_menu = scanf("%d", &number);

        if (debug_menu != 1 || number < 1 || number > 4) {
            while (getchar() != '\n'); 
            wrong_input = 1; 
            continue;
        }

        *pMenu_Choose = number;
        break; 
    }
}

void Students_Records(int *pStudents_Records){


    int number_st_rec;
    int debug_st_rec;
    int wrong_input_st_re = 0;


    system("cls");
    printf("\n");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|\t\t   Students Records                 |\n");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|\t\t[1] Add New Student                 |\n\n");
    printf("\t\t\t|\t\t[2] Searching Students              |\n\n");
    printf("\t\t\t|\t\t[3] Filtering Students              |\n\n");
    printf("\t\t\t|\t\t[4] Sorting Students                |\n\n");
    printf("\t\t\t|\t\t[5] List All Students               |\n\n");
    printf("\t\t\t|\t\t[6] Go Back                         |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");

     while (1) {

        if (wrong_input_st_re) {
            printf("\033[A\033[2K");
            printf("\t\t\tPlease choose the RIGHT section!!!: ");
        } else {
            printf("\t\t\tPlease the section you want to enter: ");
        }

        debug_st_rec = scanf("%d", &number_st_rec);

        if (debug_st_rec != 1 || number_st_rec < 1 || number_st_rec > 6) {
            while (getchar() != '\n'); 
            wrong_input_st_re = 1; 
            continue;
        }
        *pStudents_Records = number_st_rec;
        break; 
    }
    


}

void User_Guideline(){
    char temp[100];
    int first_try = 1;

    system("cls");
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t      Welcome to the Our Program            |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");

    Sleep(1500);
    system("cls");
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|        While You are using the Program...         |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");

    Sleep(2000);
    system("cls");
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|    There are Some Rules that you MUST follow!!!   |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");

    printf("\t[1] Please While using the Program enjoy the All features:)))))\n");
    printf("\t-------------------------------------------------------------------------------\n");
    Sleep(1200);
    printf("\t[2] Please don't try to TRICK input giving wrong information!!!\n");
    printf("\t-------------------------------------------------------------------------------\n");
    Sleep(1200);
    printf("\t[3] If you find GAPS related to Program tell our Programmers\n");
    printf("\t-------------------------------------------------------------------------------\n");
    Sleep(1200);
    printf("\t[4] If You exit the Program with Ctrl+C, Database will update automatically!!!\n");
    printf("\t-------------------------------------------------------------------------------\n");
    Sleep(1200);
    printf("\t[5] SEE YOU SOOOOONNNNNNN in NEW PROJECTSSSSSS DEAR USER\n");
    printf("\t-------------------------------------------------------------------------------\n");

    Sleep(1000);
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t    Thank You For Choosing Us :)            |\n");
    printf("\t\t\t-----------------------------------------------------\n\n\n\n");
    Sleep(3000);

     while (1) {
        if (!first_try) {
            printf("\033[A\033[2K");
            printf("\033[A\033[2K");
        }

        printf("\t\t\t\t Please enter 'b' for going to back: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try = 0;
            continue;
        }

        // Remove newline
        temp[strcspn(temp, "\n")] = 0;

        // Check if input is exactly one character and it is 'b'
        if (strlen(temp) != 1 || temp[0] != 'b') {
            printf("Invalid input! Please enter only the letter 'b'.\n");
            first_try = 0;
            continue;
        }
        break;
    }

    for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K");
            }
    return;

}

