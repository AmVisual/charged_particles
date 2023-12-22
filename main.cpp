/* ====================================================================================
    This is a program that simulates the motion of charged particles.
    The particles are spread across the whole window.
    There are different types of particles with different charges, masses and sizes.
    Each particle acts on other ones with electric forces.
    The particles can also deflect when they hit each other or hit the border of
    a window.
    In each iteration of the simulation the positions of particles are calculated
    using Verlet's algorithm (more precisely it uses the leap-frog algorithm).
   ==================================================================================== */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "particle.h"

// declaring the size of window
int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 600;

// particles
int nrParticles = 0;

int main()
{
    // defining a window object
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Charged particles simulation");

    // text for displaying informations about controls and settings
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Couldn't find a font file arial.ttf" << std::endl;
        return 1;
    }

    sf::Text controlsInfo;
    sf::Text nrParticlesInfo;

    controlsInfo.setFont(font);
    controlsInfo.setFillColor(sf::Color::Red);
    controlsInfo.setString("Press [R] to randomize positions\n"
                           "Press [Up Arrow] to increase nr of particles\n"
                           "Press [Down Arrow] to decrease nr of particles");
    controlsInfo.setCharacterSize(24);
    controlsInfo.setPosition(0.0f, 0.0f);
    nrParticlesInfo.setFont(font);
    nrParticlesInfo.setFillColor(sf::Color::Red);
    nrParticlesInfo.setString("Nr of particles: " + std::to_string(nrParticles));
    nrParticlesInfo.setCharacterSize(24);
    nrParticlesInfo.setPosition(0.0f, 90.0f);

    // creating a vector of particles
    std::vector<particle> particles;

    // inserting particles with random positions into a vector
    // setting a seed to random number generator
    std::srand(std::time(NULL));

    for (int i = 0; i < nrParticles; i++) {
        // random location
        float x = 0;
        float y = 0;
        sf::Vector2f pos(x, y);
        // particle's radius
        float r = 10.0;
        // particle's mass
        float m = 1;
        // particle charge
        float q = 0.0;
        // insert a particle inside the vector
        particles.push_back(particle(pos,r,m,q,sf::Color::Green));
    }
    std::cout << "Added all particles" << std::endl;
    // open the window and start the main loop
    while (window.isOpen())
    {
        // event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // if the close event is detected, close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed)
            {
                // if 'R' pressed, randomize particles' postions
                if (event.key.code == sf::Keyboard::R)
                {
                    std::cout << "Randomize particles' positions" << std::endl;
                    for (auto i = particles.begin(); i != particles.end(); ++i)
                    {
                        i->randomize_pos(WINDOW_WIDTH, WINDOW_HEIGHT);
                    }
                }
                // if 'Up arrow' pressed, increase number of particles
                if (event.key.code == sf::Keyboard::Up) {
                    nrParticles++;
                    nrParticlesInfo.setString("Nr of particles: " + std::to_string(nrParticles));
                    // random location
                    float x = 0;
                    float y = 0;
                    sf::Vector2f pos(x, y);
                    // particle's radius
                    float r = 10.0;
                    // particle's mass
                    float m = 1;
                    // particle charge
                    float q = 0.0;
                    // insert a particle inside the vector
                    particles.push_back(particle(pos,r,m,q,sf::Color::Green));
                }
                // if 'Down arrow' pressed, decrease nr of particles
                if (event.key.code == sf::Keyboard::Down) {
                    if (nrParticles > 0) {
                        nrParticles--;
                        nrParticlesInfo.setString("Nr of particles: " + std::to_string(nrParticles));
                        particles.pop_back();
                    }
                }
            }
        }

        // calculate new positions of particles

        // update the window
        window.clear();
        // draw particles
        if (nrParticles > 0) {
            for (auto i = particles.begin(); i != particles.end(); ++i) {
                window.draw(*i);
            }
        }        
        // draw info
        window.draw(controlsInfo);
        window.draw(nrParticlesInfo);
        window.display();
    }

    return 0;
}