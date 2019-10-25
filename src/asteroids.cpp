#include "asteroids.h"

// Draw the ship
void asteroids::update(renderer &renderer)
{
  // change in position and rotation
    xPos += xVelocity * elapsedTime * _accelerationFactor;
    yPos += yVelocity * elapsedTime * _accelerationFactor;
    angle += _rotFactor * elapsedTime;
    // wrap around
    wrapAround(renderer.getScreenWidth(), renderer.getScreenHeight());
}

void asteroids::draw(renderer &renderer)
{
    // Draw Asteroids
    SDL_SetRenderDrawColor(renderer.getRender(), 0, 0, 255, SDL_ALPHA_OPAQUE);
    renderer.renderObject(_modelAsteroidShape, xPos, yPos, angle, objectSize);  
}
