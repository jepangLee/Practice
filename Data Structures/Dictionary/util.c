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
	printf("1. 출력\n");
	printf("2. 입력\n");
	printf("3. 삭제\n");
	printf("4. 검색\n");
	printf("5. 종료\n");
	printf("-------------------\n");
}

void defaultSetting(BTreeNode *pBSTree)
{
	BTData handsomeMan[10] = {
		{0, "장동건", "고소영 남편"}
		,{1, "원빈", "이나영 남편"}
		,{2, "소동현", "검나 큼"}
		,{3, "김도훈", "안드로이드 갓갓"}
		,{4, "이제성", "미래의 게임 개발자"}
		,{5, "강동원", "크고 삐적 마름"}
		,{6, "정우성", "착한놈"}
		,{7, "송중기", "송혜교 남편"}
		,{8, "김수현", "별에서 온 그"}
		,{9, "이현승", "빨간 운동화"}
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
