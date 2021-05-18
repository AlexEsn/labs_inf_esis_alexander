#include <iostream>
#include <SFML/Graphics.hpp>

#include "matrix/matrix.h"

using namespace sf;

int main(int argc, char *argv[]) {

    RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    CircleShape shape(10.f);
    shape.setFillColor(sf::Color::White);
    int i = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(shape);

        shape.setPosition(i, i);
        Time time1 = microseconds(10000);
        sleep(time1);
        window.display();
        i += 1;
    }
}
