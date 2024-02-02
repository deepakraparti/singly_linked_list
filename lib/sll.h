/* 
 * sll.h
 *
 * Header file for singly linked list (SLL). 
 * This file contains the declaration of all the functionalities supported
 * by the singly linked list library.
 *
 */


#ifndef __SLL_H_
#define __SLL_H_

typedef struct sll_node
{
  void *data;
  struct sll_node *next;
}sll_node_t;

typedef struct sll
{
  sll_node_t *head;
  void (*print_list)(void *);
}sll_t;


/* function to create and return the new empty SLL */
sll_t *sll_create(void);

/* function to insert the data at the end of SLL */
int sll_insert_at_end(sll_t *sll, void *app_data);

/* callback registration functions */
void sll_register_print_list_callback(sll_t *sll, void (*print_list)(void *));

/* function to print the SLL */
int sll_print_list(sll_t *sll);

/* function to reverse the SLL */
int sll_reverse(sll_t *sll);


#endif /* __SLL_H_ */
