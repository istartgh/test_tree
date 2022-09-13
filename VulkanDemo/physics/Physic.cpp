//
//  main.cpp
//  VulkanDemo
//
//  Created by star03 on 2022/8/31.
//
#include "Physic.h"

namespace {
float Movement(float velocity, float acceleration, long time) {
    return 0.5 * velocity + 0.5 * acceleration * time * time;
}

}

void Something::UpdatePos(VectorQuantity force, long time) {
    m_pos.m_posx += Movement(m_velocity.m_lengthx, force.m_lengthx / m_quality, time);
    m_pos.m_posy += Movement(m_velocity.m_lengthy, force.m_lengthy / m_quality, time);
    m_pos.m_posz += Movement(m_velocity.m_lengthz, force.m_lengthz / m_quality, time);
}

