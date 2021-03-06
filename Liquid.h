//
//  Liquid.h
//
//  Created by Jordan Rodrigues Rangel on 1/8/15.
//  Copyright (c) 2015 Jordan Rodrigues Rangel. All rights reserved.
//

#ifndef __Liquid__
#define __Liquid__


class Liquid
{
public:
    float m_x;
    float m_y;
    float m_w;
    float m_h;
    float m_c;
    
    Liquid(float x = 0.0f, float y = 0.0f, float w = 0.0f, float h = 0.0f, float c = 0.0f);
};

#endif /* defined(__Liquid__) */