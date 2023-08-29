#include "binary_trees.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height_t - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height_t(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height_t(tree->left);
	size_t right_height = binary_tree_height_t(tree->right);

	return (max(left_height, right_height) + 1);
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

	if (binary_tree_height_t(tree->left) == binary_tree_height_t(tree->right))
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		if (tree->left && tree->left)
			return (binary_tree_is_perfect(tree->left) &&
			 binary_tree_is_perfect(tree->right));
	}

	return (0);

}