/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **node = &head;
    while (*node != NULL) {
        if ((*node)->val == val) {
            *node = (*node)->next; // bypass the current node, repeat the cycle for check
        } else {
            node = &((*node)->next); // advance the double pointer to the next node
        }
    }
    return head;
}
