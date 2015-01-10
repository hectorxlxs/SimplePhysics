//
//  Motion.h
//
//  Created by Jordan Rodrigues Rangel on 1/8/15.
//  Copyright (c) 2015 Jordan Rodrigues Rangel. All rights reserved.
//

#ifndef __NanoChallenge_ThreeComponents__Motion__
#define __NanoChallenge_ThreeComponents__Motion__

#include "AlgebraVector.h"
#include "Liquid.h"

class Motion
{
public:
    AlgebraVector m_location;
    AlgebraVector m_velocity;
    AlgebraVector m_acceleration;
    
    float m_mass;
    float m_topspeed;
    float m_width;
    float m_height;
    
    static float m_screenWidth;
    static float m_screenHeight;
    
    Motion(const AlgebraVector& location, const AlgebraVector& velocity, const AlgebraVector& acceleration, float width = 30.0f, float height = 30.0f, float mass = 1.0f, float topspeed = 10.0f);
    Motion(float xLoc = 1.0f, float yLoc = 1.0f, float width = 30.0f, float height = 30.0f, float mass = 1.0f, float topspeed = 10.0f, float xVel = 0.0f, float yVel = 0.0f, float xAcc = 0.0f, float yAcc = 0.0f);
    
    Motion& Update(void);
    Motion& CheckEdges(void);
    Motion& ApplyForce(const AlgebraVector& force);
    Motion& Drag(const Liquid& l);
    
    bool IsInside(const Liquid& l);
};

#endif /* defined(__NanoChallenge_ThreeComponents__Motion__) */