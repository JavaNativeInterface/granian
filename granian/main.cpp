#include <SFML/Graphics.hpp>
#include "object.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "granian");
    window.setFramerateLimit(60);

    std::vector<object*> listOfObjects = {};

    object *apple = new object(vector(20000, 2), Vector2(0, screenY / 2), 70000000000000000);
    apple->getShape()->setFillColor(sf::Color::Red);
    listOfObjects.push_back(apple);
    

    object *earth = new object(vector(0, 0), Vector2(screenX / 2, screenY / 2), 5970000000000000000);
    earth->getShape()->setFillColor(sf::Color::Blue);
    listOfObjects.push_back(earth);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto const obj : listOfObjects)
        {
            for (auto const objU : listOfObjects)
            {
                if (obj != objU)
                {
                    obj->update(objU);
                }
            }
        }

        window.clear();
        for (auto const obj : listOfObjects)
        {
            window.draw(*obj->getShape());
        }
        window.display();
    }

    return 0;
}