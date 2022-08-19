/*
Is the string a permutation

    algorithm:
        Check to see if the character count is the same in both strings
            if false, we know that based on the definition of a permutation that the two strings have different characters

        If the two string lengths are the same, we know that their is a possibility that it is a permutation and a easy
        way that we can test for this is to sort the two strings and compare each characters
            if the current characters being looked at is different, than the two strings cannot be a permutation
*/

#include<iostream>
#include<algorithm>

bool permutation(std::string str1, std::string str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1.compare(str2) == 0 ? true : false;
}

int main()
{
    std::cout.setf(std::ios::boolalpha);
    std::cout << "hello and hello: " << permutation("hello", "hello") << std::endl << "gello and hello: " << permutation("gello", "hello") << std::endl;
    return 0;
}