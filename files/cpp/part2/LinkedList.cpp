#include <iostream>

struct node_t {
    unsigned v;
    struct node_t* next = nullptr;
};

struct node_t* even_nodes(struct node_t**) {
    return nullptr;
};

void printlist(node_t* ptr) {
    node_t n = *ptr;
    std::cout << "List: [";

    while (true) {    
        std::cout << n.v;
        if (n.next == nullptr)
            break;
        std::cout << ", ";
        n = *n.next;
    }

    std::cout << "]" << std::endl;
}

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

    printlist(&n1);
    printlist(nullptr);
};
