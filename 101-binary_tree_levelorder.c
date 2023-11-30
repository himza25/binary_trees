#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp;
	const binary_tree_t **queue;
	int start = 0, end = 0, queue_size = 2048;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(*queue) * queue_size);
	if (!queue)
		return;

	queue[end++] = tree;
	while (start < end)
	{
		temp = queue[start++];
		func(temp->n);
		if (temp->left)
			queue[end++] = temp->left;
		if (temp->right)
			queue[end++] = temp->right;
	}
	free(queue);
}
