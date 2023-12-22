#include "particle.h"

// constructor
particle::particle() {}

particle::particle(sf::Vector2f pos, float r, float m, float q, sf::Color color)
{
    this->pos = pos;
    this->r = r;
    this->m = m;
    this->q = q;
    this->color = color;
}

// destructor
particle::~particle() {}

// get position
sf::Vector2f particle::get_pos()
{
    return this->pos;
}

// set position
void particle::set_pos(sf::Vector2f pos)
{
    this->pos = pos;
}

// get radius
float particle::get_r()
{
    return this->r;
}

// set radius
void particle::set_r(float r)
{
    this->r = r;
}

// get mass
float particle::get_m()
{
    return this->m;
}

// set mass
void particle::set_m(float m)
{
    this->m = m;
}

// get charge
float particle::get_q()
{
    return this->q;
}

// set charge
void particle::set_q(float q)
{
    this->q = q;
}

// get color
sf::Color particle::get_color()
{
    return this->color;
}

// set color
void particle::set_color(sf::Color color)
{
    this->color = color;
}

// randomize position method
void particle::randomize_pos(int windowWidth, int windowHeight)
{
    float x = std::rand() % windowWidth;
    float y = std::rand() % windowHeight;
    this->set_pos(sf::Vector2f(x,y));
}

// particle: draw method
void particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape circle(this->r);
    circle.setFillColor(this->color);
    circle.setOrigin(this->r,this->r);
    circle.setPosition(this->pos);
    target.draw(circle, states);
}