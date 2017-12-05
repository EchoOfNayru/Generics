#pragma once

class intVector
{
	int * data;			// ptr to your dynamically allocated array
	size_t capacity;	// total capacity
	size_t size;		// total number of elements stored

public:
	intVector();
	~intVector();

	int &operator[](size_t idx);
	int operator[](size_t idx) const;

	int& at(size_t idx);

	int& append(int val);

	int* c_ptr() const;

	size_t getCapacity() const;
	size_t getSize() const;

	bool empty() const;

	int front() const;
	int back() const;

	void Clear();

	void Erase(size_t idx);
	int Count(int value);
	void Insert(size_t idx, int value);
	void Reserve(size_t newCapacity);
	void Compact();

	void printVector();

private:
	bool grow(size_t minSize);
};

//template<typename T>
//class tVector
//{
//	T * data;			// ptr to your dynamically allocated array
//	size_t capacity;	// total capacity
//	size_t size;		// total number of elements stored
//
//public:
//	tVector();
//	~tVector();
//
//	T& at(size_t idx);
//
//	T& append(int val);
//};
//
//template<typename T>
//class thing
//{
//	T div(T a);
//};
//
//template<typename T>
//T thing::div(T a)
//{
//
//}