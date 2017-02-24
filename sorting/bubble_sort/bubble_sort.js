/**
 * Implemenets the bubble sort on the given array, and returns a sorted array.
 *
 * Runtime Complexity: O(n**2)
 * Space Complexity: O(1)
 *
 * @param {Array} array
 * @return {Array}
 */
var bubbleSort = function(array) {
  array.forEach(function(_) {
    array.forEach(function(item, index) {
      if (index + 1 < array.length && array[index] > array[index + 1]) {
        var temp = array[index + 1];
        array[index + 1] = array[index];
        array[index] = temp;
      }
    });
  });

  return array;
};

var result = bubbleSort([1,2,3,4,5,6,7,8,9]);
console.log(result);

var result = bubbleSort([9,1,8,2,7,3,6,4,5]);
console.log(result);

var result = bubbleSort([1,2,3,4,5,6,7,8,9]);
console.log(result);
