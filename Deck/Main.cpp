#include "Deck.h"

int main() 
{
	deck<int> myDeck;
	myDeck.pushFront(2);
	myDeck.pushFront(1);
	myDeck.pushBack(3);
	myDeck.pushBack(4);
	
	myDeck.at(3);
	myDeck.front();
	myDeck.back();

	myDeck.popFront();
	myDeck.popFront();
	myDeck.popBack();

	system("pause");
}