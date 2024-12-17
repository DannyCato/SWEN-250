#include "shape.h"

class Circle: public Shape
{
public:
	Circle(int radius);     // Param Constructor
    int Area() ;
    int Size();
    int Area2();

	~Circle();
protected:
    int Circumference() ;
private:
    int radius;
    double pi = 3.14159;
};
