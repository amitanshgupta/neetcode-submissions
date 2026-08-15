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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* front = cur->next;
            cur->next = prev;
            prev = cur;
            cur = front;
        }
        return prev;
    }
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head || !head->next) return;

        ListNode* first = head;

        ListNode* middle = mid(head);
        ListNode* second = middle->next;

        middle->next = nullptr;   // split the two lists

        second = reverseList(second);

        while(first && second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
