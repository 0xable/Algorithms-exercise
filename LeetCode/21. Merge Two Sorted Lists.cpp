// https://leetcode.com/problems/merge-two-sorted-lists/
// 12 ms
// 15 MB

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode* result;
        if (l1 -> val < l2 -> val) {
            result = l1;
            l1 = l1 -> next;
        } else {
            result = l2;
            l2 = l2 -> next;
        }
        
        ListNode* curr = result;
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                curr -> next = l1;
                curr = curr -> next;
                l1 = l1 -> next;
            } else {
                curr -> next = l2;
                curr = curr -> next;
                l2 = l2 -> next;
            }
        }
        
        if (l1) curr -> next = l1;
        if (l2) curr -> next = l2;
        return result;
    }
};