/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned long long num1 = 0, num2 = 0;
    unsigned long long base1 = 1, base2 = 1;
    
    while(l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            num1 += base1 * l1->val;
            base1 *= 10;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            num2 += base2 * l2->val;
            base2 *= 10;
            l2 = l2->next;
        }
    }
    unsigned long long sum = num1 + num2;

    printf("sum: %llu\n");

    struct ListNode *res_head = malloc(sizeof(struct ListNode));
    res_head->val = sum % 10;
    res_head->next = NULL;
    sum /= 10;

    struct ListNode *res_curr = res_head;
    while (sum > 0) {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));
        tmp->val = sum % 10;
        tmp->next = NULL;
        sum /= 10;

        res_curr->next = tmp;
        res_curr = tmp;
    }
    return res_head;
}
