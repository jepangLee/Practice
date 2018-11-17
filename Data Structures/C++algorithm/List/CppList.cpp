#include "../Cppheader.h"

ArrayList::ArrayList() {
	this->Data[0] = -1;
	this->NumOfData = 0;
}

void ArrayList::LInsert(LData data)
{
	if (NumOfData == listLen)
		cout << "더이상 데이터를 넣을 수 없습니다" << endl;
	else {
		cout << data << " 삽입\n";
		this->NumOfData += 1;
		Data[NumOfData - 1] = data;
		Data[NumOfData] = -1;
	}

}

void ArrayList::LRemove(LData data)
{
	int cou = 0, funcCheck = 0;
	
	for ( ; cou < this->NumOfData; cou++) {
		if (this->Data[cou] == data) {
			Data[cou] = 0;
			funcCheck = 1;
			break;
		}
	}

	if (funcCheck == 1) {
		cout << data << " 삭제\n";
		for (; cou < this->NumOfData; cou++) {
			Data[cou] = Data[cou + 1];
		}

		Data[NumOfData - 1] = NULL;
	}

	else
		cout << "해당 데이터가 존재하지 않습니다" << endl;

}

int ArrayList::LGetFirstData()
{
	if (Data[0] == 0)
		cout << "아무런 데이터가 들어있지 않습니다. \n";
	else {
		this->curPosition = 1;
		return this->Data[0];
	}
		
}

int ArrayList::LGetNextData()
{
	if (this->curPosition >= this->NumOfData)
		return false;
	else {
		return this->Data[curPosition++];
	}
}

/********************************************************************************/

LinkedList::LinkedList()
{	
	this->Head = new Node;
	this->Head->data = NULL;
	this->Head->next = NULL;
}

void LinkedList::LInsert(LData data)
{
	Node *newNode = new Node;

	cout << data << " 삽입\n";
	
	newNode->data = data;
	newNode->next = NULL;

	if (this->Head->next == NULL) {
		this->curNode = newNode;
		this->Head->next = this->curNode;
	}
		
	else {
		if (curNode->next != NULL)
			this->LSerchLastNode();

		this->beforeNode = this->curNode;
		this->curNode = newNode;
		this->beforeNode->next = this->curNode;
	}
}

Node *LinkedList::LSerchLastNode()
{
	if (this->curNode->next == NULL)
		return curNode;
	else {
		this->beforeNode = curNode;
		this->curNode = curNode->next;
		return LSerchLastNode();
	}
}

void LinkedList::LRemove(LData data)
{
	cout << data << " 삭제\n";

	
	if (curNode->data != data) {
		int temp = this->LGetFirstData();

		while (1) {
			if (temp == data)
				break;
			else
				temp = this->LGetNextData();
		}
	}

	this->beforeNode->next = this->curNode->next;
	delete(curNode);
	this->curNode = this->beforeNode->next;
}

int LinkedList::LGetFirstData()
{
	this->beforeNode = NULL;
	this->curNode = this->Head->next;
	return curNode->data;
}

int LinkedList::LGetNextData()
{
	if (this->curNode->next == NULL) {
		cout << "마지막 노드입니다. \n";
		return -1;
	}

	this->beforeNode = this->curNode;
	this->curNode = this->curNode->next;
	return this->curNode->data;
}

void LinkedList::LPrintAll()
{
	cout << this->LGetFirstData() << ' ';
	while (1) {
		int print = this->LGetNextData();
		if (print == -1) break;
		cout << print << ' ';
	}
}

/********************************************************************************/


CircularLinkedList::CircularLinkedList()
{
	this->tail = new Node;
	this->tail->data = NULL;
	this->tail->next = NULL;
}

void CircularLinkedList::LInsert(LData data)
{
	Node *newNode = new Node;

	cout << data << " 삽입\n";

	newNode->data = data;
	newNode->next = NULL;

	if (this->tail->next == NULL) {
		this->tail->next = newNode;
		newNode->next = tail;

		this->curNode = newNode;
		this->beforeNode = tail;
	}
	else {
		if (this->curNode->next != this->tail)
			this->LSerchLastNode();
		
		this->beforeNode = this->curNode;

		newNode->next = this->tail;
		this->curNode = newNode;

		this->beforeNode->next = this->curNode;
	}
}

