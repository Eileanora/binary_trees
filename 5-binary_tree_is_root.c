#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a node is a root
 * @node: the node to be checked
 * Return: 1 if it s a root otherwise 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);
	else
		return (0);

}
