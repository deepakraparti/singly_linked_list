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


/* search callback function */
static int search_by_roll_no(void *data, void *key)
{
  student_t *student = (student_t *) data;

  return (student->roll_no == (int)key) ? 0 : -1; 
}


/* compare callback function */
static int compare_student_by_roll_no(void *student1, void *student2)
{
  student_t *st1 = (student_t *)student1;
  student_t *st2 = (student_t *)student2;

  if (st1->roll_no > st2->roll_no)
  {
    return 1;
  }
  else if (st1->roll_no < st2->roll_no)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}


int main(void)
{
  /* create a new and empty singly linekd list */
  sll_t *student_list = sll_create();

  /* register the callbacks */
  sll_register_print_list_callback(student_list, print_student_data);
  sll_register_search_callback(student_list, search_by_roll_no);
  sll_register_compare_callback(student_list, compare_student_by_roll_no);

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

#if 0
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

  student_t *student = sll_search(student_list, (void *)2);
  if (!student)
  {
    printf("Student details not found\n");
  }
  else
  {
    print_student_data(student);
  }

#else

  /* insert data into SLL */
  sll_insert_at_front(student_list, s1);
  sll_insert_at_front(student_list, s2);
  sll_insert_at_front(student_list, s3);
  sll_insert_at_front(student_list, s4);

  /* print SLL data */
  sll_print_list(student_list);

  /* Sort the list */
  sll_sort_ascending(student_list);

  /* print SLL data */
  sll_print_list(student_list);
#endif
  
  return 0;
}
