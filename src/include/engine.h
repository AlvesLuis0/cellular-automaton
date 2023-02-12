#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;
int WIDTH;
int HEIGHT;
int IS_RUNNING;


void INTERFACE_Init(const char *title, int _WIDTH, int _HEIGHT);
void INTERFACE_ChooseColor(int red, int green, int blue, int alpha);
void INTERFACE_RenderPixel(int x, int y);
void INTERFACE_RenderRect(int x, int y, int _WIDTH, int _HEIGHT);
void INTERFACE_RenderFillRect(int x, int y, int _WIDTH, int _HEIGHT);
void INTERFACE_ClearWindow();
void INTERFACE_UpdateWindow();
void INTERFACE_Input();
void INTERFACE_SetTitle(const char *title);
void INTERFACE_Delay(int ms);
void INTERFACE_Quit();


#endif