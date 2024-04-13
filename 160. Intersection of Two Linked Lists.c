/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    struct ListNode *node_a = headA;
    struct ListNode *node_b = headB;
    int len_a = 1;
    int len_b = 1;

    while(node_a->next != NULL || node_b->next != NULL) {
        if (node_a->next != NULL) {
            node_a = node_a->next;
            len_a++;
        }
        if (node_b->next != NULL) {
            node_b = node_b->next;
            len_b++;
        }
    }

    if (node_a != node_b) {
        return NULL;
    }

    int wait_a = len_b > len_a ? len_b - len_a : 0;
    int wait_b = len_a > len_b ? len_a - len_b : 0;

    node_a = headA;
    node_b = headB;
    while (node_a != node_b) {
        if (wait_a > 0) {
            wait_a--;
        } else {
            node_a = node_a->next;
        }
        if (wait_b > 0) {
            wait_b--;
        } else {
            node_b = node_b->next;
        }
    }
    return node_a;
}
