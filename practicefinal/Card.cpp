#include "Card.h"

//Some starter code is provided here -- mainly constructors
//Finish implementing anything required in the constructors and add implementation
//for the remaining methods
//If you want to split this up into multiple files, that is fine.  Make sure you update the Makefile accordingly

Card::Card()
{
    //Initialize to invalid values
    suit = "";
}
Card::~Card()
{
    //Your code here
}
std::string Card::GetSuit() 
{
    return "";//Placeholder.  Your code here
}


PipCard::PipCard(std::string _suit, int number)
{
    //Your code here
}
PipCard::~PipCard()
{
    //Your code here
}
int PipCard::GetNumber()
{
    return -1;//Placeholder.  Your code here
}

FaceCard::FaceCard(std::string _name, std::string _suit)
{
    //Your code here
}
FaceCard::~FaceCard()
{
    //Your code here
}
std::string FaceCard::GetName()
{
    
    return "";//Placeholder.  Your code here.
}

bool FaceCard::IsAce() 
{
    return false;//Placeholder.  Your code here
}


