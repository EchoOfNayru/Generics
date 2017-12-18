#pragma once
#include <cassert>
#include <iostream>
#include <stdio.h>

template<typename T>
class deck 
{
private:
	int size;
	struct deckNode 
	{
		int value;
		deckNode* next;
		deckNode* prev;
	};
	deckNode* head;
	deckNode* tail;

public:
	deck()
		:head(nullptr), tail(nullptr) 
	{
	
	};
	~deck() 
	{
		deckNode* iter = head;
		while (iter->next != nullptr)
		{
			deckNode* next = iter->next;
			delete iter;
			iter = next;
			size--;
		}
		head = nullptr;
	};

	void pushFront(T value)
	{
		deckNode* newNode = new deckNode;
		newNode->value = value;
		newNode->next = head;
		newNode->prev = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head = newNode;
			newNode->next->prev = newNode;
		}

		size++;
	}

	void pushBack(T value) 
	{
		deckNode* newNode = new deckNode;
		newNode->value = value;
		newNode->next = head;
		newNode->prev = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			deckNode* iter = head;
			while (iter->next != nullptr)
			{
				iter = iter->next;
			}

			iter->next = newNode;
			newNode->prev = iter;
			tail = newNode;
			tail->next = nullptr;
		}

		size++;
	}

	void popFront()
	{
		deckNode* temp = head;
		assert(temp != nullptr);
		head = head->next;
		delete temp;
		size--;
	}

	void popBack() 
	{

		deckNode* temp = tail;
		assert(temp != nullptr);
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
		size--;
	}

	T at(int index)
	{
		deckNode* iter = head;
		int counter = 0;
		while (counter != index && iter->next != nullptr)
		{
			iter = iter->next;
			counter++;
		}

		assert(iter != nullptr);


		return iter->value;
	}

	int getSize()
	{
		return size;
	}
	bool empty()
	{
		return size == 0;
	}

	T front()
	{
		assert(head != nullptr);
		return head->value;
	}

	T back()
	{
		assert(tail != nullptr);
		return tail->value;
	}
	void Clear()
	{
		deckNode* iter = head;
		while (iter->next != nullptr)
		{
			deckNode* next = iter->next;
			delete iter;
			iter = next;
			size--;
		}
		head = nullptr;
	}

};