#ifndef CELL_H
#define CELL_H


#include "grid.h"

void CELL_Render(int x, int y);
int CELL_Neighbors(Grid*, int x, int y);
void CELL_Update(Grid *grid, Grid *tmpGrid, int x, int y);


#endif