#include "dog.h"
#include <iostream>

using namespace std;

Dog::Dog()
{
    //Doesn't do anything
}
Dog::Dog(std::string a_name, std::string a_sound)
{
        name = a_name;
        sound = a_sound;
}

void Dog::Speak()
{
    cout << "The dog " << name << " says " << sound << endl;
}

void Dog::Trick()
{
    cout << "I can roll over" << endl;
}