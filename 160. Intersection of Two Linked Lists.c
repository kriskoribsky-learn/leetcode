/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *node_a = headA;
    struct ListNode *node_b = headB;

    while(node_a != node_b) {
        node_a = node_a == NULL ? headB : node_a->next;
        node_b = node_b == NULL ? headA : node_b->next;
    }
    
    return node_a;
}
