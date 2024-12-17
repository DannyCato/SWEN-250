#include <string>
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

#ifndef _markdownconvert_
#define _markdownconvert_

class markdownconvert
{
    private:
        std::ofstream outFile;
        vector<std::string> lines;
    protected:
        int countRepeatedChar(std::string, char);
        vector<std::string> tagBuilder(std::string);
        vector<std::string> tagBuilder(char, int);
    public:
        markdownconvert(std::string);
        markdownconvert(ofstream &);
        markdownconvert();

        void write();
        void buffer(std::string);
        void openFile(std::string);
        void closeFile();

        std::string markdownToHeading(std::string);
        std::string markdownToHeading(std::string, int);
        std::string markdownToBold(std::string);
        std::string markdownToItalics(std::string);
        std::string markdownToBQ(std::string, bool);
        std::string markdownToEndBQ(std::string);


        std::ofstream *get_outFile();
        std::vector<std::string> get_Lines();
};

#endif