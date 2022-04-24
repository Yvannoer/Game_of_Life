#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "grid.h"
#include "Cell.h"


using namespace std;

const int setGridSize() {

	int size;

	cout << "Size of the grid : " << endl;
	cin >> size;
	cout << endl;

	return size;
}

const int cellNumber() {
	int num;

	cout << "Number of cells on a line : " << endl;
	cin >> num;
	cout << endl;

	return num;
}

void setGrid() {

	const int sizeG = setGridSize();
	const int numC = cellNumber();

	float ratio = (float)sizeG / numC;
	int ratioInt = (int)ratio;
	const int* ratioConst = &ratioInt;

	sf::RenderWindow window(sf::VideoMode(sizeG, sizeG), "Niama !"); //fenetrebgette

	Cell** cell;
	cell = new Cell*[numC];
	*cell = new Cell[numC];


	while (window.isOpen())
	{

		for (int i = 0; i < numC; i++) {
			for (int j = 0; j < numC; j++) {
				//cell[i][j].setPos(i * ratioInt, j * ratioInt, ratioInt);

				//window.draw((cell[i][j]).rectangle_);
			}
		}

		sf::RectangleShape right(sf::Vector2f(1.,(float) sizeG));

		right.setPosition((float) (sizeG - 1.), 0.);

		window.draw(right);

		sf::RectangleShape bot(sf::Vector2f((float)sizeG, 1.));

		bot.setPosition(0., (float) (sizeG - 1.));

		window.draw(bot);

		for (int i = 0; i < numC; i++) {
			sf::RectangleShape rectangle(sf::Vector2f(1.,(float) sizeG));

			rectangle.setPosition(i * ratio, 0.);


			window.draw(rectangle);

		}




		for (int i = 0; i < numC; i++) {
			sf::RectangleShape rectangle(sf::Vector2f((float) sizeG, 1.));

			rectangle.setPosition(0., i * ratio);


			window.draw(rectangle);

		}

		window.display();

		sf::Event event;

		while (window.pollEvent(event))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		

			int x = (localPosition.x - localPosition.x % ratioInt) / numC;
			int y = (localPosition.y - localPosition.y % ratioInt) / numC;


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				cell[x][y].changeState();
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

}