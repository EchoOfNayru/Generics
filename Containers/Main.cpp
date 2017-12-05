#include "intLinkedList.h"
#include "intvector.h"
#include "test.h"

int main() 
{
	intLinkedList nums;
	nums.append(1);
	nums.append(2);
	nums.append(3);
	nums.append(4);
	nums.Insert(2, 7);
	
	nums.~intLinkedList();
}