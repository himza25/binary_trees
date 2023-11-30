#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);

/**
 * inorder_successor - Finds the in-order successor in a BST.
 * @root: A pointer to the root node of the BST.
 *
 * Return: Pointer to the in-order successor.
 */
bst_t *inorder_successor(bst_t *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root);
}

/**
 * bst_delete - Deletes a node from a BST.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete.
 *
 * Return: Pointer to the new root after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
    bst_t *parent = node->parent, *successor = NULL;

    if (node->left == NULL)
    {
        if (parent && parent->left == node)
            parent->left = node->right;
        else if (parent)
            parent->right = node->right;
        if (node->right)
            node->right->parent = parent;
        free(node);
        return (parent == NULL ? node->right : root);
    }

    if (node->right == NULL)
    {
        if (parent && parent->left == node)
            parent->left = node->left;
        else if (parent)
            parent->right = node->left;
        if (node->left)
            node->left->parent = parent;
        free(node);
        return (parent == NULL ? node->left : root);
    }

    successor = inorder_successor(node->right);
    node->n = successor->n;
    return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Recursively removes a node from a BST.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the current node.
 * @value: The value to remove.
 *
 * Return: Pointer to the root after removal.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
    if (node != NULL)
    {
        if (node->n == value)
            return (bst_delete(root, node));
        if (node->n > value)
            return (bst_remove_recursive(root, node->left, value));
        return (bst_remove_recursive(root, node->right, value));
    }
    return (NULL);
}

/**
 * bst_remove - Removes a node from a BST.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove.
 *
 * Return: Pointer to the new root after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return (bst_remove_recursive(root, root, value));
}
