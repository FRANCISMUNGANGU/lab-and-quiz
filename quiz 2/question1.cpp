#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
}

// Example usage
int main() {
    // Create a linked list: 3 -> 2 -> 0 -> -4 -> cycle back to 2
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    //position of cycle
    int pos;
    std::cout << "Which node should the cycle point to?0, 1, 2, 3? You can put -1 if you don't want a cycle: "<< std::endl;
    std::cin >> pos;

    // Create cycle
    switch(pos){
        case -1:
            head->next->next->next->next = nullptr;
            break;
        case 0:
            head->next->next->next->next = head;
            break;
        case 1:
            head->next->next->next->next = head->next;
            break;
        case 2:
            head->next->next->next->next = head->next->next;
            break;
        case 3:
            head->next->next->next->next = head->next->next->next;
            break;
    }


    // Check if the linked list has a cycle
    bool result = hasCycle(head);
    std::cout << (result ?"True" : "False") << std::endl;

    return 0;
}
