/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    struct ListNode *prev = head;
    struct ListNode *curr = head->next;
    struct ListNode *next = head->next->next;

    while (next != NULL) {
        curr->next = prev;

        prev = curr;
        curr = next;
        next = next->next;
    }

    curr->next = prev; // begin linked list
    head->next = NULL; // end linked list
    
    return curr;
}
