/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int remainder = 0;

    while (l1 != NULL || l2 != NULL || remainder > 0) {
        int sum = remainder;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        struct ListNode* tmp = malloc(sizeof(struct ListNode));
        tmp->val = sum % 10;
        tmp->next = NULL;

        if (head == NULL) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        remainder = sum > 9 ? 1 : 0;
    }
    return head;
}
