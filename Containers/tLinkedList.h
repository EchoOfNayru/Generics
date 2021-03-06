#pragma once
#include <cassert>
#include <iostream>

template<typename T>
class tLinkedList 
{
private:
	int size;
	struct tLinkedListNode 
	{
		int value;
		tLinkedListNode* next;
	};
	tLinkedListNode* head;
	tLinkedListNode* last;

public:
	tLinkedList()
		:head(nullptr), last nullptr
	{
	
	};
	~tLinkedList() 
	{
		intLinkedListNode* iter = head;
		while (iter != nullptr)
		{
			intLinkedListNode* next = iter->next;
			delete iter;
			iter = next;
			size--;
		}
	};

	iterator<tLinkedList<< T >> begin()
	{
		return iterator<tLinkedList<< T >> (*this, 0);
	}

	iterator<tLinkedList<T>> end()
	{
		return iterator<tLinkedList<T>>(*this, size);
	}

	void append(T value) 
	{
		intLinkedListNode* newNode = new intLinkedListNode;
		newNode->value = value;
		newNode->next = nullptr;

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
			last = newNode;
		}

		size++;
	}

	T at(int index) 
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
		assert(last != nullptr);
		return last->value;
	}

	void Clear() 
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

	void Erase(int index)
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

		counter = 0;
		while (counter != index - 1 && iter->next != nullptr)
		{
			iter = iter->next;
			counter++;
		}

		assert(iter != nullptr);

		iter - next = temp->next;

		delete temp;
	}

	int Count(T value) 
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

	void Insert(int index, T value) 
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
		size++;

		counter = 0;
		while (counter != index - 1 && iter->next != nullptr)
		{
			iter = iter->next;
			counter++;
		}

		assert(iter != nullptr);

		iter->next = newNode;
	}

	void printIndex(int index) 
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
};