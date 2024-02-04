/*
 * @file sll.c 
 *
 * This file contains the implementation of the singly linked list (SLL)
 * library. It contains various operations which can be performed on the
 * SLL
 *
 */

#include <stdio.h>
#include <stdlib.h> 
#include "sll.h"


/* sll_create
 *
 * This function creates and initializes SLL.
 * It provides the empty list.
 *
 * @return pointer to the linked list
 */
sll_t *sll_create(void)
{
  sll_t *sll = calloc(1, sizeof(sll_t));
  sll->head = NULL;
  sll->len = 0;
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
 * sll_inser_at_end
 *
 * This function adds the data sent by the application to the SLL.
 *
 * @param[in]     sll          Pointer to singly linked list
 * @param[in]     app_data     Pointer to the data
 *
 * @return 0 if SUCCESS and -1 on failure
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
    sll->len++;
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
    sll->len++;
  }

  return 0;
}


/*
 * sll_insert_at_front
 *
 * This function inserts the data at the begining of the SLL
 * and adjusts the head accordingly
 *
 * @param[in]     sll          Pointer to singly linked list
 * @param[in]     app_data     Pointer to the data
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_insert_at_front(sll_t *sll, void *app_data)
{
  if(sll == NULL || app_data == NULL)
  {
    return -1;
  }

  sll_node_t *new_node = calloc(1, sizeof(sll_node_t));
  new_node->next = NULL;
  new_node->data = app_data;

  new_node->next = sll->head;
  sll->head = new_node;
  sll->len++;

  return 0;  
}


/*
 * sll_insert_at_pos
 *
 * This function inserts the data at the position specified in the SLL.
 * If the list is empty, data will be added as the first node in the list.
 * If the position specified is out of the range then -1 will be returned.
 *
 * @param[in]     sll          Pointer to singly linked list
 * @param[in]     app_data     Pointer to the data
 * @param[in]     pos          Position at which data to be inserted
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_insert_at_pos(sll_t *sll, void *app_data, int pos)
{
  int i = 1;

  if (sll == NULL || app_data == NULL)
  {
    return -1;
  }

  sll_node_t *new_node = calloc(1, sizeof(sll_node_t));
  new_node->next = NULL;
  new_node->data = app_data;

  /* list is empty add the first node */
  if (sll->head == NULL)
  {
    sll->head = new_node;
    sll->len++;
  }
  else if (pos > (sll->len + 1))
  {
    printf("Postion entered is out of range\n");
    return -1;
  }
  else
  {
    sll_node_t *head = sll->head;

    while(i < pos - 1)
    {
      head = head->next;
      i++;
    }

    new_node->next = head->next;
    head->next = new_node;
    sll->len++;
  }

  return 0;
}


/*
 * sll_delete_front
 *
 * This function deletes front node from the SLL. If the list is empty,
 * no action will be performed.
 *
 * @param[in]     sll          Pointer to singly linked list
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_delete_front(sll_t *sll)
{
  if (sll == NULL)
  {
    return -1;
  }

  if (sll->head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    sll_node_t *front = sll->head;
    sll->head = sll->head->next;

    free(front);
    front = NULL;

    sll->len--;
  }

  return 0;
}


/*
 * sll_delete_end
 *
 * This function deletes end node from the SLL. If the list is empty,
 * no action will be performed.
 *
 * @param[in]     sll          Pointer to singly linked list
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_delete_end(sll_t *sll)
{
  sll_node_t *prev = NULL;

  if (sll == NULL)
  {
    return -1;
  }

  if (sll->head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    sll_node_t *temp = sll->head;

    while(temp->next != NULL)
    {
      prev = temp;
      temp = temp->next;
    }

    free(temp);
    temp = NULL;
    prev->next = NULL;

    sll->len--;
  }

  return 0;
}


/*
 * sll_delete_at_pos
 *
 * This function deletes the node specified by position from the SLL. If 
 * the list is empty no action will be performed.
 *
 * @param[in]     sll          Pointer to singly linked list
 * @param[in]     pos          Position of the node to be deleted
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_delete_at_pos(sll_t *sll, int pos)
{
  int i = 1;

  if (sll == NULL)
  {
    return -1;
  }

  if (sll->head == NULL)
  {
    printf("List is empty\n");
  }
  else if (pos > sll->len)
  {
    printf("Position entered is out of range\n");
  }
  else if (pos == 1)
  {
    sll_delete_front(sll);
  }
  else
  {
    sll_node_t *temp = sll->head;
    sll_node_t *node = NULL;

    while (i < pos - 1)
    {
      temp = temp->next;
      i++;
    }

    node = temp->next;
    temp->next = node->next;

    free(node);
    node = NULL;

    sll->len--;
  }

  return 0;
}


/*
 * sll_reverse
 *
 * This function reverses the SLL
 *
 * @param[in]     sll          Pointer to singly linked list
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_reverse(sll_t *sll)
{
  sll_node_t *next = NULL;
  sll_node_t *prev = NULL;

  if (sll == NULL)
  {
    return -1;
  }

  if (sll->head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    sll_node_t *head = sll->head;

    while(head)
    {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    /* point SLL head to end of list */
    sll->head = prev;
  }

  return 0;
}


/* sll_print_list
 *
 * This function is a generic print function.
 * It will print the data from the list
 *
 * @param[in]     sll          Pointer to singly linked list
 *
 * @return 0 if SUCCESS and -1 on failure
 */
int sll_print_list(sll_t *sll)
{
  if (sll == NULL)
  {
    return -1;
  }

  sll_node_t *head = sll->head;

  printf("================================\n");
  printf("Length of the list: %u\n", sll->len);
  
  while(head)
  {
    sll->print_list(head->data);
    head = head->next;
  }

  printf("================================\n");
}
