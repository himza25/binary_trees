#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - checks if tree is complete
 *
 * @tree: pointer to the tree root
 * @i: node index
 * @cnodes: number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * binary_tree_is_complete - calls to tree_is_complete function
 *
 * @tree: tree root
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * check_max_heap - checks if a binary tree node follows max heap property
 * @tree: pointer to the current node
 * Return: 1 if node follows max heap property, 0 otherwise
 */
int check_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->left)
	{
		if (tree->n < tree->left->n)
			return (0);
		if (!check_max_heap(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (tree->n < tree->right->n)
			return (0);
		if (!check_max_heap(tree->right))
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a Max Binary Heap
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is a Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree || !binary_tree_is_complete(tree))
		return (0);
	return (check_max_heap(tree));
}
