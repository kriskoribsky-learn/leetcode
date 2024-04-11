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

#define MAX_NODES 100

void check_capacity(int current_index);

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int stack_vals[MAX_NODES];
    int stack_vals_top = 0;

    struct TreeNode *stack_nodes[MAX_NODES];
    int stack_nodes_top = 0;

    struct TreeNode *current_node;
    stack_nodes[stack_nodes_top++] = root;
    while (stack_nodes_top > 0 && (current_node = stack_nodes[--stack_nodes_top]) != NULL) {
        check_capacity(stack_vals_top);
        stack_vals[stack_vals_top++] = current_node->val;

        if (current_node->left != NULL) {
            check_capacity(stack_nodes_top);
            stack_nodes[stack_nodes_top++] = current_node->left;
        }
        if (current_node->right != NULL) {
            check_capacity(stack_nodes_top);
            stack_nodes[stack_nodes_top++] = current_node->right;
        }
    }

    int *array_vals = malloc(MAX_NODES * sizeof(int));
    if (array_vals == NULL) {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    int array_index = 0;
    while(stack_vals_top > 0) {
        check_capacity(array_index);
        array_vals[array_index++] = stack_vals[--stack_vals_top];
    }

    *returnSize = array_index;
    return array_vals;
}

void check_capacity(int current_index) {
    if (current_index == MAX_NODES) {
        fprintf(stderr, "Maximum capacity of statically allocated array reached!\n");
        exit(EXIT_FAILURE);
    }
}
