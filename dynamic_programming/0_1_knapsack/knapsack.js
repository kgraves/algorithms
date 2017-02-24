var TOTAL_CAPACITY = 7;

var ITEMS = [
  {}, // dummy item
  { w: 1, v: 1 },
  { w: 3, v: 4 },
  { w: 4, v: 5 },
  { w: 5, v: 7 },
];

var MATRIX = [
  [0,0,0,0,0,0,0,0], // dummy row
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0],
];

for (var row=1; row<ITEMS.length; row++) {
  for (var col=1; col<=TOTAL_CAPACITY; col++) {
    // sub-problem pack has enough capacity for current item?
    if (ITEMS[row].w <= col) {
      MATRIX[row][col] = Math.max(
          ITEMS[row].v + MATRIX[row-1][col-ITEMS[row].w],
          MATRIX[row-1][col]);
    } else {
      // not enough capacity, so either use the last item or 0 if first row
      MATRIX[row][col] = MATRIX[row-1][col];
    }
  }
}

console.log(MATRIX[ITEMS.length-1][TOTAL_CAPACITY]);
