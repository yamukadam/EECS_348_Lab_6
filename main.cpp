#include <iostream>
#include <fstream>

#define file_name "matrix_input.txt"

static const int max_size = 100;
void read_file(int matrixA[max_size][max_size],int matrixB[max_size][max_size],int &size);
void print_matrix(int matrix[max_size][max_size], int &size);
void add_matrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int &size);
void multiply_matrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int &size);
void matrix_difference(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int &size);

int main(){
    int size;
    int matrixA[max_size][max_size];
    int matrixB[max_size][max_size];
    read_file(matrixA, matrixB, size);
    std::cout<< "Yaeesh Mukadam \n";
    std::cout<< "Lab #6: Matrix Manipulation \n\n";
    std::cout<< "Matrix A: \n";
    print_matrix(matrixA, size);
    std::cout<< "Matrix B: \n";
    print_matrix(matrixB, size);
    std::cout << "Matrix Sum (A+B): \n";
    add_matrices(matrixA, matrixB, size);
    std::cout<< "Matrix Product (A*B): \n";
    multiply_matrices(matrixA, matrixB, size);
    std::cout << "Matrix Difference (A-B): \n";
    matrix_difference(matrixA, matrixB, size);


    return 0;
}


void read_file(int matrixA[max_size][max_size],int matrixB[max_size][max_size],int &size){
    std::ifstream file(file_name);
    char text;
    std:: string extra_text;
    file >> size;
    getline(file, extra_text);
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            file >> matrixA[i][j];
        }
    }
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            file >> matrixB[i][j];
        }
    }
    file.close();
}

void print_matrix(int matrix[max_size][max_size], int &size){
    for (int i=0; i<size; i++ ){
        for (int j=0; j<size; j++){
            std::cout<< matrix[i][j] << " ";
        }
        std::cout<< std::endl;
    }
    std::cout<< std::endl;
}

void add_matrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int &size){
    int matrixResult[max_size][max_size];
    for (int i =0; i<size; i++){
        for (int j=0; j<size; j++){
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    print_matrix(matrixResult, size);
}

void multiply_matrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int &size){
    int matrixResult[max_size][max_size] = {0};
    for (int i =0; i<size; i++){
        for (int j=0; j<size; j++){
            for (int k = 0; k<size; k++){
                matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    print_matrix(matrixResult, size);
}

void matrix_difference(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int &size){
    int matrixResult[max_size][max_size];
    for (int i =0; i<size; i++){
        for (int j=0; j<size; j++){
            matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    print_matrix(matrixResult, size);
}
