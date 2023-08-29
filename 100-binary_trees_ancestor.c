#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return:  a pointer to the lowest common ancestor node of the two given nodes
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second && first->parent == second->parent)
		return ((binary_tree_t *)first);

	if (first->parent == second->parent)
		return (first->parent);

	if (second->parent == first)
		return (second->parent);

	if (first->parent == second)
		return (first->parent);

	while (binary_tree_depth(first) > binary_tree_depth(second))
		first = first->parent;

	while (binary_tree_depth(first) < binary_tree_depth(second))
		second = second->parent;

	if (binary_tree_depth(first) == binary_tree_depth(second))
		return (binary_trees_ancestor(first, second));

	return (NULL);

}
