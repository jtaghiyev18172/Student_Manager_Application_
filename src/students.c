#include "students.h"
#include "utils.h"

// Global variable definitions
FILE *Add_St;
FILE *Srch_Stdnt;
FILE *Update_Edits;
FILE *Delete_Students;
FILE *Sort_Stdnt;
FILE *Print_All_Stdnts;
FILE *Filter_Stdnt;
FILE *FIrst_Reading_DB;
Student *original_data = NULL;
int original_count = 0;

void Add_Students(Student *Add_St, char *end_choice_add_st){
    system("cls");  
    char temp[100];
    int first_try_first_name = 1;
    int first_try_last_name = 1;
    int first_try_faculty = 1;
    int first_try_country = 1;
    int first_try_city = 1;
    int first_try_age = 1;
    int first_try_id = 1;
    int first_try_gpa = 1;
    int first_try_email = 1;
    int age;
    int id;
    float gpa;

    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  Please enter the Student's information correctly |\n");
    printf("\t\t\t-----------------------------------------------------\n\n\n");
    

    while (1) {
        if (!first_try_first_name) {
        
            printf("\033[A\033[2K");
        
            printf("\033[A\033[2K");
        }
        
        printf("\t | [1] Enter Student's First Name: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_first_name = 0;
            continue;
        }
        temp[strcspn(temp, "\n")] = 0;  

        if (strlen(temp) == 0 || !Letter_Checker(temp)) {
            printf("Invalid input! Please enter only letters and not empty.\n");
            first_try_first_name = 0;
            continue;
        }

    
        strncpy(Add_St->name.first_name, temp, sizeof(Add_St->name.first_name));
        Add_St->name.first_name[sizeof(Add_St->name.first_name) - 1] = '\0';
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_last_name) {
        
            printf("\033[A\033[2K");
        
            printf("\033[A\033[2K");
        }

        printf("\t | [2] Enter Student's Last Name: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_last_name = 0;
            continue;
        }
        temp[strcspn(temp, "\n")] = 0;  

        if (strlen(temp) == 0 || !Letter_Checker(temp)) {
            printf("Invalid input! Please enter only letters and not empty.\n");
            first_try_last_name = 0;
            continue;
        }

    
        strncpy(Add_St->name.last_name, temp, sizeof(Add_St->name.last_name));
        Add_St->name.last_name[sizeof(Add_St->name.last_name) - 1] = '\0';
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_faculty) {
        
            printf("\033[A\033[2K");
        
            printf("\033[A\033[2K");
        }
        
        printf("\t | [3] Enter Student's Faculty: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_faculty = 0;
            continue;
        }
        temp[strcspn(temp, "\n")] = 0;  

        if (strlen(temp) == 0 || !Letter_Checker(temp)) {
            printf("Invalid input! Please enter only letters and not empty.\n");
            first_try_faculty = 0;
            continue;
        }

    
        strncpy(Add_St->faculty, temp, sizeof(Add_St->faculty));
        Add_St->faculty[sizeof(Add_St->faculty) - 1] = '\0';
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_country) {
        
            printf("\033[A\033[2K");
        
            printf("\033[A\033[2K");
        }
        
        printf("\t | [4] Enter Student's Country: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_country = 0;
            continue;
        }
        temp[strcspn(temp, "\n")] = 0;  

        if (strlen(temp) == 0 || !Letter_Checker(temp)) {
            printf("Invalid input! Please enter only letters and not empty.\n");
            first_try_country = 0;
            continue;
        }

    
        strncpy(Add_St->location.country, temp, sizeof(Add_St->location.country));
        Add_St->location.country[sizeof(Add_St->location.country) - 1] = '\0';
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_city) {
        
            printf("\033[A\033[2K");
        
            printf("\033[A\033[2K");
        }
        
        printf("\t | [5] Enter Student's City: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_city = 0;
            continue;
        }
        temp[strcspn(temp, "\n")] = 0;  

        if (strlen(temp) == 0 || !Letter_Checker(temp)) {
            printf("Invalid input! Please enter only letters and not empty.\n");
            first_try_city = 0;
            continue;
        }

    
        strncpy(Add_St->location.city, temp, sizeof(Add_St->location.city));
        Add_St->location.city[sizeof(Add_St->location.city) - 1] = '\0';
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
         if (!first_try_age) {
             printf("\033[A\033[2K");  // Clear error message
            printf("\033[A\033[2K");  // Clear prompt line
        }

        printf("\t | [6] Enter Studen's Age: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_age = 0;
            continue;
        }

        temp[strcspn(temp, "\n")] = 0;  
    
        int valid = 1;
        for (int i = 0; temp[i]; i++) {
            if (!isdigit((unsigned char)temp[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid || strlen(temp) == 0) {
            printf("Invalid input! Please enter a valid number.\n");
            first_try_age = 0;
            continue;
        }

        age = atoi(temp);

        if (age < 17 || age > 70) {
            printf("Age must be between 17 and 70.\n");
            first_try_age = 0;
            continue;
        }

        Add_St->age = age;
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_id) {
            printf("\033[A\033[2K");  // Clear error message
            printf("\033[A\033[2K");  // Clear prompt line
        }

        printf("\t | [7] Enter Student's ID (20000 - 30000): ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_id = 0;
            continue;
        }

        temp[strcspn(temp, "\n")] = 0;  // Remove newline
        int valid = 1;
        for (int i = 0; temp[i]; i++) {
            if (!isdigit((unsigned char)temp[i])) {
                valid = 0;
                break;
            }
        }

         if (!valid || strlen(temp) == 0) {
            printf("Invalid input! Please enter only digits.\n");
            first_try_id = 0;
            continue;
        }

        id = atoi(temp);

        if (id < 20000 || id > 30000) {
            printf("ID must be between 20000 and 30000.\n");
            first_try_id = 0;
            continue;
        }
        Add_St->id = id;
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_gpa) {
            printf("\033[A\033[2K");  
            printf("\033[A\033[2K");  
        }

        printf("\t | [8] Enter Student's GPA (0.00 - 4.00): ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_gpa = 0;
            continue;
        }

        temp[strcspn(temp, "\n")] = 0; 

    
        int dot_count = 0, valid = 1;
        for (int i = 0; temp[i]; i++) {
            if (temp[i] == '.') {
                dot_count++;
                if (dot_count > 1) {
                    valid = 0;
                    break;
                }
            } else if (!isdigit((unsigned char)temp[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid || strlen(temp) == 0) {
            printf("Invalid input! Please enter a valid GPA number.\n");
            first_try_gpa = 0;
            continue;
        }

        gpa = atof(temp);

        if (gpa < 0.00 || gpa > 4.00) {
            printf("GPA must be between 0.00 and 4.00.\n");
            first_try_gpa = 0;
            continue;
        }

        Add_St->gpa = gpa;
        break;
    }
    printf("\t ----------------------------------------\n");
    while (1) {
        if (!first_try_email) {
            printf("\033[A\033[2K"); 
            printf("\033[A\033[2K"); 
        }

        printf("\t | [10] Enter Student's ADA Email: ");
        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try_email = 0;
            continue;
        }

        temp[strcspn(temp, "\n")] = 0; 

        if (strlen(temp) == 0) {
            printf("Email cannot be empty.\n");
            first_try_email = 0;
            continue;
        }

        const char *domain = "@ada.edu.az";
        int len_email = strlen(temp);
        int len_domain = strlen(domain);

        if (len_email < len_domain || strcmp(temp + len_email - len_domain, domain) != 0) {
            printf("Email must end with '@ada.edu.az'\n");
            first_try_email = 0;
            continue;
        }

        // Copy to struct
        strncpy(Add_St->contact.email, temp, sizeof(Add_St->contact.email));
        Add_St->contact.email[sizeof(Add_St->contact.email) - 1] = '\0';
        break;
    }
    printf("\t ----------------------------------------\n\n");
    FILE *Add_Student = fopen("students.txt", "a");
    if (Add_Student) {
        fprintf(Add_Student, "%s, %s, %d, %.2f, %d, %s, %s, %s, %s\n",
            Add_St->name.first_name,
            Add_St->name.last_name,
            Add_St->age,
            Add_St->gpa,
            Add_St->id,
            Add_St->faculty,
            Add_St->location.country,
            Add_St->location.city,
            Add_St->contact.email);
        fclose(Add_Student);
        printf("\t\t\t\tYour Student Registration is Successfully Finished!!!\n");
        printf("\t\t-------------------------------------------------------------------------------------\n");
        printf("\t\t\tGoBack(b)----------------------------------------------------AddNewSt(a)\n\n");
        printf("\t\t\t\t\t\tPlease Enter: ");
        while (1) {
            scanf("%s", end_choice_add_st);

            if (strcmp(end_choice_add_st, "a") == 0 || strcmp(end_choice_add_st, "b") == 0) {
                break;
            } 
            else {
            // Clear the previous line (move cursor up and clear line)
            printf("\033[A\033[2K");
            }
        }

    }
}

int CompareData(Student data1[], int count1, Student data2[], int count2) {
    if (count1 != count2) return 1;

    for (int i = 0; i < count1; i++) {
        if (strcmp(data1[i].name.first_name, data2[i].name.first_name) != 0) return 1;
        if (strcmp(data1[i].name.last_name, data2[i].name.last_name) != 0) return 1;
        if (data1[i].age != data2[i].age) return 1;
        if (data1[i].gpa != data2[i].gpa) return 1;
        if (data1[i].id != data2[i].id) return 1;
        if (strcmp(data1[i].faculty, data2[i].faculty) != 0) return 1;
        if (strcmp(data1[i].location.country, data2[i].location.country) != 0) return 1;
        if (strcmp(data1[i].location.city, data2[i].location.city) != 0) return 1;
        if (strcmp(data1[i].contact.email, data2[i].contact.email) != 0) return 1;
    }

    return 0; // Equal
}

void Delete_Searched_Student(int index, Student students[], int *count){
    
    if (index < 0 || index >= *count) {
        printf("Invalid index. Cannot delete.\n");
        return;
    }

    // Shift elements left
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--; // decrease the student count

    // Rewrite the file
    FILE *Delete_Students = fopen("students.txt", "w");
    if (!Delete_Students) {
        perror("Failed to update file after deletion");
        return;
    }

    for (int i = 0; i < *count; i++) {
        fprintf(Delete_Students, "%s, %s, %d, %.2f, %d, %s, %s, %s, %s\n",
                students[i].name.first_name,
                students[i].name.last_name,
                students[i].age,
                students[i].gpa,
                students[i].id,
                students[i].faculty,
                students[i].location.country,
                students[i].location.city,
                students[i].contact.email);
    }

    fclose(Delete_Students);
    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|     Student Deleted Successfully From Database    |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");

    for (int i = 5; i >= 1; i--) {
		printf("\t\t\t\tReturning to student search in %d...\n", i);
		fflush(stdout);
		Sleep(1000);
		printf("\033[A\033[2K"); // Move up and clear the entire line
	}
}

void Edit_Searched_Student(Student *s, int index, Student students[], int *count){

    int option_srch_stdnt_edit; // Option that decides which attribute we are looking for.
    int wrong_input_srch_stdnt_edit = 0;
    int debug_srch_stdnt_edit;

    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t\t  Searching Students                |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t| Please Select the Option You Want to Edit Student's information  |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t   [1] Edit The Name: %s",  s->name.first_name);
    printf("\n\t\t   [2] Edit The Surname: %s", s->name.last_name);
    printf("\n\t\t   [3] Edit The Age: %d", s->age); 
    printf("\n\t\t   [4] Edit The GPA: %f", s->gpa);
    printf("\n\t\t   [5] Edit The ID: %d", s->id); 
    printf("\n\t\t   [6] Edit The Faculty: %s", s->faculty);
    printf("\n\t\t   [7] Edit The Country: %s", s->location.country); 
    printf("\n\t\t   [8] Edit The City: %s", s->location.city);
    printf("\n\t\t   [9] Edit The Email: %s", s->contact.email);
    printf("\n\t\t--------------------------------------------------------------------\n");
    printf("\t\t|               [10] Back To Searching The Students                |\n");
    printf("\t\t--------------------------------------------------------------------\n\n");

    while (1) {
        if (wrong_input_srch_stdnt_edit) {
            printf("\033[A\033[2K");
            printf("\t\t\t\tPlease choose the RIGHT section!!!: ");
        } else {
            printf("\t\t\t\tPlease the section you want to enter: ");
        }

        debug_srch_stdnt_edit = scanf("%d", &option_srch_stdnt_edit);

        if (debug_srch_stdnt_edit != 1 || option_srch_stdnt_edit < 1 || option_srch_stdnt_edit > 10) {
            while (getchar() != '\n'); 
            wrong_input_srch_stdnt_edit = 1; 
            continue;
        }
        if (option_srch_stdnt_edit == 10) {
            for (int i = 5; i >= 1; i--) {
                    system("cls");
		            printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
		            fflush(stdout);
		            Sleep(1000);
		            printf("\033[A\033[2K"); // Move up and clear the entire line
	            }
            Searching_Students();
            break;
        }
        break; 
    }

    switch (option_srch_stdnt_edit) {
        case 1: { // Edit First Name
            char temp[100];
            int first_try = 1;
            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New First Name: ");
                fflush(stdout);
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;
                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try = 0;
                    continue;
                }
                strncpy(s->name.first_name, temp, sizeof(s->name.first_name) - 1);
                s->name.first_name[sizeof(s->name.first_name) - 1] = '\0';
                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }

        case 2: { // Edit Last Name
            char temp[100];
            int first_try = 1;
            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New Last Name: ");
                fflush(stdout);
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;
                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try = 0;
                    continue;
                }
                strncpy(s->name.last_name, temp, sizeof(s->name.last_name) - 1);
                s->name.last_name[sizeof(s->name.last_name) - 1] = '\0';
                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }
       
        case 3: { // Edit Age
            char temp[100];
            int new_age;
            int first_try = 1;

            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New Age(17-70): ");
                fflush(stdout);

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;  // remove newline

                // Check if input is numeric and convert to integer
                char *endptr;
                new_age = (int)strtol(temp, &endptr, 10);

                if (endptr == temp || *endptr != '\0' || new_age < 17 || new_age > 70) {
                    // Input is not a valid integer or out of your valid age range
                    printf("Invalid input! Please enter a valid age between 17 and 70.\n");
                    first_try = 0;
                    continue;
                }

                s->age = new_age; // assign new age

                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }
        
        case 4: { // Edit GPA
            char temp[100];
            float new_gpa;
            int first_try = 1;

            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New GPA: ");
                fflush(stdout);

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;  // remove newline

                char *endptr;
                new_gpa = strtof(temp, &endptr);

                if (endptr == temp || *endptr != '\0' || new_gpa < 0.0 || new_gpa > 4.0) {
                    printf("Invalid input! Please enter a valid GPA between 0.0 and 4.0.\n");
                    first_try = 0;
                    continue;
                }

                s->gpa = new_gpa;

                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }
        
        case 5: { // Edit ID
            char temp[100];
            int new_id;
            int first_try = 1;

            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\tPlease Enter New ID (20000 - 30000): ");
                fflush(stdout);

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;  // remove newline

                char *endptr;
                new_id = (int)strtol(temp, &endptr, 10);

                if (endptr == temp || *endptr != '\0' || new_id < 20000 || new_id > 30000) {
                    printf("Invalid input! Please enter an integer between 20000 and 30000.\n");
                    first_try = 0;
                    continue;
                }

                s->id = new_id;

                printf("\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }

        case 6: { // Edit Faculty
             
            char temp[100];
            int first_try = 1;

            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New Faculty: ");
                fflush(stdout);

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;  // remove newline

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {  // Letter_Checker should verify only letters
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try = 0;
                    continue;
                }

                strncpy(s->faculty, temp, sizeof(s->faculty) - 1);
                s->faculty[sizeof(s->faculty) - 1] = '\0';

                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }

        case 7: { // Edit Country
            char temp[100];
            int first_try = 1;

            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New Country: ");
                fflush(stdout);

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;  // remove newline

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {  // Letter_Checker should verify only letters
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try = 0;
                    continue;
                }

                strncpy(s->location.country, temp, sizeof(s->location.country) - 1);
                s->location.country[sizeof(s->location.country) - 1] = '\0';

                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }
 
        case 8: { // Edit City
    char temp[100];
    int first_try = 1;

    while (1) {
        if (!first_try) {
            printf("\033[A\033[2K");
            printf("\033[A\033[2K");
        }
        printf("\t\t\t\tPlease Enter New City: ");
        fflush(stdout);

        if (!fgets(temp, sizeof(temp), stdin)) {
            printf("Input error, try again.\n");
            first_try = 0;
            continue;
        }
        temp[strcspn(temp, "\n")] = 0;  // Remove newline

        if (strlen(temp) == 0 || !Letter_Checker(temp)) {  // Letter_Checker validates only letters
            printf("Invalid input! Please enter only letters and not empty.\n");
            first_try = 0;
            continue;
        }

        strncpy(s->location.city, temp, sizeof(s->location.city) - 1);
        s->location.city[sizeof(s->location.city) - 1] = '\0';

        printf("\n\t\t\t-----------------------------------------------------\n");
        printf("\t\t\t|      Student Information Successfully Updated     |\n");
        printf("\t\t\t-----------------------------------------------------\n\n");
        Sleep(1500);
        break;
    }
    break;
}

        case 9: { // Edit Email
            char temp[100];
            int first_try = 1;

            while (1) {
                if (!first_try) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }
                printf("\t\t\t\tPlease Enter New Email (@ada.edu.az): ");
                fflush(stdout);

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0;  // Remove newline

                // Check empty
                if (strlen(temp) == 0) {
                    printf("Invalid input! Email cannot be empty.\n");
                    first_try = 0;
                    continue;
                }

                // Check if email ends with "@ada.edu.az"
                const char *required_suffix = "@ada.edu.az";
                size_t len_temp = strlen(temp);
                size_t len_suffix = strlen(required_suffix);

                if (len_temp < len_suffix || strcmp(temp + len_temp - len_suffix, required_suffix) != 0) {
                    printf("Invalid email! It must end with %s\n", required_suffix);
                    first_try = 0;
                    continue;
                }

                // If valid, copy
                strncpy(s->contact.email, temp, sizeof(s->contact.email) - 1);
                s->contact.email[sizeof(s->contact.email) - 1] = '\0';

                printf("\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|      Student Information Successfully Updated     |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                break;
            }
            break;
        }
    }
    Save_Students_To_File(students, *count);
    system("cls");
    for (int i = 5; i >= 1; i--) {
		printf("\t\t\t\tReturning to Student Search in %d...\n", i);
		fflush(stdout);
		Sleep(1000);
		printf("\033[A\033[2K"); // Move up and clear the entire line
	}
    Searching_Students();
}

void Filtering_Students(Student* students, int count){
    
    int option_filter_stdnt; // Option that decides which attribute we are looking for.
    int wrong_input_filter_stdnt = 0;
    int debug_filter_stdnt;

        FILE *Filter_Stdnt = fopen("students.txt", "r");
    if (!Filter_Stdnt) {
        perror("Failed to open file");
        return;
    }

    while (count < MAX_STUDENTS &&
           fscanf(Filter_Stdnt, " %[^,], %[^,], %d, %f, %d, %[^,], %[^,], %[^,], %s\n",
                  students[count].name.first_name,
                  students[count].name.last_name,
                  &students[count].age,
                  &students[count].gpa,
                  &students[count].id,
                  students[count].faculty,
                  students[count].location.country,
                  students[count].location.city,
                  students[count].contact.email) == 9) {
        count++;
    }
    fclose(Filter_Stdnt);
//----------------------------------------------------------------------------------------------
    Student filtered[MAX_STUDENTS];
    memcpy(filtered, students, sizeof(Student) * count);
    int filteredCount = count;

    int used_filters[10] = {0}; // Track used filters
    int choice;
    int found;
    found = 0;

    while (1) {
        
        system("cls");
        printf("\t\t\t-----------------------------------------------------\n");
        printf("\t\t\t|  \t\t  Filtering  Students               |\n");
        printf("\t\t\t-----------------------------------------------------\n\n");
        
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t| \tPlease Select the Option You Want to Filter Student        |\n");
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t|     [1] Filter By Name           |       [2] Filter By Surname   |\n");
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t|     [3] Filter By Age            |       [4] Filter By GPA       |\n");
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t|     [5] Filter By ID             |       [6] Filter By Faculty   |\n");
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t|     [7] Filter By Country        |       [8] Filter By City      |\n");
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t|                         [9] Filter By Email                      |\n");
        printf("\t\t--------------------------------------------------------------------\n");
        printf("\t\t|                   [10] Back To Student's Records                 |\n");
        printf("\t\t--------------------------------------------------------------------\n\n");

        while (1) {

            if (wrong_input_filter_stdnt) {
                printf("\033[A\033[2K");
                printf("\t\t\t\tPlease choose the RIGHT section!!!: ");
            } else {
                printf("\t\t\t\tPlease the section you want to enter: ");
            }

            debug_filter_stdnt = scanf("%d", &option_filter_stdnt);

            if (debug_filter_stdnt != 1 || option_filter_stdnt < 1 || option_filter_stdnt > 10) {
                while (getchar() != '\n'); 
                wrong_input_filter_stdnt = 1; 
                continue;
            }
            break; 
    }
        getchar(); // clear newline

        if (option_filter_stdnt == 10) {
                    system("cls");
                    for (int i = 3; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K");
                    }
                    return;  // Exit the search menu
                }

        if (option_filter_stdnt < 1 || option_filter_stdnt > 9) {
            printf("Invalid choice.\n");
            continue;
        }

        if (used_filters[option_filter_stdnt - 1]) {
            printf("Filter already used. Choose another.\n");
            continue;
        }

        Student temp[MAX_STUDENTS];
        int newCount = 0;

        if (option_filter_stdnt == 1) {
            char name[50];
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|       Filtering Students by First Name            |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");
            
            char input_filter_name[100];
            int first_try_first_name = 1;

            while (1) {
                if (!first_try_first_name) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter Student's First Name: ");
                if (!fgets(input_filter_name, sizeof(input_filter_name), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_first_name = 0;
                    continue;
                }
                input_filter_name[strcspn(input_filter_name, "\n")] = 0;

                if (strlen(input_filter_name) == 0 || !Letter_Checker(input_filter_name)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_first_name = 0;
                    continue;
                }
                break;
            }
            
            for (int i = 0; i < filteredCount; i++) {
                if (strcmp(filtered[i].name.first_name, input_filter_name) == 0) {
                    temp[newCount++] = filtered[i];  // collect into temp
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);  // update filtered array
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);  // ✅ print once
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                    printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Filtering_Students(students, count);

                    break;
            }  
        }

        else if (option_filter_stdnt == 2) {
            char name[50];
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|       Filtering Students by Last Name             |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char input_filter_last_name[100];
            int first_try_last_name = 1;

            while (1) {
                if (!first_try_last_name) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter Student's Last Name: ");
                if (!fgets(input_filter_last_name, sizeof(input_filter_last_name), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_last_name = 0;
                    continue;
                }
                input_filter_last_name[strcspn(input_filter_last_name, "\n")] = 0;

                if (strlen(input_filter_last_name) == 0 || !Letter_Checker(input_filter_last_name)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_last_name = 0;
                    continue;
                }
                break;
            }

            for (int i = 0; i < filteredCount; i++) {
                if (strcmp(filtered[i].name.last_name, input_filter_last_name) == 0) {
                    temp[newCount++] = filtered[i];  // collect into temp
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);  // update filtered array
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);  // print once
            }
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);
                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                    printf("\033[A\033[2K"); // Move up and clear the entire line
                }
                Filtering_Students(students, count);
            }

        }

        else if (option_filter_stdnt == 3) {
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|            Filtering Students by Age              |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            int input_filter_age;
            int first_try_age = 1;

            while (1) {
                if (!first_try_age) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter Student's Age: ");
                int age_input_result = scanf("%d", &input_filter_age);
                while (getchar() != '\n'); // clear input buffer

                if (age_input_result != 1 || input_filter_age < 17 || input_filter_age > 70) {
                    printf("Invalid input! Please enter a valid age between 17 and 70.\n");
                    first_try_age = 0;
                    continue;
                }
                break;
            }

            // Filter by age
            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (filtered[i].age == input_filter_age) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }
        
        }

        else if (option_filter_stdnt == 4) {
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|         Filtering Students by Exact GPA           |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            float input_filter_gpa;
            int first_try_gpa = 1;

            while (1) {
                if (!first_try_gpa) {
                    printf("\033[A\033[2K"); // clear previous prompt
                    printf("\033[A\033[2K"); // clear previous line
                }

                printf("\t Please Enter Student's GPA (e.g., 3.45): ");
                int gpa_input_result = scanf("%f", &input_filter_gpa);
                while (getchar() != '\n'); // clear input buffer

                if (gpa_input_result != 1 || input_filter_gpa < 0.0 || input_filter_gpa > 4.0) {
                    printf("Invalid input! Please enter a valid GPA between 0.00 and 4.00.\n");
                    first_try_gpa = 0;
                    continue;
                }
                break;
            }

            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (filtered[i].gpa == input_filter_gpa) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }

        }
         
        else if (option_filter_stdnt == 5) {
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|           Filtering Students by ID                |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            int input_filter_id;
            int first_try_id = 1;

            while (1) {
                if (!first_try_id) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter Student ID (20000-30000): ");
                int input_status = scanf("%d", &input_filter_id);
                while (getchar() != '\n'); // clear buffer

                if (input_status != 1 || input_filter_id < 20000 || input_filter_id > 30000) {
                    printf("Invalid input! Please enter an ID between 20000 and 30000.\n");
                    first_try_id = 0;
                    continue;
                }
                break;
            }

            // Filter by ID
            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (filtered[i].id == input_filter_id) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }

        }
        
        else if (option_filter_stdnt == 6) {
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|         Filtering Students by Faculty             |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char input_filter_faculty[100];
            int first_try_faculty = 1;

            while (1) {
                if (!first_try_faculty) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter Faculty Name: ");
                if (!fgets(input_filter_faculty, sizeof(input_filter_faculty), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_faculty = 0;
                    continue;
                }

                input_filter_faculty[strcspn(input_filter_faculty, "\n")] = 0; // remove newline

                if (strlen(input_filter_faculty) == 0 || !Letter_Checker(input_filter_faculty)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_faculty = 0;
                    continue;
                }
                break;
            }

            // Filter by faculty
            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (strcmp(filtered[i].faculty, input_filter_faculty) == 0) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }

        }

        else if (option_filter_stdnt == 7){
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|         Filtering Students by Country             |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char input_filter_country[100];
            int first_try_country = 1;

            while (1) {
                if (!first_try_country) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter Country: ");
                if (!fgets(input_filter_country, sizeof(input_filter_country), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_country = 0;
                    continue;
                }

                input_filter_country[strcspn(input_filter_country, "\n")] = 0; // remove newline

                if (strlen(input_filter_country) == 0 || !Letter_Checker(input_filter_country)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_country = 0;
                    continue;
                }
                break;
            }

            // Filter by country
            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (strcmp(filtered[i].location.country, input_filter_country) == 0) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }

        }

        else if (option_filter_stdnt == 8) {
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|          Filtering Students by City              |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char input_filter_city[100];
            int first_try_city = 1;

            while (1) {
                if (!first_try_city) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter City: ");
                if (!fgets(input_filter_city, sizeof(input_filter_city), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_city = 0;
                    continue;
                }

                input_filter_city[strcspn(input_filter_city, "\n")] = 0; // remove newline

                if (strlen(input_filter_city) == 0 || !Letter_Checker(input_filter_city)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_city = 0;
                    continue;
                }
                break;
            }

            // Filter by city
            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (strcmp(filtered[i].location.city, input_filter_city) == 0) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }

        }

        else if (option_filter_stdnt == 9) {
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|          Filtering Students by City              |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char input_filter_city[100];
            int first_try_city = 1;

            while (1) {
                if (!first_try_city) {
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t Please Enter City: ");
                if (!fgets(input_filter_city, sizeof(input_filter_city), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_city = 0;
                    continue;
                }

                input_filter_city[strcspn(input_filter_city, "\n")] = 0; // remove newline

                if (strlen(input_filter_city) == 0 || !Letter_Checker(input_filter_city)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_city = 0;
                    continue;
                }
                break;
            }

            // Filter by city
            found = 0;
            for (int i = 0; i < filteredCount; i++) {
                if (strcmp(filtered[i].location.city, input_filter_city) == 0) {
                    temp[newCount++] = filtered[i];
                    found = 1;
                }
            }

            if (found) {
                memcpy(filtered, temp, sizeof(Student) * newCount);
                filteredCount = newCount;

                Print_Filtered_Students(filtered, filteredCount);
            } 
            
            else {
                printf("\n\n\t\t\t-----------------------------------------------------\n");
                printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                printf("\t\t\t-----------------------------------------------------\n\n");
                Sleep(1500);

                for (int i = 3; i >= 1; i--) {
                    system("cls");
                    printf("\n\t\t\t\tReturning to Filtering Students in %d...\n", i);
                    fflush(stdout);
                    Sleep(1000);
                }

                Filtering_Students(students, count);
            }

        }

        memcpy(filtered, temp, sizeof(Student) * newCount);
        filteredCount = newCount;
        used_filters[option_filter_stdnt - 1] = 1;

        int more;
        int wrong_input = 0;

        while (1) {

            if (wrong_input) {
                printf("\033[A\033[2K"); // clear previous prompt line
                printf("\nCountinue Filtering or Stop?(1 or 0): ");
            } else {
                printf("\nCountinue Filtering or Stop?(1 or 0): ");
            }

            int debug_menu = scanf("%d", &more);

            if (debug_menu != 1 || (more != 0 && more != 1)) {
                while (getchar() != '\n'); // clear input buffer
                wrong_input = 1;
                continue;
            }

            // valid input 0 or 1
            break;
        }
        
        if (more == 0) {
            // Reset filtered array to full original database
            memcpy(filtered, students, sizeof(Student) * count);
            filteredCount = count;
            break; // stop filtering
            }
    }
}

