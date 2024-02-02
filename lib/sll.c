/*
 * sll.c 
 *
 * This file contains the implementation of the singly linked list (SLL)
 * library. It contains various operations which can be performed on the
 * SLL
 *
 */

#include <stdio.h>
#include <stdlib.h> 
#include "sll.h"


/* 
 * This function creates and initializes SLL.
 * It provides the empty list.
 */
sll_t *sll_create(void)
{
  sll_t *sll = calloc(1, sizeof(sll_t));
  sll->head = NULL;
  sll->print_list = NULL;
  return sll;
}


/*
 * Function to register the callback to print the SLL data
 */
void sll_register_print_list_callback(sll_t *sll, void (*print_list)(void *))
{
  sll->print_list = print_list;
}


/* 
 * This function adds the data sent by the application to the SLL.
 */
int sll_insert_at_end(sll_t *sll, void *app_data)
{
  if (sll == NULL || app_data == NULL)
  {
    return -1;
  }

  sll_node_t *new_node = calloc(1, sizeof(sll_node_t));
  new_node->next = NULL;
  new_node->data = app_data;

  /* if list is empty add the first node */
  if (sll->head == NULL)
  {
    sll->head = new_node;
  }
  else
  {
    /* add node at the end of the list */
    sll_node_t *temp = sll->head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = new_node;
  }

  return 0;
}


/*
 * This function is a generic print function.
 * It will print the data from the list
 */
int sll_print_list(sll_t *sll)
{
  if (sll == NULL)
  {
    return -1;
  }

  sll_node_t *head = sll->head;

  printf("================================\n");

  while(head)
  {
    sll->print_list(head->data);
    head = head->next;
  }

  printf("================================\n");
}

