var TOTAL_AMOUNT = 13;
var COINS = [0, 7, 6, 3, 2];
var MATRIX = [
  [0,9,9,9,9,9,9,9,9,9,9,9,9,9], // dummy row
  [0,9,9,9,9,9,9,9,9,9,9,9,9,9],
  [0,9,9,9,9,9,9,9,9,9,9,9,9,9],
  [0,9,9,9,9,9,9,9,9,9,9,9,9,9],
  [0,9,9,9,9,9,9,9,9,9,9,9,9,9],
];

for (var row=1; row<COINS.length; row++) {
  for (var col=1; col<=TOTAL_AMOUNT; col++) {
    // if coin value is less than or equal to current amount
    if (COINS[row] <= col) {
      MATRIX[row][col] = Math.min(
          MATRIX[row-1][col],
          1 + MATRIX[row][col-COINS[row]]);
    } else {
      // can not use coin, use last number calculated
      MATRIX[row][col] = MATRIX[row-1][col];
    }
  }
}

console.log('min number of coins to make ' +
    TOTAL_AMOUNT + ' is: ' + MATRIX[COINS.length-1][TOTAL_AMOUNT]);
