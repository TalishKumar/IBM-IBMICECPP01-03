#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()   //DO NOT change the 'main' signature
{
    //Initialize luckyNumberTable
    char luckyNumberTable[2][26]
    {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
        {'1', '2', '3', '4', '5', '8', '3', '5', '1', '1', '2', '3', '4', '5', '7', '8', '1', '2', '3', '4', '6', '6', '6', '5', '1', '7'}
    };

    //Get user name
    cout << "Enter your name:\n";
    string userName{};
    getline(cin, userName);

    //Length of string
    int stringLength{ 0 };
    for (int i{ 0 }; userName[i] != '\0'; ++i)
    {
        ++stringLength;
    }

    //Validate characters
    bool invalidChar{ false };
    for (int i{ 0 }; i < stringLength; ++i)
    {
        if ((userName[i] > 90 || userName[i] < 65) || (userName[i] == 32))
        {
            invalidChar = true;
        }
    }

    //Lucky number evaluation condition
    if (invalidChar)
    {
        cout << "Invalid name";
    }
    else
    {
        int finalNumber{ 0 };

        for (int i1{ 0 }; i1 < stringLength; ++i1)
        {
            for (int i2{ 0 }; i2 < 25; ++i2)
            {
                if (userName[i1] == luckyNumberTable[0][i2])
                {

                    finalNumber += (luckyNumberTable[1][i2] - '0');

                }
                else
                {
                    //Do nothing
                }
            }
        }

        cout << "Your lucky number is:" << finalNumber;
    }

    return 0;
}
