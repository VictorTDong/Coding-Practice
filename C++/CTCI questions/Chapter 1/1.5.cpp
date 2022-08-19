/*
1 Away

    algorithm

    if string is is same length or size is not different by more than 1
        check to see if the characters are the same

    if one of the two strings is shorter by 1 then
        we can remove a character from the longer string then check to see if they are the same
    
    to check
        compare the characters and count the number of characters that are different
*/

#include<iostream>

bool checkString(const std::string& str1,const std::string& str2)
{
    int x = 0;
    int y = 0;
    int size = 0;
    int diff = 0;

    (str1.size() > str2.size()) ? size = str1.size(): size = str2.size(); 
    
    while(x != str1.size() && y != str2.size())
    {
        if(diff > 1) return false;

        if(str1[x] != str2[y])
        {
            diff++;
            if(str1.size() == str2.size())
            {
                x++;
            }
        }
        else x++;
        y++;
    }
    return true;
}

bool checkCharCount(const std::string& str1,const std::string& str2)
{
    if(str1.size() == str2.size() || abs((long)str1.size() - (long)str2.size()) < 2)
    {
        return checkString(str1,str2);
    }
    
    return false;
}

int main()
{
    std::cout.setf(std::ios::boolalpha);
    std::cout << "The strings pale and ple are one edit away: " << checkCharCount("pale", "ple") << std::endl;
    std::cout << "The strings pales and pale are one edit away: " << checkCharCount("pales", "pale") << std::endl; 
    std::cout << "The strings pale and bale are one edit away: " << checkCharCount("pale", "bale") << std::endl; 
    std::cout << "The strings pale and bake are one edit away: " << checkCharCount("pale", "bake") << std::endl; 
}
