#include "renderer.h"

void renderer::init(const std::size_t screenWidth,
                   const std::size_t screenHeight)
 {
  _screenWidth = screenWidth;
  _screenHeight = screenHeight;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  _sdlWindow = SDL_CreateWindow("Asteroids Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, _screenWidth,
                                _screenHeight, SDL_WINDOW_SHOWN);

  if (nullptr == _sdlWindow) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  _sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == _sdlRenderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

renderer::~renderer() {
  SDL_DestroyRenderer(_sdlRenderer);
  _sdlRenderer = nullptr;
  SDL_DestroyWindow(_sdlWindow);
  _sdlWindow = nullptr;
  SDL_Quit();
}

void renderer::updateScreen() {
  // Update Screen
  SDL_RenderPresent(_sdlRenderer);
}

void renderer::clearScreen() {
  // clear Screen
  SDL_SetRenderDrawColor(_sdlRenderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(_sdlRenderer);
}

void renderer::updateWindowTitle(std::string title) {
  SDL_SetWindowTitle(_sdlWindow, title.c_str());
}

const std::size_t renderer::getScreenWidth(){
  return _screenWidth;
}

const std::size_t renderer::getScreenHeight(){
  return _screenHeight;
}

SDL_Renderer *renderer::getRender(){
  return _sdlRenderer;
}

SDL_Window *renderer::getWindows(){
  return _sdlWindow;
}

// function does basic tranformation and renders the shape on to the screen
void renderer::renderObject(const std::vector<std::pair<float, float>> &modelCoordinates, float x, float y, float r = 0.0f, float s = 1.0f)
{
		
  // Create translated model vector of coordinate pairs
  std::vector<std::pair<float, float>> transformedCoordinates;
  int verts = modelCoordinates.size();
  transformedCoordinates.resize(verts);

  // Rotate
  for (int i = 0; i < verts; i++)
  {
    transformedCoordinates[i].first = modelCoordinates[i].first * cosf(r) - modelCoordinates[i].second * sinf(r);
    transformedCoordinates[i].second = modelCoordinates[i].first * sinf(r) + modelCoordinates[i].second * cosf(r);
  }

  // Scale
  for (int i = 0; i < verts; i++)
  {
    transformedCoordinates[i].first = transformedCoordinates[i].first * s;
    transformedCoordinates[i].second = transformedCoordinates[i].second * s;
  }

  // Translate
  for (int i = 0; i < verts; i++)
  {
    transformedCoordinates[i].first = transformedCoordinates[i].first + x;
    transformedCoordinates[i].second = transformedCoordinates[i].second + y;
  }

  // Draw Closed Polygon
  for (int i = 0; i < verts + 1; i++)
  {
    int j = (i + 1);
    SDL_RenderDrawLine(_sdlRenderer, transformedCoordinates[i % verts].first, transformedCoordinates[i % verts].second, 
                       transformedCoordinates[j % verts].first, transformedCoordinates[j % verts].second);
  } 
}