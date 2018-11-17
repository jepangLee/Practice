#include "../Cppheader.h"

int const listLen = 100;

typedef int LData;

struct Node {
	LData data;
	Node *next;
	Node *before;
};

class ArrayList {
	LData Data[listLen];
	int NumOfData;
	int curPosition;
public:
	ArrayList();
	
	void LInsert(LData data);
	void LRemove(LData data);
	//void LPrintAll();

	int LGetFirstData();
	int LGetNextData();
};

class LinkedList {
	Node *Head;
	Node *curNode;
	Node *beforeNode;
	

public:
	LinkedList();
	
	Node *LSerchLastNode();

	void LInsert(LData data);
	void LRemove(LData data);
	
	int LGetFirstData();
	int LGetNextData();
	void LPrintAll();
};

class CircularLinkedList {
	Node *tail;
	Node *curNode;
	Node *beforeNode;

public:
	CircularLinkedList();
	void LInsert(LData data);
	void LInsertFront(LData data);
	Node * LSerchLastNode();
	void LRemove(LData data);
	int LGetFirstData();
	int LGetNextData();
	void LPrintAll();
};

class DoublyLinkedList {
	Node *Head;
	Node *curNode;


public:
	DoublyLinkedList();

	void LInsert(LData data);
	void LRemove(LData data);

	int LGetFirstData();
	int LGetNextData();
	int LGetBeforeData();
	void LPrintAll();
	Node * LSerchLastNode();
};

typedef DoublyLinkedList List;