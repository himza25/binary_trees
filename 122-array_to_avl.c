#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from a given array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the created AVL tree, or NULL if failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t index;
	avl_t *root_node = NULL;

	for (index = 0; index < size; ++index)
	{
		if (!avl_insert(&root_node, array[index]))
		{

		}
	}

	return (root_node);
}
