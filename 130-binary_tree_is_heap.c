#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, int index, int node_count);
int has_heap_property(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int node_count = tree_size(tree);

	return (is_complete(tree, 0, node_count) && has_heap_property(tree));
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * has_heap_property - Checks if a tree satisfies Max Heap properties
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree satisfies Max Heap properties, 0 otherwise
 */
int has_heap_property(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (has_heap_property(tree->left) && has_heap_property(tree->right));
}
