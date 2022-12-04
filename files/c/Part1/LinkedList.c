#include <stdlib.h>
#include <stdio.h>

/*
    Work in progress...
*/

/// @brief Struct representing a node in a singly linked list
struct node_t {
    unsigned v;
    struct node_t* next;
};

/// @param headptr, the pointer to the head node of a given list
void print_list(struct node_t* headptr) {
    printf("[");

    struct node_t* currentptr = headptr;
    while (currentptr != NULL) {
        printf("%d", (*currentptr).v);
        currentptr = (*currentptr).next;
        if (currentptr != NULL)
            printf(", ");
    }

    printf("]\n");
}

/// @brief Removes any even nodes from a given list, adding them to a new list
/// @param ptr, the pointer (to the pointer) to the head node of the given list - this list is edited in-place
/// @return a pointer to the head node of the new list of even nodes
struct node_t* even_nodes(struct node_t** ptr) {
    struct node_t* headptr = *ptr;
    struct node_t* currentptr = headptr;
    struct node_t* prevptr = NULL;

    struct node_t* new_headptr = NULL;
    struct node_t* new_currentptr = new_headptr;

    while (currentptr != NULL) {
        struct node_t* nextptr = (*currentptr).next;

        if ((*currentptr).v % 2 == 0) {
            // remove from given list
            if (prevptr == NULL) {
                headptr = nextptr;
            } else
                (*prevptr).next = nextptr;
            (*currentptr).next = NULL;

            // add to new list
            if (new_currentptr == NULL)
                new_headptr = currentptr;
            else
                (*new_currentptr).next = currentptr;
            
            // update current pointers
            currentptr = nextptr;
            if (new_currentptr == NULL)
                new_currentptr = new_headptr;
            else
                new_currentptr = (*new_currentptr).next;
        } else {
            // update pointers
            prevptr = currentptr;
            currentptr = nextptr;
        }
    }

    // Point given pointer to head pointer, which may have changed
    *ptr = headptr;
    return new_headptr;
};

/* The following is a test of the even_nodes method functionality */

int main() {
    
    printf( "\n===== Test =====\n");
    
    struct node_t n1;
    n1.v = 0;
    struct node_t n2;
    n2.v = 1;
    struct node_t n3;
    n3.v = 2;
    struct node_t n4;
    n4.v = 3;
    struct node_t n5;
    n5.v = 4;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    struct node_t* headptr1 = &n1;


    printf("Head pointer: %p\n", headptr1);
    printf("List: "); print_list(headptr1);

    struct node_t* new_headptr1 = even_nodes(&headptr1);

    printf("Head pointer: %p\n", headptr1); // note list now points to different location (node 1)
    printf("List: "); print_list(headptr1);
    
    printf("New list head pointer: %p\n", new_headptr1); // note new list pointer equals original (node 0)
    printf("New list: "); print_list(new_headptr1);

    // =====================

    printf("\n===== Test 2 =====\n");

    struct node_t* headptr2 = NULL;


    printf("Head pointer: %p\n", headptr2);
    printf("List: "); print_list(headptr2);

    struct node_t* new_headptr2 = even_nodes(&headptr2);

    printf("Head pointer: %p\n", headptr2); // note list now points to different location (node 1)
    printf("List: "); print_list(headptr2);
    
    printf("New list head pointer: %p\n", new_headptr2); // note new list pointer equals original (node 0)
    printf("New list: "); print_list(new_headptr2);

    return 0;
};

/* End of test */
