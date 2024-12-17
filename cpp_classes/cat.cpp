#include "cat.h"
#include <iostream>

using namespace std;

Cat::Cat()
{
    name = "a cat" ;
    sound = "what do you want me to meow or something" ;
}
Cat::Cat(std::string a_name, std::string a_sound)
{
        name = a_name;
        sound = a_sound;
}

void Cat::Speak()
{
    cout << "The cat " << name << " says " << sound << endl;
}

void Cat::Trick()
{
    cout << "I dont do tricks for pesky humans!" << endl;
}