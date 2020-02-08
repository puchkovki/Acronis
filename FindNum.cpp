#include <iostream>
#include <vector>

int main(void) {
    // "Input" array and it's size
    std::vector<int> array;
    int array_size;
    // Auxiliary array and it's size
    std::vector<int> domain;
    int M;

    std::cout << "Введите M и размер массива" << std::endl;
    std::cin >> M >> array_size;

    // Auxiliary variable for reading
    int number;
    std::cout << "Введите массив" << std::endl;
    // Filling the "input" array
    for(int i = 0; i < array_size; i++) {
        std::cin >> number;
        array.push_back(number);
    }
    // Filling the auxiliary array
    for(int i = 0; i < M; i++) {
        domain.push_back(i);
    }

    // Marking the auxiliary array's matches with the "input" one 
    for(auto i: array) {
        domain[i] = -1; 
    }

    // All unmarked elements are the missing ones
    for(int i = 0; i < M; i++) {
        if(domain[i] != -1) {
            std::cout << domain[i] << " ";
        } 
    }
    std::cout << std::endl;
}