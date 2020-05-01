#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    data *node_data;
    struct _node *next;
} node;

struct _linked_list
{
    node *head;
};

linked_list *get_linked_list_instance()
{
    linked_list *list_instance = (linked_list *)malloc(sizeof(linked_list));
    if (list_instance == NULL)
    {
        printf("[%s]:[ERROR]: Faield to allocate a memory for list_instance!\n", __FUNCTION__);
        return NULL;
    }

    list_instance->head = NULL;

    return list_instance;
}

void remove_linked_list_instance(linked_list *list)
{
    node *temp = list->head;

    while (temp != NULL)
    {
        free(temp->node_data); /* Maybe memory leak? */

        node *current = temp;
        temp = temp->next;

        free(current);
    }

    free(list);
}

void add_node_linked_list(linked_list *list, data new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("[%s]:[ERROR]: Faield to allocate a memory for new_node!\n", __FUNCTION__);
        return;
    }
    new_node->node_data = new_data;

    if (list->head == NULL)
    {
        new_node->next = NULL;
        list->head = new_node;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
    }
}

data remove_node_linked_list(linked_list *list)
{
    if (list->head == NULL)
    {
        printf("[%s]:[ERROR]: Linked List is empty!\n", __FUNCTION__);
        return NULL;
    }
    node *temp = list->head;
    list->head = list->head->next;

    data *data_to_return = NULL;
    data_to_return = temp->node_data;

    free(temp);

    return data_to_return;
}