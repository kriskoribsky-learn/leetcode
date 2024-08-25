/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    struct ListNode *list_end = reverseList(head->next);

    head->next->next = head;    // reverse next node to point to the current
    head->next = NULL;          // trim current node, will be overwritten

    return list_end;
}
