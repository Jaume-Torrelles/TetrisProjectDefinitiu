#include "Tetris.h"
#include "Menu.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <thread>
#include <chrono>
using namespace std;

Tetris::Tetris(const string& fitxerPuntuacions)
{
	ifstream fitxer;
	fitxer.open(fitxerPuntuacions);
	if (fitxer.is_open())
	{
		Score score;
		fitxer >> score.nom >> score.punts;
		while (!fitxer.eof())
		{
			m_leaderboard.push_back(score);
			fitxer >> score.nom >> score.punts;
		}
		fitxer.close();
	}
}

void Tetris::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Tetris::printCenteredText(const std::string& text, int line, int consoleWidth) {
	int textLength = text.length();
	int textX = (consoleWidth - textLength) / 2;
	gotoxy(textX, line);
	std::cout << text;
}

void Tetris::setConsoleColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Tetris::coutLeaderboard()
{
	increaseConsoleWindowSize();
	int consoleWidth, consoleHeight;
	getConsoleDimensions(consoleWidth, consoleHeight);

	system("cls");

	// Print ASCII art for "LEADERBOARD" in yellow
	setConsoleColor(14); // Yellow
	printCenteredText(" _                   _              _                              _ ", 1, consoleWidth);
	printCenteredText("| |                 | |            | |                            | |", 2, consoleWidth);
	printCenteredText("| |  ___   __ _   __| |  ___  _ __ | |__    ___    __ _  _ __   __| |", 3, consoleWidth);
	printCenteredText("| | / _ \\ / _` | / _` | / _ \\| '__|| '_ \\  / _ \\  / _` || '__| / _` |", 4, consoleWidth);
	printCenteredText("| ||  __/| (_| || (_| ||  __/| |   | |_) || (_) || (_| || |   | (_| |", 5, consoleWidth);
	printCenteredText("|_| \\___| \\__,_| \\__,_| \\___||_|   |_.__/  \\___/  \\__,_||_|    \\__,_|", 6, consoleWidth);

	// Calculate starting positions for column titles
	int titleX = (consoleWidth + 80) / 2; // Adjust as needed
	int titleY = 9;

	// Print column titles in white and bold
	setConsoleColor(15 | FOREGROUND_INTENSITY); // White with intensity (bold)
	printCenteredText("NICKNAME", titleY, titleX);
	printCenteredText("SCORE", titleY, titleX + 57); // Adjust as needed

	// Calculate starting positions for leaderboard data
	int dataX = (consoleWidth + 80) / 2; // Adjust as needed
	int dataY = titleY + 1;

	// Print leaderboard data
	int pos = 1;
	setConsoleColor(15); // White
	for (auto it = m_leaderboard.rbegin(); it != m_leaderboard.rend(); ++it) {
		std::string lineText = "#" + std::to_string(pos) + " " + it->nom;
		printCenteredText(lineText, dataY + pos, dataX);
		printCenteredText(std::to_string(it->punts), dataY + pos, dataX + 60); // Adjust as needed
		pos++;
	}

	setConsoleColor(15); // Reset to white
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	// Wait for "esc" key to be pressed
	char key;
	do {
		key = _getch();
	} while (key != 27); // 27 is ASCII code for "esc"

	// Clear any remaining key presses from the input buffer
	while (_kbhit())
		_getch();
}

void Tetris::saveScore(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	list<Score>::iterator actual = m_leaderboard.begin();
	while (actual != m_leaderboard.end())
	{
		fitxer << actual->nom << " " << actual->punts << endl;
		actual++;
	}
	fitxer.close();
}

void Tetris::refreshScore(const string& nom, int punts)
{
	// Buscar la posición donde se debe insertar el nuevo puntaje
	auto it = m_leaderboard.begin();
	while (it != m_leaderboard.end() && punts > it->punts) {
		++it;
	}

	// Insertar el nuevo puntaje en la posición correcta
	Score score;
	score.nom = nom;
	score.punts = punts;
	m_leaderboard.insert(it, score);
}

int Tetris::play(Screen& pantalla, ModeJoc mode, const string& nomFitxerInicial, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
	pantalla.show();

	Partida game(mode);
	game.inicialitza(nomFitxerInicial, nomFitxerFigures, nomFitxerMoviments);

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		pantalla.processEvents();

		game.actualitza(deltaTime);

		pantalla.update();
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

	int punts = game.getPuntuacio();

	return punts;
}