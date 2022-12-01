#include <iostream>

/* 
    Work in progress...
*/

struct node_t {
    unsigned v;
    node_t* next = nullptr;
};

std::ostream& operator<<(std::ostream& os, const node_t& node) {
    return os 
            << "Node " << &node << std::endl
            << "\tValue: " << node.v << std::endl
            << "\tNext pointer: " << node.next << std::endl;
};

node_t* even_nodes(node_t** ptr) {
    return nullptr;
};

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
    
    std::cout << *headptr1 << std::endl;
};
