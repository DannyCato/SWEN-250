#include <string> //string class
#include <iostream> //cout, cin ...
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "parrot.h"
#include "giraffe.h"

using namespace std; //so we don't have to say 'std::string' etc.


#define TEST_DOG
#define TEST_CAT
#define TEST_PARROT
#define TEST_GIRAFFE

int main()
{
    Animal generic("blank slate", "silence is golden");
    generic.Speak();
    generic.Trick();
    cout<<endl;

#ifdef TEST_DOG
    Dog fido("Rover", "Woof");
    fido.Speak();
    fido.Trick();
    cout<<endl;
    Animal* animal = new Animal("Old Yeller", "Bark and Bite");
    animal->Speak();
    animal->Trick();
    ((Dog*)animal)->Trick();
    delete animal;
    cout<<endl;
#endif

#ifdef TEST_CAT
    Cat whiskers("meowth", "team rocket blasting off again");
    whiskers.Speak();
    whiskers.Trick();
    cout<<endl;
#endif

#ifdef TEST_PARROT
    Parrot polly("Polly", "gimme all your crackers");
    polly.Speak();
    polly.Trick();
    cout << endl;
#endif

#ifdef TEST_GIRAFFE
    Giraffe geoff("Geoff", "1 for the money, 2 for the show, 3 to get ready, 4 to go");
    geoff.Speak();
    geoff.Trick();
    cout << endl;
#endif
    return 0;
}