void LoadData(const char* filename, Student students[], int* count) {
    FILE* FIrst_Reading_DB = fopen(filename, "r");
    if (!FIrst_Reading_DB) {
        perror("Error opening file");
        *count = 0;
        return;
    }

    *count = 0;
    while (fscanf(FIrst_Reading_DB, " %[^,], %[^,], %d, %f, %d, %[^,], %[^,], %[^,], %s",
                  students[*count].name.first_name,
                  students[*count].name.last_name,
                  &students[*count].age,
                  &students[*count].gpa,
                  &students[*count].id,
                  students[*count].faculty,
                  students[*count].location.country,
                  students[*count].location.city,
                  students[*count].contact.email) == 9) {
        (*count)++;
        if (*count >= MAX_STUDENTS) break;
    }

    fclose(FIrst_Reading_DB);
}

void Print_All_Students(Student students[]){

    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t\tPrinting All Students               |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");


    FILE *Print_All_Stdnts = fopen("students.txt", "r");
    if (Print_All_Stdnts == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    int count = 0;

    while (count < MAX_STUDENTS &&
           fscanf(Print_All_Stdnts, " %[^,], %[^,], %d, %f, %d, %[^,], %[^,], %[^,], %s\n",
                  students[count].name.first_name,
                  students[count].name.last_name,
                  &students[count].age,
                  &students[count].gpa,
                  &students[count].id,
                  students[count].faculty,
                  students[count].location.country,
                  students[count].location.city,
                  students[count].contact.email) == 9) {
        count++;
    }
    fclose(Print_All_Stdnts);
//------------------------------------------------------------------------------------------
    printf("Total %d students, with 9 contacts:\n", count);
    for (int i = 0; i < count; i++) {
        printf("\n[%d] %s %s | Age: %d | GPA: %.2f | ID: %d | Faculty: %s\n",
            i + 1,
            students[i].name.first_name,
            students[i].name.last_name,
            students[i].age,
            students[i].gpa,
            students[i].id,
            students[i].faculty);

        printf("    Location: %s, %s | Email: %s\n",
            students[i].location.city,
            students[i].location.country,
            students[i].contact.email);
        printf("-------------------------------------------------------------\n");
        Sleep(800);
    }

    Sleep(1500);
    printf("\n\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t\tAll Students have printed :)        |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    Sleep(4000);
    for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K");
    }





}

void Print_Filtered_Students(Student* filtered, int filteredCount){
    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t          Filtered  Students                |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    printf("Total Students: %d", filteredCount);
    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < filteredCount; i++) {
        printf("\n[%d] %s %s | Age: %d | GPA: %.2f | ID: %d | Faculty: %s\n",
            i + 1,
            filtered[i].name.first_name,
            filtered[i].name.last_name,
            filtered[i].age,
            filtered[i].gpa,
            filtered[i].id,
            filtered[i].faculty);

        printf("    Location: %s, %s | Email: %s\n",
            filtered[i].location.city,
            filtered[i].location.country,
            filtered[i].contact.email);
        printf("-------------------------------------------------------------\n");
    }
    Sleep(2000);
}

