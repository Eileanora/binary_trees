#include "binary_trees.h"
#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	return (max(binary_tree_height(tree->left),
	binary_tree_height(tree->right)) + 1);
}
