#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <complex>
#include <algorithm>
#include <iomanip>
#include <complex>
#include <initializer_list>
using namespace std;
template <typename T>
T extraction(int degree) {
    const long double argument = 2*M_PI/degree;
    T unit (cos(argument), sin(argument));
    if(abs(unit.real()) < pow(10, -5)){
        unit.real(0);
    }
    if(abs(unit.imag()) < pow(10, -5)){
        unit.imag(0);
    }
    return unit;
};
template <typename T>
vector<T> AddPadding(const std::vector<T>& data, size_t expected_length){
    if(expected_length < data.size()){
        throw runtime_error("Expexted length is too small!");
        return data;
    }
    vector<T> data_edited = data;
    data_edited.resize(expected_length, 0);
    return data_edited;
};
template <typename T>
vector<T> Fastfunction_1(const std::vector<T>& data){
    std::vector<T> data_edited = data;
    int size = data_edited.size();
    if (size == 1)  return data_edited;
    vector<T> data_0(size/2),  data_1(size/2);
    for (int i=0, j=0; i < size; i+=2, j++) {
        data_0[j] = data_edited[i];
        data_1[j] = data_edited[i+1];
    }
    data_0 = Fastfunction_1(data_0);
    data_1 = Fastfunction_1(data_1);
    T root(1);
    T unit = extraction<T>(size);
    cout << "size = " << size << endl;
    for(auto e: data_0){
        cout << e;
    };
    cout << endl;
    for(auto e: data_1){
        cout << e;
    };
    cout << endl;
    for(int i = 0; i < (size/2); i++){
        data_edited[i] = data_0[i] + root*data_1[i];
        if(abs(data_edited[i].real()) < 1e-5){
            data_edited[i].real(0);
        }
        if(abs(data_edited[i].imag()) < 1e-5){
            data_edited[i].imag(0);
        }
        cout << "[i] = " << i << ": " << data_0[i] << " + " << root << "*" << data_1[i] << "="<< data_edited[i] << endl;
        data_edited[i + (size/2)] = data_0[i] - root*data_1[i];
        if(abs(data_edited[i + (size/2)].real()) < 1e-5){
            data_edited[i + (size/2)].real(0);
        }
        if(abs(data_edited[i + (size/2)].imag()) < 1e-5){
            data_edited[i + (size/2)].imag(0);
        }
        root *= unit;
        cout << "[i + (size/2)] = " << i + (size/2) << ": " << data_0[i] << " - " << root << "*" << data_1[i] << "="<< data_edited[i + (size/2)] << endl;
        
    }
    return data_edited;
};
template <typename T>
vector<T> Fastvice_versa_function_1(const std::vector<T>& data){
    std::vector<T> data_edited = data;
    int size = data_edited.size();
    if (size == 1)  return data_edited;
    vector<T> data_0(size/2),  data_1(size/2);
    for (int i=0, j=0; i < size; i+=2, j++) {
        data_0[j] = data_edited[i];
        data_1[j] = data_edited[i+1];
    }
    data_0 = Fastvice_versa_function_1(data_0);
    data_1 = Fastvice_versa_function_1(data_1);
    T root(1);
    T unit = extraction<T>(-size);
    cout << "size = " << size << endl;
    for(auto e: data_0){
        cout << e;
    };
    cout << endl;
    for(auto e: data_1){
        cout << e;
    };
    cout << endl;
    for(int i = 0; i < (size/2); i++){
        data_edited[i] = data_0[i] + root*data_1[i];
        data_edited[i] /= 2;
        if(abs(data_edited[i].real()) < 1e-5){
            data_edited[i].real(0);
        }
        if(abs(data_edited[i].imag()) < 1e-5){
            data_edited[i].imag(0);
        }
        cout << "[i] = " << i << ": " << data_0[i] << " + " << root << "*" << data_1[i] << "=2*"<< data_edited[i] << endl;
        data_edited[i + (size/2)] = data_0[i] - root*data_1[i];       
        data_edited[i + (size/2)] /= 2;
        if(abs(data_edited[i + (size/2)].real()) < 1e-5){
            data_edited[i + (size/2)].real(0);
        }
        if(abs(data_edited[i + (size/2)].imag()) < 1e-5){
            data_edited[i + (size/2)].imag(0);
        }
        cout << "[i + (size/2)] = " << i + (size/2) << ": " << data_0[i] << " - " << root << "*" << data_1[i] << "=2*"<< data_edited[i + (size/2)] << endl;
        root *= unit;
    }
    
    return data_edited;
};
template <typename T>
vector<T> function_1(const std::vector<T>& data){
    int data_size = data.size(), power = 1;
    while(power < data_size){
        power *=2;
    };
    vector<T> data_edited = AddPadding(data, power);
    cout << "FFT:";
    for(auto e: data_edited){
        cout << e;
    };
    cout << endl;
    vector<T> transformed_by_Furie_data = Fastfunction_1(data_edited);
    return transformed_by_Furie_data;
};
template <typename T>
vector<T> vice_versa_function_1(const std::vector<T>& data){
    vector<T> transformed_by_Furie_data = data;
    int data_size = transformed_by_Furie_data.size(), power = 1;
    while(power < data_size){
        power *=2;
    };
    vector<T> data_edited = AddPadding(transformed_by_Furie_data, power);    
    cout << "FIFT:";
    for(auto e: data_edited){
        cout << e;
    };
    cout << endl;
    vector<T> normal_data = Fastvice_versa_function_1(data_edited);
    return normal_data;
};
int main(void) {
    vector<complex<double>> data_1{1, 2, 0, 3};
    vector<complex<double>> data_edited_1= function_1(data_1);
    for(auto e: data_edited_1){
        cout << e;
    };
    cout << endl;
    vector<complex<double>> data_2{1, 1, 1, 1};
    vector<complex<double>> data_edited_2= function_1(data_2);
    for(auto e: data_edited_2){
        cout << e;
    };
    cout << endl;
    int vector_size = max(data_edited_1.size(), data_edited_1.size());
    cout << vector_size << endl;
    vector<complex<double>> data_edited(vector_size);
    for (int i = 0; i < vector_size; i++) {
        data_edited[i] = data_edited_1[i] * data_edited_2[i];
    }
    vector<complex<double>> data = vice_versa_function_1(data_edited);
    for(const auto& e: data) {
        cout << e;
    }
    cout << endl;
}