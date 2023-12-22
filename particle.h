#ifndef _particle_h_
#define _particle_h_

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

// particle class

class particle: public sf::Drawable
{
private:
    // position
    sf::Vector2f pos;
    // radius
    float r;
    // mass
    float m;
    // charge
    float q;
    // color
    sf::Color color;
    // a method for drawing a particle onto the screen
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    // constructors and destructors
    particle();
    particle(sf::Vector2f pos, float r, float m, float q, sf::Color color);
    ~particle();

    // getters and setters

    // get position
    sf::Vector2f get_pos();

    // set position
    void set_pos(sf::Vector2f pos);

    // get radius
    float get_r();

    // set radius
    void set_r(float r);

    // get mass
    float get_m();

    // set mass
    void set_m(float m);

    // get charge
    float get_q();

    // set charge
    void set_q(float q);

    // get color
    sf::Color get_color();

    // set color
    void set_color(sf::Color color);

    // methods
    void randomize_pos(int windowWidth, int windowHeight);

};

#endif