#include "binary_trees.h"

int check_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (check_bst(tree, INT_MIN, INT_MAX));
}

/**
 * check_bst - Helper function to check BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (check_bst(tree->left, min, tree->n - 1) &&
		check_bst(tree->right, tree->n + 1, max));
}
