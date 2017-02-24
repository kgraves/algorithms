using namespace std;
#include <iostream>

/**
 * Implemenets the bubble sort on the given array.
 *
 * Runtime Complexity: O(n**2)
 * Space Complexity: O(1)
 *
 * @param array An array of integers to sort
 * @param length Length of the given array
 * @return {Array}
 */
// int* bubbleSort(int &array[], int length) {
int* bubbleSort(int* array, int length) {
  for (int _=0; _ < length-1; _++) {
    for (int index=0; index < length-1; index++) {
      if (array[index] > array[index + 1]) {
        int temp = array[index + 1];
        array[index + 1] = array[index];
        array[index] = temp;
      }
    }
  }
};

void printArray(int array[], int length) {
  for (int index=0; index < length; index++) {
    cout << array[index] << " ";
  }

  cout << endl;
};

int main() {
  int array[] = {1,2,3,4,5,6,7,8,9};
  bubbleSort(array, 9);
  printArray(array, 9);
  
  int array2[] = {9,8,7,6,5,4,3,2,1};
  bubbleSort(array2, 9);
  printArray(array2, 9);
  
  int array3[] = {9,1,8,2,7,3,6,4,5};
  bubbleSort(array3, 9);
  printArray(array3, 9);
  
  return 0;
};
