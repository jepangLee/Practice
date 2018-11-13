#include "header.h"

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

BTreeNode *defaultSetting()
{
	BTData handsomeMan[10] = {
		{10, "�赵��", "�ȵ���̵� ����"}
		,{1, "�迵��", "�軧��"}
		,{2, "������", "�߻���"}
		,{3, "�ڿ���", "�Ϳ��� �ȵ� ������"}
		,{4, "������", "�˹ɸ���"}
		,{5, "�ҵ���", "2000"}
		,{6, "������", "Ż�� ������ ����"}
		,{7, "������", "���� �ȭ"}
		,{8, "�����", "������"}
		,{9, "��ȣ��", "�Ӻ���� ������"}
	};


	BTreeNode *pBSTree = NULL;
	BSTMakeAndInit(pBSTree);

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

	return pBSTree;
}

void printData(BTreeNode *bst)
{
	inorderTraverse(bst);
	system("pause");
	system("cls");
}

void inputData(BTreeNode *bst, int *count)
{
	BSTData input;
	char check = 0;
	int funcCheck = 1, trueCheck = 0;

	input.ID = *count + 1;

	while (funcCheck) {
		printf("���� �����͸� �̸� ������ ������ �Է��ϼ���.\n>");
		scanf("%s %s", &input.name, &input.Details);

		while (getchar() != '\n' && getchar() != NULL);
		
		printf("�̸� : %s\n������ : %s\n�½��ϱ�? Y / N\n>", input.name, input.Details);
		while (1) {

			check = getchar();

			if (check == 'Y' || check == 'y') {
				BSTInsert(&bst, input);
				funcCheck = 0;
				break;
			}
			else if (check == 'N' || check == 'n')
			{
				system("cls");
				splash();
				showMain();
				break;
			}
			else
			{
				printf("y�� n�߿��� �Է��� �ּ���");
				system("pause");
				while (getchar() != '\n' && getchar() != NULL);
			}
		}
		 
	}
	system("cls");
}

void deleteData()
{
}

void searchData()
{
}
