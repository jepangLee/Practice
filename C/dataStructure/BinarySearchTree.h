#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "../C.h"
#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode *pRoot);
BSTData BSTGetNodeData(BTreeNode *bst);
void BSTInsert(BTreeNode **pRoot, BSTData data);
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

#endif