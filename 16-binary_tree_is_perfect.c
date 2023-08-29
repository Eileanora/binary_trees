#include "binary_trees.h"

/**
 * binary_tree_height_h - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height_h(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (max(binary_tree_height_h(tree->left),
	binary_tree_height_h(tree->right)) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if it is perfect or 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right) ||
	 (tree->left && tree->right == NULL))
		return (0);

	if (binary_tree_height_h(tree->left) == binary_tree_height_h(tree->right))
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		if (tree->left && tree->left)
			return (binary_tree_is_perfect(tree->left) &&
			 binary_tree_is_perfect(tree->right));
	}

	return (0);

}
