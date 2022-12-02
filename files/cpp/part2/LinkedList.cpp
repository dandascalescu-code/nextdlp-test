#include <iostream>
#include <string>

/* 
    Work in progress...
*/

struct node_t {
    unsigned v;
    node_t* next = nullptr;
};

std::string list_string(node_t* headptr) {
    std::string s = "";

    s += "[";

    node_t* currentptr = headptr;
    while (currentptr != nullptr) {
        node_t current = *currentptr;
        s += std::to_string(current.v);
        currentptr = current.next;
        if (currentptr != nullptr)
            s += ", ";
    }

    s += "]";
    
    return s;
}

void print_node(node_t* ptr) {
    std::cout
        << "Node " << ptr << std::endl
        << "\tValue: " << (*ptr).v << std::endl
        << "\tNext: " << (*ptr).next << std::endl;
}

node_t* even_nodes(node_t** ptr) {
    node_t* headptr = *ptr;
    node_t* currentptr = headptr;
    node_t* prevptr = nullptr;

    node_t* new_headptr = nullptr;
    node_t* new_currentptr = new_headptr;

    std::cout << "\nStart" << std::endl;
    std::cout << list_string(headptr) << " " << list_string(new_headptr) << std::endl;
    while (currentptr != nullptr) {
        //std::cout << "\nloop" << std::endl;
        node_t* nextptr = (*currentptr).next;
        //std::cout << "Current "; print_node(currentptr);
        std::cout << "(Node " << currentptr << ") ";
        if ((*currentptr).v % 2 == 0) {
            // remove from given list
            if (prevptr == nullptr) {
                //std::cout << "No previous" << std::endl;
                //std::cout << "setting new head..." << std::endl;
                headptr = nextptr;
            } else {
                //std::cout << "Previous "; print_node(prevptr);
                //std::cout << "changing..." << std::endl;
                (*prevptr).next = nextptr;
                //std::cout << "Previous "; print_node(prevptr);
            }
            (*currentptr).next = nullptr;

            // add to new list
            if (new_currentptr == nullptr)
                new_headptr = currentptr;
            else
                (*new_currentptr).next = currentptr;
            
            // update current pointers
            currentptr = nextptr;
            if (new_currentptr == nullptr)
                new_currentptr = new_headptr;
            else
                new_currentptr = (*new_currentptr).next;

            //std::cout << "Current "; print_node(currentptr);
            //std::cout << "New Current "; print_node(new_currentptr);
        } else {
            // update pointers
            prevptr = currentptr;
            currentptr = nextptr;
        }

        std::cout << list_string(headptr) << " " << list_string(new_headptr) << std::endl;
    }

    std::cout << "End\n" << std::endl;

    // Point given pointer to head pointer, which may have changed
    *ptr = headptr;
    return new_headptr;
};

/* The following is a test of the even_nodes method functionality */

main() {
    std::cout
        << "\n===== Test =====\n";
    
    node_t n1;
    n1.v = 0;
    node_t n2;
    n2.v = 1;
    node_t n3;
    n3.v = 2;
    node_t n4;
    n4.v = 3;
    node_t n5;
    n5.v = 4;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    node_t* headptr1 = &n1;
    node_t* headptr2 = nullptr;
    
    std::cout
        << "Head pointer: "<< headptr1 << std::endl;
    std::cout
        << "List: " << list_string(headptr1) << std::endl;

    node_t* new_headptr1 = even_nodes(&headptr1);

    std::cout
        << "Head pointer: " << headptr1 << std::endl; // note list now points to different location (node 1)
    std::cout
        << "List: " << list_string(headptr1) << std::endl;
    
    std::cout
        << "New list head pointer: " << new_headptr1 << std::endl; // note new list pointer equals original (node 0)
    std::cout
        << "New list: " << list_string(new_headptr1) << std::endl;


    std::cout
        << "\n===== Test 2 =====\n";


    std::cout
        << "Head pointer: " << headptr2 << std::endl;
    std::cout
        << "List: " << list_string(headptr2) << std::endl;

    node_t* new_headptr2 = even_nodes(&headptr2);

    std::cout
        << "Head pointer: " << headptr2 << std::endl; // note list now points to different location (node 1)
    std::cout
        << "List: " << list_string(headptr2) << std::endl;
    
    std::cout
        << "New list head pointer: " << new_headptr2 << std::endl; // note new list pointer equals original (node 0)
    std::cout
        << "New list: " << list_string(new_headptr2) << std::endl;

};

/* End of test */
