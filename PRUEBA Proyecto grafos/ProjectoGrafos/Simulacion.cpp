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

		//if (estadoSubmenu == SBMN_SIMULACION) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {  
					// cuando se da un click se crea un nuevo vertice y con este una nueva arista o se esta seleccionando un vector


					agregarVertice(posMouse);
					pos.push_back(posMouse);
				}
			}
		//}
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

			//grafo->mostarMatriz();
		}

		if (btnSalir->procesarBoton(&*ventana)) {
			btnSalir->setEstadoBoton(BTN_INACTIVO);
			ventana->close();
			
		}
	}

	//if (estadoSubmenu == SBMN_SIMULACION) {

		graficarLineasAndPuntos();
		agregarLinea();
		
	//}//ventana->draw(shape);
}

void Simulacion::graficarLineasAndPuntos() {
	vector <Vector2f> val = { Vector2f(0,0),Vector2f(0,0) };
	if (!grafo->getVertices().empty()) {
		for (int i = 0;i < grafo->getVertices().size();i++) {
			grafo->getVertice(i).procesarBoton(ventana);
		}
	}
	if (!grafo->getMatriz().empty()) {

		for (int i = 0;i < grafo->getMatriz().size();i++) {
			for (int j = 0; j < grafo->getMatriz().size();j++) {

				if (grafo->getMatriz()[i][j].getXY() != val) {
					vector<Vector2f> n = grafo->getMatriz()[i][j].getXY(); //El vector que hay en esa posicion es de mas de dimension 
					Vertex v[] = { Vertex(n[0]), Vertex(n[1]) };
					ventana->draw(v, 6, sf::Lines);
				}
			}
		}
	}

	if (!grafo->getMatriz().empty()) { // dibuja los textos de las aristas
		for (int i = 0;i < grafo->getMatriz().size();i++) {
			for (int j = 0; j < grafo->getMatriz().size();j++) {

				if (grafo->getMatriz()[i][j].getXY() != val) {

					string num = grafo->getMatriz()[i][j].getTexto().getString();
					if (stoi(num) > 0)
						ventana->draw(grafo->getMatriz()[i][j].getTexto());     /// Se cae por rango del vector
				}
			}
		}
	}


	if (permisoDigitar) { 
		ventana->draw(*pesoArista);
	}

}


void Simulacion::agregarVertice(Vector2f posMouse) {
	char c = 'A';
	int letra = grafo->getVertices().size();
	c += letra;
	string t = string(1, c);
	vertice = new Vertice(t, posMouse, grafo->getVertices().size());
	grafo->setVertice(*vertice);
}

void Simulacion::agregarLinea() {
	if (pos.size()==2) {

		vector <Vector2f> v = { Vector2f(0,0),Vector2f(0,0) }; // vector que guardar ambas posiciones de vetices
		Arista aux(0, v);

		// insercion de 2 vectores en si a la vez con sus resctivas aristas

		vector <Arista> vec; // creacion de nueva fila y columna en matriz segun como este esta
		if (grafo->getMatriz().size() == 0) { // si matriz esta vacia 

			// creacion de fila 1 para el primer vertor insertado con sus respectivas aristas
			Arista ar(0, v);
			vec.push_back(ar);
			vec.push_back(*new Arista(-1, pos)); // -1 denota que hay camino pero no oficializado con un peso
			grafo->setVector(vec);

			// creacion de segunda fila para hacerle pareja
			int aux = vec[1].getPeso();
			vec[0].setPeso(aux);
			vec[1].setPeso(0);
			grafo->setVector(vec);

			vec.clear();
		}
		else {

			vec.clear();
			
			// crecimiento de matriz en cuadrado
			for (size_t i = 0; i < grafo->getMatriz().size(); i++) // rellenado de ceros en filas
			{
				for (size_t j = 0; j < 2; j++)
					grafo->setAristaPos(i, *new Arista(0, v));				
			}

			for (size_t i = 0; i < grafo->getVertices().size(); i++)// cargado de vec de aristas en cero	
				vec.push_back(*new Arista(0, pos));
			// agregacion de las 2 nuevas filas en matriz
			grafo->setVector(vec);
			grafo->setVector(vec);

			// asignacion de pesos a conexiones entre dichas filas

			auxIJ.x = grafo->getVertices().size() - 1;
			auxIJ.y = grafo->getVertices().size() - 2;

			//grafo->getMatriz()[auxIJ.x][auxIJ.y].setPeso(-1);
			//grafo->getMatriz()[auxIJ.y][auxIJ.x].setPeso(-1);


			//vec[vec.size() - 2].setPeso(3);
			//vec[vec.size() - 1].setPeso(0);
			
		}

		permisoDigitar = true; // creacion de texto de peso Arista

		pesoArista = new Text();
		pesoArista->setFont(*font);
		pesoArista->setString("1");
		pesoArista->setCharacterSize(20);
		pesoArista->setFillColor(Color::Black);
		pesoArista->setPosition( pos[0].x + ((pos[1].x - pos[0].x)/2), pos[0].y + ((pos[1].y - pos[0].y) / 2));		
		pos.clear();

		//if (grafo->getMatriz().size() == 2)
		//{
		//	grafo->setPeso(0,1, -1); // cuidado cuando la matriz es de tamaño 2
		//	grafo->setPeso(1,0, -1);
		//}
		//else
		//{
			grafo->setPeso(auxIJ.x, auxIJ.y, -1); 
			grafo->setPeso(auxIJ.y, auxIJ.x, -1);
		//}

		
		cout << endl;
		grafo->mostarMatriz();
	}

	if (pos.size() == 1 && permisoDigitar == true) { // en caso de no colocar peso a la arista (guardado automatico)
		string num = pesoArista->getString();
		if ( stoi(num) < 1) { // si va vacia de peso la arista
			pesoArista->setString("1");
		}
		permisoDigitar = false; // dejar de escribir

		// asignacion de peso arista a una arista en espefico dentro de la matriz
		// si peso es <=0 se pone un 1
		grafo->getMatriz()[auxIJ.x][auxIJ.y].setTexto(*pesoArista); // agregar el peso de la arista
		grafo->getMatriz()[auxIJ.y][auxIJ.x].setTexto(*pesoArista); // agregar el peso de la arista
		
		string num2 = pesoArista->getString();
		grafo->setPeso(auxIJ.x, auxIJ.y, stoi(num2) );
		grafo->setPeso(auxIJ.y, auxIJ.x, stoi(num2) );

		pesoArista = new Text();
	}
}


void Simulacion::modificarPesoArista(Event event) {

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

			if (event.text.unicode) {
				pesoArista->setString(pesoArista->getString() + (char)event.text.unicode);
			}
		}
	}

}
