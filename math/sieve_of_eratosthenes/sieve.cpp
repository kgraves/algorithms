using namespace std;
#include <iostream>


void initArray(int *array, int length) {
  for (int i=0; i<=length; i++) {
    array[i] = 1;
  }
}

void printArray(int *array, int length) {
  for (int i=1; i<=length; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;
}

void sieve(int *array, int length) {
  array[1] = 1;

  int upper = length / 2;
  for (int i=2; i<upper; i++) {
    for (int j=2; j<upper && (i*j) <= length; j++) {
      array[i*j] = 0;
    }
  }
}

bool isPrime(int *array, int number) {
  return array[number] == 1;
}

int main() {
  int length = 100;
  int *array = new int[length + 1];

  initArray(array, length);
  printArray(array, length);
  sieve(array, length);
  printArray(array, length);

  cout << "5 is prime? " << isPrime(array, 5) << endl;
  cout << "13 is prime? " << isPrime(array, 13) << endl;
  cout << "20 is prime? " << isPrime(array, 20) << endl;
  cout << "97 is prime? " << isPrime(array, 97) << endl;

  delete[] array;
  return 0;
};
