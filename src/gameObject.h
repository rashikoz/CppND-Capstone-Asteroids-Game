#pragma once
#include <iostream>
#include "renderer.h"

class gameObject {
    protected:
        float xPos=0.0, yPos = 0.0; 
        float angle = 0.0;
        float xVelocity=0.0, yVelocity=0.0, objectSize=1.0;
        float elapsedTime=0.001;
    public:
        void wrapAround(std::size_t screenWidth, std::size_t screenHeight);
        void setParams(float x, float y, float xV, float yV, float a, float oSize);
        bool checkObjectOutsideScreenSpace(std::size_t screenWidth, std::size_t screenHeight);
        float getxPos();
        float getyPos();
        float getAngle();
        float getxVelocity();
        float getyVelocity();
        float getObjectSize();
        void throwOutsideScreen(void);
        void setElapsedTime(float elapsedTime);
        float getElapsedTime();  
};
