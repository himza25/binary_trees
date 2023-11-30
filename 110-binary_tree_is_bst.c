#include "binary_trees.h"
#include <limits.h>

/**
 * validate_bst - Recursively verifies if a segment of a binary tree adheres to
 *                the properties of a binary search tree.
 * @tree: Pointer to the node currently being checked.
 * @lo: Lower boundary for the current subtree's node values.
 * @hi: Upper boundary for the current subtree's node values.
 *
 * Return: 1 if the subtree rooted at 'tree' is a valid BST, otherwise 0.
 */
int validate_bst(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (validate_bst(tree->left, lo, tree->n - 1) &&
				validate_bst(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if an entire binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the binary tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (validate_bst(tree, INT_MIN, INT_MAX));
}
