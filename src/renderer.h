#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "SDL.h"

class renderer {
 public:
  ~renderer();
  void init(const std::size_t screenWidth, const std::size_t screenHeight);
  SDL_Renderer *getRender();
  SDL_Window *getWindows();
  const std::size_t getScreenWidth();
  const std::size_t getScreenHeight();
  void updateWindowTitle(std::string title);
  void updateScreen(void);
  void clearScreen(void);
  void renderObject(const std::vector<std::pair<float, float>> &modelCoordinates, float x, float y, float r, float s);

 private:
  SDL_Window *_sdlWindow;
  SDL_Renderer *_sdlRenderer;
  std::size_t _screenWidth=640;
  std::size_t _screenHeight=640;
};

