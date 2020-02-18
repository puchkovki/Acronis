#include <iostream>
#include <string>
#include <cctype>

// The number is divisible by 3, if the numerals' sum is divisible by 3
bool divisible_by_three(std::string number) {
    int numeral = 0;
    
    if(number[0] == '-') {
        number.erase(0, 1);
    }

    // Iterative summation of numbers' numerals
    while(number.length() > 1) {
        numeral = 0;
        for(auto i: number) {
            numeral += i - '0';
        }
        number = std::to_string(numeral);
    }
    

    switch(number[0]) {
        case '0':
            return true;
        case '3':
            return true;
        case '6':
            return true;
        case '9':
            return true;
    }

    return false;
}

int main(void) {

    // Reading and checking number for divisibility
    std::string number;
    while(std::cin >> number) {
        std::string fizzbuzz = "fizzbuzz";
        bool error = false;

        // Checking the incoming number is it number or not
        for(auto i: number) {
            if(number[0] == '-') {
                continue;
            }
            if(!isdigit(i)) {
                std::cout << "Tne input is not a number. Please write only numbers!" << std::endl;
                error = true;
                break;
            };
        }

        // If the input is not the number, read next string
        if(error) {
            std::cout << number << " ";
            continue;
        } else {
            // The number is divisible by 5, if the last numeral is '0' or '5'
            if((number[number.length() - 1] != '0') && (number[number.length() - 1] != '5')) {
                fizzbuzz.erase(4);
            }

            if(!divisible_by_three(number)) {
                fizzbuzz.erase(0, 4);
            }

            // Not changing the number if it's not divisible by '3' and '5'
            // Printing the answer
            if(fizzbuzz.length() != 0) {
                std::cout << fizzbuzz << " ";
            } else {
                std::cout << number << " ";
                continue;
            }
        }    
    } 
    
    std::cout << std::endl;
}