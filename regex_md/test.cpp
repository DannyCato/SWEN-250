#include "markdownconvert.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    markdownconvert mdc;

    std::string s = mdc.markdownToHeading("# 123");
    cout << s << endl;
}