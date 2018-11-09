#include <stdio.h>
#include "BinaryTree.h"

BTreeNode * makeBTreeNode()
{
	BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData getData(BTreeNode * bt)
{
	return bt->data;
}

void setData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * getLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * getRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void makeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void makeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void inorderTraverse(BTreeNode * bt) {
	if (bt == NULL)
		return;

	inorderTraverse(bt->left);
	printf("%3d", bt->data);
	inorderTraverse(bt->right);
}

void preorderTraverse(BTreeNode * bt) {
	if (bt == NULL)
		return;

	printf("%3d", bt->data);
	preorderTraverse(bt->left);
	preorderTraverse(bt->right);
}

void postorderTraverse(BTreeNode * bt) {
	if (bt == NULL)
		return;

	postorderTraverse(bt->left);
	postorderTraverse(bt->right);
	printf("%3d", bt->data);
}

void deleteTree(BTreeNode * root) {
	if (root == NULL)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	deleteNode(root);
}

void deleteNode(BTreeNode * node) {
	free(node);
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	BTreeNode *delNode = NULL;

	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
	BTreeNode *delNode = NULL;

	if (bt != NULL) {
		delNode = bt->left;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->right = sub;
}
