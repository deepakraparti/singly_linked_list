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
  unsigned int len;
  void (*print_list)(void *);
  int (*search)(void *, void *);
  int (*compare)(void *, void *);
}sll_t;


/* function to create and return the new empty SLL */
sll_t *sll_create(void);

/* function to insert the data into SLL */
int sll_insert_at_end(sll_t *sll, void *app_data);
int sll_insert_at_front(sll_t *sll, void *app_data);
int sll_insert_at_pos(sll_t *sll, void *app_data, int pos);

/* function to delete the data from SLL */
int sll_delete_front(sll_t *sll);
int sll_delete_end(sll_t *sll);
int sll_delete_at_pos(sll_t *sll, int pos);

/* function to reverse the SLL */
int sll_reverse(sll_t *sll);

/* callback registration functions */
void sll_register_print_list_callback(sll_t *sll, void (*print_list)(void *));
void sll_register_search_callback(sll_t *sll, int (*search)(void *, void *));
void sll_register_compare_callback(sll_t *sll, int (*compare)(void *, void *));

/* function to search the data using key in SLL */
void *sll_search(sll_t *sll, void *key);

/* function to sort the SLL in acsending order */
void sll_sort_ascending(sll_t *sll);

/* function to print the SLL */
int sll_print_list(sll_t *sll);

#endif /* __SLL_H_ */
