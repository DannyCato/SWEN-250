#include <iostream>
#include "circle.h"
#include "square.h"
#include <vector>
#include <typeinfo>

using namespace std;

void PrintShapes1(vector<Shape*> list);
void PrintShapes2(vector<Shape*> list);
void PrintShapes3(vector<Shape*> list);
void Cleanup(vector<Shape*> list);

int main()
{
    //Try to uncomment this code.
    //What happens?  How can you fix it?
    
    std::vector<Shape*> myVec;
    Square s(2);
    Circle c(3);
    myVec.push_back(&s);
    myVec.push_back(&c);
    for (auto *sh: myVec)
    {
        cout << "area:"<<*sh->Area()<<";Perimiter:"<<*sh.Size()<<";Name:"<<*sh.GetName()<<endl;
    }

    vector<Shape*> myPointerVec;
    Square* p_s = new Square(2);
    Circle* p_c = new Circle(3);
    myPointerVec.push_back(p_s);
    myPointerVec.push_back(p_c);
    PrintShapes1(myPointerVec);
    PrintShapes2(myPointerVec);
    Cleanup(myPointerVec);

}

void PrintShapes1(vector<Shape*> list)
{
    for (Shape* p_sh: list)
    {
        cout << "area:"<<p_sh->Area()<<";Size:"<<p_sh->Size()<<";Name:"<<p_sh->GetName()<<endl;
    }

}

void PrintShapes2(vector<Shape*> list)
{
    for (Shape* p_sh: list)
    {
        cout << "area2:"<<p_sh->Area2()<<";Size:"<<p_sh->Size()<<";Name:"<<p_sh->GetName()<<endl;
    }
}



void Cleanup(vector<Shape*> list)
{
    for (Shape* p_sh: list)
    {
       if (p_sh != nullptr)
        delete p_sh;
    }
 
}