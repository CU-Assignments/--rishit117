#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0), *prev = dummy;
    dummy->next = head;

    while (head) {
        if (head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) head = head->next;
            prev->next = head->next; // Skip all duplicates
        } else prev = prev->next; // Move forward if no duplicate
        head = head->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    printList(head);
    head = deleteDuplicates(head);
    printList(head);

    return 0;
}
