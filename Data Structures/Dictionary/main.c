#include "util.h"

int main()
{
	BTreeNode *dicionary = NULL;
	defaultSetting(dicionary);

	while (1)
	{
		char input = 0;

		splash();
		showMain();

		input = getch();

		//while (getchar() != NULL);

		switch (input) {
		case '1':
			printData(dicionary);
			break;
		case '2':
			inputData();
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


