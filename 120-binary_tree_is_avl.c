#include "binary_trees.h"

int binary_tree_is_bst(const binary_tree_t *tree);
int bst_height(const binary_tree_t *tree);
int abs_diff(int a, int b);
int is_bst_util(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	left_height = bst_height(tree->left);
	right_height = bst_height(tree->right);

	if (abs_diff(left_height, right_height) > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a BST.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_util - Utility function to check BST property.
 * @tree: A pointer to the root node of the tree to check.
 * @min: Minimum valid value for a node.
 * @max: Maximum valid value for a node.
 *
 * Return: 1 if tree is a BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n - 1) &&
			is_bst_util(tree->right, tree->n + 1, max));


}

/**
 * bst_height - Calculates the height of a BST.
 * @tree: A pointer to the root node of the BST.
 *
 * Return: Height of the BST.
 */
int bst_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = bst_height(tree->left);
	right_height = bst_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * abs_diff - Calculates the absolute difference between two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: Absolute difference between a and b.
 */
int abs_diff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}
