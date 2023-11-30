#include "binary_trees.h"

/**
 * insert_node_avl - Inserts a value in an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node.
 * @new: Double pointer for the new node insertion.
 * @val: The value to be inserted.
 *
 * Return: Pointer to the new root node after insertion, or NULL on failure.
 */
avl_t *insert_node_avl(avl_t **tree, avl_t *parent, avl_t **new, int val)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, val));
	if ((*tree)->n > val)
	{
		(*tree)->left = insert_node_avl(&(*tree)->left, *tree, new, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = insert_node_avl(&(*tree)->right, *tree, new, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_factor = binary_tree_balance(*tree);
	if (balance_factor > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree to insert into.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	return (insert_node_avl(tree, *tree, &new_node, value));
}
