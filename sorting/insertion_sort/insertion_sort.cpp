using namespace std;
#include <iostream>

/**
 * Implements the insertion sort algorithm
 *
 * Runtime Complexity: O(N^2)
 * Space Complexity: O(N)
 */
void insertionSort(int *array, int length) {
  for (int i=1; i<length; i++) {
    int j=i;

    while (j>0 && array[j-1] > array[j]) {
      int temp = array[j-1];
      array[j-1] = array[j];
      array[j] = temp;

      j -= 1;
    }
  }
}

void printArray(int *array, int length) {
  for (int i=0; i<length; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;
}

int main() {
  int array1[7] = {1,2,3,4,5,6,7};
  insertionSort(array1, 7);
  printArray(array1, 7);

  int array2[7] = {7,6,5,4,3,2,1};
  insertionSort(array2, 7);
  printArray(array2, 7);

  int array3[7] = {7,1,6,2,5,3,4};
  insertionSort(array3, 7);
  printArray(array3, 7);

  return 0;
};