void CircularLinkedList::LInsertFront(LData data)
{
	Node *newNode = new Node;

	cout << data << " 삽입\n";

	newNode->data = data;
	newNode->next = NULL;

	if (this->tail->next == NULL) {
		this->tail->next = newNode;
		newNode->next = tail;

		this->curNode = newNode;
		this->beforeNode = tail;
	}
	else {
		newNode->next = this->tail->next;
		this->tail->next = newNode;
	}
}

Node *CircularLinkedList::LSerchLastNode()
{
	if (this->curNode == this->tail)
		return curNode;
	else {
		this->beforeNode = curNode;
		this->curNode = this->curNode->next;
		return LSerchLastNode();
	}
}

void CircularLinkedList::LRemove(LData data)
{
	int temp = 0;
	cout << data << " 삭제\n";

	if (curNode->data != data) {
		temp = this->LGetFirstData();

		while (1) {
			if (temp == data)
				break;
			else
				temp = this->LGetNextData();
		}
	}

	if (this->tail->next->data == temp)
		this->tail->next = this->curNode->next;

	this->beforeNode->next = this->curNode->next;
	delete(curNode);
	this->curNode = this->beforeNode->next;

}

int CircularLinkedList::LGetFirstData()
{
	this->beforeNode = this->tail;
	this->curNode = this->tail->next;
	return curNode->data;
}

int CircularLinkedList::LGetNextData()
{
	if (this->curNode->next == this->tail) {
		this->beforeNode = this->tail;
		this->curNode = this->tail->next;
	}
	else {
		this->beforeNode = this->curNode;
		this->curNode = this->curNode->next;
	}
	return this->curNode->data;
}

void CircularLinkedList::LPrintAll()
{
	int firstData = this->LGetFirstData();
	cout << firstData << ' ';
	while (1) {
		int print = this->LGetNextData();
		if (print == firstData) break;
		cout << print << ' ';
	}
}

/*************************************************************************/

DoublyLinkedList::DoublyLinkedList()
{
	this->Head = new Node;
	this->Head->data = NULL;
	this->Head->next = NULL;
}

void DoublyLinkedList::LInsert(LData data)
{
	Node *newNode = new Node;

	cout << data << " 삽입\n";

	newNode->before = NULL;
	newNode->data = data;
	newNode->next = NULL;

	if (this->Head->next == NULL) {
		this->Head->next = newNode;
		this->curNode = newNode;
		this->curNode->before = this->Head;
	}

	else {
		if (curNode->next != NULL)
			this->LSerchLastNode();
		newNode->before = this->curNode;
		this->curNode->next = newNode;
		this->curNode = newNode;
	}
}

void DoublyLinkedList::LRemove(LData data)
{
	cout << data << " 삭제\n";


	if (curNode->data != data) {
		int temp = this->LGetFirstData();

		while (1) {
			if (temp == data)
				break;
			else
				temp = this->LGetNextData();
		}
	}
	curNode->before->next = curNode->next;
	delete(curNode);
}

int DoublyLinkedList::LGetFirstData()
{
	this->curNode = this->Head->next;
	return curNode->data;
}

int DoublyLinkedList::LGetNextData()
{
	if (this->curNode->next == NULL) {
		cout << "마지막 노드입니다. \n";
		return -1;
	}

	this->curNode = this->curNode->next;
	return this->curNode->data;
}

int DoublyLinkedList::LGetBeforeData()
{
	if (this->curNode->before->before == NULL) {
		cout << "첫 노드입니다. \n";
		return -1;
	}

	this->curNode = this->curNode->before;
	return this->curNode->data;
}

void DoublyLinkedList::LPrintAll()
{
	cout << this->LGetFirstData() << ' ';
	while (1) {
		int print = this->LGetNextData();
		if (print == -1) break;
		cout << print << ' ';
	}
}


Node *DoublyLinkedList::LSerchLastNode()
{
	if (this->curNode->next == NULL)
		return curNode;
	else {
		this->curNode = this->curNode->next;
		return LSerchLastNode();
	}
}