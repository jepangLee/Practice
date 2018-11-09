#include "util.h"

void splash()
{
	printf("       *    *	   **********      *\n");
	printf("      * *   ****       **      *****\n");
	printf("     *   *  *         *  *         *\n");
	printf("\n");
	printf("                          * \n");
	printf("                          * \n");
	printf("                          * \n");
	printf("                          ******** \n");
}

void showMain()
{
	printf("-------------------\n");
	printf("1. ���\n");
	printf("2. �Է�\n");
	printf("3. ����\n");
	printf("4. �˻�\n");
	printf("5. ����\n");
	printf("-------------------\n");
}

void defaultSetting(BTreeNode *pBSTree)
{
	BTData handsomeMan[10] = {
		{0, "�嵿��", "��ҿ� ����"}
		,{1, "����", "�̳��� ����"}
		,{2, "�ҵ���", "�˳� ŭ"}
		,{3, "�赵��", "�ȵ���̵� ����"}
		,{4, "������", "�̷��� ���� ������"}
		,{5, "������", "ũ�� ���� ����"}
		,{6, "���켺", "���ѳ�"}
		,{7, "���߱�", "������ ����"}
		,{8, "�����", "������ �� ��"}
		,{9, "������", "���� �ȭ"}
	};

	BSTMakeAndInit(&pBSTree);

	BSTInsert(&pBSTree, handsomeMan[0]);
	BSTInsert(&pBSTree, handsomeMan[1]);
	BSTInsert(&pBSTree, handsomeMan[2]);
	BSTInsert(&pBSTree, handsomeMan[3]);
	BSTInsert(&pBSTree, handsomeMan[4]);
	BSTInsert(&pBSTree, handsomeMan[5]);
	BSTInsert(&pBSTree, handsomeMan[6]);
	BSTInsert(&pBSTree, handsomeMan[7]);
	BSTInsert(&pBSTree, handsomeMan[8]);
	BSTInsert(&pBSTree, handsomeMan[9]);

}

void printData(BTreeNode *pBSTree)
{
	BSTShowAll(pBSTree);
}

void inputData()
{

}

void deleteData()
{
}

void searchData()
{
}
