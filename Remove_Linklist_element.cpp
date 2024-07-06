#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

// Function to print the list 
void printList(ListNode* head){
    ListNode* current = head;
    while(current!= nullptr){
      cout<< current->val <<"->";
      current = current->next;
    }
    cout<<"nullptr"<<endl;
}

int main()
{
      // Creating a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    int valToRemove = 6;
    head = solution.removeElements(head, valToRemove);

    cout << "List after removing " << valToRemove << ": ";
    printList(head);

    // Freeing remaining allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}