#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) {
        return nullptr; // No cycle
    }

    ListNode* slow = head;
    ListNode* fast = head;
    int counter = 0;

    // Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break; // Cycle detected

        }
    }

    // If no cycle, return nullptr
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    // Move slow to head and advance both slow and fast by one step
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        counter++;

    }
    if (slow == fast){

        std::cout << "tail connects to node index "<< counter << std::endl;


    }

    return slow; // Return starting node of cycle
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





    // Find the starting node of the cycle
    ListNode* cycleStart = detectCycle(head);
    if (cycleStart == nullptr) {
        std::cout << "There is no cycle in the linked list." << std::endl;
    }

    return 0;
}
