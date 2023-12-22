#ifndef _motion_h_
#define _motion_h_

float k = 1;

#include <SFML/Graphics.hpp>
#include "particle.h"

// a function for calculating a force between particle p1 and p2
sf::Vector2f F(particle p1, particle p2);

// a function for calculating particle's acceleration based on:
// f - force
// m - mass
sf::Vector2f a(sf::Vector2f f, float m);

// a function for calculating particle's velocity in next iteration based on:
// v_i - velocity in current iteration
// a_i - acceleration in current iteration
// a_i1 - acceleration in next iteration
// dt - time step between iterations
sf::Vector2f v(sf::Vector2f v_i, sf::Vector2f a_i, sf::Vector2f a_i1, float dt);

// a function for calculating particle's position in next iteration based on:
// x_i - position in current iteration
// v_i - velocity in current iteration
// a_i - acceleration in current iteration
// dt - time step between iterations
sf::Vector2f x(sf::Vector2f x_i, sf::Vector2f v_i, sf::Vector2f a_i, float dt);

// a function for applying leap frog algorithm to particles p1 and p2
void leap_frog(particle p1, particle p2);

#endif