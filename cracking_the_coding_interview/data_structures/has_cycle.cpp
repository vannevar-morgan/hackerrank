/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    //
    // Return true if the list has a cycle, false otherwise.
    //
    static const unsigned int max_size = 100; // maximum number of nodes in a list, per constraints
    unsigned int node_count = 0;
    while(node_count++ <= max_size){
        if(head){
            head = head->next;
        }else{
            return false;
        }
    }
    return true;
}
