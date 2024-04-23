#include <iostream>

using namespace std;


class ListNodes{
    public:
        int val;
        ListNodes* next;
        ListNodes* previous;

        ListNodes(int value): val(value),previous(nullptr),next(nullptr){}
};

ListNodes* Reversed_List(ListNodes* head){
    if(head == nullptr){
        return nullptr;
    }
    ListNodes* current = head;
    ListNodes* prev = nullptr;
    ListNodes* nextNode = nullptr;

    while(current != nullptr){

        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;


    }
    return prev;

}

int main()
{
    ListNodes* head = new ListNodes(3);
    head->next = new ListNodes(2);
    head->next->previous = head;
    head->next->next = new ListNodes(1);
    head->next->next->previous = head->next;
    head->next->next->next = new ListNodes(0);
    head->next->next->next->previous = head->next->next;
    head->next->next->next->next = new ListNodes(4);
    head->next->next->next->next->previous = head->next->next->next;

    ListNodes* reversal = Reversed_List(head);
    cout << "Reversed List: ";
    while(reversal != nullptr){
        cout << reversal->val << " ";
        reversal = reversal->next;

    }
    return 0;
}
