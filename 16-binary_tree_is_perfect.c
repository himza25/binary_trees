#include "binary_trees.h"

/**
 * depth - Measures the depth of a node
 * @node: Pointer to the node to measure the depth
 *
 * Return: Depth of the node
 */
size_t depth(const binary_tree_t *node)
{
    size_t d = 0;
    while (node != NULL)
    {
        d++;
        node = node->left;
    }
    return d;
}

/**
 * is_perfect_rec - Helper function to check if tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @d: Depth of the tree
 * @level: Current level in the tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int is_perfect_rec(const binary_tree_t *tree, size_t d, size_t level)
{
    if (tree == NULL)
        return 1;

    if (tree->left == NULL && tree->right == NULL)
        return (d == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return 0;

    return is_perfect_rec(tree->left, d, level + 1) &&
           is_perfect_rec(tree->right, d, level + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t d;

    if (tree == NULL)
        return (0);

    d = depth(tree);
    return is_perfect_rec(tree, d, 0);
}
