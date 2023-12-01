#include "binary_trees.h"

/**
 * tree_height - Calculates the height of a binary tree recursively.
 * @tree: Pointer to the root node of the tree.
 * Return: The maximum height from the root, or 0 if tree is NULL.
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * tree_size_h - Computes the total sum of the heights of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The sum of heights from the root, or 0 if tree is NULL.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size_h(tree->left) + tree_size_h(tree->right));
}

/**
 * _preorder - Performs a pre-order traversal of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * @node: Pointer updated to the last node in the traversal.
 * @height: Height of the tree.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (height == 0)
		*node = tree;
	else
	{
		_preorder(tree->left, node, height - 1);
		_preorder(tree->right, node, height - 1);
	}
}

/**
 * heapify - Ensures the Max Heap property is maintained in the heap.
 * @root: Pointer to the root of the heap.
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	while (root && root->left)
	{
		tmp2 = (!root->right || root->left->n > root->right->n) ?
		       root->left : root->right;

		if (root->n >= tmp2->n)
			break;

		value = root->n;
		root->n = tmp2->n;
		tmp2->n = value;
		root = tmp2;
	}
}

/**
 * heap_extract - Extracts and returns the root node's value Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);

	heap_r = *root;
	value = heap_r->n;

	if (!heap_r->left && !heap_r->right)
	{
		free(heap_r);
		*root = NULL;
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));
	heap_r->n = node->n;
	if (node->parent)
		(node->parent->right == node) ? (node->parent->right = NULL) :
										(node->parent->left = NULL);
	free(node);
	heapify(heap_r);

	return (value);
}
