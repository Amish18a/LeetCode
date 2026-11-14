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
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) return NULL;
        ListNode *ptr = head,*prev=NULL;
        for(ptr;ptr;ptr = ptr->next){
            if(ptr->val == val){
                if(prev == NULL) {head = ptr->next;continue;}
                prev->next = ptr->next;
            }
            else{
            prev = ptr;}
        }
        return head;
    }
};