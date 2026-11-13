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
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(0), bigDummy(0);
        ListNode *s = &smallDummy, *b = &bigDummy;

        for(ListNode* cur = head;cur;cur = cur->next){
            if(cur->val < x) {
                s->next = cur;
                s = s->next;
            }
            else{
                b->next = cur;
                b = b->next;
            }
        }
        b->next = nullptr;
        s->next = bigDummy.next;
        return smallDummy.next;
    }
};