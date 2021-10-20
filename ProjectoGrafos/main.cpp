#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 700), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Texture* imagen;
    Sprite* sprite;
    imagen = new Texture();
    sprite = new Sprite();
    imagen->loadFromFile("mapa.jpg", sf::IntRect(0, 0, 800, 600));
    sprite->setTexture(*imagen);
    sprite->setScale((float)window.getSize().x / sprite->getTexture()->getSize().x, (float)window.getSize().y / sprite->getTexture()->getSize().y); // tama�o deseado dividido tama�o actual

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*sprite); //imagen
        window.draw(shape);
        window.display();
    }

    return 0;
}