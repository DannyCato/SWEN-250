#include "shape.h"
#include <iostream> //needed to cout

// Constructors – Notice class name before ::
Shape::Shape() 
{ 
    std::cout<<"Shape ctor"<<std::endl;
    name = "Amorphous Blob";
}


std::string Shape::GetName() 
{
     return "";
    //Fill in here 
}
int Shape::Area2()
{
    return 51;
}

Shape::~Shape() { std::cout<<"Destructor: Nothing to do"<<std::endl;}

