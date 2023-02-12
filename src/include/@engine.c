#include <stdlib.h>
#include "engine.h"


void INTERFACE_Init(const char *title, int _WIDTH, int _HEIGHT) {

  SDL_Init(SDL_INIT_EVERYTHING);
  IS_RUNNING = 1;
  WIDTH = _WIDTH;
  HEIGHT = _HEIGHT;
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}


void INTERFACE_ChooseColor(int red, int green, int blue, int alpha) {

  SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
  
}


void INTERFACE_RenderPixel(int x, int y) {

  SDL_RenderDrawPoint(renderer, x, y);

}


void INTERFACE_RenderRect(int x, int y, int _WIDTH, int _HEIGHT) {

  SDL_Rect rect = { x, y, _HEIGHT, _WIDTH };
  SDL_RenderDrawRect(renderer, &rect);

}


void INTERFACE_RenderFillRect(int x, int y, int _WIDTH, int _HEIGHT) {

  SDL_Rect rect = { x, y, _HEIGHT, _WIDTH };
  SDL_RenderFillRect(renderer, &rect);

}


void INTERFACE_UpdateWindow() {

  SDL_RenderPresent(renderer);

}


void INTERFACE_ClearWindow() {

  SDL_RenderClear(renderer);

}


void INTERFACE_SetTitle(const char *title) {

  SDL_SetWindowTitle(window, title);

}


void INTERFACE_Delay(int ms) {

  SDL_Delay(ms);

}


void INTERFACE_Input() {

  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT:
        IS_RUNNING = 0;
    }
  }

}


void INTERFACE_Quit() {

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

}