void Print_Searched_Student(Student *s, int index, Student students[], int *count, int number){
    
    printf("\n[%d] %s %s | Age: %d | GPA: %.2f | ID: %d | Faculty: %s\n",
           number,
           s->name.first_name,
           s->name.last_name,
           s->age,
           s->gpa,
           s->id,
           s->faculty);
    printf("    Location: %s, %s | Email: %s\n",
           s->location.city,
           s->location.country,
           s->contact.email);
    printf("-------------------------------------------------------------\n");
 
    Sleep(1000);
}

void Print_Sorted_Students(Student students[], int n){

    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t\t    Sorted  Students                |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    printf("Total Number of Students: %d", n);
    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("\n[%d] %s %s | Age: %d | GPA: %.2f | ID: %d | Faculty: %s\n",
            i + 1,
            students[i].name.first_name,
            students[i].name.last_name,
            students[i].age,
            students[i].gpa,
            students[i].id,
            students[i].faculty);

        printf("    Location: %s, %s | Email: %s\n",
            students[i].location.city,
            students[i].location.country,
            students[i].contact.email);
        printf("-------------------------------------------------------------\n");
    }
    Sleep(10000);
    for (int i = 5; i >= 1; i--) {
         system("cls");
		printf("\n\t\t\t\tReturning to Sorting Students in %d...\n", i);
		fflush(stdout);
		Sleep(1000);
		printf("\033[A\033[2K"); // Move up and clear the entire line
	}
    Sorting_Students();
}

