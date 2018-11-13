#include "../header.h"

void BSTMakeAndInit(BTreeNode *pRoot) {
	pRoot = NULL;
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

void ShowIntData(BTData data)
{
	printf("%d. %s : %s \n", data.ID, data.name, data.Details);
}

void BSTShowAll(BTreeNode * bst)
{
	inorderTraverse(bst);
}