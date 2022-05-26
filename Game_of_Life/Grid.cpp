#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Grid.h"
#include "Cell.h"
#include "Conv.h"


using namespace std;




// sf::RectangleShape right(sf::Vector2f(float x,float y));

// sf::RenderWindow window(sf::VideoMode(Size, Size), const char* titre);


/*Grid::Grid(int size, int nbCells) {
	size_ = size; 
	nbCells_ = nbCells; 
}*/

Grid::Grid() {
	int size = setGridSize();

	int nbCells = cellNumber();

	size_ = size;
	nbCells_ = nbCells;
}

/*Grid::Grid(vector<vector<Cell>> cell) {
	
	int size = setGridSize();

	int nbCells = cellNumber();

	size_ = size;
	nbCells_ = nbCells;

	//cell_ = cell;
}*/


Grid::~Grid(){}

// On defini la taille de la grille

const int Grid::setGridSize() {

	int size;

	cout << "Size of the grid : " << endl;
	cin >> size;
	cout << endl;

	return size;
}


// Defini le nombre de cellule par ligne

const int Grid::cellNumber() {
	int num;

	cout << "Number of cells on a line : " << endl;
	cin >> num;
	cout << endl;

	return num;
}


// On met tous les paramètres ensemble et ça marche en gros

void Grid::setGrid() {

	const int sizeG = size_;
	const int numC = nbCells_;

	float ratio = (float)sizeG / numC;
	int ratioInt = (int)ratio;

	// Definit la fenêtre

	sf::RenderWindow window(sf::VideoMode(sizeG, sizeG), "Niamavion !"); //fenetrebgette

	vector <vector <Cell>> cell;
	vector <Cell> oui;
	Cell non(0,0,sizeG/numC,0);
	// Ici y a un pb mais je sais pas ce que c'est 😠

	for (int i = 0; i < numC; i++) {
		cell.push_back(oui);
		for (int j = 0; j < numC; j++) {
			non.setPos(i * ratioInt, j * ratioInt, ratioInt);
			cell[i].push_back(non);
		}
	}

	//cell_ = cell;

	// La dernière colonne de la grille

	sf::RectangleShape right(sf::Vector2f(1., (float)sizeG));

	right.setPosition((float)(sizeG - 1.), 0.);

	window.draw(right);


	// Dernière ligne de la grille

	sf::RectangleShape bot(sf::Vector2f((float)sizeG, 1.));

	bot.setPosition(0., (float)(sizeG - 1.));

	window.draw(bot);

	// Pour toutes les autres lignes

	for (int i = 0; i < numC; i++) {
		sf::RectangleShape rectangle(sf::Vector2f(1., (float)sizeG));

		rectangle.setPosition(i * ratio, 0.);


		window.draw(rectangle);

	}


	// Pour toutes les autres colonnes

	for (int i = 0; i < numC; i++) {
		sf::RectangleShape rectangle(sf::Vector2f((float)sizeG, 1.));

		rectangle.setPosition(0., i * ratio);


		window.draw(rectangle);

	}

	// Affichage de la grille

	window.display();
	int dt = 0;

	while (window.isOpen()) {
		dt++;

		sf::Event event;

		while (window.pollEvent(event)) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2i localPositionR = sf::Mouse::getPosition(window);

			localPosition /= sizeG / numC ;

			int x = localPosition.x;
			int y = localPosition.y;


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (dt >= 20000)) {
				dt = 0;
				cell[x][y].changeState();
				if (cell[x][y].getState() == 1) {
					window.display();
					sf::RectangleShape cellG(sf::Vector2f((float)(sizeG / numC), (float)(sizeG / numC)));
					cellG.setPosition(sf::Vector2f((float) (localPositionR.x - (localPositionR.x % (sizeG / numC))), (float)localPositionR.y - (localPositionR.y % (sizeG / numC))));
					window.draw(cellG);
					window.display();
				}
				else {
					window.display();
					sf::RectangleShape cellG(sf::Vector2f((float)(sizeG / numC - 1.), (float)(sizeG / numC - 1.)));
					cellG.setFillColor(sf::Color(0, 0, 0, 255));
					cellG.setPosition(sf::Vector2f((float)(localPositionR.x - (localPositionR.x % (sizeG / numC))) + 1, (float)localPositionR.y - (localPositionR.y % (sizeG / numC)) + 1));
					window.draw(cellG);
					window.display();
				}
				
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

}


/*Cell Grid::getID(int i, int j) {
	return cell_[i][j];
}

int Grid::size() {

	return (int) cell_.size();
}*/