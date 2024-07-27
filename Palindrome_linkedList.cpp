#include <iostream>
#include <vector>

using namespace std;

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
    bool isPalindrome(ListNode* head) {
        vector<int> listVals;
        while (head) {
            listVals.push_back(head->val);
            head = head->next;
        }
        
        int left = 0, right = listVals.size() - 1;
        while (left < right && listVals[left] == listVals[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
};

// Function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Function to clean up a linked list
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test case 1: Palindrome
    vector<int> vals1 = {1, 2, 2, 1};
    ListNode* head1 = createLinkedList(vals1);
    cout << (sol.isPalindrome(head1) ? "True" : "False") << endl; // Expected output: True
    deleteLinkedList(head1);

    // Test case 2: Not a palindrome
    vector<int> vals2 = {1, 2, 3, 4};
    ListNode* head2 = createLinkedList(vals2);
    cout << (sol.isPalindrome(head2) ? "True" : "False") << endl; // Expected output: False
    deleteLinkedList(head2);

    // Test case 3: Single element (palindrome)
    vector<int> vals3 = {1};
    ListNode* head3 = createLinkedList(vals3);
    cout << (sol.isPalindrome(head3) ? "True" : "False") << endl; // Expected output: True
    deleteLinkedList(head3);

    return 0;
}
