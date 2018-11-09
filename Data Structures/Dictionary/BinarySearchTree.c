#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode **pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return getData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *pRoot;
	BTreeNode *nNode = NULL;

	while (cNode != NULL)
	{
		if (data.ID == getData(cNode).ID)
			return;

		pNode = cNode;

		if (getData(cNode).ID > data.ID)
			cNode = getLeftSubTree(cNode);
		else
			cNode = getRightSubTree(cNode);
	}

	nNode = makeBTreeNode();
	setData(nNode, data);

	if (pNode != NULL)
	{
		if (data.ID < getData(pNode).ID)
			makeLeftSubTree(pNode, nNode);
		else
			makeRightSubTree(pNode, nNode);
	}
	else
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode *cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = getData(cNode);

		if (target.ID == cd.ID)
			return cNode;
		else if (target.ID < cd.ID)
			cNode = getLeftSubTree(cNode);
		else
			cNode = getRightSubTree(cNode);
	}

	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode *pvRoot = makeBTreeNode();
	BTreeNode *pNode = pvRoot;
	BTreeNode *cNode = *pRoot;
	BTreeNode *dNode;

	ChangeRightSubTree(pvRoot, *pRoot);

	while (cNode != NULL && getData(cNode).ID != target.ID)
	{
		pNode = cNode;
		if (target.ID < getData(cNode).ID)
			cNode = getLeftSubTree(cNode);
		else
			cNode = getRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	if (getLeftSubTree(dNode) == NULL && getRightSubTree(dNode) == NULL)
	{
		if (getLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	else if (getLeftSubTree(dNode) == NULL || getRightSubTree(dNode) == NULL)
	{
		BTreeNode *dcNode;

		if (getLeftSubTree(dNode) != NULL)
			dcNode = getLeftSubTree(dNode);
		else
			dcNode = getRightSubTree(dNode);

		if (getLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	else
	{
		BTreeNode *mNode = getRightSubTree(dNode);
		BTreeNode *mpNode = dNode;
		BTData delData;

		while (getLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = getLeftSubTree(mNode);
		}

		delData = getData(dNode);
		setData(dNode, getData(mNode));

		if (getLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, getRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, getRightSubTree(mNode));

		dNode = mNode;
		setData(dNode, delData);
	}

	if (getRightSubTree(pvRoot) != *pRoot)
		*pRoot = getRightSubTree(pvRoot);

	free(pvRoot);
	return dNode;
}

void ShowIntData(BTData data)
{
	printf("%d %s %s\n", data.ID, data.name, data.information);
}

void BSTShowAll(BTreeNode * bst)
{
	inorderTraverse(bst, ShowIntData);
}
