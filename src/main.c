#include <stdlib.h>
#include "include/engine.h"
#include "include/grid.h"


int main(int argc, char *argv[]) {
  
  INTERFACE_Init("Cellular Automaton", 900, 800);

  Grid *grid = GRID_New(WIDTH/PIXEL_SIZE, HEIGHT/PIXEL_SIZE);
  Grid *tmpGrid = GRID_New(WIDTH/PIXEL_SIZE, HEIGHT/PIXEL_SIZE);

  GRID_Generate(grid);
  GRID_Render(grid);
  INTERFACE_UpdateWindow();

  while(IS_RUNNING) {
    INTERFACE_Delay(50);
    INTERFACE_Input();
    GRID_Update(grid, tmpGrid);
    GRID_Render(grid);
    INTERFACE_UpdateWindow();
  }

  INTERFACE_Quit();
  GRID_Free(grid);
  GRID_Free(tmpGrid);

  return 0;

}