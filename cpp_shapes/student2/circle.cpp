#include "circle.h"
#include <iostream> //needed to cout

// Constructors – Notice class name before ::
Circle::Circle(int r) 
{ 
    std::cout<<"Circle ctor"<<std::endl;
    radius = r;
    name = "Circle";
}


int Circle::Area()
{
    return 0;
    //Fill in your code
}

int Circle::Area2()
{
    return Area();
}

int Circle::Size()
{
    return Circumference();
}

int Circle::Circumference()
{
    return 0;
    //Fill in your code
}


Circle::~Circle(){std::cout<<"Destructor for Circle"<<std::endl;}