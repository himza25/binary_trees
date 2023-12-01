#include "binary_trees.h"

/**
 * height - Calculates the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The height of the tree, or -1 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);
		if (tree->left && !(tree->left->left) && !(tree->left->right) &&
			tree->right && !(tree->right->left) && !(tree->right->right))
			return (1);
		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
	}
	return (0);
}

/**
 * swap - Swaps two nodes in a binary heap.
 * @arg_node: Double pointer to the parent node.
 * @arg_child: Double pointer to the child node.
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		child->left ? child->left->parent = node : 0;
		child->right ? child->right->parent = node : 0;
		left_right = (node->left == child) ? 0 : 1;
		node_child = left_right == 0 ? node->right : node->left;
		node_left = child->left, node_right = child->right;
		left_right == 0 ? (child->right = node_child, child->left = node)
						: (child->left = node_child, child->right = node);
		node_child ? node_child->parent = child : 0;
		if (node->parent)
			node->parent->left == node ? (node->parent->left = child)
									   : (node->parent->right = child);
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left, node->right = node_right;
		*arg_node = child;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: The value to insert.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		new_node = (*root)->left ? heap_insert(&((*root)->left), value)
								 : ((*root)->left = binary_tree_node(*root, value));
		swap(root, &((*root)->left));
		return (new_node);
	}

	new_node = (*root)->right ? heap_insert(&((*root)->right), value)
							  : ((*root)->right = binary_tree_node(*root, value));
	swap(root, &((*root)->right));
	return (new_node);
}
