#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
static size_t height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
		return (1 + height(tree->left));
}

/**
 * node_count - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes
 */
static size_t node_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
		return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, nodes;

	if (!tree)
		return (0);

		h = height(tree);
		nodes = node_count(tree);
		return ((1 << h) == nodes + 1);
}
