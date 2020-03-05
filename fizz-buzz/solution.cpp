/*
Fizzbuzz
author: Puchkov Kyryll
date: 22.02.2020

1. Input - sequence of numbers.
2. If number is divizible by 3, replace it with fizz.
3. If number is divizible by 5, replace it with buzz.
4. If both, then fizzbuzz.
5. Output to the console.
Division operation and modulo operation are prohibited
*/

#include <iostream>
#include <string>

// Checking for the overflow
void overflow(std::string &number)
{
    try
    {
        std::stoll(number);
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        exit(1);
    }
}

// Checking the incoming string is it number or not
void is_it_number(std::string &number)
{
    for (auto i : number)
    {
        if (number[0] == '-')
        {
            continue;
        }

        if (!isdigit(i))
        {
            std::cerr << "Tne input is not a number!" << std::endl;
            exit(1);
        }
    }
}

// The number is divisible by 3, if the numerals' sum is divisible by 3
void divisible_by_3(std::string number, std::string &fizzbuzz)
{
    int numeral = 0;
    bool result = false;

    if (number[0] == '-')
    {
        number.erase(0, 1);
    }

    // Iterative summation of numbers' numerals
    while (number.length() > 1)
    {
        numeral = 0;
        for (auto i : number)
        {
            numeral += i - '0';
        }
        number = std::to_string(numeral);
    }

    switch (number[0])
    {
    case '0':
        result = true;
        break;
    case '3':
        result = true;
        break;
    case '6':
        result = true;
        break;
    case '9':
        result = true;
        break;
    }

    if (result == false)
    {
        fizzbuzz.erase(0, 4);
    }
}

// The number is divisible by 5, if the last numeral is '0' or '5'
void divisible_by_5(std::string &number, std::string &fizzbuzz)
{
    if ((number[number.length() - 1] != '0') && (number[number.length() - 1] != '5'))
    {
        fizzbuzz.erase(4);
    }
}

// Checking the string for the errors and divisibility
void check(std::string &number, std::string &fizzbuzz)
{
    is_it_number(number);
    overflow(number);

    divisible_by_5(number, fizzbuzz);
    divisible_by_3(number, fizzbuzz);
}

int main(void)
{
    std::string number;
    while (std::cin >> number)
    {
        std::string fizzbuzz = "fizzbuzz";

        check(number, fizzbuzz);

        if (fizzbuzz.length() != 0)
        {
            std::cout << fizzbuzz << " ";
        }
        else
        {
            // Not changing the number if it's not divisible by '3' and '5'
            std::cout << number << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}