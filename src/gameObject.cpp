#include "gameObject.h"

void gameObject::wrapAround(std::size_t screenWidth, std::size_t screenHeight){
    // wrapAround
    if (xPos < 0.0f)	xPos += (float)screenWidth;
    if (xPos >= (float)screenWidth)	xPos -= (float)screenWidth;
    if (yPos < 0.0f)	yPos += (float)screenHeight;
    if (yPos >= (float)screenHeight) yPos -= (float)screenHeight;
}

void gameObject::setParams(float x, float y, float xV, float yV, float a, float oSize){
    // create model asteroid shape
    xPos = x;
    yPos = y;
    xVelocity = xV;
    yVelocity = yV;
    angle = a;
    objectSize = oSize;
}

bool gameObject::checkObjectOutsideScreenSpace(std::size_t screenWidth, std::size_t screenHeight)
{
    bool outside = false;
    outside = (xPos < 0.0f) || (xPos >= (float)screenWidth) || (yPos < 0.0f) || (yPos >= (float)screenHeight);
    return outside;
}

float gameObject::getxPos(){return xPos;}
float gameObject::getyPos(){return yPos;}
float gameObject::getAngle(){return angle;};
float gameObject::getxVelocity(){return xVelocity;}
float gameObject::getyVelocity(){return yVelocity;}
float gameObject::getObjectSize(){return objectSize;}
float gameObject::getElapsedTime(){return elapsedTime;}

void gameObject::setElapsedTime(float elapsedTime)
{
    elapsedTime = elapsedTime;
}

void gameObject::throwOutsideScreen(void)
{
    xPos = -100.0; 
}

