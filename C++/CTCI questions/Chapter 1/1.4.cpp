//need to check for at most 1 char has an odd amount of chars based on def of palindome
//if palindome exist then permutation exist
//not case sensitive

/*
    algorithm:

    Check character count of each char in the string (through hash map)
        convert to lowercase if necessary
    
    Check hash map and make sure at most only 1 char in hash map is odd
         cases:
            all even
            1 odd
            >2 odd
*/

// got rid of another for loop
/*
bool checkOdd()
{
    bool odd = false;

    for(int& x : table)
    {
        if(x % 2 == 1)
        {
            if(odd == true) return false;
            odd = true;
        }
    }
    return true;
}

*/
#include<iostream>

int table['z' - 'a' + 1];

int getCharIntVal(char& c)
{
    return (tolower(c) >= 'a' && tolower(c) <= 'z') ? tolower(c) -'a': -1;
}

bool buildTable(std::string& str)
{
    int oddCount = 0;

    for(char c : str)
    {
        int charVal = getCharIntVal(c);
        if(charVal != -1)
        {
            table[charVal]++;
            (table[charVal] % 2 == 1) ? oddCount++ : oddCount--;
        }
    }
    return !(oddCount > 1);
}

bool palindromePermutation(std::string& str)
{
    return buildTable(str);
}

int main()
{
    std::string str = "asdfgf";
    std::cout.setf(std::ios::boolalpha);
    std::cout << palindromePermutation(str) << std::endl;   
    return 0;
}