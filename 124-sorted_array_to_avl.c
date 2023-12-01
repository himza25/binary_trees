#include "binary_trees.h"

avl_t *sorted_array_to_avl_helper(int *array, int start, int end);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1));
}

/**
 * sorted_array_to_avl_helper - Helper function to build AVL from array
 * @array: The array to build the AVL tree from
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array
 *
 * Return: Pointer to the root node of the AVL tree
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);

	if (!root)
		return (NULL);

	root->left = sorted_array_to_avl_helper(array, start, mid - 1);
	if (root->left)
		root->left->parent = root;

	root->right = sorted_array_to_avl_helper(array, mid + 1, end);
	if (root->right)
		root->right->parent = root;

	return (root);
}