void SaveData(const char* filename, Student students[], int count) {
    FILE *FIrst_Reading_DB = fopen(filename, "w");
    if (!FIrst_Reading_DB) {
        perror("Error writing to file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(FIrst_Reading_DB, "%s, %s, %d, %.2f, %d, %s, %s, %s, %s\n",
                students[i].name.first_name,
                students[i].name.last_name,
                students[i].age,
                students[i].gpa,
                students[i].id,
                students[i].faculty,
                students[i].location.country,
                students[i].location.city,
                students[i].contact.email);
    }

    fclose(FIrst_Reading_DB);
}

void Save_Students_To_File(Student students[], int count) {
    FILE *Update_Edits = fopen("students.txt", "w");
    if (!Update_Edits) {
        perror("Failed to save students");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(Update_Edits, "%s, %s, %d, %.2f, %d, %s, %s, %s, %s\n",
            students[i].name.first_name,
            students[i].name.last_name,
            students[i].age,
            students[i].gpa,
            students[i].id,
            students[i].faculty,
            students[i].location.country,
            students[i].location.city,
            students[i].contact.email);
    }
    fclose(Update_Edits);
}

void Searching_Students(){

    int option_srch_stdnt; // Option that decides which attribute we are looking for.
    int wrong_input_srch_stdnt = 0;
    int debug_srch_stdnt;
    int matched_indices[100];
    int found_count = 1; 


    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t\t  Searching Students                |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t| \tPlease Select the Option You Want to Search Student        |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [1] Search By Name           |       [2] Seach By Surname    |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [3] Search By Age            |       [4] Seach By GPA        |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [5] Search By ID             |       [6] Seach By Faculty    |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [7] Search By Country        |       [8] Seach By City       |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|                         [9] Search By Email                      |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|                   [10] Back To Student's Records                 |\n");
    printf("\t\t--------------------------------------------------------------------\n\n");


     while (1) {


        if (wrong_input_srch_stdnt) {
            printf("\033[A\033[2K");
            printf("\t\t\t\tPlease choose the RIGHT section!!!: ");
        } else {
            printf("\t\t\t\tPlease the section you want to enter: ");
        }

        debug_srch_stdnt = scanf("%d", &option_srch_stdnt);

        if (debug_srch_stdnt != 1 || option_srch_stdnt < 1 || option_srch_stdnt > 10) {
            while (getchar() != '\n'); 
            wrong_input_srch_stdnt = 1; 
            continue;
        }
        break; 
    }

    FILE *Srch_Stdnt = fopen("students.txt", "r");
    if (!Srch_Stdnt) {
        perror("Failed to open file");
        return;
    }

    Student students[MAX_STUDENTS];
    int count = 0;

    while (count < MAX_STUDENTS &&
           fscanf(Srch_Stdnt, " %[^,], %[^,], %d, %f, %d, %[^,], %[^,], %[^,], %s\n",
                  students[count].name.first_name,
                  students[count].name.last_name,
                  &students[count].age,
                  &students[count].gpa,
                  &students[count].id,
                  students[count].faculty,
                  students[count].location.country,
                  students[count].location.city,
                  students[count].contact.email) == 9) {
        count++;
    }
    fclose(Srch_Stdnt); 
//---------------------------------------------------------------------------------------------------
        if (option_srch_stdnt == 10) {
            system("cls");
            for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K");
            }
            return;  // Exit the search menu
        }
