// https://leetcode.com/problems/reorder-list/
// 40 ms
// 15.7 MB

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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        if (head -> next == nullptr) return;
        
        queue<ListNode*> q;
        stack<ListNode*> s;
        
        ListNode* curr = head -> next;
        while (curr != nullptr) {
            q.push(curr);
            s.push(curr);
            curr = curr -> next;
        }
        
        curr = head;
        ListNode* forward;
        ListNode* reverse;
        bool odd = q.size() & 1;
        int n = (q.size()) / 2;
        int i = 0;
        while (i < n) {
            forward = q.front();
            reverse = s.top();
            q.pop();
            s.pop();
            
            curr -> next = reverse;
            reverse -> next = forward;
            curr = forward;
            ++i;
        }
        if (odd) {
            curr -> next = q.front();
            curr = curr -> next;
        }
        curr -> next = nullptr;
    }
};