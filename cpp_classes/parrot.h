#include <string>
#include "animal.h"
#ifndef _parrot
#define _parrot
class Parrot : public Animal
{
    public:
    Parrot() ;
    Parrot(std::string a_name, std::string a_sound) ;
    void Speak() ;
    void Trick() ;
    
    private:
    std::string name ;
    std::string sound ;
};

#endif