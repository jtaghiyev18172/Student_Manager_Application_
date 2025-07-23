#include "utils.h"

int main(){
    system("cls");
    int menu_choice;
    int students_records_choice;
    Student student_registration;
    char end_choice_add_st[2]; 
    int count = 0;
    Student *students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed for students array\n");
        return 1;
    }
    original_data = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    if (original_data == NULL) {
        fprintf(stderr, "Memory allocation failed for original_data array\n");
        free(students);
        return 1;
    }

    LoadData("students.txt", original_data, &original_count);


    while (1) {   // Main program loop
        system("cls");
        Main_Menu(&menu_choice);

        if (menu_choice == 1) {
            // Students Records menu loop
            while (1) {
                Students_Records(&students_records_choice);

                if (students_records_choice == 1) {  // Add students
                    do {
                        Add_Students(&student_registration, end_choice_add_st);

                        if (count < MAX_STUDENTS) {
                            students[count] = student_registration;
                            count++;
                        } else {
                            printf("Student list full!\n");
                            break;
                        }

                    } while (strcmp(end_choice_add_st, "a") == 0);

                    if (strcmp(end_choice_add_st, "b") == 0) {
                        for (int i = 3; i >= 1; i--) {
                            system("cls");
                            printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                            fflush(stdout);
                            Sleep(1000);
                            printf("\033[A\033[2K");
                        }
                    }
                }
                else if (students_records_choice == 2) {
                    Searching_Students();
                }
                else if (students_records_choice == 3) {
                    Filtering_Students(students, count);
                }
                else if (students_records_choice == 4) {
                    Sorting_Students();
                }
                else if (students_records_choice == 5) {
                    Print_All_Students(students);
                }
                else if (students_records_choice == 6) {
                    break;  // exit this inner loop and return to Main_Menu loop
                }
                else {
                    printf("Invalid choice, please try again.\n");
                }
            }  // End Students Records menu loop
        }
        else if (menu_choice == 2) {
            User_Guideline();
        }
        else if (menu_choice == 3) {
            About_Us();
        }
        else if (menu_choice == 4) {
            Exit_Program("students.txt");
            
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

}

