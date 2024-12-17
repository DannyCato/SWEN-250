#include "square.h"
#include <iostream> //needed to cout

// Constructors – Notice class name before ::
Square::Square(int s) 
{ 
    std::cout<<"Square ctor"<<std::endl;
    side = s;
    name = "Square";
}


int Square::Area()
{
    return side*side;
}

int Square::Size()
{
    return Perimeter();
}

int Square::Area2()
{
    return Area();
}

int Square::Perimeter()
{
    return 4*side;
}

Square::~Square(){std::cout<<"Destructor for Square"<<std::endl;}