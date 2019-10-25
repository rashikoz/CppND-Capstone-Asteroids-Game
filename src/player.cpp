#include "player.h"


void player::reset(std::size_t screenWidth, std::size_t screenHeight)
{
	// Ship position
	xPos = screenWidth / 2;
	yPos = screenHeight / 2;
  
	// Ship orientation
	angle = 0;
	// Velocity
	xVelocity = yVelocity = 0;
	objectSize = 5.0;
}

// Rotate the ship
void player::rotate(int direction)
{
	angle += direction*_rotFactor*elapsedTime;
}

// Draw the ship
void player::draw(renderer &renderer)
{
	SDL_SetRenderDrawColor(renderer.getRender(), 255, 0, 0, SDL_ALPHA_OPAQUE);
  	renderer.renderObject(_modelPlayerShape, xPos, yPos, angle, objectSize);  
}

// accelerate
void player::accelerate(std::size_t screenWidth, std::size_t screenHeight)
{
  // accelerate in the direction of the angle
  	xVelocity += sin(angle)*_accelerationFactor*elapsedTime;
	yVelocity -= cos(angle)*_accelerationFactor*elapsedTime;
  	xPos += xVelocity*elapsedTime;
	yPos += yVelocity*elapsedTime;
	wrapAround(screenWidth, screenHeight);
}


// Draw the ship
void bullet::update()
{
  // change in position and rotation
    xPos += xVelocity * elapsedTime * _accelerationFactor;
    yPos += yVelocity * elapsedTime * _accelerationFactor;
    angle += _rotFactor * elapsedTime; 
}

void bullet::draw(renderer &renderer)
{
	SDL_Rect bulletRect;
    // Draw bullets
    SDL_SetRenderDrawColor(renderer.getRender(), 0, 255, 0, SDL_ALPHA_OPAQUE);
	bulletRect.x = xPos;
	bulletRect.y = yPos;
	bulletRect.w = 3;
	bulletRect.h = 3;
	SDL_RenderFillRect(renderer.getRender(), &bulletRect);      
}

