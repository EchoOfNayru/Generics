#include "intvector.h"
#include <cassert>
#include <cstring>
#include <iostream>
intVector::intVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector()
{
	delete[] data;
}

int & intVector::operator[](size_t idx)
{
	return data[idx];
}

int intVector::operator[](size_t idx) const
{
	return data[idx];
}

int& intVector::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);

	return data[idx];
}

int& intVector::append(int val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	data[size] = val;
	++size;

	return data[size - 1];
}

bool intVector::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize)
	{
		capacity *= 2;
	}

	int* newData = new int[capacity];
	memcpy(newData, data, sizeof(int) * size);

	delete[] data;

	data = newData;
	return true;
}

int* intVector::c_ptr() const
{
	return data;
}

size_t intVector::getCapacity() const
{
	return capacity;
}

size_t intVector::getSize() const
{
	return size;
}

bool intVector::empty() const
{
	return size == 0;
}

int intVector::front() const
{
	return data[0];
}

int intVector::back() const
{
	return data[size - 1];
}

void intVector::Clear()
{
	size = 0;
}

void intVector::Erase(size_t idx)
{
	for (int i = idx; i < size; i++)
	{
		int temp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}

	size--;
}

int intVector::Count(int value)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			counter++;
		}
	}
	return counter;
}

void intVector::Insert(size_t idx, int value)
{
	assert(idx >= 0);
	assert(idx <= size);

	append(value);

	for (int i = size - 1; i > idx; i--)
	{
		int temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

void intVector::Reserve(size_t newCapacity)
{
	if (newCapacity > capacity)
	{
		int *newData = new int[newCapacity];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

}

void intVector::Compact()
{
	if (capacity > size)
	{
		int *newData = new int[size];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = size;
	}
}

void intVector::printVector()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << std::endl;
	}
}