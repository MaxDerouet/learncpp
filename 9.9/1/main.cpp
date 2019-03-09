#include <iostream>
#include <string>
#include <cassert>

class Mystring
{
    std::string m_string;
public:
    Mystring(std::string str): m_string(str)
    {
    }
    std::string operator()(const int start, const int length);
};

std::string Mystring::operator()(const int start, const int length)
{
    assert(start+length<=m_string.length() && "Substring out of range.");
    std::string temp;
    for (int count=start; count<start + length; ++count)
        temp+=m_string[count];
    return temp;
}

int main()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 5); // start at index 7 and return 5 characters

    return 0;
}
