#pragma once
#include <vector>
#include "retronomicon/lib/physics/physics_system.h"

namespace retronomicon::platformer::lib::physics {

/**
 * Platformer-specific 2D physics system.
 */
class PlatformerPhysicsSystem final : public retronomicon::lib::physics::PhysicsSystem
{
public:
    PlatformerPhysicsSystem() = default;
    ~PlatformerPhysicsSystem() override = default;

protected:
    void integrate(float dt) override;
    void resolveCollisions() override;

private:
    struct Body
    {
        glm::vec2 position{0.0f};
        glm::vec2 velocity{0.0f};
        glm::vec2 halfExtent{0.5f, 0.5f};
        bool      grounded{false};
    };

    std::vector<Body> m_bodies;
};

} // namespace retronomicon::platformer::lib::core::system
