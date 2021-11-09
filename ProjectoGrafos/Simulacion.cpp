#include "Simulacion.h"

Simulacion::Simulacion() {
	grafo = new Grafo();
	ventana = new RenderWindow(VideoMode(900, 700), "SIMULADOR GRAFOS", Style::Close);
	imagen = new Texture();
	sprite = new Sprite();
	imagen->loadFromFile("mapa.jpg", sf::IntRect(0, 0, 800, 600));
	sprite->setTexture(*imagen);
	sprite->setScale((float)ventana->getSize().x / sprite->getTexture()->getSize().x, (float)ventana->getSize().y / sprite->getTexture()->getSize().y); // tamano deseado dividido tamano actual

	Image img;
	img.loadFromFile("Icono.png");
	ventana->setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());

	font = new Font();
	font->loadFromFile("HU The Game.ttf");
	centro = ventana->getSize().x / 2;
	titulo.setFont(*font);
	titulo.setString("-SIMULADOR GRAFOS-");
	titulo.setCharacterSize(50);
	titulo.setFillColor(Color::Black);
	titulo.setPosition(centro - titulo.getGlobalBounds().width / 2.f, 50);
	rectangle.setSize(sf::Vector2f(titulo.getGlobalBounds().width, titulo.getGlobalBounds().height + 15));
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(centro - titulo.getGlobalBounds().width / 2.f, 50);


	btnNuevaSimulacion = new Boton(centro - titulo.getGlobalBounds().width / 3.f, 200, 170, 80, &*font, "Nuevo Juego", 25, Color::Blue, Color::Green, Color::Red);
	btnSalir = new Boton(centro - titulo.getGlobalBounds().width / 3.f, 500, 170, 80, &*font, "Salir", 25, Color::Red, Color::Green, Color::Black);
	this->estadoSubmenu = MENU_PRINCIPAL;



	permisoDigitar = false;
	pesoArista = new Text();

	//shape.setRadius(10);
	//shape.setFillColor(Color::Red);
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



void Simulacion::procesarEventos()
{
	sf::Event event;
	while (ventana->pollEvent(event)) // pollevent : escuchar evento 
	{
		if (event.type == sf::Event::Closed) {
			ventana->close();
		}

		if (event.type == sf::Event::TextEntered && permisoDigitar) {
			modificarPesoArista(event);
		}

		// get mouse position
		Vector2f posMouse = Vector2f(Mouse::getPosition(*ventana));

		// MENU Principal
		if (estadoSubmenu == MENU_PRINCIPAL) {

			btnNuevaSimulacion->actualizarBoton(posMouse);
			btnSalir->actualizarBoton(posMouse);
		}

		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				agregarVertice(posMouse);
				pos.push_back(posMouse);
			}
		}
	}
}

void Simulacion::graficar()
{
	ventana->draw(*sprite);
	if (estadoSubmenu == MENU_PRINCIPAL) {
		ventana->draw(rectangle);
		ventana->draw(titulo);

		if (btnNuevaSimulacion->procesarBoton(&*ventana)) {
			btnNuevaSimulacion->setEstadoBoton(BTN_INACTIVO);
			estadoSubmenu = SBMN_SIMULACION;
		}

		if (btnSalir->procesarBoton(&*ventana)) {
			btnSalir->setEstadoBoton(BTN_INACTIVO);
			ventana->close();
		}
	}
	graficarLineasAndPuntos();
	agregarLinea();
	//ventana->draw(shape);
}

void Simulacion::graficarLineasAndPuntos() {
	if (!lts.empty()) {
		for (int i = 0;i < lts.size();i++) {
			ventana->draw(lts[i]);
		}
	}
	if (!lineas.empty()) {
		for (int i = 0;i < lineas.size();i++) {
			Vertex v[] = { Vertex(lineas[i][0]), Vertex(lineas[i][1]) };
			ventana->draw(v, 6, sf::Lines);
		}
	}
	if (!pesosAristas.empty()) {
		for (int i = 0;i < pesosAristas.size();i++) {
			ventana->draw(pesosAristas[i]);
		}
	}

	if (permisoDigitar) {
		ventana->draw(*pesoArista);
	}

}

void Simulacion::agregarVertice(Vector2f posMouse) {
	vertice = new CircleShape();
	vertice->setRadius(10);
	vertice->setFillColor(Color::Red);
	vertice->setPosition(posMouse.x - 10, posMouse.y - 10);
	lts.push_back(*vertice);
}

void Simulacion::agregarLinea() {
	if (pos.size() == 2) {
		lineas.push_back(pos);
		//pos.clear();

		permisoDigitar = true; // creacion de texto de peso Arista
		pesoArista = new Text();
		pesoArista->setFont(*font);
		pesoArista->setString("0");
		pesoArista->setCharacterSize(20);
		pesoArista->setFillColor(Color::Black);
		pesoArista->setPosition( pos[0].x + ((pos[1].x - pos[0].x)/2), pos[0].y + ((pos[1].y - pos[0].y) / 2));

		pos.clear();

	}
	if (pos.size() == 1 && permisoDigitar == true ) { // en caso de no colocar peso a la arista
		if (pesoArista->getString().getSize() == 0) { // si va vacia de peso la arista
			pesoArista->setString("0");
		}
		permisoDigitar = false; // dejar de escribir
		pesosAristas.push_back(*pesoArista); // agregar el peso de la arista
		pesoArista = new Text();
	}
}


void Simulacion::modificarPesoArista(Event event) {

	//cout << event.text.unicode<<endl;
//cout << (char)event.text.unicode<<endl;
	//pesoArista->setString(pesoArista->getString() + (char)event.text.unicode);


	if (event.text.unicode == 8) { // si va a borrar
		if (pesoArista->getString().getSize() > 0) {
			string palabra = pesoArista->getString();
			size_t tam = palabra.length(); //obtenemos el tamaño del string
			palabra.erase(tam - 1);

			pesoArista->setString(palabra);
		}
	}

	if (pesoArista->getString().getSize() <= 4) { // Si va a escribir .....limite de tamaño de peso de arista
		if (event.text.unicode >= 48 && event.text.unicode <= 57) { // aceptacion de solo numeros
			
			if(event.text.unicode ) {
				pesoArista->setString(pesoArista->getString() + (char)event.text.unicode);
			}
		}
	}

	if (event.text.unicode == 13) { // si ya acepto o termino la escritura con un enter
		if (pesoArista->getString().getSize() == 0) { // si va vacia de peso la arista
			pesoArista->setString("0");
		}
		permisoDigitar = false; // dejar de escribir
		pesosAristas.push_back(*pesoArista); // agregar el peso de la arista
		pesoArista = new Text();
	}

}
