#include "Simulacion.h"

Simulacion::Simulacion() {
	ventana = new RenderWindow(VideoMode(900, 700), "SOKOBAN", Style::Close);
    Texture* imagen;
    imagen = new Texture();
    shape.setRadius(10);
    shape.setFillColor(Color::Red);
    sprite = new Sprite();
    imagen->loadFromFile("mapa.jpg", sf::IntRect(0, 0, 800, 600));
    sprite->setTexture(*imagen);
    sprite->setScale((float)ventana->getSize().x / sprite->getTexture()->getSize().x, (float)ventana->getSize().y / sprite->getTexture()->getSize().y); // tamano deseado dividido tamano actual
}

void Simulacion::mostrarVentana() // Loop principal
{
    while (ventana->isOpen())
    {
        dibujarVentana();
    }
}

void Simulacion::dibujarVentana()
{
    // area de eventos
    procesarEventos();

    //  Limpieza de pantalla
    ventana->clear(Color::White);

    //Area de dibujo de cosas    
    graficar();

    // mostar pantalla
    ventana->display();
}

void Simulacion::graficar()
{
    ventana->draw(*sprite);
    ventana->draw(shape);
}

void Simulacion::procesarEventos()
{
    sf::Event event;
    while (ventana->pollEvent(event)) // pollevent : escuchar evento 
    {
        if (event.type == sf::Event::Closed) {
            ventana->close();
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left){
                cout << "hola";    
                shape.setPosition(Mouse::getPosition(*ventana).x-10, Mouse::getPosition(*ventana).y-10);
            }
        }
    }
}