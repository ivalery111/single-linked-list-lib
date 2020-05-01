#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef void *data;

/**
 * Opaque structure.
 */
typedef struct _linked_list linked_list;

/**
 * Create new list instance and initialize the head with NULL
 * 
 * @return on success: new list instance, on failure: NULL
 */
linked_list *get_linked_list_instance();

/**
 * Remove the linked list. Releases all nodes.
 */
void remove_linked_list_instance(linked_list *);

void add_node_linked_list(linked_list *, data);

/**
 * Removes the node from the head.
 * 
 * @return on succes: Data(void *) stored in node, on failure: NULL
 */
data remove_node_linked_list(linked_list *);

#endif