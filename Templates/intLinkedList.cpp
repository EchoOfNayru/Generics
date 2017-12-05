#include "intLinkedList.h"
#include <cassert>
intLinkedList::intLinkedList()
	: head(nullptr), last(nullptr)
{

}

intLinkedList::~intLinkedList()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr) 
	{
		intLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
		size--;
	}
}

void intLinkedList::append(int value)
{
	intLinkedListNode* newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;
	newNode->prev = last;

	if (head == nullptr) 
	{
		head = newNode;
		last = newNode;
	}
	else 
	{
		
		//last = newNode;
		intLinkedListNode* iter = head;
		while (iter->next != nullptr) 
		{
			iter = iter->next;
		}

		iter->next = newNode;
		newNode->prev = iter;
		last = newNode;
	}

	size++;
}


int intLinkedList::at(int index)
{
	intLinkedListNode* iter = head;
	int counter = 0;
	while (counter != index && iter->next != nullptr)
	{
		iter = iter->next;
		counter++;
	}

	assert(iter != nullptr);

	return iter->value;
}

int intLinkedList::getSize()
{
	return size;
}

bool intLinkedList::empty()
{
	return size == 0;
}

int intLinkedList::front()
{
	assert(head != nullptr);
	return head->value;
}

int intLinkedList::back() 
{
	assert(last != nullptr);
	return last->value;
}

void intLinkedList::Clear()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr)
	{
		intLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
		size--;
	}
}

void intLinkedList::Erase(int index) 
{
	//find index
	intLinkedListNode* iter = head;
	int counter = 0;
	while (counter != index && iter->next != nullptr)
	{
		iter = iter->next;
		counter++;
	}
	
	//nullptr check
	assert(iter != nullptr);

	//store data and erase
	intLinkedListNode* temp = iter;
	delete iter;

	//find index -1 to link to the next index
	counter = 0;
	while (counter != index - 1 && iter->next != nullptr)
	{
		iter = iter->next;
		counter++;
	}

	//null ptr check
	assert(iter != nullptr);

	//link data
	iter->next = temp->next;
}