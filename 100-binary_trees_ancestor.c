#include "binary_trees.h"

/**
 * binary_tree_depth_1 - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
*/
size_t binary_tree_depth_1(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth_1(tree->parent));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth_1(first);
	depth_second = binary_tree_depth_1(second);
	while (depth_first != 0 && depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second != 0 && depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
