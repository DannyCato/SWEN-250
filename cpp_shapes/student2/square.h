#include "shape.h"

class Square: public Shape
{
public:
	Square(int s);     // Param Constructor
    int Area() ;
    int Size();
    int Area2();
	~Square();
protected:
    int Perimeter() ;
private:
    int side;
};

