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
    struct Cmp{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        
        for(auto list : lists){
            if(list) pq.push(list);
        }

        ListNode* head = nullptr;
        ListNode* temp = nullptr;

        while(!pq.empty()){
            ListNode* listTop = pq.top();
            pq.pop();
            if(!head){
                head = listTop;
                temp = head;
            }else{
                temp->next = listTop;
                temp = temp->next;
            }
            if(listTop->next != nullptr){
                pq.push(listTop->next);
            }
        }
        return head;
    }
};