// --------------------------------------------------------------------------------------------------

    char input_str[100];
    int input_int;
    int found = 0;

    getchar(); // clear input buffer after scanf
  
    switch (option_srch_stdnt) {
        
        case 1: { // Search by First Name
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|       Searching Students by First Name            |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_first_name = 1;

            while (1) {
                if (!first_try_first_name) {
                    printf("\033[A\033[2K"); // Clear previous message
                    printf("\033[A\033[2K"); // Clear previous prompt
                }

                printf("\t Please Enter Student's First Name: ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_first_name = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_first_name = 0;
                    continue;
                }

                // Search student by First name
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].name.first_name, temp) == 0) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;

    }
        
        case 2: { // Search by Last Name (only letters, no spaces)
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|       Searching Students by Last  Name            |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_first_name = 1;

            while (1) {
                if (!first_try_first_name) {
                    printf("\033[A\033[2K"); // Clear previous message
                    printf("\033[A\033[2K"); // Clear previous prompt
                }

                printf("\t Please Enter Student's Last  Name: ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_first_name = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_first_name = 0;
                    continue;
                }

                // Search student by Last name
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].name.last_name, temp) == 0) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;
        }

        case 3: { // Search by Age (only digits, must be 17–70)

            char temp[100];
            int first_try_age = 1;
            int age_input;

            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|            Searching Students by Age              |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            while (1) {
                if (!first_try_age) {
                    printf("\033[A\033[2K"); // Clear previous message
                    printf("\033[A\033[2K"); // Clear previous prompt
                }

                printf("\t Please Enter Student's Age (17 - 70): ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_age = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline

                // Validate: not empty and all digits
                int valid = 1;
                for (int i = 0; temp[i]; i++) {
                    if (!isdigit((unsigned char)temp[i])) {
                        valid = 0;
                        break;
                    }
                }

                if (!valid || strlen(temp) == 0) {
                    printf("Invalid input! Please enter digits only and not empty.\n");
                    first_try_age = 0;
                    continue;
                }

                age_input = atoi(temp);

                if (age_input < 17 || age_input > 70) {
                    printf("Age must be between 17 and 70.\n");
                    first_try_age = 0;
                    continue;
                }

                // Search by age
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (students[i].age == age_input) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count,found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;
        }

        case 4: { // Search by GPA range with input validation like ID search
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|           Searching Students by GPA               |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_gpa_option = 1;
            int gpa_option = 0;
            float exact_gpa = 0.0f;

            while (1) {
                if (!first_try_gpa_option) {
                    // Clear previous message and prompt lines (2 lines)
                    printf("\033[A\033[2K");
                    printf("\033[A\033[2K");
                }

                printf("\t\t\t\tPlease Select GPA Range to Search:\n");
                printf("\t\t\t\t------------------------------------------\n");
                printf("\t\t\t\t\t  [1] Less than 1.0\n");
                printf("\t\t\t\t   ------------------------------------\n");
                printf("\t\t\t\t\t  [2] 1.0 Between 2.0\n");
                printf("\t\t\t\t   ------------------------------------\n");
                printf("\t\t\t\t\t  [3] 2.0 Between 3.0\n");
                printf("\t\t\t\t   ------------------------------------\n");
                printf("\t\t\t\t\t  [4] 3.0 Between 4.0\n");
                printf("\t\t\t\t   ------------------------------------\n");
                printf("\t\t\t\t\t  [5] Other (enter exact GPA)\n");
                printf("\t\t\t\t   ------------------------------------\n\n");
                printf("\t\t\t\t\t    Your choice: ");

                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_gpa_option = 0;
                    continue;
                }
                temp[strcspn(temp, "\n")] = 0; // Remove newline

                if (strlen(temp) != 1 || temp[0] < '1' || temp[0] > '5') {
                    printf("Invalid option! Please enter a number between 1 and 5.\n");
                    first_try_gpa_option = 0;
                    continue;
                }
                gpa_option = temp[0] - '0';

                 if (gpa_option == 5) {
                    int first_try_exact_gpa = 1;
                    while (1) {
                        if (!first_try_exact_gpa) {
                            printf("\033[A\033[2K");
                            printf("\033[A\033[2K");
                        }
                        printf("Enter exact GPA (0.0 - 4.0): ");

                        if (!fgets(temp, sizeof(temp), stdin)) {
                            printf("Input error, try again.\n");
                            first_try_exact_gpa = 0;
                            continue;
                        }

                        temp[strcspn(temp, "\n")] = 0; // Remove newline
                        char *endptr;
                        exact_gpa = strtof(temp, &endptr);

                        if (endptr == temp || *endptr != '\0') {
                            printf("Invalid input! Please enter a valid floating-point number.\n");
                            first_try_exact_gpa = 0;
                            continue;
                        }
                        if (exact_gpa < 0.0f || exact_gpa > 4.0f) {
                            printf("GPA must be between 0.0 and 4.0.\n");
                            first_try_exact_gpa = 0;
                            continue;
                        }
                        break;
                    }
                }
                break;
            }
            found = 0;
            for (int i = 0; i < count; i++) {
                float gpa = students[i].gpa;
                int match = 0;
                switch (gpa_option) {
                    case 1:
                        if (gpa < 1.0f) match = 1;
                        break;
                    case 2:
                        if (gpa >= 1.0f && gpa < 2.0f) match = 1;
                        break;
                    case 3:
                        if (gpa >= 2.0f && gpa < 3.0f) match = 1;
                        break;
                    case 4:
                        if (gpa >= 3.0f && gpa <= 4.0f) match = 1;
                        break;
                    case 5:
                        if (gpa == exact_gpa) match = 1;
                         break;
                }
                if (match) {
                    matched_indices[found_count - 1] = i;
                    Print_Searched_Student(&students[i], i, students, &count, found_count);
                    found = 1;
                    found_count++;
                }
            }
            if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }            
            if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
            }
            break;
        }

        case 5: { // Search by ID (20000–30000)
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|  \t\tSearching Students by ID            |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_id = 1;
            int id;

            while (1) {
                if (!first_try_id) {
                    printf("\033[A\033[2K");  // Clear previous message
                    printf("\033[A\033[2K");  // Clear previous prompt
                }

                printf("\t Please Enter Student's ID (20000 - 30000): ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_id = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0;  // Remove newline

                int valid = 1;
                for (int i = 0; temp[i]; i++) {
                    if (!isdigit((unsigned char)temp[i])) {
                        valid = 0;
                        break;
                    }
                }

                if (!valid || strlen(temp) == 0) {
                    printf("Invalid input! Please enter only digits.\n");
                    first_try_id = 0;
                    continue;
                }

                id = atoi(temp);

                if (id < 20000 || id > 30000) {
                    printf("ID must be between 20000 and 30000.\n");
                    first_try_id = 0;
                    continue;
                }

                // Search student by ID
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (students[i].id == id) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;
        }

        case 6: { // Search by Faculty 
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|  \t    Searching Students by Faculty           |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_faculty = 1;

            while (1) {
                if (!first_try_faculty) {
                    printf("\033[A\033[2K"); // Clear previous message
                    printf("\033[A\033[2K"); // Clear prompt
                }

                printf("\t Please Enter Student's Faculty: ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_faculty = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_faculty = 0;
                    continue;
                }

                // Valid input — search
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].faculty, temp) == 0) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;
        }
       
        case 7: { // Search by Country
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|\t    Searching Students by Country           |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_country = 1;

            while (1) {
                if (!first_try_country) {
                    printf("\033[A\033[2K"); // Clear previous line
                    printf("\033[A\033[2K"); // Clear input prompt
                }

                printf("\t Please Enter Student's Country: ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_country = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_country = 0;
                    continue;
                }

                // Valid input, now search
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].location.country, temp) == 0) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }
                break;
            }
            break;
        }
    
        case 8: { // Search by City 
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|\t    Searching Students by City              |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_city = 1;

            while (1) {
                if (!first_try_city) {
                    printf("\033[A\033[2K"); // Clear previous message line
                    printf("\033[A\033[2K"); // Clear prompt line
                }

                printf("\t  Please Enter Student's City: ");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_city = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline at end

                if (strlen(temp) == 0 || !Letter_Checker(temp)) {
                    printf("Invalid input! Please enter only letters and not empty.\n");
                    first_try_city = 0;
                    continue;
                }

                // Valid input — search students
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].location.city, temp) == 0) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;
        }
 
        case 9: { // Search by ADA Email1
            system("cls");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t|        Searching Students by ADA Email            |\n");
            printf("\t\t\t-----------------------------------------------------\n\n");

            char temp[100];
            int first_try_email = 1;

            while (1) {
                if (!first_try_email) {
                    printf("\033[A\033[2K"); // Clear previous message
                    printf("\033[A\033[2K"); // Clear previous prompt
                }

                printf("\t Please Enter ADA Email (must end with @ada.edu.az): \n\n");
                if (!fgets(temp, sizeof(temp), stdin)) {
                    printf("Input error, try again.\n");
                    first_try_email = 0;
                    continue;
                }

                temp[strcspn(temp, "\n")] = 0; // Remove newline

                // Check empty or spaces
                if (strlen(temp) == 0 || strchr(temp, ' ') != NULL) {
                    printf("Invalid input! Email cannot be empty or contain spaces.\n");
                    first_try_email = 0;
                    continue;
                }

                // Check if it ends with @ada.edu.az
                const char *required_suffix = "@ada.edu.az";
                size_t email_len = strlen(temp);
                size_t suffix_len = strlen(required_suffix);

                if (email_len < suffix_len || strcmp(temp + (email_len - suffix_len), required_suffix) != 0) {
                    printf("Invalid email! Must end with @ada.edu.az.\n");
                    first_try_email = 0;
                    continue;
                }

                // Valid input — search
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].contact.email, temp) == 0) {
                        matched_indices[found_count - 1] = i;
                        Print_Searched_Student(&students[i], i, students, &count, found_count);
                        found = 1;
                        found_count++;
                    }
                }
                if (found_count > 0) {
                    printf("\nTotal Number of Students Found: %d\n\n", found_count-1);
                }

                if (!found) {
                    printf("\n\n\t\t\t-----------------------------------------------------\n");
                    printf("\t\t\t|  \t\t  Student Not Found!!!              |\n");
                    printf("\t\t\t-----------------------------------------------------\n\n");
                    Sleep(1500);
                    for (int i = 5; i >= 1; i--) {
                        system("cls");
                        printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
                        fflush(stdout);
                        Sleep(1000);
                        printf("\033[A\033[2K"); // Move up and clear the entire line
                    }
                    Searching_Students();
                }

                break;
            }
            break;
        } 
    }

    //------------------------------------------------------------------------------
    int selection;
    int wrong_input = 0;
    int debug_menu;
    int number;

    while (1) {
        if (wrong_input) {
            printf("\033[A\033[2K"); // clear current line (prompt)
            printf("\t\t\tPlease choose the RIGHT section!!!(1-%d): ", found_count-1);
        } else {
            printf("\t\t\tPlease enter the number of the student to manage (1-%d): ", found_count-1);
        }

        debug_menu = scanf("%d", &selection);

        if (debug_menu != 1 || selection < 1 || selection > found_count-1) {
            while (getchar() != '\n'); // flush invalid input
            wrong_input = 1;
            continue;
        }

        while (getchar() != '\n'); // flush leftover chars

        break; // valid input
    }


    int index = matched_indices[selection - 1];
    Student *s = &students[index];
    //---------------------------------------------------------------------------

    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|   Delete(d)          Edit(e)           Back(b)    |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
 
    char temp[10];
    int first_try = 1;

    while (1) {
	    if (!first_try) {
		    printf("\033[A\033[2K"); // clear error message
		    printf("\033[A\033[2K"); // clear prompt line
	    }

	    printf("\t\t\t\t\tPlease enter a letter: ");
	    fflush(stdout);

	    if (!fgets(temp, sizeof(temp), stdin)) {
		    printf("Input error, try again.\n");
		    first_try = 0;
		    continue;
	    }

	    temp[strcspn(temp, "\n")] = 0; // Remove newline

	    if (strlen(temp) == 1 && (temp[0] == 'd' || temp[0] == 'e' || temp[0] == 'b')) {
		    break; // Valid input, exit loop
	    } else {
		    printf("Invalid input! Please enter only one letter: d, e, or b.\n");
		    first_try = 0;
	    }
    }
    if (strlen(temp) == 1) {
            char c = temp[0];

            if (c == 'd') {
                Delete_Searched_Student(index, students, &count);
                Searching_Students();

            }
            else if (c == 'e') {
                Edit_Searched_Student(s, index, students, &count);
            }
            else if (c == 'b'){
                for (int i = 5; i >= 1; i--) {
                    system("cls");
		            printf("\n\t\t\t\tReturning to Student Search in %d...\n", i);
		            fflush(stdout);
		            Sleep(1000);
		            printf("\033[A\033[2K"); // Move up and clear the entire line
	            }
                Searching_Students();
            }
    return;
    }

    return;
}

