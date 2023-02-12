#ifndef GRID_H
#define GRID_H


#define PIXEL_SIZE 4


typedef struct Grid {

  int **$;
  int HEIGHT;
  int WIDTH;

} Grid;


Grid* GRID_New(int _HEIGHT, int _WIDTH);
void GRID_Free(Grid*);
void GRID_Generate(Grid*);
void GRID_Render(Grid*);
void GRID_Clone(Grid* grid, Grid* tmpGrid);
void GRID_Update(Grid* grid, Grid* tmpGrid);


#endif