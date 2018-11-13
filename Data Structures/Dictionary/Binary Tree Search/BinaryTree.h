#pragma once

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

//typedef int BTData;

typedef struct _BTData
{
	int ID;
	char name[10];
	char Details[50];
}BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

BTreeNode *makeBTreeNode();
BTData getData(BTreeNode *bt);
void setData(BTreeNode *bt, BTData data);
BTreeNode *getLeftSubTree(BTreeNode *bt);
BTreeNode *getRightSubTree(BTreeNode *bt);
void makeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void makeRightSubTree(BTreeNode *main, BTreeNode *sub);
void inorderTraverse(BTreeNode *bt);
void preorderTraverse(BTreeNode *bt);
void postorderTraverse(BTreeNode *bt);
void deleteTree(BTreeNode *root);
void deleteNode(BTreeNode *node);

#endif