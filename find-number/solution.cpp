#include <iostream>
#include <vector>

// Filling the auxiliary array
void auxiliary_vector(std::vector<int> &domain, int &M) {
    for(int i = 0; i < M; i++) {
        domain.push_back(i);
    }
}

// Marking numbers from the "input" array
void marking_vector(std::vector<int> &array, std::vector<int> &domain) {
    int size = domain.size();
    for(auto i: array) {
        if(i > size) {
            std::cerr << i << " — invalid number in input array!\n";
            exit(1);
        }
        domain[i] = -1; 
    }
}

void check_the_sizes(int &M, int& array_size) {
    if(M < array_size) {
        std::cerr << "Invalid sizes!\n";
        exit(1);
    }
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

    check_the_sizes(M, array_size);

    // Auxiliary variable for reading
    int number;
    std::cout << "Введите массив" << std::endl;
    for(int i = 0; i < array_size; i++) {
        std::cin >> number;
        array.push_back(number);
    }

    auxiliary_vector(domain, M);
    marking_vector(array, domain);

    // Unmarked elements are reqiered
    for(int i = 0; i < M; i++) {
        if(domain[i] != -1) {
            std::cout << domain[i] << " ";
        } 
    }
    std::cout << std::endl;
}