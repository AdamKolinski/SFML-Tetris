// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"

using namespace sf;
using namespace std;

int yPos = -4, xPos = 4, speed = 1, n = 0, r = 0;

float timer = 0, delay = 0.5;
void ableToMove(Block block, Board& board, RenderWindow& window);
Clock zegar;

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode{ 600, 600 }, "Tetris", sf::Style::Close);
	window.setFramerateLimit(60);
	Event event;
	Board board(10, 18, 30);
	board.initializeBoard();
	zegar.restart();

	while (window.isOpen())
	{
		float time = zegar.getElapsedTime().asSeconds();
		zegar.restart();
		timer += time;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (event.key.code == sf::Keyboard::A) {
				xPos -= 1;
			}
			if (event.key.code == sf::Keyboard::D) {
				xPos += 1;
			}*/
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta < 0)
				{
					xPos += 1;
				}
				else if (event.mouseWheelScroll.delta > 0)
				{
					xPos -= 1;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					delay = 0.05;
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					r+=1;
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					delay = 0.5;
				}
			}
		}
		if (r > 3) r = 0;
		window.clear(sf::Color(66, 66, 66));
		if (xPos > 8) xPos = 8;
		if (xPos <= -1 && n != 0) xPos = 0;
		else if (xPos <= -1) xPos = -1;
		Block block(n, r, 32*xPos+2, 32*yPos+2);
		ableToMove(block, board, window);
		board.drawBoard(window);
		block.drawBlock(window);
		if (timer >= delay) {
			if (yPos < 14) {
				speed = 1;
				yPos += speed;
			}
			else
			{
				speed = 0;
			}
			timer = 0;
			for (int i = 0; i < 10; i++) {
				if (board.boardStates[i][0] == 1) window.close();
			}
		}

		window.display();
	}

	return 0;
}

