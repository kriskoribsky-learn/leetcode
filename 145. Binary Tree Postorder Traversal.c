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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int *array_vals = malloc(MAX_NODES * sizeof(int));
    if (array_vals == NULL) {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    int array_size = 0;

    struct TreeNode *stack_nodes[MAX_NODES];
    int stack_top = 0;

    stack_nodes[stack_top++] = root;

    struct TreeNode *current_node;
    while(stack_top > 0 && (current_node = stack_nodes[--stack_top]) != NULL) {
        // push child nodes onto the stack
        if (root->right != NULL) {
            if (stack_top == MAX_NODES) {
                fprintf(stderr, "Maximum capacity of node stack reached!\n");
                exit(EXIT_FAILURE);
            }
            stack_nodes[stack_top++] = root->right;
        }
        if (root->left != NULL) {
            
        }
    }
}
