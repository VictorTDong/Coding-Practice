/*
Urlify a string

    algorithm:
        Create a new string

        Run through each character of the string until the true length is met
            for each character 
                check to see if it is ' '
                if true
                    append "%20" to new string
                if false
                    apped current char to new string

        return new string 
*/

#include<iostream>

std::string urlify(std::string str, int trueLength)
{
    std::string str1 = "";
    for(int i = 0; i < trueLength; i++)
    {
        char curr = str[i];
        if(str[i] == ' ')
        {
            str1 = str1 + "%20";

        }
        else
            str1 = str1 + str[i];
    }

    return str1;
}

int main()
{
    std::cout << urlify("hello how are you        ", 17) << std::endl;
    return 0;
}