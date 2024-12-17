#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "markdownconvert.h"
#include "parser.h"

using namespace std;

int check_inputs(std::vector<std::string> &argv)
{
    std::regex reg[2] = {regex("(-i|-o)"), regex(".*([.](html|md))")};
    for (int i = 0; i < argv.size(); i++ ) 
    {
        if (!std::regex_match(argv[i], reg[i % 2]))
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> allArgs; // https://stackoverflow.com/a/15344748
    if (argc == 5)
    {
        allArgs.assign(argv + 1, argv + argc);
        if (check_inputs(allArgs) == 0)
        {
            std::string iFileName;
            std::string oFileName;
            int res = allArgs[0].compare("-i");
            if (!res)
            {
                iFileName = allArgs[1];
                oFileName = allArgs[3];
            }
            else
            {
                iFileName = allArgs[3];
                oFileName = allArgs[1];
            }
            std::ifstream readFile(iFileName);
            std::ofstream writeFile(oFileName);
            
            parser p(readFile);
            // p.readFile();
            p.manager(writeFile);

            return 0;
        }
    }    
    std::cout << "To run properly use: ./md_convert -i <markdown file>.md -o <html file>.html" << std::endl;
    return 1;
}
