#include "binary_trees.h"

/**
 * balance_avl - Balances an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 */
void balance_avl(avl_t **tree)
{
	int balance_factor;

	if (!tree || !*tree)
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;
	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);
	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the in-order successor of a node
 * @node: Pointer to the node
 * Return: Value of the successor
 */
int find_successor(bst_t *node)
{
	int left_val;

	if (!node)
		return (0);
	left_val = find_successor(node->left);
	if (left_val == 0)
		return (node->n);
	return (left_val);
}

/**
 * remove_node - Removes a node and adjusts the tree accordingly
 * @root: Node to remove
 * Return: Adjusted value if children exist, 0 otherwise
 */
int remove_node(bst_t *root)
{
	int successor_val;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	if ((!root->left && root->right) || (root->right && !root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	successor_val = find_successor(root->right);
	root->n = successor_val;
	return (successor_val);
}

/**
 * bst_remove - Removes a node from a BST tree
 * @root: Root of the tree
 * @value: Value of the node to remove
 * Return: Pointer to the root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int node_type;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else
	{
		node_type = remove_node(root);
		if (node_type != 0)
			bst_remove(root->right, node_type);
	}
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Root of the tree
 * @value: Value of the node to remove
 * Return: Pointer to the root node after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root = (avl_t *)bst_remove((bst_t *)root, value);

	if (!avl_root)
		return (NULL);
	balance_avl(&avl_root);
	return (avl_root);
}
