#include "markdownconvert.h"
#include <string>
#include <regex>

// opens a output file stream for writing and sends it to *outFile and populates it with a proper heading
// @param fileName a proper name of a file with a .html extension
void markdownconvert::openFile(std::string fileName)
{
    if (std::regex_search(fileName, regex(".*[.]html$")))
    {
        ofstream file(fileName);
        outFile.swap(file);
        
    } else {
        std::cout << "given filename does not end with .html. The output file pointer has not been changed" << std::endl;
    }
}

// TO BE USED AFTER EVERYTHING HAS BEEN WRITTEN AND DELETES EVERYTHING IN LINES and closes outFile
void markdownconvert::closeFile()
{
    for (std::string s : lines)
    {
        s.clear();
    }
    lines.clear();
    outFile.close();
}

// returns the output file stream
// @returns ofstream outFile
std::ofstream *markdownconvert::get_outFile()
{
    return &outFile;
}

// returns the vector buffer filled with parsed lines
// @returns std::vector<std::string> all currently parsed lines
std::vector<std::string> markdownconvert::get_Lines()
{
    return lines;
}

// returns half the count of the total number of markdown control characters.
// this helps determine the control flow of the character.
// 
// especially helpful for heading
// @param s a c++ string used to represent a line of the file
// @param c a char that is the markdown control character to look for
// @returns an int that is the count of c in s
int markdownconvert::countRepeatedChar(std::string s, char c)
{
    // regex reg("" + c);
    // std::smatch match;
    // std::regex_search(s, match, reg, std::regex_constants::match_any);
    // return match.length();
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }
    return count;
}

void markdownconvert::buffer(std::string s)
{
    lines.push_back(s);
}

// After everything has been compiled into lines, this is called to push it all into the file
void markdownconvert::write()
{
    std::ifstream openTemplate("page_template.html");
    std::string line;
    // std::streampos length;

    // openTemplate.seekg(0, std::ios::end);
    // length = openTemplate.tellg();
    // openTemplate.seekg(0, std::ios::beg);

    // std::vector<char> file;
    // openTemplate.read(&(file[0]), length);
    
    // for (int i = 0; i < 92; i++)
    // {
    //     outFile << file[i];
    // }
    
    // for (std::string s : lines)
    // {
    //     outFile << s << endl;
    // }

    // for (int i = 92; i < 108 ; i++)
    // {
    //     outFile << file[i];
    // }

    for (int i = 0; i < 5; i++)
    {
        getline(openTemplate, line);
        outFile << line;
    }
    outFile << "<body>" << endl;

    for (std::string s : lines)
    {
        outFile << s << endl;
    }
    outFile << "</body>" << endl;

    getline(openTemplate, line);
    while(getline(openTemplate, line))
    {
        outFile << line;
    }
}

// general tagBuilder method
// @param s c++ string
// @returns a vector of c++ strings that gives the open and close headers for the string 
vector<std::string> markdownconvert::tagBuilder(std::string s)
{
    vector<std::string> sv;
    sv.push_back("<" + s + ">");
    sv.push_back("</" + s + ">");
    return sv;
}

// this overload is meant for header tags
// @param c char for the tag that is being built
// @param a int for the degree
// @returns a vector of c++ strings that gives the open and close headers for the string 
vector<std::string> markdownconvert::tagBuilder(char c, int a)
{
    std::string s = c + std::to_string(a);
    return tagBuilder(s);
}

// overload to input only a string in case its useful. ulimately redirects to markdownToHeading(std::string, int) overload
// @param s a c++ string that is taken as a whole line to process a heading tag from markdown
std::string markdownconvert::markdownToHeading(std::string s)
{
    return markdownToHeading(s, countRepeatedChar(s, '#'));
}

// converts a string of markdown into a heading
// @param s a c++ string that is taken as a whole line to process a heading tag from markdown
// @param a the number of heading markers that were found in the string
std::string markdownconvert::markdownToHeading(std::string s, int a)
{
    vector<std::string> headers = tagBuilder('h', a);
    std::string line = headers[0] + s.substr(a + 1) + headers[1];
    return line;
}

// replaces bold markdown characters with strong tags
// also should be used if line contains italic markers as it can handle both within this function
// @param s c++ string that contains bold markers
std::string markdownconvert::markdownToBold(std::string s)
{
    std::string safe = s;
    vector<std::string> bolds = tagBuilder("strong");
    int pos = s.find('*');
    int rpos = s.find('*', pos+2);
    // if (regex_search(match[0].str(), std::regex("_.*_"))) // check for italics
    // {
    //     std::string newMiddle = markdownToItalics(match[0].str().substr(2, match[0].str().length() - 4), true);
    //     s = s.substr(0,pos) + "**" + newMiddle + "**" + s.substr(rpos, s.length() - rpos) ;
    // }
    std::string line = s.substr(0, pos) + bolds[0]; 
    line += s.substr(pos + 2, rpos - pos - 2) + bolds[1];
    line += s.substr(rpos + 2, s.length() - rpos + 2);
    return line;
}

std::string markdownconvert::markdownToItalics(std::string s)
{
    vector<std::string> italics = tagBuilder("i");
    int pos = s.find('_');
    int rpos = s.find('_', pos+1);
    std::string line = s.substr(0, pos) + italics[0]; 
    line += s.substr(pos + 1, rpos - pos - 1) + italics[1];
    line += s.substr(rpos + 1, s.length() - rpos + 2);
    return line;
}

std::string markdownconvert::markdownToBQ(std::string s, bool open)
{
    std::vector<std::string> p = tagBuilder("p");
    if (!open)
    {
        std::string blockquote = tagBuilder("blockquote")[0];
        return blockquote + p[0] + s.substr(2) + p[1];
    }
    else
    {
        return p[0] + s.substr(2) + p[1];
    }
}

std::string markdownconvert::markdownToEndBQ(std::string s)
{
    std::string blockquote = tagBuilder("blockquote")[1];
    return blockquote + s;
}

markdownconvert::markdownconvert() 
{
    lines = vector<std::string>();
}

markdownconvert::markdownconvert(ofstream &out) 
{
    outFile.swap(out);
    markdownconvert();
}

markdownconvert::markdownconvert(std::string str)
{
    openFile(str);
    markdownconvert();
}