void Sorting_Students(){

    int option_sort_stdnt; // Option that decides which attribute we are looking for.
    int wrong_input_sort_stdnt = 0;
    int debug_sort_stdnt;

    int order_sort_stdnt; // 1 for Ascending, 2 for Descending
    int wrong_input_order = 0;
    int debug_order;

    system("cls");
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|  \t\t  Sorting  Students                 |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t| \tPlease Select the Option You Want to Sorting Students      |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [1] Sort  By Name           |       [2] Sort By Surname      |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [3] Sort  By Age            |       [4] Sort  By GPA         |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [5] Sort  By ID             |       [6] Sort  By Faculty     |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|     [7] Sort  By Country        |       [8] Sort  By City        |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|                         [9] Sort  By Email                       |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t|                   [10] Back To Student's Records                 |\n");
    printf("\t\t--------------------------------------------------------------------\n\n");


    while (1) {


        if (wrong_input_sort_stdnt) {
            printf("\033[A\033[2K");
            printf("\t\t\t\tPlease choose the RIGHT section!!!: ");
        } else {
            printf("\t\t\t\tPlease the section you want to enter: ");
        }

        debug_sort_stdnt = scanf("%d", &option_sort_stdnt);

        if (debug_sort_stdnt != 1 || option_sort_stdnt < 1 || option_sort_stdnt > 10) {
            while (getchar() != '\n'); 
            wrong_input_sort_stdnt = 1; 
            continue;
        }
        break; 
    }
 
    //-------------------------------------------------------------------------------------------------
              if (option_sort_stdnt == 10) {
            system("cls");
            for (int i = 3; i >= 1; i--) {
                system("cls");
                printf("\n\t\t\t\tReturning to Student Records in %d...\n", i);
                fflush(stdout);
                Sleep(1000);
                printf("\033[A\033[2K");
            }
            return;  // Exit the search menu
        }
    //-------------------------------------------------------------------------------------------------
    printf("\n\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t|     Ascending Order(1) or Descending Order(2)     |\n");
    printf("\t\t\t-----------------------------------------------------\n\n");

    while (1) {
    if (wrong_input_order) {
        printf("\033[A\033[2K");
        printf("\t\t\t\t   Please choose 1 or 2 only: ");
    } else {
        printf("\t\t\t\t\tEnter your choice: ");
    }

    debug_order = scanf("%d", &order_sort_stdnt);

    if (debug_order != 1 || (order_sort_stdnt != 1 && order_sort_stdnt != 2)) {
        while (getchar() != '\n');
        wrong_input_order = 1;
        continue;
    }
    break;
}

        FILE *Sort_Stdnt = fopen("students.txt", "r");
    if (!Sort_Stdnt) {
        perror("Failed to open file");
        return;
    }

    Student students[MAX_STUDENTS];
    int count = 0;

    while (count < MAX_STUDENTS &&
           fscanf(Sort_Stdnt, " %[^,], %[^,], %d, %f, %d, %[^,], %[^,], %[^,], %s\n",
                  students[count].name.first_name,
                  students[count].name.last_name,
                  &students[count].age,
                  &students[count].gpa,
                  &students[count].id,
                  students[count].faculty,
                  students[count].location.country,
                  students[count].location.city,
                  students[count].contact.email) == 9) {
        count++;
    }
    fclose(Sort_Stdnt);

// ---------------------------------------------------------------------------------------------
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int swap = 0;
            switch (option_sort_stdnt) {
                        case 1: // First Name + Last Name
                            if (strcmp(students[i].name.first_name, students[j].name.first_name) == 0) {
                                swap = (order_sort_stdnt == 1)
                                    ? strcmp(students[i].name.last_name, students[j].name.last_name) > 0
                                    : strcmp(students[i].name.last_name, students[j].name.last_name) < 0;
                            } else {
                                swap = (order_sort_stdnt == 1)
                                    ? strcmp(students[i].name.first_name, students[j].name.first_name) > 0
                                    : strcmp(students[i].name.first_name, students[j].name.first_name) < 0;
                            }
                            break;

                        case 2: // Last Name
                            swap = (order_sort_stdnt == 1)
                                ? strcmp(students[i].name.last_name, students[j].name.last_name) > 0
                                : strcmp(students[i].name.last_name, students[j].name.last_name) < 0;
                            break;

                        case 3: // Age
                            swap = (order_sort_stdnt == 1)
                                ? students[i].age > students[j].age
                                : students[i].age < students[j].age;
                            break;

                        case 4: // GPA
                            swap = (order_sort_stdnt == 1)
                                ? students[i].gpa > students[j].gpa
                                : students[i].gpa < students[j].gpa;
                            break;

                        case 5: // ID
                            swap = (order_sort_stdnt == 1)
                                ? students[i].id > students[j].id
                                : students[i].id < students[j].id;
                            break;

                        case 6: // Faculty
                            swap = (order_sort_stdnt == 1)
                                ? strcmp(students[i].faculty, students[j].faculty) > 0
                                : strcmp(students[i].faculty, students[j].faculty) < 0;
                            break;

                        case 7: // Country
                            swap = (order_sort_stdnt == 1)
                                ? strcmp(students[i].location.country, students[j].location.country) > 0
                                : strcmp(students[i].location.country, students[j].location.country) < 0;
                            break;

                        case 8: // City
                            swap = (order_sort_stdnt == 1)
                                ? strcmp(students[i].location.city, students[j].location.city) > 0
                                : strcmp(students[i].location.city, students[j].location.city) < 0;
                            break;

                        case 9: // Email
                            swap = (order_sort_stdnt == 1)
                                ? strcmp(students[i].contact.email, students[j].contact.email) > 0
                                : strcmp(students[i].contact.email, students[j].contact.email) < 0;
                            break;
                    }

                    if (swap) {
                        Student temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
            }
        }
    

    Print_Sorted_Students(students, count);

}

