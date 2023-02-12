#include <stdio.h>
#include "engine.h"
#include "cell.h"
#include "grid.h"


void CELL_Render(int x, int y) {

  INTERFACE_RenderFillRect(x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE);

}


int CELL_Neighbors(Grid *grid, int x, int y) {

  int numberOfNeighbors = 0;

  for(int i = x - 1; i <= x + 1; i++)
    for(int j = y - 1; j <= y + 1; j++)
      if(
          !(i == x && j == y) &&
          i >= 0 && i < grid->HEIGHT &&
          j >= 0 && j < grid->WIDTH
        )
        numberOfNeighbors += grid->$[i][j];

  return numberOfNeighbors;

}


void CELL_Update(Grid *grid, Grid *tmpGrid, int x, int y) {

  int numberOfNeighbors = CELL_Neighbors(grid, x, y);

  if(grid->$[x][y])
    tmpGrid->$[x][y] = numberOfNeighbors == 2 || numberOfNeighbors == 3;

  else
    tmpGrid->$[x][y] = numberOfNeighbors == 3;

}