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


/* print SLL callback function */
void print_student_data(void *data)
{
  student_t *student = (student_t *) data;
  printf("-----------------------------\n");
  printf("Name: %s\n", student->name);
  printf("Age: %d\n", student->age);
  printf("Roll No: %d\n", student->roll_no);
  printf("-----------------------------\n");
}


int main(void)
{
  /* create a new and empty singly linekd list */
  sll_t *student_list = sll_create();

  /* register the callbacks */
  sll_register_print_list_callback(student_list, print_student_data);

  /* students data */
  student_t *s1 = calloc(1, sizeof(student_t));
  strncpy(s1->name, "Ram", strlen("Ram"));
  s1->age = 14;
  s1->roll_no = 1;

  student_t *s2 = calloc(1, sizeof(student_t));
  strncpy(s2->name, "Jakson", strlen("Jakson"));
  s2->age = 13;
  s2->roll_no = 2;

  student_t *s3 = calloc(1, sizeof(student_t));
  strncpy(s3->name, "Serene", strlen("Serene"));
  s3->age = 13;
  s3->roll_no = 3;

  student_t *s4 = calloc(1, sizeof(student_t));
  strncpy(s4->name, "Alex", strlen("Alex"));
  s4->age = 14;
  s4->roll_no = 4;

  /* insert data into SLL */
  sll_insert_at_end(student_list, s2);
  sll_insert_at_end(student_list, s4);
  sll_insert_at_front(student_list, s1);
  sll_insert_at_pos(student_list, s3, 3);

  /* print SLL data */
  sll_print_list(student_list);

  /* delete data from SLL */
  sll_delete_front(student_list);
  sll_delete_end(student_list);
  sll_delete_at_pos(student_list, 2);

  /* print SLL data */
  sll_print_list(student_list);

  /* reverse SLL */
  sll_reverse(student_list);

  /* print reversed SLL */
  sll_print_list(student_list);

  return 0;
}
