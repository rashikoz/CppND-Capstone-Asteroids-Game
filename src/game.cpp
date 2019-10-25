#include "game.h"

game::game(const std::size_t screenWidth, const std::size_t screenHeight, const std::size_t targetFrameDuration):
  _isRunning(false),
  _targetFrameDuration(targetFrameDuration){
  _renderer.init(screenWidth, screenHeight);
  }
// get the final score 
int game::getScore(){return _score;}
// handle the inputs from keyboard
void game::handleInput(){
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      _isRunning = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          // accelerate
          _player.accelerate(_renderer.getScreenWidth(),
                             _renderer.getScreenHeight());
          break;
        case SDLK_LEFT:
          _player.rotate(-1);
          break;
        case SDLK_RIGHT:
          _player.rotate(1);
          break;
        case SDLK_SPACE:
          bullet b1;
          b1.setParams(_player.getxPos(), _player.getyPos(), 50.0f * sinf(_player.getAngle()),
                      -50.0f * cosf(_player.getAngle()), 100.0f, 1.0);
          _bulletsVector.emplace_back(b1);
          break;
        
      }
    }
  }
}
// reset the game
void game::reset(void){
    _score=0;
    _maxAsteroids = 10;
   _numberOfAsteroids = 0;
    _renderer.clearScreen();
    _player.reset(_renderer.getScreenWidth(),
                  _renderer.getScreenHeight());
    _asteroidsVector.clear();
    _bulletsVector.clear();
    // add 4 asteroids
    asteroids as1, as2;
    as1.setParams(30.0f, 20.0f, 5.0f, 5.0f, 0.0f, 5.0);
    as2.setParams(500.0f, 500.0f, 3.0f, -3.0f, 0.0f, 5.0f);
    _asteroidsVector.emplace_back(as1);
    _asteroidsVector.emplace_back(as2);
    _numberOfAsteroids += 2;
}
// collision function
bool game::isBulletAsteroidCollide(asteroids &as, bullet &bl){
    //even though the asteroid is slanted we assume with out angle and
    // check for collision
    SDL_Rect bulletRect, asteroidRect;
    bulletRect.x = bl.getxPos();
    bulletRect.y = bl.getyPos();
    bulletRect.w = 3;
    bulletRect.h = 3;
    asteroidRect.x = as.getxPos();
    asteroidRect.y = as.getyPos();
    asteroidRect.w = as.getObjectSize()*10;
    asteroidRect.h = as.getObjectSize()*10;
    return SDL_HasIntersection(&asteroidRect, &bulletRect);
}
// the game loop
void game::run() {
  Uint32 titleTimestamp = SDL_GetTicks();
  Uint32 frameStart;
  Uint32 frameEnd;
  Uint32 frameDuration=0;
  int frameCount = 0;
  std::string title;
  _isRunning = true;
  asteroids newAsteroid;

  while (_isRunning) {
      frameStart = SDL_GetTicks();
      // Input, Update, Render - the main game loop.
      handleInput();
      _renderer.clearScreen();
      // update the player elapsed time
      _player.setElapsedTime(frameDuration/1000.0f);
      // update asteroids
      for (auto &theAsteroid : _asteroidsVector)
      {
          theAsteroid.setElapsedTime(frameDuration/1000.0f);
          theAsteroid.update(_renderer);
      }
      // bullet and asteroid collision
      for (auto &theBullet : _bulletsVector)
      {
          theBullet.setElapsedTime(frameDuration/1000.0f);
          theBullet.update();
          for (auto &theAsteroid : _asteroidsVector)
          {
              if (isBulletAsteroidCollide(theAsteroid, theBullet))
              {
                  theBullet.throwOutsideScreen();
                  theAsteroid.throwOutsideScreen();
                  _score += 100;
                  // generate new asteroid
                  if (_numberOfAsteroids < _maxAsteroids)
                  {
                      // create new asteroid  make sure it is not on the player 
                      newAsteroid.setParams(200.0f * sinf(_player.getAngle() - 3.14159f/2.0f) + _player.getxPos(),
                                            200.0f * cosf(_player.getAngle() - 3.14159f/2.0f) + _player.getyPos(),
                                            5.0f, 5.0f, 0.0f, 3.0);
                      _asteroidsVector.emplace_back(newAsteroid);
                      _numberOfAsteroids += 1;
                  }
              }
          }
      }
      
      // if asteroid vetor is empty
      // game finished
      if(_asteroidsVector.empty())
      {
          _score += 1000;
          title = "Asteriod Game Finished !!!!!  Score: " + std::to_string(_score);
          _renderer.updateWindowTitle(title);
          _isRunning = false;  
      }
       // check and remove the crashed asteroids      		
      if (_asteroidsVector.size() > 0)
      {
          for(auto it = _asteroidsVector.begin(); it != _asteroidsVector.end();)
          {
            if ((*it).getxPos() < 0)
            {
                it = _asteroidsVector.erase(it); 
            }
            else
            {
                ++it;
            }
        }
      }
		
      // check and remove the bullets
      if (_bulletsVector.size() > 0)
      {
          for(auto it = _bulletsVector.begin(); it != _bulletsVector.end();)
          {
            if ((*it).getxPos() < 0)
            {
                it = _bulletsVector.erase(it); 
            }
            else
            {
                ++it;
            }
          }
      }

    //draw asteroids
      for (auto &theAsteroid : _asteroidsVector)
         theAsteroid.draw(_renderer);
		// Draw Bullets
      for (auto &theBullet : _bulletsVector)
          theBullet.draw(_renderer);
      // draw the player
      _player.draw(_renderer);
      // update screen
      _renderer.updateScreen();
      frameEnd = SDL_GetTicks();

      // Keep track of how long each loop through the input/update/render cycle
      // takes.
      frameCount++;
      frameDuration = frameEnd - frameStart;

      // After every second, update the window title.
      if (frameEnd - titleTimestamp >= 1000) {
        title = "Asteriod Score: " + std::to_string(_score);
        _renderer.updateWindowTitle(title);
        frameCount = 0;
        titleTimestamp = frameEnd;
      }

      // If the time for this frame is too small (i.e. frame_duration is
      // smaller than the target ms_per_frame), delay the loop to
      // achieve the correct frame rate.
      if (frameDuration < _targetFrameDuration) {
        SDL_Delay(_targetFrameDuration - frameDuration);
      }
  }
}





