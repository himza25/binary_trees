#include "binary_trees.h"

/**
 * binary_tree_size - calcul the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - checks tree
 *
 * @tree: pointer tree root
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
 * check_max_heap - checks if a binary tree node follows max heap property
 * @node: pointer to the current node
 * Return: 1 if node follows max heap property, 0 otherwise
 */
int check_max_heap(const binary_tree_t *node)
{
	if (node == NULL)
	return (1);

	if (node->left == NULL && node->right == NULL)
	return (1);

	if (node->right == NULL)
	return (node->n >= node->left->n);

	return (node->n >= node->left->n && node->n >= node->right->n &&
		check_max_heap(node->left) && check_max_heap(node->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a Max Binary Heap
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is a Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL || !binary_tree_is_complete(tree))
	return (0);

	return (check_max_heap(tree));
}
