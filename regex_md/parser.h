#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "markdownconvert.h"

using namespace std;

#ifndef _parser_
#define _parser_

class parser
{
private:
    std::ifstream iFile;
    std::streampos length;
    std::vector<char> contents;
    std::string line;
public:
    parser();
    parser(std::string);
    parser(ifstream &);

    int manager(ofstream &);
    void openFile(std::string);
    void readLine();
    void sender(std::string &, markdownconvert &, bool);
    void prepareFile();

    std::ifstream *get_iFile();
    std::streampos get_length();
};

#endif
