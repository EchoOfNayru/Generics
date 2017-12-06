#pragma once

#include <cassert>
#include <cstring>
#include "Iterator.h"

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:
	tVector()
	{
		capacity = 2;
		data = new int[capacity];
		size = 0;
	}
	~tVector()
	{
		delete[] data;
	};

	iterator<tVector<<T>> begin() 
	{
		return iterator<tVector<<T>>(*this, 0);
	}

	iterator<tVector<T>> end() 
	{
		return iterator<tVector<T>>(*this, size);
	}

	T &operator[](size_t idx)
	{
		return data[idx];
	};
	T operator[](size_t idx) const
	{
		return data[idx];
	};

	T& at(size_t idx)
	{
		assert(idx >= 0);
		assert(idx < size);

		return data[idx];
	};

	T& append(T val)
	{
		if (size == capacity)
		{
			bool didGrow = grow(size + 1);
			assert(didGrow);
		}

		data[size] = val;
		++size;

		return data[size - 1];
	};

	T* c_ptr() const 
	{
		return data;
	};
	
	size_t getCapacity() const 
	{
		return capacity;
	};
	size_t getSize() const 
	{
		return size;
	};

	bool empty() const 
	{
		return size == 0;
	};

	T front() const 
	{
		return data[0];
	};
	T back() const 
	{
		return data[size - 1];
	};

	void Clear() 
	{
		size = 0;
	};
	void Erase(size_t idx) 
	{
		for (int i = idx; i < size; i++)
		{
			int temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
		}

		size--;
	};
	int Count(T value) 
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
	};
	void Insert(size_t idx, T value) 
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
	};
	void Reserve(size_t newCapacity) 
	{
		if (newCapacity > capacity)
		{
			int *newData = new int[newCapacity];
			memcpy(newData, data, sizeof(int) * size);
			delete[] data;
			data = newData;
			capacity = newCapacity;
		}
	};
	void Compact() 
	{
		if (capacity > size)
		{
			int *newData = new int[size];
			memcpy(newData, data, sizeof(int) * size);
			delete[] data;
			data = newData;
			capacity = size;
		}
	};

	void printVector() 
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << std::endl;
		}
	};

private:
	bool grow(size_t minSize) 
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
	};
};