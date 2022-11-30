#include <iostream>

/* 
    Work in progress...
*/

struct node_t {
    unsigned v;
    node_t* next = nullptr;
};

node_t* even_nodes(node_t** ptr) {
    node_t* headptr = *ptr;

    node_t* evens_headptr = nullptr;

    node_t* currentptr = headptr;
    while (currentptr != nullptr) {
        node_t current = *currentptr;
        if (current.v % 2 == 0) {
            //
        }
    }

    return evens_headptr;
};

void addNodeToList(node_t** ptr, node_t* nptr) {
    node_t* headptr = *ptr;
    if (headptr == nullptr) {
        headptr = nptr;
        return;
    }

    node_t* currentptr = headptr;
    while (true) {
        node_t current = *currentptr;
        if (current.next == nullptr) {
            current.next = nptr;
            return;
        }
        currentptr = current.next;
    }
}

void addValueToList(node_t** ptr, unsigned v) {
    node_t n;
    n.v = v;
    addNodeToList(ptr, &n);
}

bool removeNodeFromList(node_t* headptr, node_t* nptr) {
    /*if (headptr == nullptr) {
        return false;
    }*/

    node_t* currentptr = headptr;
    node_t* previousptr = nullptr;
    while (currentptr != nullptr) {
        node_t* nextptr = (*currentptr).next;
        if (currentptr == nptr) {
            if (previousptr == nullptr) {
                headptr = nextptr;
            } else {
                (*previousptr).next = nextptr;
            }
            return true;
        }
        currentptr = nextptr;
    }
    return false;
}

void printlist(node_t** ptr) {
    node_t* headptr = *ptr;
    std::cout << "List: [";

    node_t* currentptr = headptr;
    while (currentptr != nullptr) {
        node_t current = *currentptr;
        std::cout << current.v;
        currentptr = current.next;
        if (currentptr != nullptr)
            std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}

main() {
    std::cout
        << "\n===== Test =====\n";
    
    /*node_t n1;
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
    node_t* headptr2 = nullptr;*/

    node_t* headptr = nullptr;
    addValueToList(&headptr, 0);
    std::cout << headptr;

};
