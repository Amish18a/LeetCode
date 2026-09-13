class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        // 1. Calculate length and find tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Optimize k
        k = k % length;
        if (k == 0) return head;

        // 3. Find new tail (length - k - 1 steps from head)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // 4. Reconnect
        ListNode* newHead = newTail->next;
        newTail->next = nullptr; // Break the list
        tail->next = head;       // Connect old tail to old head

        return newHead;
    }
};   