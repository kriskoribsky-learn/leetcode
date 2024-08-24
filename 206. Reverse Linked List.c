/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    if (head->next->next == NULL) {
        head->next->next = head;
        struct ListNode *tmp = head->next;
        head->next = NULL;
        return tmp;
    }
    
    struct ListNode *new_head = reverseList(head->next);

    head->next->next = head;    // reverse next node to point to the current
    head->next = NULL;          // trim current node, will be overwritten

    return new_head;
}
