// https://leetcode.com/problems/remove-linked-list-elements/

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
class Solution {
public:
    // 24 ms
    // 13.4 MB
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        
        ListNode* curr = head;
        if (curr -> val == val) {
            while (curr && curr -> val == val) {
                curr = curr -> next;
            }
            if (curr == nullptr) return nullptr;
            head = curr;
        }
        
        ListNode* prev = curr;
        curr = curr -> next;
        while (curr) {
            if (curr -> val == val) {
                prev -> next = curr -> next;
            } else {
                prev = curr;
            }
            curr = curr -> next;
        }
        return head;
    }
};