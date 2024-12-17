#include <stdio.h>
#include <iostream>

#include "filesecurity.h"
using namespace std;

//Your code in main will read the command line arguments, and based on the parameters
//either process the file, or detect an error in the arguments and print usage instructions.
int main(int argc, char** argv)
{
    if (argc > 2)
    {
        string option = argv[1];
        string filePath = argv[2];

        FileSecurity fManager(filePath);
        if (option.compare("-e") == 0)
        {
            fManager.Encode();
            return 0;
        } 
        else if (option.compare("-d") == 0)
        {
            fManager.Decode();
            return 0;
        }
    } 
    cout << "Usage:\nfilesec -e|-d [filename]" << endl;
    return 1;
    
}
