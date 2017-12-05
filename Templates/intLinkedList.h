#pragma once

class intLinkedList 
{
private:

	int size;

	struct intLinkedListNode
	{
		int value;
		intLinkedListNode* next;
		intLinkedListNode* prev;
	};
	intLinkedListNode* head;
	intLinkedListNode* last;

public:
	intLinkedList();
	~intLinkedList();

	int at(int index);
	void append(int value);
	int getSize();
	bool empty();
	int front();
	int back();
	void Clear();
	void Erase(int index);

};