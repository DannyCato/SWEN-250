#include <string>
#include "animal.h"
#ifndef _cat
#define _cat
class Cat : public Animal
{
    public:
    Cat() ;
    Cat(std::string a_name, std::string a_sound) ;
    void Speak() ;
    void Trick() ;

    private:
    std::string name ;
    std::string sound ;
};

#endif