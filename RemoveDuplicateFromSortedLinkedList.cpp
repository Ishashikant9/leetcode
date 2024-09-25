#include <iostream>
using namespace std;


 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* st = temp;
            while (temp->next != NULL && temp->next->val == temp->val) {
                temp = temp->next;
            }
            if (prev == NULL) {
                if (st == temp) {
                    prev = st;
                } else {
                    head = temp->next;
                }
            } else if (st == temp) {
                prev = st;
            } else {
                prev->next = temp->next;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    printList(result);  // Output the result list

    return 0;
}