void ableToMove(Block block, Board& board, RenderWindow& window) {
	if (true) {
		for (int i = 15; i >= 0; i--) {
			if (r == 0 && block.shapesArray[block.shapeNumber][i] == 1) {
				cout << "1";
				if (i % 2 == 1) {
					//cout << xPos + 1 << " | " << yPos + 4 << endl;
					//cout << board.boardStates[1][1] << endl;
					if (i == 15 && yPos + 4 > 0) if (board.boardStates[xPos + 3][yPos + 4] == 1) { speed = 0; }
					if (i == 13 && yPos + 4 > 0) if (board.boardStates[xPos + 1][yPos + 4] == 1) { speed = 0; }
					if (i == 11 && yPos + 3 > 0) if (board.boardStates[xPos + 3][yPos + 3] == 1) { speed = 0; }
					if (i == 9 && yPos + 3 > 0)	if (board.boardStates[xPos + 1][yPos + 3] == 1) { speed = 0; }
					if (i == 7 && yPos + 2 > 0)	if (board.boardStates[xPos + 3][yPos + 2] == 1) { speed = 0; }
					if (i == 5 && yPos + 2 > 0)	if (board.boardStates[xPos + 1][yPos + 2] == 1) { speed = 0; }
					if (i == 3 && yPos + 1 > 0)	if (board.boardStates[xPos + 3][yPos + 1] == 1) { speed = 0; }
					if (i == 1 && yPos + 1 > 0)	if (board.boardStates[xPos + 1][yPos + 1] == 1) { speed = 0; }

				}
				else if (i % 2 == 0) {
					if (i == 14 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 4] == 1) { speed = 0; }
					if (i == 12 && yPos + 4 > 0) if (board.boardStates[xPos][yPos + 4] == 1) { speed = 0; }
					if (i == 10 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 3] == 1) { speed = 0; }
					if (i == 8 && yPos + 4 > 0)	if (board.boardStates[xPos][yPos + 3] == 1) { speed = 0; }
					if (i == 6 && yPos + 4 > 0)	if (board.boardStates[xPos + 2][yPos + 2] == 1) { speed = 0; }
					if (i == 4 && yPos + 3 > 0)	if (board.boardStates[xPos][yPos + 2] == 1) { speed = 0; }
					if (i == 2 && yPos + 2 > 0)	if (board.boardStates[xPos + 2][yPos + 1] == 1) { speed = 0; }
					if (i == 0 && yPos + 1 > 0)	if (board.boardStates[xPos][yPos + 1] == 1) { speed = 0; }
				}

			}
			if (r == 1 && block.shapesArrayR1[block.shapeNumber][i] == 1) {
				cout << "1";
				if (i % 2 == 1) {
					//cout << xPos + 1 << " | " << yPos + 4 << endl;
					//cout << board.boardStates[1][1] << endl;
					if (i == 15 && yPos + 4 > 0) if (board.boardStates[xPos + 3][yPos + 4] == 1) { speed = 0; }
					if (i == 13 && yPos + 4 > 0) if (board.boardStates[xPos + 1][yPos + 4] == 1) { speed = 0; }
					if (i == 11 && yPos + 3 > 0) if (board.boardStates[xPos + 3][yPos + 3] == 1) { speed = 0; }
					if (i == 9 && yPos + 3 > 0)	if (board.boardStates[xPos + 1][yPos + 3] == 1) { speed = 0; }
					if (i == 7 && yPos + 2 > 0)	if (board.boardStates[xPos + 3][yPos + 2] == 1) { speed = 0; }
					if (i == 5 && yPos + 2 > 0)	if (board.boardStates[xPos + 1][yPos + 2] == 1) { speed = 0; }
					if (i == 3 && yPos + 1 > 0)	if (board.boardStates[xPos + 3][yPos + 1] == 1) { speed = 0; }
					if (i == 1 && yPos + 1 > 0)	if (board.boardStates[xPos + 1][yPos + 1] == 1) { speed = 0; }

				}
				else if (i % 2 == 0) {
					if (i == 14 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 4] == 1) { speed = 0; }
					if (i == 12 && yPos + 4 > 0) if (board.boardStates[xPos][yPos + 4] == 1) { speed = 0; }
					if (i == 10 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 3] == 1) { speed = 0; }
					if (i == 8 && yPos + 4 > 0)	if (board.boardStates[xPos][yPos + 3] == 1) { speed = 0; }
					if (i == 6 && yPos + 4 > 0)	if (board.boardStates[xPos + 2][yPos + 2] == 1) { speed = 0; }
					if (i == 4 && yPos + 3 > 0)	if (board.boardStates[xPos][yPos + 2] == 1) { speed = 0; }
					if (i == 2 && yPos + 2 > 0)	if (board.boardStates[xPos + 2][yPos + 1] == 1) { speed = 0; }
					if (i == 0 && yPos + 1 > 0)	if (board.boardStates[xPos][yPos + 1] == 1) { speed = 0; }
				}

			}
			if (r == 2 && block.shapesArrayR2[block.shapeNumber][i] == 1) {
				cout << "1";
				if (i % 2 == 1) {
					//cout << xPos + 1 << " | " << yPos + 4 << endl;
					//cout << board.boardStates[1][1] << endl;
					if (i == 15 && yPos + 4 > 0) if (board.boardStates[xPos + 3][yPos + 4] == 1) { speed = 0; }
					if (i == 13 && yPos + 4 > 0) if (board.boardStates[xPos + 1][yPos + 4] == 1) { speed = 0; }
					if (i == 11 && yPos + 3 > 0) if (board.boardStates[xPos + 3][yPos + 3] == 1) { speed = 0; }
					if (i == 9 && yPos + 3 > 0)	if (board.boardStates[xPos + 1][yPos + 3] == 1) { speed = 0; }
					if (i == 7 && yPos + 2 > 0)	if (board.boardStates[xPos + 3][yPos + 2] == 1) { speed = 0; }
					if (i == 5 && yPos + 2 > 0)	if (board.boardStates[xPos + 1][yPos + 2] == 1) { speed = 0; }
					if (i == 3 && yPos + 1 > 0)	if (board.boardStates[xPos + 3][yPos + 1] == 1) { speed = 0; }
					if (i == 1 && yPos + 1 > 0)	if (board.boardStates[xPos + 1][yPos + 1] == 1) { speed = 0; }

				}
				else if (i % 2 == 0) {
					if (i == 14 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 4] == 1) { speed = 0; }
					if (i == 12 && yPos + 4 > 0) if (board.boardStates[xPos][yPos + 4] == 1) { speed = 0; }
					if (i == 10 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 3] == 1) { speed = 0; }
					if (i == 8 && yPos + 4 > 0)	if (board.boardStates[xPos][yPos + 3] == 1) { speed = 0; }
					if (i == 6 && yPos + 4 > 0)	if (board.boardStates[xPos + 2][yPos + 2] == 1) { speed = 0; }
					if (i == 4 && yPos + 3 > 0)	if (board.boardStates[xPos][yPos + 2] == 1) { speed = 0; }
					if (i == 2 && yPos + 2 > 0)	if (board.boardStates[xPos + 2][yPos + 1] == 1) { speed = 0; }
					if (i == 0 && yPos + 1 > 0)	if (board.boardStates[xPos][yPos + 1] == 1) { speed = 0; }
				}

			}
			if (r == 3 && block.shapesArrayR3[block.shapeNumber][i] == 1) {
				cout << "1";
				if (i % 2 == 1) {
					//cout << xPos + 1 << " | " << yPos + 4 << endl;
					//cout << board.boardStates[1][1] << endl;
					if (i == 15 && yPos + 4 > 0) if (board.boardStates[xPos + 3][yPos + 4] == 1) { speed = 0; }
					if (i == 13 && yPos + 4 > 0) if (board.boardStates[xPos + 1][yPos + 4] == 1) { speed = 0; }
					if (i == 11 && yPos + 3 > 0) if (board.boardStates[xPos + 3][yPos + 3] == 1) { speed = 0; }
					if (i == 9 && yPos + 3 > 0)	if (board.boardStates[xPos + 1][yPos + 3] == 1) { speed = 0; }
					if (i == 7 && yPos + 2 > 0)	if (board.boardStates[xPos + 3][yPos + 2] == 1) { speed = 0; }
					if (i == 5 && yPos + 2 > 0)	if (board.boardStates[xPos + 1][yPos + 2] == 1) { speed = 0; }
					if (i == 3 && yPos + 1 > 0)	if (board.boardStates[xPos + 3][yPos + 1] == 1) { speed = 0; }
					if (i == 1 && yPos + 1 > 0)	if (board.boardStates[xPos + 1][yPos + 1] == 1) { speed = 0; }

				}
				else if (i % 2 == 0) {
					if (i == 14 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 4] == 1) { speed = 0; }
					if (i == 12 && yPos + 4 > 0) if (board.boardStates[xPos][yPos + 4] == 1) { speed = 0; }
					if (i == 10 && yPos + 4 > 0) if (board.boardStates[xPos + 2][yPos + 3] == 1) { speed = 0; }
					if (i == 8 && yPos + 4 > 0)	if (board.boardStates[xPos][yPos + 3] == 1) { speed = 0; }
					if (i == 6 && yPos + 4 > 0)	if (board.boardStates[xPos + 2][yPos + 2] == 1) { speed = 0; }
					if (i == 4 && yPos + 3 > 0)	if (board.boardStates[xPos][yPos + 2] == 1) { speed = 0; }
					if (i == 2 && yPos + 2 > 0)	if (board.boardStates[xPos + 2][yPos + 1] == 1) { speed = 0; }
					if (i == 0 && yPos + 1 > 0)	if (board.boardStates[xPos][yPos + 1] == 1) { speed = 0; }
				}

			}
		if (block.shapesArray[block.shapeNumber][i] == 0) cout << "0";
		}
		
		if (speed == 0) {
			for (int i = 15; i >= 0; i--) {
				if (r == 0 && block.shapesArray[block.shapeNumber][i] == 1) {
					if (i == 15) board.boardStates[xPos + 3][yPos + 3] = 1;
					if (i == 13) board.boardStates[xPos + 1][yPos + 3] = 1;
					if (i == 11) board.boardStates[xPos + 3][yPos + 2] = 1;
					if (i == 9) board.boardStates[xPos + 1][yPos + 2] = 1;
					if (i == 7) board.boardStates[xPos + 3][yPos + 1] = 1;
					if (i == 5) board.boardStates[xPos + 1][yPos + 1] = 1;
					if (i == 3) board.boardStates[xPos + 3][yPos + 0] = 1;
					if (i == 1) board.boardStates[xPos + 1][yPos + 0] = 1;
				
					if (i == 14) board.boardStates[xPos][yPos + 3] = 1;
					if (i == 12) board.boardStates[xPos][yPos + 3] = 1;
					if (i == 10) board.boardStates[xPos][yPos + 2] = 1;
					if (i == 8) board.boardStates[xPos][yPos + 2] = 1;
					if (i == 6) board.boardStates[xPos][yPos + 1] = 1;
					if (i == 4) board.boardStates[xPos][yPos + 1] = 1;
					if (i == 2) board.boardStates[xPos][yPos + 0] = 1;
					if (i == 0) board.boardStates[xPos][yPos + 0] = 1;
				}
				if (r == 1 && block.shapesArrayR1[block.shapeNumber][i] == 1) {
					if (i == 15) board.boardStates[xPos + 3][yPos + 3] = 1;
					if (i == 13) board.boardStates[xPos + 1][yPos + 3] = 1;
					if (i == 11) board.boardStates[xPos + 3][yPos + 2] = 1;
					if (i == 9) board.boardStates[xPos + 1][yPos + 2] = 1;
					if (i == 7) board.boardStates[xPos + 3][yPos + 1] = 1;
					if (i == 5) board.boardStates[xPos + 1][yPos + 1] = 1;
					if (i == 3) board.boardStates[xPos + 3][yPos + 0] = 1;
					if (i == 1) board.boardStates[xPos + 1][yPos + 0] = 1;

					if (i == 14) board.boardStates[xPos + 2][yPos + 3] = 1;
					if (i == 12) board.boardStates[xPos][yPos + 3] = 1;
					if (i == 10) board.boardStates[xPos + 2][yPos + 2] = 1;
					if (i == 8) board.boardStates[xPos][yPos + 2] = 1;
					if (i == 6) board.boardStates[xPos + 2][yPos + 1] = 1;
					if (i == 4) board.boardStates[xPos][yPos + 1] = 1;
					if (i == 2) board.boardStates[xPos + 2][yPos + 0] = 1;
					if (i == 0) board.boardStates[xPos][yPos + 0] = 1;
				}
				if (r == 2 && block.shapesArrayR2[block.shapeNumber][i] == 1) {
					if (i == 15) board.boardStates[xPos + 3][yPos + 3] = 1;
					if (i == 13) board.boardStates[xPos + 1][yPos + 3] = 1;
					if (i == 11) board.boardStates[xPos + 3][yPos + 2] = 1;
					if (i == 9) board.boardStates[xPos + 1][yPos + 2] = 1;
					if (i == 7) board.boardStates[xPos + 3][yPos + 1] = 1;
					if (i == 5) board.boardStates[xPos + 1][yPos + 1] = 1;
					if (i == 3) board.boardStates[xPos + 3][yPos + 0] = 1;
					if (i == 1) board.boardStates[xPos + 1][yPos + 0] = 1;

					if (i == 14) board.boardStates[xPos + 2][yPos + 3] = 1;
					if (i == 12) board.boardStates[xPos][yPos + 3] = 1;
					if (i == 10) board.boardStates[xPos + 2][yPos + 2] = 1;
					if (i == 8) board.boardStates[xPos][yPos + 2] = 1;
					if (i == 6) board.boardStates[xPos + 2][yPos + 1] = 1;
					if (i == 4) board.boardStates[xPos][yPos + 1] = 1;
					if (i == 2) board.boardStates[xPos + 2][yPos + 0] = 1;
					if (i == 0) board.boardStates[xPos][yPos + 0] = 1;
				}
				if (r == 3 && block.shapesArrayR3[block.shapeNumber][i] == 1) {
					if (i == 15) board.boardStates[xPos + 3][yPos + 3] = 1;
					if (i == 13) board.boardStates[xPos + 1][yPos + 3] = 1;
					if (i == 11) board.boardStates[xPos + 3][yPos + 2] = 1;
					if (i == 9) board.boardStates[xPos + 1][yPos + 2] = 1;
					if (i == 7) board.boardStates[xPos + 3][yPos + 1] = 1;
					if (i == 5) board.boardStates[xPos + 1][yPos + 1] = 1;
					if (i == 3) board.boardStates[xPos + 3][yPos + 0] = 1;
					if (i == 1) board.boardStates[xPos + 1][yPos + 0] = 1;

					if (i == 14) board.boardStates[xPos + 2][yPos + 3] = 1;
					if (i == 12) board.boardStates[xPos][yPos + 3] = 1;
					if (i == 10) board.boardStates[xPos + 2][yPos + 2] = 1;
					if (i == 8) board.boardStates[xPos][yPos + 2] = 1;
					if (i == 6) board.boardStates[xPos + 2][yPos + 1] = 1;
					if (i == 4) board.boardStates[xPos][yPos + 1] = 1;
					if (i == 2) board.boardStates[xPos + 2][yPos + 0] = 1;
					if (i == 0) board.boardStates[xPos][yPos + 0] = 1;
				}

			}
			xPos = 4;
			yPos = -4;
			n = (std::rand() % 7);
			r = 0;
			speed = 1;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		
	}
}