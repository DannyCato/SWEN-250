#include "giraffe.h"
#include <iostream>

using namespace std;

Giraffe::Giraffe()
{
    name = "a giraffe" ;
    sound = "*leaf munching*" ;
}
Giraffe::Giraffe(std::string a_name, std::string a_sound)
{
        name = a_name;
        sound = a_sound;
}

void Giraffe::Speak()
{
    cout << "The giraffe " << name << " says " << sound << endl;
}

void Giraffe::Trick()
{
    cout << "I love selling my soul to commericalism" << endl;
}