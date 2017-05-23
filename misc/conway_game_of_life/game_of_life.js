class Grid {

  constructor(size, seed) {
    // create 2d array to represent the game grid.
    this.size = size;
    this.grid = Array(size).fill().map(el => Array(size).fill(0));

    if (seed) {
      this.grid = this.grid.map((el, i) => seed[i]);
    }
  }

  tick() {
    // updated state of grid
    var newGrid = Array(this.size).fill().map(el => Array(this.size).fill(0));

    for (var r=0; r<this.size; r++) {
      for (var c=0; c<this.size; c++) {
        const neighborCount = this.countNeighbors(r, c, this.size);

        if (this.grid[r][c] === 1) {
          // Any live cell with two or three live neighbours lives on to the next generation.
          if (neighborCount === 2 || neighborCount === 3) newGrid[r][c] = 1;
        } else {
          // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
          if (neighborCount === 3) newGrid[r][c] = 1;
        }
      }
    }

    this.grid = newGrid;
  }

  countNeighbors(row, col, size) {
    var count = 0;

    for (var r=row-1; r<=row+1; r++) {
      for (var c=col-1; c<=col+1; c++) {
        if (r === row && c === col) continue;
        else if (r < 0 || c < 0) continue;
        else if (r >= size || c >= size) continue;
        else if (this.grid[r][c] === 1)  count++;
      }
    }

    return count;
  }

}

const l = console.log;
const seed = [
  [0,1,0,0,0],
  [0,0,1,0,0],
  [1,1,1,0,0],
  [0,0,0,0,0],
  [0,0,0,0,0],
];

// test a 'glider' pattern
// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Examples_of_patterns
var g = new Grid(5, seed);
l(g.grid);

g.tick();
l(g.grid);

g.tick();
l(g.grid);

g.tick();
l(g.grid);

g.tick();
l(g.grid);
