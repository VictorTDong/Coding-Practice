/*
String Compression

    algorithm:
        loop through each char of string
            add count for current char
            if index+1 of current char is different
            append current char + count into new string
            count = 0;
*/

#include <iostream>
#include <string> 

std::string compression(const std::string& str)
{
    std::string compressed = "";
    int count = 0;

    for(int i = 0; i < str.size(); i++)
    {
        count++;

        if (str[i] != str[i+1])
        {
            compressed = compressed + str[i] + std::to_string(count);
            count = 0;
        }
    }

    return (str.size() > compressed.size()) ? compressed : str;
}

int main()
{
    std::cout.setf(std::ios::boolalpha);
    std::cout << compression("aabcccccaaa") << std::endl;
}