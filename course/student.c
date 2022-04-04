/**
 * @file student.c
 * @author Viransh Shah (shahv47@mcmaster.ca)
 * @brief Functions for adding student grades, getting their average, 
 *        printing student's info and generating a random student.
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Adds a new grade for a specific student.
 * 
 * @param student a specific student
 * @param grade that will added to the current grades of the student
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double)); /** If student only has one grade, calloc is used to get memory for only one element in the grades array */
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades); /** Otherwise, realloc is used to get more memory according to the number of grades for grades array */
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief Calculates the current student's average grades.
 * 
 * @param student a specific student
 * @return double, which is the average of student's grades
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i]; /** Sums all the grades in student type's grades array */
  return total / ((double) student->num_grades);
}

/**
 * @brief Prints the name, id, grades, and average grade of the student.
 * 
 * @param student a specific student
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]); /** Print all grades in the grades array to 2 decimal places */
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief Generates a student with a random first and last name, id and grades.
 * 
 * @param grades, which are the total number of grades for the new_student
 * @return Student*, pointer to the new student generated
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student)); /** new_student allocated memory for only one student type with default values */

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48); /** new_student's id assigned randomly in a loop*/
  new_student->id[10] = '\0';

  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75))); /** new_student's grades assigned randomly */
  }

  return new_student;
}