#include <string>


#ifndef __SHAPE__H
#define __SHAPE__H
class Shape
{
public:
	Shape();     // Default Constructor
    virtual int Area() = 0;//Pure virtual
    virtual int Size() = 0;
    int Area2();//Overridable with a default implementation
    std::string GetName();
	virtual ~Shape(); //Have to make this virtual, otherwise child destructor will not be called
protected:
    std::string name;
};
#endif