#include <iostream>
#include <string>
#include "test.h"
#include <cassert>

class Person
{
public:
	std::string name;
	int age;
	float height;
};

template<typename T>
void print(T value)
{
	std::cout << value;
}

template<>
void print(Person value)
{
	std::cout << value.name << std::endl;
	std::cout << value.age << std::endl;
	std::cout << value.height << std::endl;
}

template<typename T>
T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}

	return b;
}

template<typename T>
T max(T a, T b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

template<typename T>
T clamp(T value, T lower, T upper)
{
	if (value < lower)
	{
		return lower;
	}
	else if (value > upper)
	{
		return upper;
	}
	else
	{
		return value;
	}
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	assert<true>(5 == 5);
	assertEqual(5, 5);
	assertNotEqual(5, 4);

	int thing = 5;
	int fwoob = 7;

	double dinosaur = 1.1f;
	double hotdog = 2.3f;

	swap(dinosaur, hotdog);
	swap(thing, fwoob);

	Person theKob;
	theKob.name = "Kobington";
	theKob.age = 19;
	theKob.height = 170.18f;

	print(theKob);

	int age = 22;
	float weight = 105.7f;

	print(age);
	std::cout << std::endl;
	print(weight);

	int smallest = min(5, 7);
	int smallestFlt = min<int>(5, 7.5f);

	int biggest = max(5, 7);

	int squished = clamp(2, 5, 7);
	float somethingElse = clamp(2.1f, 0.0f, 1.0f);

	char example[20];
	example[0] = 'a';
	example[1] = 'a';
	example[2] = 'a';
	std::cout << example << std::endl;

	return 0;
}