/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode** stack_realloc(struct ListNode **stack, size_t size) {
    struct ListNode **new_stack = realloc(stack, size * sizeof(struct ListNode*));
    if (new_stack == NULL) {
        fprintf(stderr, "Stack memory allocation error.\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    return new_stack;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;

    size_t stack_size = 100;
    size_t stack_top = 0;
    struct ListNode **stack = stack_realloc(NULL, stack_size);
    
    // push nodes onto the stack
    for (struct ListNode *node = head; node != NULL; node = node->next) {
        if (stack_top >= stack_size) {
            stack = stack_realloc(stack, stack_size *= 2);
        }
        stack[stack_top++] = node;
    }

    // pop nodes from the stack
    for (struct ListNode *node = head = stack[--stack_top]; stack_top > 0; node = stack[--stack_top]) {
        node->next = stack[stack_top - 1];
    }

    stack[0]->next = NULL;
    free(stack);
    return head;
}
