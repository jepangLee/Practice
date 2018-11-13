#pragma warning (disable : 4996)

#include "header.h"

int main()
{
	BTreeNode *pBSTree = defaultSetting();
	int handsomeManNum = 10;
	for(int first = 0; ;first++)
	{
		int temp = 0;
		char input = 0;

		splash();
		showMain();

		if (first != 0)
			getch();

		input = getch();

		switch (input) {
		case '1':
			printData(pBSTree);
			break;
		case '2':
			inputData(pBSTree, &handsomeManNum);
			break;
		case '3':
			deleteData();
			break;
		case '4':
			searchData();
			break;
		case '5':
			exit(0);
		default:
			system("cls");
			continue;
		}
	}
}


