#include "binary_trees.h"
#include <limits.h>

int is_bst_util(const binary_tree_t *tree, long min, long max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, LONG_MIN, LONG_MAX));
}

/**
 * is_bst_util - Utility function to check BST validity
 * @tree: Pointer to the current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, long min, long max)
{
	if (!tree)
		return (1);

	if ((long)tree->n <= min || (long)tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, (long)tree->n) &&
			is_bst_util(tree->right, (long)tree->n + 1, max));
}
