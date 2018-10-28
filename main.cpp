#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>
#include <algorithm> //funcion swap

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapify(int *array,size_t size,int i);//crear heapify para el heapsort
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    cout<<"Elementos del array:"<<endl;
    printArray(numbers, numberOfElements);
    cout<<endl;
    heapsort(numbers, numberOfElements);
    cout<<"Array ordenado:"<<endl;
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapify(int *array,size_t size,int i){
    int masLargo = i; //el mas largo es la raiz
    int izquierda = 2*i+1; 
    int derecha = 2*i+2;

    if (izquierda < size && array[izquierda] > array[masLargo]){ //si la izquierda es mas largo que la raiz
        masLargo = izquierda;
    }
    if (derecha < size && array[derecha] > array[masLargo]){ //si la derecha es mas largo que la raiz
        masLargo = derecha;
    }
    if (masLargo != i){ //si el mas largo no es la raiz
        swap(array[i],array[masLargo]);
        heapify(array,size,masLargo);
    }
}

void heapsort(int* array, size_t size) {
    for (int i = size/2 - 1; i >= 0; i--){
        heapify(array,size,i);//construccion del heap
    }
    for (int i = size-1; i >= 0; i--){
        swap(array[0],array[i]);//mover la raiz al final
        heapify(array,i,0);//heapify del heap reducido
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}