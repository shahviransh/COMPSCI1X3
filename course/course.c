/**
 * @file course.c
 * @author Viransh Shah (shahv47@mcmaster.ca)
 * @brief Functions for enrolling a student, printing course info,
 *        finding top student from a course, and finding all students who passed a course.
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Enrolls a specific student into a specific course.
 * 
 * @param course a specific student
 * @param student a specific course
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student)); /** If course only has one student, calloc is used to get memory for only one element in the students array */
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student));  /** Otherwise, realloc is used to get more memory according to the number of students for students array */
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Prints the name, code, and total students in the course.
 * 
 * @param course a specific course
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]); /** Print all students in the students array recursively with pointer's address */
}

/**
 * @brief Uses selection search to find the top students in a course according to their averages.
 * 
 * @param course a specific course
 * @return Student*, pointer to the top student
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average)
    {
      max_average = student_average; /** Finds the highest average from the all the students */
      student = &course->students[i]; /** Top student is set if their average is higher than max_average */
      /** Until there is no higher average */
    }   
  }

  return student;
}

/**
 * @brief Finds the students who have an average above 50 and save them to an array of students.
 * 
 * @param course a specific course
 * @param total_passing total number of students passed
 * @return Student*, pointer to passing students
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++; /** Increments count if the students pass */
  
  passing = calloc(count, sizeof(Student)); /** Allocates memory for array at default values for the passed students accordimg to count */

  int j = 0;
  for (int i = 0; i < course->total_students; i++) /** Students who pass are assigned to the passed array */
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}