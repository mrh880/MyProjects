// ReadingInputs.cpp
#include "ReadingInputs.h"

#include "../PrintingOutputsLibrary/PrintingOutputs.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

namespace ReadText
{
    string ReadTextOnScreen(const string &Text)
    {
        if (!Text.empty())
            cout << Text;
        string UserInput = "";
        getline(cin, UserInput);
        return UserInput;
    }

    char ReadCharacter(const string &Text)
    {
        if (!Text.empty())
            cout << Text;
        char Character = ' ';
        cin >> Character;
        return Character;
    }

}

namespace ReadNumbers
{
    short ReadingShortNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        short Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }

    int ReadingIntegerNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        int Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }

    float ReadFloatingPointNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        float Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        PrintingText::PrintLines();
        return Number;
    }

    double ReadingDoubleNumber(const string &Message)
    {
        if (!Message.empty())
            cout << Message;
        double Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }

    double ReadingDoubleNumber(short NumberOfCharacters, const std::string &Message)
    {
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();
        double Number = ReadingIntegerNumber(Message);
        PrintingText::PrintSequenceOfCharacters('*', NumberOfCharacters);
        PrintingText::PrintLines();

        return Number;
    }

    long double ReadingLongDoubleNumber(const std::string &Message)
    {
          if (!Message.empty())
            cout << Message;
        long double Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintingText::PrintTextOnScreen("Invalid number, enter a valid number: ");
            cin >> Number;
        }
        return Number;
    }
}

