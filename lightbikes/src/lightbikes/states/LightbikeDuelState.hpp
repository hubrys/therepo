#ifndef LIGHTBIKES_LIGHTBIKEDUELSTATE_HPP
#define LIGHTBIKES_LIGHTBIKEDUELSTATE_HPP


#include <yage/yage.hpp>

namespace lightbikes {
class LightbikeDuelState : public yage::GameState {
    void setup(yage::World &world) override;

    bool fixedUpdate(yage::World &world) override;

private:
    void resetDuel(yage::World &world);

    std::vector<yage::World::entity_type> lightbikes_;
};
}


#endif //LIGHTBIKES_LIGHTBIKEDUELSTATE_HPP
