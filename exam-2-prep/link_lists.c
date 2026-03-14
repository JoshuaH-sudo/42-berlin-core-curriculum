#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

// int main()
// {
//     // Create nodes
//     struct Node *head = NULL;
//     struct Node *second = NULL;
//     struct Node *third = NULL;

//     // Allocate memory
//     head = (struct Node *)malloc(sizeof(struct Node));
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));

//     // Check allocation
//     if (!head || !second || !third) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     // Assign data and link nodes
//     head->data = 10;
//     head->next = second;

//     second->data = 20;
//     second->next = third;

//     third->data = 30;
//     third->next = NULL;

//     // Print linked list
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");

//     // Free allocated memory
//     temp = head;
//     while (temp != NULL)
//     {
//         struct Node *next = temp->next;
//         free(temp);
//         temp = next;
//     }

//     return 0;
// }
    typedef struct t_list
    {
        struct t_list *next;
        char          *data;
    } t_list;

int delete_first_match(t_list **head, const char *target)
{
    t_list *curr;
    t_list *prev;

    if (!head || !*head || !target)
        return 0;

    curr = *head;
    prev = NULL;

    while (curr)
    {
        if (strcmp(curr->data, target) == 0)
        {
            if (prev == NULL)
                *head = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

int main()
{


    t_list *head = NULL;
    t_list *second = NULL;
    t_list *third = NULL;

    head = malloc(sizeof(t_list));
    second = malloc(sizeof(t_list));
    third = malloc(sizeof(t_list));

    head->data = "hello";
    head->next = second;

    second->data = "world";
    second->next = third;

    third->data = "yeet";
    third->next = NULL;

    t_list *temp = head;
    while (temp != NULL)
    {
        printf("%s -> ", temp->data);
        temp = temp->next; 
    }
    delete_first_match(&head, "world");
    printf("\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
}