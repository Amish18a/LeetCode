class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);                              // CHANGE 1: dummy node, so we can always return dummy.next
        ListNode *groupPrev = &dummy;                         // node just before the current group
        ListNode *preptr = NULL, *ptr = NULL, *prepreptr = NULL, *nxt = NULL;

        while (true) {                                        // CHANGE 2: we break manually instead of testing ptr
            preptr = groupPrev->next;                         // first node of this group
            ptr = preptr;
            int i = k;
            while (i != 1) {
                if (ptr == NULL) break;
                ptr = ptr->next;
                i--;
            }
            if (ptr == NULL) break;                           // CHANGE 3: break (not return head), fewer than k nodes left

            ListNode* groupNext = ptr->next;                  // CHANGE 4: remember the node after the group
            ListNode* start = preptr;                         // old first node, it becomes the group's tail
            prepreptr = groupNext;                            // CHANGE 5: reset per group; the new tail links to the rest

            while (preptr != groupNext) {                     // CHANGE 6: runs through the kth node too
                nxt = preptr->next;
                preptr->next = prepreptr;
                prepreptr = preptr;
                preptr = nxt;
            }

            groupPrev->next = ptr;                            // CHANGE 7: previous part now points to the new head (kth node)
            groupPrev = start;                                // next group starts after this group's new tail
        }
        return dummy.next;                                    // CHANGE 8: not head
    }
};                                                            // CHANGE 9: the semicolon you were missing