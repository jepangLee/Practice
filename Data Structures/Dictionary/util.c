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
	printf("1. 출력\n");
	printf("2. 입력\n");
	printf("3. 삭제\n");
	printf("4. 검색\n");
	printf("5. 종료\n");
	printf("-------------------\n");
}

BTreeNode *defaultSetting()
{
	BTData handsomeMan[10] = {
		{10, "김도훈", "안드로이드 갓갓"}
		,{1, "김영래", "김빵래"}
		,{2, "김태현", "잘생김"}
		,{3, "박영진", "귀여운 안드 개발자"}
		,{4, "서동영", "똥믈리에"}
		,{5, "소동현", "2000"}
		,{6, "이제성", "탈모 개발자 예정"}
		,{7, "이현승", "빨간 운동화"}
		,{8, "이희웅", "히희훙"}
		,{9, "장호승", "임베디드 빡빡이"}
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
		printf("넣을 데이터를 이름 상세정보 순으로 입력하세요.\n>");
		scanf("%s %s", &input.name, &input.Details);

		while (getchar() != '\n' && getchar() != NULL);
		
		printf("이름 : %s\n상세정보 : %s\n맞습니까? Y / N\n>", input.name, input.Details);
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
				printf("y와 n중에서 입력해 주세요");
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
