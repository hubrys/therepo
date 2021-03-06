#ifndef LIGHTBIKES_LIGHTBIKE_HPP
#define LIGHTBIKES_LIGHTBIKE_HPP

namespace lightbikes {
struct Lightbike {
    enum Direction : char {
        None,
        Left,
        Right,
        Up,
        Down
    };

    float speed; // Units per second
    Direction direction;
    bool isDead;
};
}

#endif //LIGHTBIKES_LIGHTBIKE_HPP
