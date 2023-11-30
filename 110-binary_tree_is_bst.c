#include "binary_trees.h"
#include <limits.h>

/**
 * validate_bst - Recursively checks if a binary tree is a valid BST
 * @tree: Pointer to the current node
 * @min: Minimum valid value
 * @max: Maximum valid value
 *
 * Return: 1 if tree segment is a valid BST, 0 otherwise
 */
int validate_bst(const binary_tree_t *tree, long min, long max)
{
	if (!tree)
		return (1);

	if ((long)tree->n <= min || (long)tree->n >= max)
		return (0);

	return (validate_bst(tree->left, min, (long)tree->n - 1) &&
			validate_bst(tree->right, (long)tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Determines if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the entire tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (validate_bst(tree, LONG_MIN, LONG_MAX));
}
