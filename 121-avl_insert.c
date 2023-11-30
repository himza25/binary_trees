#include "binary_trees.h"

/**
 * recursive_insert - Inserts a node into an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @parent_node: Parent node in the AVL tree structure.
 * @insert_node: Pointer for insertion on left or right.
 * @value: Value to insert into the AVL tree.
 * Return: New root after insertion, or NULL if fails.
 */
avl_t *recursive_insert(avl_t **root, avl_t *parent_node, 
						avl_t **insert_node, int value)
{
	int balance;

	if (*root == NULL)
		return (*insert_node = binary_tree_node(parent_node, value));
	if ((*root)->n > value)
	{
		(*root)->left = recursive_insert(&(*root)->left, *root, 
										 insert_node, value);
		if ((*root)->left == NULL)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = recursive_insert(&(*root)->right, *root, 
										  insert_node, value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*root);
	}
	balance = binary_tree_balance(*root);
	if (balance > 1 && (*root)->left->n > value)
	{
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance < -1 && (*root)->right->n < value)
	{
		*root = binary_tree_rotate_left(*root);
	}
	else if (balance < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	return (*root);
}

/**
 * insert_avl_value - Inserts a value into an AVL tree.
 * @root: Pointer to the root of the AVL tree.
 * @value: Value to store in the node being inserted.
 * Return: Pointer to inserted node, or NULL if fails.
 */
avl_t *insert_avl_value(avl_t **root, int value)
{
	avl_t *new_node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	recursive_insert(root, *root, &new_node, value);
	return (new_node);
}
