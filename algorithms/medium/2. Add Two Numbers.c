/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* curr = NULL;
    int remainder = 0;
    
    while (l1 != NULL || l2 != NULL || remainder > 0) {
        int sum = 0;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        struct ListNode* tmp = malloc(sizeof(struct ListNode));
        tmp->val = (sum + remainder) % 10;
        tmp->next = NULL;

        if (head == NULL) {
            head = curr = tmp;
        } else {
            curr->next = tmp;
            curr = tmp;
        }
        remainder = (sum + remainder) / 10;
    }
    return head;
}
