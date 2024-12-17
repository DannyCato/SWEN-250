#include "parser.h"
#include <string>
#include <regex>

void parser::openFile(std::string filename)
{
    if (regex_match(filename, regex(".*[.]md$")))
    {
        ifstream file(filename);
        iFile.swap(file);

        prepareFile();
    }
    
}

void parser::prepareFile()
{
    iFile.seekg(0, std::ios::end);
    length = iFile.tellg();
    iFile.seekg(0, std::ios::beg);
}

void parser::readLine()
{
    // iFile.read(&contents[0], length); // when contents was a vector 
    // getline(iFile, line);
}

int parser::manager(ofstream &ofile)
{
    markdownconvert mdc = markdownconvert(ofile);
    // std::string s;
    std::vector<std::string> unconverted_lines;

    bool last_was_BQ = false;
    bool BQ_check = false;

//  for (char c : contents)
    while (getline(iFile, line))
    {
        if (line[line.size() - 1] == '\r')
        {
            line.pop_back();
        }
        if (line[0] == '>')
        {
            BQ_check = true;
        }
        // for (char c : line)
        // {
        //     s.push_back(c);
        //     if (iscntrl(c))
        //     {
        unconverted_lines.push_back(line);
        sender(line, mdc, last_was_BQ);
        if (BQ_check)
        {
            last_was_BQ = true;
        }
        else
        {
            last_was_BQ = false;
        }
        BQ_check = false;
        // line.clear();
        //     }
        // }
    }

    if (last_was_BQ)
    {
        mdc.buffer("</blockquote>");
    }

    mdc.write();
    mdc.closeFile();
    iFile.close();
    return 0;
}

void parser::sender(std::string &s, markdownconvert &mdc, bool last_was_block)
{
    do
    {
        if (std::regex_search(s, std::regex("^[>]")))
        {
            s = mdc.markdownToBQ(s, last_was_block);
        }
        else if (last_was_block)
        {
            s = mdc.markdownToEndBQ(s);
        }
        
        if(std::regex_search(s, std::regex("^[#]")))
        {
            s = mdc.markdownToHeading(s);
        }

        if(std::regex_search(s, std::regex("[*]")))
        {
            s = mdc.markdownToBold(s);
        }
        
        if(std::regex_search(s, std::regex("[_]")))
        {
            s = mdc.markdownToItalics(s);
        }
    }
    while(std::regex_search(s, std::regex("^[#>]|[*]|[_]")));
    mdc.buffer(s);    
}

parser::parser() {contents = std::vector<char>('0'); line = "";}

parser::parser(std::string s)
{
    openFile(s);
    contents = std::vector<char>('0');
    line = "";
}

parser::parser(ifstream &file)
{
    iFile.swap(file);
    prepareFile();
    contents = std::vector<char>('0');
    line = "";
}

std::ifstream *parser::get_iFile()
{
    return &iFile;
}

std::streampos parser::get_length()
{
    return length;
}