#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * @tree: pointer to the root node
 * Return: number of nodes with at least 1 child
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
	{
		counter += 1;
		if (tree->left)
			counter += binary_tree_nodes(tree->left);
		if (tree->right)
			counter += binary_tree_nodes(tree->right);
	}

	return (counter);

}
