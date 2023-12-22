#include "motion.h"
#include <math.h>

// a function for calculating a force between particle p1 and p2
sf::Vector2f F(particle p1, particle p2) {
    // calculate vector R between p1 and p2
    float Rx = p2.get_pos().x - p1.get_pos().x;
    float Ry = p2.get_pos().y - p1.get_pos().y;
    // calculate R's length
    float R2 = Rx*Rx + Ry*Ry;
    float R = std::sqrt(R2);
    // get unit vector parallel to R vector
    sf::Vector2f unit_v = sf::Vector2f(Rx / R2, Ry / R2);
    // return force acting on p1
    return k * (p1.get_q() * p2.get_q()) / R2 * unit_v;
}

// a function for calculating particle's acceleration based on:
// f - force
// m - mass
sf::Vector2f a(sf::Vector2f f, float m) {return f / m;}

// a function for calculating particle's velocity in next iteration based on:
// v_i - velocity in current iteration
// a_i - acceleration in current iteration
// a_i1 - acceleration in next iteration
// dt - time step between iterations
sf::Vector2f v(sf::Vector2f v_i, sf::Vector2f a_i, sf::Vector2f a_i1, float dt) {
    return v_i + (float)0.5 * (a_i + a_i1) * dt;
}

// a function for calculating particle's position in next iteration based on:
// x_i - position in current iteration
// v_i - velocity in current iteration
// a_i - acceleration in current iteration
// dt - time step between iterations
sf::Vector2f x(sf::Vector2f x_i, sf::Vector2f v_i, sf::Vector2f a_i, float dt) {
    return x_i + v_i*dt + (float)0.5*a_i*dt*dt;
}

// a function for applying leap frog algorithm to particles p1 and p2
void leap_frog(particle p1, particle p2) {
    
}