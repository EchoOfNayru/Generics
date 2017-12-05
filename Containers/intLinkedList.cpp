#include "intLinkedList.h"
#include <cassert>
#include <iostream>

intLinkedList::intLinkedList()
	: head(nullptr), last(nullptr)
{

}

intLinkedList::~intLinkedList()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr) 
	{
		intLinkedListNode* temp = iter->next;
		delete iter;
		iter = temp;
		size--;
	}

	head = nullptr;
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
	
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	delete temp;
}

int intLinkedList::Count(int value)
{
	intLinkedListNode* iter = head;
	int counter = 0;
	while (iter->next != nullptr) 
	{
		if (iter->value == value) 
		{
			counter++;
		}
	}
	return counter;
}

void intLinkedList::Insert(int index, int value)
{
	intLinkedListNode* iter = head;
	int counter = 0;
	while (counter != index && iter->next != nullptr) 
	{
		iter = iter->next;
		counter++;
	}

	assert(iter != nullptr);

	intLinkedListNode* newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = iter->next;
	newNode->prev = iter->prev;
	size++;

	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
	
	/*intLinkedListNode* temp = iter;
	iter = last;
	append(value);
	last->prev->next = nullptr;
	last = temp;
	last->value = value;
	last->prev->next = last;
	last->next->prev = last;*/
	
}

void intLinkedList::printIndex(int index)
{
	intLinkedListNode* iter = head;
	int counter = 0;
	while (counter != index && iter->next != nullptr) 
	{
		iter = iter->next;
		counter++;
	}

	assert(iter != nullptr);

	std::cout << iter->value << std::endl;
}
