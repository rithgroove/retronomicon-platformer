#include "platformer_physics_system.h"
#include <algorithm>

namespace retronomicon::platformer::lib::core::system {

void PlatformerPhysicsSystem::integrate(float dt)
{
    constexpr float kGravity = 9.81f;

    for (auto& body : m_bodies)
    {
        body.velocity.y += kGravity * dt;
        body.position   += body.velocity * dt;
    }
}

void PlatformerPhysicsSystem::resolveCollisions()
{
    constexpr float kGroundY = 0.0f;

    for (auto& body : m_bodies)
    {
        if (body.position.y - body.halfExtent.y < kGroundY)
        {
            body.position.y = kGroundY + body.halfExtent.y;
            body.velocity.y = 0.0f;
            body.grounded   = true;
        }
        else
        {
            body.grounded = false;
        }
    }
}

} // namespace retronomicon::platformer::lib::core::system
