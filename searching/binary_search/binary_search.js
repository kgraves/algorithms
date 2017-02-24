/**
 * Implements a binary search on a sorted array with the given key
 *
 * Runtime Complexity: O(Log n)
 * Space Complexity: O(1)
 *
 * @param {Array} array
 * @param {Number} key
 * @return {Array}
 */
var binarySearch = function(array, key) {
  var hi = array.length - 1;
  var lo = 0;

  while (hi >= lo) {
    var mid = lo + Math.floor((hi - lo) / 2);

    console.log('lo: ' + lo + '; mid: ' + mid + '; hi: ' + hi);

    if (array[mid] === key) {
      return true;
    } else if (array[mid] > key) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  // we didn't find the given `key`, return false.
  return false;
};

var result = binarySearch([1,2,3,4,5,6,7,8,9], 2);
console.log('2 in array? ' + result);

var result = binarySearch([1,2,3,4,5,6,7,8,9], 4);
console.log('4 in array? ' + result);

var result = binarySearch([1,2,3,4,5,6,7,8,9], 9);
console.log('9 in array? ' + result);

var result = binarySearch([1,2,3,4,5,6,7,8,9], 10);
console.log('10 in array? ' + result);

var result = binarySearch([1,2,3,4,5,6,7,8,9], 0);
console.log('0 in array? ' + result);

