#include "Cppheader.h"

int main(void) {
	List AL;
	AL.LInsert(1);
	AL.LInsert(2);
	AL.LInsert(3);
	AL.LInsert(4);
	AL.LInsert(5);
	AL.LInsert(6);
	AL.LInsert(7);
	cout << AL.LGetNextData() << endl;
	cout << AL.LGetNextData() << endl;
	AL.LRemove(3);
	AL.LPrintAll();
}