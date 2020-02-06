#include <iostream>
#include <vector>

int main(void) {
    int arraySize, M, number;
    std::vector<int> array, temp;
    std::cout << "Введите M и размер массива" << std::endl;
    std::cin >> M >> arraySize;
    std::cout << "Введите массив" << std::endl;
    for(int i = 0; i < arraySize; i++){
        std::cin >> number;
        array.push_back(number);
    }
    for(int i = 0; i < M; i++){
        temp.push_back(i);
    }
    /*for (auto i: array){
        std::cout << i;
    }
    for (auto i: temp){
        std::cout << i;
    }*/
    for(auto i: array){
        temp[i] = -1; 
    }
    for(int i = 0; i < M; i++){
        if(temp[i] != -1){
            std::cout << temp[i] << " ";
        } 
    }
    std::cout << std::endl;
}