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
void auxiliary_vector(std::vector<int> &domain, int &M) {
    for(int i = 0; i < M; i++) {
        domain.push_back(i);
    }
}

// Marking numbers from the "input" array
bool marking_vector(std::vector<int> &array, std::vector<int> &domain) {
    int size = domain.size();
    for(auto i: array) {
        if(i >= size) {
            std::cerr << i << " is invalid number in input array!\n";
            return 1;
        }
        domain[i] = -1; 
    }
    return 0;
}

bool check_the_sizes(int &M, int& array_size) {
    if(M < array_size) {
        std::cerr << "Invalid sizes!\n";
        return 1;
    }
    return 0;
}

int main(void) {
    // "Input" array and it's size
    std::vector<int> array;
    int array_size;

    // Auxiliary array and it's size
    std::vector<int> domain;
    int M;

    std::cout << "Введите M и размер массива" << std::endl;
    std::cin >> M >> array_size;

    if(check_the_sizes(M, array_size) == 1) {
        return 1;
    }

    // Auxiliary variable for reading
    int number;
    std::cout << "Введите массив" << std::endl;
    for(int i = 0; i < array_size; i++) {
        std::cin >> number;
        array.push_back(number);
    }

    auxiliary_vector(domain, M);
    if(marking_vector(array, domain) == 1) {
        return 1;
    }

    // Unmarked elements are reqiered
    for(int i = 0; i < M; i++) {
        if(domain[i] != -1) {
            std::cout << domain[i] << " ";
        } 
    }
    std::cout << std::endl;
}