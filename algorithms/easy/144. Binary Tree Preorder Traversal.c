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

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int *array_vals = malloc(MAX_NODES * sizeof(int));
    if (array_vals == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    int array_count = 0;

    struct TreeNode *stack_nodes[MAX_NODES];
    int stack_top = 0;

    stack_nodes[stack_top++] = root; 
    
    struct TreeNode *current_node;
    while (stack_top > 0 && (current_node = stack_nodes[--stack_top]) != NULL) {
        // save val of the current node
        if (array_count == MAX_NODES) {
            fprintf(stderr, "Maximum value array capacity reached!\n");
            exit(EXIT_FAILURE);
        }
        array_vals[array_count++] = current_node->val;

        // push child nodes onto the stack
        if (current_node->right != NULL) {
            if (stack_top == MAX_NODES) {
                fprintf(stderr, "Maximum node stack capacity reached!\n");
                exit(EXIT_FAILURE);
            }
            stack_nodes[stack_top++] = current_node->right;
        }
        if (current_node->left != NULL) {
            if (stack_top == MAX_NODES) {
                fprintf(stderr, "Maximum node stack capacity reached!\n");
                exit(EXIT_FAILURE);
            }
            stack_nodes[stack_top++] = current_node->left;
        }
    }
    *returnSize = array_count;
    return array_vals;
}
