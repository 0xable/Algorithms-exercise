// https://leetcode.com/problems/add-two-numbers/

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
    // 68 ms
    // 70.2 MB
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit = l1 -> val + l2 -> val;
        int carry = digit / 10;
        digit %= 10;
        
        ListNode* result = new ListNode(digit);
        ListNode* curr = result;
        l1 = l1 -> next;
        l2 = l2 -> next;
        while (l1 != nullptr && l2 != nullptr) {
            digit = l1 -> val + l2 -> val + carry;
            carry = digit / 10;
            
            l1 = l1 -> next;
            l2 = l2 -> next;
            curr -> next = new ListNode(digit % 10);
            curr = curr -> next;
        }
        
        ListNode* remain = l1 != nullptr ? l1 : l2;
        while (remain != nullptr) {
            digit = remain -> val + carry;
            carry = digit / 10;
            
            remain = remain -> next;
            curr -> next = new ListNode(digit % 10);
            curr = curr -> next;
        }
        if (carry) curr -> next = new ListNode(1);
        
        return result;
    }
};