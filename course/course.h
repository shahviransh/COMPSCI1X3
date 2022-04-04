/**
 * @file course.h
 * @author Viransh Shah (shahv47@mcmaster.ca)
 * @brief A header file containing typedef struct Course and its various function declerations.
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "student.h"
#include <stdbool.h>
 
/**
 * @brief Course type stores a course name, code, Student types and total number of students.
 * 
 */
typedef struct _course 
{
  char name[100]; /**< Course's name */
  char code[10]; /**< Course's 10 digit code */
  Student *students; /**< Student types in the course */
  int total_students; /**< Total number of students */
} Course;

// Function Decleration
void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


