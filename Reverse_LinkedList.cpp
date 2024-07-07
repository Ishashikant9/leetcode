#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    for (ListNode* curr = head; curr != NULL; curr = curr->next) {
        cout << curr->val << " ";
    }
    cout << endl;
}

// Function to create a linked list from an array of values
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int n = sizeof(values) / sizeof(values[0]);
    ListNode* head = createList(values, n);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
