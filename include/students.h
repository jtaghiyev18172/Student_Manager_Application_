#ifndef STUDENTS_H
#define STUDENTS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX_STUDENTS 200

typedef struct {
    char city[15];
    char country[15];
} Location;

typedef struct {
    char first_name[15];
    char last_name[18];
} Name;

typedef struct {
    char email[25];
    char phone[10];
} Contact;

typedef struct {
    Name name;          // Nested struct for first and last name
    int age;
    char faculty[15];
    Location location;  // Nested struct for city and country
    float gpa;
    int id;
    Contact contact;    // Nested struct for email and phone
} Student;

// Global variables shared across translation units
extern FILE *Add_St;
extern FILE *Srch_Stdnt;
extern FILE *Update_Edits;
extern FILE *Delete_Students;
extern FILE *Sort_Stdnt;
extern FILE *Print_All_Stdnts;
extern FILE *Filter_Stdnt;
extern FILE *FIrst_Reading_DB;
extern Student *original_data;
extern int original_count;

// Function prototypes (student library)
void Add_Students(Student *Add_St, char *end_choice_add_st);
int CompareData(Student data1[], int count1, Student data2[], int count2);
void Delete_Searched_Student(int index, Student students[], int *count);
void Edit_Searched_Student(Student *s, int index, Student students[], int *count);
void Filtering_Students(Student* students, int count);
void LoadData(const char* filename, Student students[], int* count);
void Print_All_Students(Student students[]);
void Print_Filtered_Students(Student* filtered, int filteredCount);
void Print_Searched_Student(Student *s, int index, Student students[], int *count, int number);
void Print_Sorted_Students(Student students[], int n);
void SaveData(const char* filename, Student students[], int count);
void Save_Students_To_File(Student students[], int count);
void Searching_Students();
void Sorting_Students();

#endif /* STUDENTS_H */
