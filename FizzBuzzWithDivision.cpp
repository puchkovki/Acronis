#include <iostream>
#include <string>

// The number is divisible by 3, if the numerals' sum is divisible by 3
bool divisible_by_three(std::string number) {
    long long int numeral = 0;
    
    if(number[0] == '-') {
        number.erase(0, 1);
    }

    // Iterative summation of numbers' numerals
    numeral = 0;
    for(auto i: number) {
        numeral += i - '0';
    }
    if(numeral % 3 == 0) {
        return true;
    }

    return false;
}

int main(void) {
    // Reading and checking number for divisibility
    std::string number;
    while(std::cin >> number) {
        std::string fizzbuzz = "fizzbuzz";
        
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
        }
    } 
    
    std::cout << std::endl;
}