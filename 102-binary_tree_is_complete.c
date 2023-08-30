#include "binary_trees.h"
/**
 * binary_tree_size_2 - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree
*/
size_t binary_tree_size_2(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + (binary_tree_size_2(tree->left)
	+ binary_tree_size_2(tree->right)));
}
/**
 * rec - cdo the recursion to check if the tree is complete
 * @tree: pointer to the root node of the tree to measure the size
 * @index: index of the node
 * @size: size of the tree
 * Return: 1 if complete, 0 if not
*/
int rec(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (rec(tree->left, 2 * index + 1, size)
	&& rec(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size_2(tree);
	return (rec(tree, 0, size));
}
