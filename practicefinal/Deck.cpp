#include "Deck.h"

//Starter code.  Add anything you need.  Add remaining methods.
DeckCard::DeckCard(int number, std::string suit)
{
    //Your code here
}

DeckCard::DeckCard(std::string name, std::string suit)
{
    //Your code here
}
DeckCard::~DeckCard()
{
    //Your code here
}

Deck::Deck()
{
    pCardListHead = nullptr;
//Add any additional code
}

Deck::~Deck()
{
    //Your code here
}
void Deck::Push(DeckCard* pCard) //Pushes a card to top of stack
{
    //Your code here
}

DeckCard* Deck::Pop() //Returns top card and moves ptr head to next card
{
    return nullptr;//Placeholder.  Your code here
}
    
//Returns top card; ptr head doesn't change
DeckCard* Deck::Peek()
{
    return nullptr;//Placeholder.  Your code here.
} 

//Returns count of cards in the deck
int Deck::Count()
{
    return -1;   //Placeholder.  Your code here.
} 
