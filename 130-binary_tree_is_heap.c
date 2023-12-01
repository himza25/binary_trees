#include "binary_trees.h"

int heap_check(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, size_t index, size_t size);
size_t tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t size = tree_size(tree);

	return (is_complete(tree, 0, size) && heap_check(tree));
}

/**
 * heap_check - Helper function to check Max Heap property
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree satisfies Max Heap property, 0 otherwise
 */
int heap_check(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (heap_check(tree->left) && heap_check(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Node index
 * @size: Number of nodes in the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
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
