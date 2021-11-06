        #include <SFML/Graphics.hpp>
#include "Simulacion.h"
#include<iostream>
#include<vector>
using namespace std;
using namespace sf;

int main()
{

    Simulacion* simulacion = new Simulacion();
    simulacion->mostrarVentana();

   /*sf::RenderWindow window(sf::VideoMode(900, 700), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
   */
    //Texture* imagen;
    //Sprite* sprite;
    //imagen = new Texture();
    //sprite = new Sprite();
    //imagen->loadFromFile("mapa.jpg", sf::IntRect(0, 0, 800, 600));
    //sprite->setTexture(*imagen);
    //sprite->setScale((float)window.getSize().x / sprite->getTexture()->getSize().x, (float)window.getSize().y / sprite->getTexture()->getSize().y); // tama�o deseado dividido tama�o actual
    //
    //vector<vector<int>> matriz;
    //vector<int> p;
    //p.push_back(3);
    //p.push_back(0);
    //
    //matriz.push_back(p);  
    //matriz[0].push_back(3);
    //cout<<"-"<<matriz[0].back();

    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    window.clear();
    //    window.draw(*sprite); //imagen
    //    window.draw(shape);
    //    window.display();       
    //}   
    return 0;
}