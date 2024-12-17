#include "parrot.h"
#include <iostream>

using namespace std;

Parrot::Parrot()
{
    name = "a parrot" ;
    sound = "Polly want a cracker" ;
}
Parrot::Parrot(std::string a_name, std::string a_sound)
{
        name = a_name;
        sound = a_sound;
}

void Parrot::Speak()
{
    cout << "The parrot " << name << " says " << sound << endl;
}

void Parrot::Trick()
{
    cout << "Polly want a cracker *Sqwuack*" << endl;
}