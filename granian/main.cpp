#include <SFML/Graphics.hpp>
#include "object.hpp"
#include <iostream>

int main()
{
 
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "granian");
    window.setFramerateLimit(60);

    object obj1 = object(vector(20, 1.0), Vector2(0, screenY / 2), 70000000000000000);
    obj1.getShape()->setFillColor(sf::Color::Green);
    
    object obj2 = object(vector(0, 0), Vector2(screenX / 2, screenY / 2), 5970000000000000000);
    obj2.getShape()->setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        obj1.update(obj2);
       // obj2.update(obj1);
        window.clear();
        window.draw(*obj1.getShape());
        window.draw(*obj2.getShape());
        window.display();
    }

    return 0;
}