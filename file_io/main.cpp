#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <filesystem>
#include <vector>

using namespace std;

// helper function to nicely hide away an ugly switch statement
// takes in an unsigned short that holds less information than a nibble
// returns a char representing a hexadecimal number
char shortToHex(unsigned short a)
{
    try
    {
        switch (a)
        {
            case 0:
                return '0';
                break;
            case 1:
                return '1';
                break;
            case 2:
                return '2';
                break;
            case 3:
                return '3';
                break;
            case 4:
                return '4';
                break;
            case 5:
                return '5';
                break;
            case 6:
                return '6';
                break;
            case 7:
                return '7';
                break;
            case 8:
                return '8';
                break;
            case 9:
                return '9';
                break;
            case 10:
                return 'a';
                break;
            case 11:
                return 'b';
                break;
            case 12:
                return 'c';
                break;
            case 13:
                return 'd';
                break;
            case 14:
                return 'e';
                break;
            case 15:
                return 'f';
                break;
            default:
                throw a;
                break;
        }
    }
    catch(...)
    {
        cout << a << " is out of range to be turned into hex";
    }
    return '\0';
}

// helper function to turn from integer into bits
// input integer must be less than a byte
// passes a bool vector by reference to fill
// returns the input vector
void shortToBinary(unsigned short a, std::vector<bool> &bits)
{
    for (int i = (bits.size() - 1); i >= 0; i--) // represent a as bits manually one byte at a time
    {
        bits[i] = a % 2;
        a /= 2;
    }
}

// helper function to turn size of 8 bool vectors into 2 digit hex char vectors
// input bool vector of size 8
// passes a char vector of size 2 by reference to fill
// returns input char vector
void binaryToHex(std::vector<bool> bits, std::vector<char> &characters)
{
    bool flag = false;
    for (int i = 0; i < 2; i++)
    {
        int j = i * 4;
        unsigned short sum = 0;
        sum += bits[j] * 8;
        sum += bits[j + 1] * 4;
        sum += bits[j + 2] * 2;
        sum += bits[j + 3];
        characters[i] = shortToHex(sum);
    }
}

int readText1(string fileName)
{
    ifstream inFileText(fileName);
    string fileText;
    int num = 1;
    int charCount = 0;
    while (getline (inFileText, fileText)) 
    {
        // Output the text from the file 
        cout << "Line "<< num << ": " << fileText << endl ;
        charCount += fileText.length() + 1; // newline is cr and lf but only one character is counted 
        num++;
    }
    charCount -= 1 ; // remove one character from no new line at the end
    inFileText.close();
    return charCount;
}

int readBinary(string fileName)
{
    //open file
    ifstream inFile(fileName, std::ios::binary);
    //get length
    std::streampos fileSize;
    inFile.seekg(0, std::ios::end);
    fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);
    //read into buffer
    std::vector<unsigned char> buffer(fileSize);
    inFile.read((char *) &buffer[0], fileSize);

    long i = 0;
    unsigned short a;
    std::vector<bool> bits(8); // byte representation of the unsigned int a
    std::vector<char> characters(2); // hex represetation of unsigned int a
    //read buffer and put into cout as hexadecimal
    for (unsigned char c : buffer)
    {
        if (i % 64 == 0 && i != 0)
        {
            cout << '\n' ;
        }
        a = c ;
        shortToBinary(a, bits);
        binaryToHex(bits, characters);
        cout << characters[0] << characters[1] << ' ' ;
        i++;
    }
    cout << endl;

    return fileSize;
}



void printHeading(string data)
{
    cout<<endl<<"******** " <<data<<" ********"<<endl;
}
int main()
{
    cout << "C++ version:" << __cplusplus <<endl;

    printHeading("readText1");
    int count = readText1("testfile2.txt");
    cout << "Count: " << count << endl;
    count = filesystem::file_size("testfile2.txt");
    cout<<"\n\nFrom filesystem, size is:"<<count <<endl;

    printHeading("readBinary");
    count = readBinary("firebug.jpg");
    cout << "Count: " << count << endl;
    count = filesystem::file_size("firebug.jpg");
    cout<<"\n\nFrom filesystem, size is:"<<count <<endl;

}
