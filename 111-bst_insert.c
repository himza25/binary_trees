#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *parent;

	if (!tree)
		return (NULL);

	parent = NULL;
	node = *tree;
	while (node)
	{
		parent = node;
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (NULL);
	}

	node = binary_tree_node(parent, value);
	if (!parent)
		*tree = node;
	else if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}
