// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // 8 ms
    // 7.2 MB
    Node* flatten(Node* head) {
        process(head);
        return head;
    }
    
    Node* process(Node* head) {
        if (head == nullptr) return head;
        if (head -> child == nullptr) {
            if (head -> next)
                return process(head -> next);
            return head;
        }
        
        if (head -> next == nullptr) {
            head -> child -> prev = head;
            head -> next = head -> child;
            head -> child = nullptr;
            return process(head -> next);
        } else {
            Node* currNext = head -> next;
            head -> child -> prev = head;
            head -> next = head -> child;
            head -> child = nullptr;
            
            Node* processEnd = process(head -> next);
            processEnd -> next = currNext;
            currNext -> prev = processEnd;
            return process(currNext);
        }
    }
};