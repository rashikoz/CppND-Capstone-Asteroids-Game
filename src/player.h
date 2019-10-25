#pragma once

#include <iostream>
#include <vector>
#include "renderer.h"
#include "gameObject.h"

class player:public gameObject {
  public:
    // Reset the ship to its default settings
    void reset(std::size_t screenWidth, std::size_t screenHeight);
    // Rotate the ship (user interaction)
    void rotate(int);
    void draw(renderer &renderer);
    void accelerate(std::size_t screenWidth, std::size_t screenHeight);
  private:
    // A simple Isoceles Triangle;
    std::vector<std::pair<float, float>> _modelPlayerShape =  {{ 0.0f, -5.0f},
			                                                        {-2.5f, +2.5f},
			                                                        {+2.5f, +2.5f}};
    float _rotFactor=30.0f;
    float _accelerationFactor=100000.0f;
};

class bullet:public gameObject{
  public:
    void update();
    void draw(renderer &renderer);
  private:
    float _rotFactor=5.0f;
    float _accelerationFactor=500.0f;
};

