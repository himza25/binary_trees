#include "binary_trees.h"

/* binary_tree_size from the second code */

/* swap function from the first code */

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new;
	int size, leaves, sub, bit, level;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	for (level = 0, sub = 1, leaves = size; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	if (leaves & 1)
		tree->right = new;
	else
		tree->left = new;

	while (new->parent && new->n > new->parent->n)
	{
		swap(&(new->parent), &new);
	}

	return (new);
}
