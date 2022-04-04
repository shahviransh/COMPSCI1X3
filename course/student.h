/**
 * @file student.h
 * @author Viransh Shah (shahv47@mcmaster.ca)
 * @brief A header file containing typedef struct Student and its various function declerations.
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Student type stores a student with full name, id, grades and total number of grades.
 * 
 */
typedef struct _student 
{ 
  char first_name[50]; /**< Student's first name */
  char last_name[50]; /**< Student's last name */
  char id[11]; /**< Student's 11 character long id */
  double *grades; /**< Pointer to student's grades */
  int num_grades; /**< Student's total number of grades */
} Student;

// Function Decleration
void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
