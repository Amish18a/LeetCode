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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,*fast = head,*prev = NULL,*nxt,*ptr = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        while (slow!=NULL){
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        while(prev!=NULL){
            if (prev->val != ptr->val) return false;
            prev = prev->next;
            ptr = ptr->next;
        }
        return true;
    }
};