/*
Find number
author: Puchkov Kyryll
date: 22.02.2020

1. You have sequence from 0 to M: [0;M).
2. Input — unordered array of integer numbers of size M-n.
3. Output — array of missing numbers in input array.
Example:
M = 5, arraySize = 3, array = {4, 1, 3}
Output = {0, 2}
*/

#include <iostream>
#include <vector>

// Filling the auxiliary array
void auxiliary_vector(std::vector<int> &domain, size_t &M) {
    for(size_t i = 0; i < M; i++) {
        domain.push_back(i);
    }
}

// Marking numbers from the "input" array
bool marking_vector(std::vector<int> &array, std::vector<int> &domain) {
    size_t size = domain.size();
    for(auto i: array) {
        if(i >= size) {
            std::cerr << i << " is invalid number in input array!\n";
            return EXIT_FAILURE;
        }
        domain[i] = -1; 
    }
    return 0;
}

bool check_the_sizes(size_t &M, size_t& array_size) {
    if(M < array_size) {
        std::cerr << "Invalid sizes!\n";
        return EXIT_FAILURE;
    }
    return 0;
}

int main(void) {
    // "Input" array and it's size
    std::vector<int> array;
    size_t array_size;

    // Auxiliary array and it's size
    std::vector<int> domain;
    size_t M;

    std::cout << "Введите M и размер массива" << std::endl;
    std::cin >> M >> array_size;

    if(check_the_sizes(M, array_size) == 1) {
        return EXIT_FAILURE;
    }

    // Auxiliary variable for reading
    size_t number;
    std::cout << "Введите массив" << std::endl;
    for(size_t i = 0; i < array_size; i++) {
        std::cin >> number;
        if(std::cin.fail()) {
            // Get cin in the normal operation mode
            std::cin.clear();
            // Clear the input buffer
            std::cin.ignore(32767,'\n'); 
            std::cerr << "Invalid input!\n";
            return EXIT_FAILURE;
        }
        array.push_back(number);
    }

    auxiliary_vector(domain, M);
    if(marking_vector(array, domain) == 1) {
        return EXIT_FAILURE;
    }

    // Unmarked elements are reqiered
    for(size_t i = 0; i < M; i++) {
        if(domain[i] != -1) {
            std::cout << domain[i] << " ";
        } 
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}