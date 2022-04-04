/**
 * @file main.c
 * @author Viransh Shah (shahv47@mcmaster.ca)
 * @brief A brief simulation of creating a course, adding students, 
 *        finding top student, and printing all students who passed.
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief Main function who calls all functions to work with a Course and Student type.
 * 
 * @return int value to show program executed successfully
 */
int main()
{
  srand((unsigned) time(NULL)); /** random seed */

  Course *MATH101 = calloc(1, sizeof(Course)); /** Course type with only one specific course */
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8)); /** 20 random students with 8 grades are enrolled to MATH101 */
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101); /** Top student from MATH101 */
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing); /** All students who passed MATH 101 */
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]); /** Prints each student's info who passed */
  
  return 0;
}