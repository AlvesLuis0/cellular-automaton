#include <stdlib.h>
#include "engine.h"
#include <time.h>
#include "cell.h"
#include "grid.h"


Grid* GRID_New(int _HEIGHT, int _WIDTH) {

  Grid *grid = calloc(1, sizeof(Grid));
  grid->HEIGHT = _HEIGHT;
  grid->WIDTH = _WIDTH;
  grid->$ = (int**) calloc(_HEIGHT, sizeof(int*));

  for(int i = 0; i < _HEIGHT; i++)
    grid->$[i] = (int*) calloc(_WIDTH, sizeof(int));

  return grid;

}


void GRID_Free(Grid *grid) {

  for(int i = 0; i < grid->WIDTH; i++)
    free(grid->$[i]);

  free(grid->$);
  free(grid);

}


void GRID_Generate(Grid *grid) {

  srand(time(NULL));

  for(int i = 0; i < grid->HEIGHT; i++)
    for(int j = 0; j < grid->WIDTH; j++)
      grid->$[i][j] = rand() % 2;

}


void GRID_Render(Grid *grid) {

  INTERFACE_ChooseColor(0, 0, 0, 255);
  INTERFACE_ClearWindow();
  INTERFACE_ChooseColor(255, 255, 255, 255);

  for(int i = 0; i < grid->HEIGHT; i++)
    for(int j = 0; j < grid->WIDTH; j++)
      if(grid->$[i][j])
        CELL_Render(i, j);

}


void GRID_Clone(Grid *grid, Grid *tmpGrid) {

  for(int i = 0; i < grid->HEIGHT; i++)
    for(int j = 0; j < grid->WIDTH; j++)
      grid->$[i][j] = tmpGrid->$[i][j];

}


void GRID_Update(Grid *grid, Grid *tmpGrid) {

  for(int i = 0; i < grid->HEIGHT; i++)
    for(int j = 0; j < grid->WIDTH; j++)
      CELL_Update(grid, tmpGrid, i, j);

  GRID_Clone(grid, tmpGrid);

}