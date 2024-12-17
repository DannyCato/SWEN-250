#include "regextests.h"
#include <string>
#include <regex>

// #include <iostream>

using namespace std;

//This method will check to see if the provided string 
//contains numbers ONLY
//Returns true if there are only numbers, else returns false;
bool RegexTests::TestNumberMatch(string input)
{
    regex reg("[^0-9]");
    bool answer = regex_search(input, reg);
    // cout << (!answer ? "true" : "false") << endl;
    return !answer;
}

//This method will check to see if the provided string 
//starts with the string in 'substring'
//Returns true if the condition is met, else returns false
bool RegexTests::TestStartsWith(string input, string substring)
{
    regex reg("^" + substring);
    bool answer = regex_search(input, reg);
    // cout << (answer ? "true" : "false") << endl;
    return answer;
}

//This method will check to see if the provided string 
//ends with the string in 'substring'
//Returns true if the condition is met, else returns false
bool RegexTests::TestEndsWith(string input, string substring)
{
    regex reg(substring + "$");
    bool answer = regex_search(input, reg);
    // cout << (answer ? "true" : "false") << endl;
    return answer;
}

//This method will check to see if the provided string 
//starts with the string in 'start', and ends with the string in 'end'
//Returns true if the condition is met, else returns false
bool RegexTests::TestStartsAndEndsWith(string input, string start, string end)
{
    regex reg("^" + start + ".*" + end + "$");
    bool answer = regex_search(input, reg);
    // cout << (answer ? "true" : "false") << endl;
    return answer;
}

//This method will check to see if the provided string 
//is a valid email patterns
//The rules are: 
//- alphanumerics followed by a '@', (typical naming characters including '.', '-', '_' are also allowed)
//- then more alphanumerics, followed by a '.', 
//- and then 2-3 letters
//Note: We are using a simplified version of email validation
//Returns true if the condition is met, else returns false
bool RegexTests::TestEmailPattern(string input)
{
    // ^([a-zA-Z0-9\.\-_]+)@((\.|[a-zA-z0-9]*)*)(\.[a-zA-Z]{3})$
    // after repeated trial and error in regex101.com i came up with that string ^^
    regex reg("^([a-zA-Z0-9\\.\\-_]+)@((\\.|[a-zA-z0-9]*)*)(\\.[a-zA-Z]{3})$");
    bool answer = regex_match(input, reg);
    // cout << (answer ? "true" : "false") << endl;
    return answer;
}


