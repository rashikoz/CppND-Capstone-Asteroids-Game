#pragma once

#include <iostream>
#include <vector>
#include "renderer.h"
#include "gameObject.h"

class asteroids:public gameObject {
  public:
    void update(renderer &renderer);
    void draw(renderer &renderer);
  private:
    // asteroid shape is a rectangle;
    std::vector<std::pair<float, float>> _modelAsteroidShape =  {{+5.0f, +5.0f},
			                                                           {-5.0f, +5.0f},
                                                                 {-5.0f, -5.0f},
                                                                 {5.0f, -5.0f}};
    float _rotFactor=5.0f;
    float _accelerationFactor=250.0f;
};