#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth
 *
 * Return: Depth of the node
 */
size_t tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node)
	{
		depth++;
		node = node->parent;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = tree_depth(first);
	depth_second = tree_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
