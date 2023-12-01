#include "binary_trees.h"

/**
 * count_h_nodes - Recursively counts the nodes in a binary tree.
 * @root: Pointer to the root node of the binary tree.
 * Return: The total number of nodes in the tree.
 */
int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) + count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - Transforms a Binary Max Heap into a sorted array.
 * @heap: Pointer to the root node of the heap.
 * @size: Pointer to store the size of the resulting array.
 * Return: Pointer to the sorted array of integers, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	if (!heap)
	{
		*size = 0;
		return (NULL);
	}

	nodes = count_h_nodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
