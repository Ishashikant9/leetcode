#include <iostream>
#include <cmath> // Include cmath for the pow function

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to get the length of the linked list
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        
        return length;
    }
 
    // Function to get the decimal value from the binary linked list
    int getDecimalValue(ListNode* head) {
        int len = getLength(head) - 1;
        int x, total = 0;
        ListNode* current = head;
        while(len >= 0) {
            x = current->val;
            total = total + pow(2, len) * x;
            len--;
            current = current->next;
        }
        return total;
    }
};

int main() {
    // Example input: [1, 0, 1]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution solution;
    int result = solution.getDecimalValue(head);
    std::cout << "Decimal value of the binary linked list: " << result << std::endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
