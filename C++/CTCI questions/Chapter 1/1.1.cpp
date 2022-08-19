/*
Is the string unique

    algorithm:
    If ASCII we know that their are 128 characters

    Check to see if the string length is higher than 128
        if true
            return false - We know that their has to be atleast one repeated character
        
    Create a boolean map to map each ASCII character *could also implement with an integer map to count each character*

    Run through each character in the string and set the corresponding map value to true
        if current character is true, we know that it is repeated
    
    if we get to the end of the string
        return true *signifies that the string is unique*
*/

#include<iostream>

bool isUnique(const std::string& str)
{
    if(str.length() > 128)
    {
        return false;
    }

    bool* asciiSet = new bool[128];

    for(auto x : str)
    {
        int val = x;
        if(asciiSet[val] == true)
        {
            return false;
        }
        asciiSet[val] = true;
    }

    delete(asciiSet);
    
    return true;
}

int main()
{
    std::cout.setf(std::ios::boolalpha);
    std::cout << "hello: " << isUnique("hello") << std::endl << "helo: " << isUnique("helo") << std::endl;
    return 0;
}