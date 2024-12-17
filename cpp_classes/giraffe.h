#include <string>
#include "animal.h"
#ifndef _giraffe
#define _giraffe
class Giraffe : public Animal
{
    public:
    Giraffe() ;
    Giraffe(std::string a_name, std::string a_sound) ;
    void Speak() ;
    void Trick() ;
    
    private:
    std::string name ;
    std::string sound ;
};

#endif