/*
 * app.c
 *
 * This is the sample application to demonstrate the usage of the 
 * singly linked list library
 *
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"


typedef struct student
{
  char name[32];
  int age;
  int roll_no;
}student_t;

int main(void)
{
  /* create a new and empty singly linekd list */
  sll_t *student_list = create_sll();

  /* stundents data */
  student_t *s1 = calloc(1, sizeof(student_t));
  strncpy(s1->name, "Ram", strlen("Ram"));
  s1->age = 14;
  s1->roll_no = 1;

  student_t *s2 = calloc(1, sizeof(student_t));
  strncpy(s2->name, "Jakson", strlen("Jakson"));
  s2->age = 13;
  s2->roll_no = 15;

  student_t *s3 = calloc(1, sizeof(student_t));
  strncpy(s3->name, "Serene", strlen("Serene"));
  s3->age = 13;
  s3->roll_no = 3;

  insert_at_end(student_list, s1);
  insert_at_end(student_list, s2);
  insert_at_end(student_list, s3);

  return 0;
}
