//
//  Motion.cpp
//
//  Created by Jordan Rodrigues Rangel on 1/8/15.
//  Copyright (c) 2015 Jordan Rodrigues Rangel. All rights reserved.
//

#include "Motion.h"
#include "iostream"

float Motion::m_screenWidth = 500.0f;
float Motion::m_screenHeight = 350.0f;

Motion::Motion(float xLoc, float yLoc, float width, float height, float mass, float topspeed, float xVel, float yVel, float xAcc, float yAcc):m_location(xLoc, yLoc), m_velocity(xVel, yVel), m_acceleration(xAcc, yAcc), m_mass(mass), m_topspeed(topspeed), m_width(width), m_height(height) {}

Motion::Motion(const AlgebraVector& location, const AlgebraVector& velocity, const AlgebraVector& acceleration, float width, float height, float mass, float topspeed): m_location(location), m_velocity(velocity), m_acceleration(acceleration), m_mass(mass), m_topspeed(topspeed), m_width(width), m_height(height) {}

Motion& Motion::Update(void)
{
    //std::cout << m_acceleration;
    m_velocity += m_acceleration;
    
    float mag = m_velocity.GetMagnitude();
    
    if(mag > m_topspeed)
    {
        m_velocity.Normalize();
        m_velocity*m_topspeed;
    }
    
    m_location += m_velocity;
    
    m_acceleration *= 0.0f;
    
    return *this;
}

Motion& Motion::CheckEdges(void)
{
    if(m_location.m_x < 0.0f)
    {
        m_velocity.m_x *= -1.0f;
        m_location.m_x = 0.0f;
    }
    else if((m_location.m_x + m_width) > m_screenWidth)
    {
        m_velocity.m_x *= -1.0f;
        m_location.m_x = m_screenWidth - m_width;
    }
    
    if(m_location.m_y < 0.0f)
    {
        m_velocity.m_y *= -1.0f;
        m_location.m_y = 0.0f;
    }
    else if((m_location.m_y + m_height) > m_screenHeight)
    {
        m_velocity.m_y *= -1.0f;
        m_location.m_y = m_screenHeight - m_height;
    }
    
    return *this;
}

Motion& Motion::ApplyForce(const AlgebraVector& force)
{
    m_acceleration += force/m_mass;
    //std::cout << m_acceleration;
    return *this;
}

Motion& Motion::Drag(const Liquid& l)
{
    float speed = m_velocity.GetMagnitude();
    float dragMag = l.m_c * speed * speed;
    
    AlgebraVector dragVec(m_velocity);
    dragVec *= -1.0f;
    dragVec.Normalize();
    dragVec *= dragMag;
    ApplyForce(dragVec);
    
    return *this;
}

bool Motion::IsInside(const Liquid& l)
{
    return ((m_location.m_x > l.m_x) && (m_location.m_x + m_width < l.m_x + l.m_w) && (m_location.m_y > l.m_y) && (m_location.m_y + m_height < l.m_y +l.m_h));
}