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
sll_t *create_sll(void)
{
  sll_t *sll = calloc(1, sizeof(sll_t));
  sll->head = NULL;
  return sll;
}

/* 
 * This function adds the data sent by the application to the SLL.
 */
int insert_at_end(sll_t *sll, void *app_data)
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
