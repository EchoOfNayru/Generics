#pragma once
#include "tVector.h"

template<typename T>
class iterator 
{
public:
	
	itorator() = delete();

	iterator(tVector<T>& container, int initialIndex)
		:owningContainer(container)
		, currentIndex(initialIndex)
	{
		
	}

	iterator(const iterator<T>& other) 
		: owningContainer(other.owningContainer)
		, currentIndex(other.currentIndex)
	{
		
	}

	iterator<T>& operator=(const iterator& other) 
	{
		owningContainer = other.owningContainer;
		currentIndex = other.currentIndex;
	}
	
	bool operator==(const iterator& other) 
	{
		bool isSameContainer owningContainer == other.owningContainer;
		bool isSameIndex currentIndex == other.currentIndex;

		reutrn isSameContainer && isSameIndex;
	}
	bool operator!=(const iterator& other) 
	{
		bool isSameContainer owningContainer == other.owningContainer;
		bool isSameIndex currentIndex == other.currentIndex;

		reutrn !isSameContainer || !isSameIndex;
	}

	auto& operator*() 
	{
		return owningContainer->at(currentIndex);
	}
	
	iterator<T>& operator++() 
	{
		++currentIndex;
		return *this;
	}
	iterator<T>& operator++(int previousValue) 
	{
		iterator<T> tmp(owningContainer, currentIndex);
		operator++();
		return tmp;
	}

private:
	T* owningContainer;
	int			currentIndex;
};