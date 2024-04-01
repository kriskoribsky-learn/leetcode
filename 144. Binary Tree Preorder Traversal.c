/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_SIZE 1000

struct ValueArray {
        int *array;
        size_t size;
};

void array_append(struct ValueArray *values, int value);

bool array_full(struct ValueArray *values);

bool array_empty(struct ValueArray *values);

struct NodeStack {
        struct TreeNode **nodes;
        size_t top;
};

void stack_push(struct NodeStack *stack, struct TreeNode *node);

struct TreeNode *stack_pop(struct NodeStack *stack);

bool stack_full(struct NodeStack *stack);

bool stack_empty(struct NodeStack *stack);

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    struct ValueArray values = {
        .array = NULL,
        .size = 0
    };

    struct NodeStack stack = {
        .nodes = NULL,
        .top = -1,
    };

    stack_push(&stack, root);
    struct TreeNode *node = stack_pop(&stack);
    printf("%d", node->val);

    free(values.array);
    free(stack.nodes);

    *returnSize = values.size;
    return values.array;
}

void array_append(struct ValueArray *values, int value) {
    if (array_full(values)) {
        fprintf(stderr, "Maximum capacity of array reached.\n");
        free(values->array);
        exit(EXIT_FAILURE);
    }

    values->size++;
    int *tmp = realloc(values->array, values->size * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "Array memory reallocation error.\n");
        free(values->array);
        exit(EXIT_FAILURE); 
    }

    values->array = tmp;
    values->array[values->size - 1] = value;
}

bool array_full(struct ValueArray *values) {
    return values->size == MAX_SIZE;
}

bool array_empty(struct ValueArray *values) {
    return values->size == 0;
}

void stack_push(struct NodeStack *stack, struct TreeNode *node) {
    if (stack_full(stack)) {
        fprintf(stderr, "Maximum capacity of stack reached.\n");
        free(stack->nodes);
        exit(EXIT_FAILURE);
    }

    stack->top++;
    struct TreeNode *tmp = realloc(stack->nodes, (stack->top + 1) * sizeof(struct TreeNode));
    if (tmp == NULL) {
        fprintf(stderr, "Stack memory reallocation error.\n");
        free(stack->nodes);
        exit(EXIT_FAILURE);
    }

    stack->nodes = tmp;
    stack->nodes[stack->top] = node; 
}

struct TreeNode *stack_pop(struct NodeStack *stack) {
    if (stack_empty(stack)) {
        return NULL;
    }

    struct TreeNode *node = stack->nodes[stack->top];
    stack->top--;
    struct TreeNode *tmp = realloc(stack->nodes, (stack->top + 1) * sizeof(struct TreeNode));
    if (tmp == NULL) {
        fprintf(stderr, "Stack memory reallocation error.\n");
        free(stack->nodes);
        exit(EXIT_FAILURE);
    }

    stack->nodes = tmp;
    return node;
}

bool stack_full(struct NodeStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool stack_empty(struct NodeStack *stack) {
    return stack->top == -1;
}
