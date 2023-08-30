#include "binary_trees.h"
/**
 * binary_tree_size_1 - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree
*/
size_t binary_tree_size_1(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size_1(tree->left) + binary_tree_size_1(tree->right));
}
/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t size, head, tail;
	binary_tree_t **queue, *node;

	if (!tree || !func)
		return;

	size = binary_tree_size_1(tree);
	queue = calloc(size, sizeof(binary_tree_t *));
	head = 0, tail = 0;

	queue[tail++] = (binary_tree_t *)tree;
	while (head < tail)
	{
		node = queue[head];
		func(node->n);
		if (node->left)
			queue[tail++] = node->left;
		if (node->right)
			queue[tail++] = node->right;
		head++;
	}
	free(queue);
}
