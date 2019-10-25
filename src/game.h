#pragma once

#include <iostream>
#include "renderer.h"
#include "player.h"
#include "asteroids.h"

class game {
 public:
    game(const std::size_t screenWidth, const std::size_t screenHeight, const std::size_t targetFrameDuration);
    void run(void);
    void reset(void);
    int getScore();
    
 private:
   bool _isRunning;
   std::size_t _targetFrameDuration;
   void handleInput(void);
   renderer _renderer;
   player _player;
   std::vector<asteroids> _asteroidsVector;
   std::vector<bullet> _bulletsVector;
   bool isBulletAsteroidCollide(asteroids &as, bullet &bl);
   int _score=0;
   int _maxAsteroids = 10;
   int _numberOfAsteroids = 0;

};
