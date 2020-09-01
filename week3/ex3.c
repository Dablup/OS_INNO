#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *next;
};
struct linked_list {
    struct node *head;
    int size;
};
void print_list(struct linked_list *list){
    if (list->size == 0){
        printf("The list is empty!\n");

    } else{
        struct node *tempNodeForHead;
        tempNodeForHead = list->head;
        printf("Printing the list: ");
        while (list->head!= NULL){
            printf("%d ",list->head->value);
            list->head = list->head->next;
        }
        list->head = tempNodeForHead;
        printf("\n");
    }

}
void insert_node(struct linked_list *list, int insertAfterWhatValue, int val){
    int checker = 0;
    if (list->size == 0) {
        printf("Linked list does not any value therefore value %d was added at the 1 position of the list\n", val);
        list->head->value = val;
        list->size++;
    } else if (list->size == 1 && list->head->value != insertAfterWhatValue){
        printf("There is no element: %d in the list\n", insertAfterWhatValue);
    } else {
        struct node *tempNodeForHead;
        tempNodeForHead = list->head;

        while (list->head->value != insertAfterWhatValue){
            list->head = list->head->next;
            if (list->head->next == NULL && list->head->value != insertAfterWhatValue){
                printf("There is no element: %d in the list\n", insertAfterWhatValue);
                checker++;
                break;
            }
        }
        if (checker == 0){
            struct node *new_node = malloc(sizeof(struct node));
            struct node *tempNode;
            tempNode = list->head->next;
            list->head->next = new_node;
            new_node->next = tempNode;
            new_node->value = val;
            list->size++;
        }

        list->head = tempNodeForHead;
    }
}
void delete_node(struct linked_list *list, int val){
    if (list->size == 1 && list->head->value == val){
        list->head = NULL;
        list->size--;
    } else if (list->size == 1 && list->head->value != val){
            printf("There is no element: %d in the list\n", val);
    } else {
        struct node *tempNodeForHead;
        tempNodeForHead = list->head;
        if (list->head->value == val){
            list->head = list->head->next;
            list->size--;
        } else{
            while (list->head->next->value != val){
                list->head = list->head->next;
                if (list->head->next == NULL){
                    printf("There is no element: %d in the list\n", val);
                    break;
                }
            }
            if (list->head->next != NULL && list->head->next->next != NULL){
                list->head->next = list->head->next->next;
                list->size--;
            } else if (list->head->next == NULL && list->head->value == val){
                list->head = NULL;
                list->size--;
            } else if (list->head->next != NULL && list->head->next->next == NULL){
                list->head->next = NULL;
                list->size--;
            }
            list->head = tempNodeForHead;

        }
    }
}
int main() {
    struct linked_list *list1 = malloc(sizeof(struct linked_list()));   // creating a list using struct
    struct node *head = malloc(sizeof(struct node()));                                                  // creating a node using struct
    head->next = NULL;                                                  // set the next node of head is to NULL
                                                   // set the value of the node to NULL
    list1->size = 0;                                                    // set the size of the list to 0
    list1->head = head;                                                 // set the head of the list to our node 'head'


    print_list(list1);                                                  // check if it is printing that list is empty
    insert_node(list1,2,0);                     // insert first value(it will be inserted into 1 place since there are no elements in list)
    insert_node(list1,0,100);                   // insert value '150' after the value '100'
    insert_node(list1,100,150);
    print_list(list1);                                                  // check if it is printing everything after adding
    delete_node(list1,150);                                         // check if it deleting the last element correctly
    print_list(list1);
    insert_node(list1,100,125);
    print_list(list1);
    delete_node(list1,0);                                         // check if it deleting the first element correctly
    delete_node(list1,1000);                                        // it will write that there is no such element in the list
    print_list(list1);
    insert_node(list1,125,123213);
    insert_node(list1,125,123213213);
    insert_node(list1,1,555);                   // inserting after non-existent value(it will print that there is no such value)
    print_list(list1);


    return 0;
}

