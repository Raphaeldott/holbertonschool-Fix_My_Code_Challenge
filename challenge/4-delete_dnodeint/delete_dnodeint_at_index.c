#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
 int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
 {
     dlistint_t *temp;
     unsigned int i;
 
     if (*head == NULL)
         return (-1);
 
     temp = *head;
 
     for (i = 0; temp != NULL && i < index; i++)
         temp = temp->next;
 
     if (temp == NULL)
         return (-1);
 
     if (temp == *head)  /* Deleting the head node */
     {
         *head = temp->next;
         if (*head != NULL)
             (*head)->prev = NULL;
     }
     else if (temp->next == NULL)  /* Deleting the last node */
     {
         temp->prev->next = NULL;
     }
     else  /* Deleting a middle node */
     {
         temp->prev->next = temp->next;
         temp->next->prev = temp->prev;
     }
 
     free(temp);
     return (1);
 } 