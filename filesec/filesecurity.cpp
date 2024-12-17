#include "filesecurity.h"
#include <fstream> //File streams

//Default constructor
FileSecurity::FileSecurity()
{
    sourcePath = "";
}


//constructor with param.  Initialize the appropriate variables
FileSecurity::FileSecurity(string filePath)
{
    sourcePath = filePath;
}

//Encode the sourceFile and put result in outputFile
//Return true if successful, return false if there is a problem
//NOTE: ALL bytes in the file must be encoded - even the non-printing ones, such as new-line
bool FileSecurity::Encode()
{
    try
    {
        // prepare source file for reading
        ifstream iFile(sourcePath);
        std::streampos length;
        // prepare output file
        string oFilename = CreateOutputFileName("_enc");
        ofstream oFile(oFilename);
        // get length of source file
        iFile.seekg(0, std::ios::end);
        length = iFile.tellg();
        iFile.seekg(0, std::ios::beg);
        // read source file
        char* buffer = new char[length];
        iFile.read(buffer, length);
        // encode 
        for (int i = 0; i < length; i++)
        {
            oFile << EncodeByte(buffer[i]);
        }
        // close all files and delete buffer
        delete buffer;
        iFile.close();
        oFile.close();
        return true;
    }
    catch(...)
    {
        return false;
    }
    
    
}

//Decode the sourceFile and put result in outputFile
//Return true if successful, return false if there is a problem
bool FileSecurity::Decode()
{
    try
    {
        // prepare source file for reading
        ifstream iFile(sourcePath);
        std::streampos length;
        // prepare output file
        string oFilename = CreateOutputFileName("_dec");
        ofstream oFile(oFilename);
        // get length of source file
        iFile.seekg(0, std::ios::end);
        length = iFile.tellg();
        iFile.seekg(0, std::ios::beg);
        // read source file
        char* buffer = new char[length];
        iFile.read(buffer, length);
        // encode 
        for (int i = 0; i < length; i++)
        {
            oFile << DecodeByte(buffer[i]);
        }
        // close all files and delete buffer
        delete buffer;
        iFile.close();
        oFile.close();
        return true;
    }
    catch(...)
    {
        return false;
    }
}

//Use the sourcePath to generate the output file name, based on the assignment requirements
//The parameter 'append' is passed in, so the same method can be used for both encoding files
//and decoding files.
string FileSecurity::CreateOutputFileName(string append)
{
    // std::string::size_type pos;
    // if ((pos = sourcePath.find("_enc")) != std::string::npos)
    // {
    //     sourcePath = sourcePath.substr(0, pos) + ".txt";
    // }
    // else if (pos = sourcePath.find("_dec") != std::string::npos)
    // {
    //     sourcePath = sourcePath.substr(0, pos - 1) + sourcePath.substr(pos + 4);
    // }
    string pruned = sourcePath.substr(0, sourcePath.length() - 4);
    return pruned + append + ".txt";
}

//Basic encode
//Follow the directions in the requirements to encode a single char/ byte
char FileSecurity::EncodeByte(char c)
{
    return (c + 100) % 256;
}

//Basic decode
//Follow the directions in the requirements to decode a single char/ byte

char FileSecurity::DecodeByte(char c)
{
    return (c - 100) % 256;
}