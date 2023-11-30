#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * is_complete_rec - Helper function for checking if binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @number_nodes: Number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete_rec(const binary_tree_t *tree, size_t index,
			size_t number_nodes)
{
	if (!tree)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (is_complete_rec(tree->left, 2 * index + 1, number_nodes) &&
			is_complete_rec(tree->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t number_nodes;

	if (!tree)
		return (0);

	number_nodes = tree_size(tree);
	return (is_complete_rec(tree, 0, number_nodes));
}
