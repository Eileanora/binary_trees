#include "binary_trees.h"

/**
 * binary_tree_height_t - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height_t(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (max(binary_tree_height_t(tree->left),
	binary_tree_height_t(tree->right)) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor of a binary tree
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height_t(tree->left) - binary_tree_height_t(tree->right));
}
