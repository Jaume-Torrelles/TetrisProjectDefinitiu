#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)
#define SDL_MAIN_HANDLED
#include <windows.h>
#include <iostream>
#include <conio.h>
#endif

#include <SDL.h>
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include "Partida.h"
#include "InfoJoc.h"
#include "Tetris.h"
#include "Menu.h"

using namespace std;

void llegeixNomFitxers(string& nomInicial, string& nomFigures, string& nomMoviments) {
	int consoleWidth = 80; // Assuming console width of 80 characters, adjust as needed

	// Read the first filename
	system("cls");
	cout << endl;
	printCenteredText("Nom del fitxer amb l'estat inicial del tauler: ", 10, consoleWidth);
	cout << endl;
	printCenteredText("", 10, consoleWidth + strlen("Nom del fitxer amb l'estat inicial del tauler: ")); // Adjust the padding as needed
	getline(cin, nomInicial);
	nomInicial = "./data/Games/" + nomInicial;

	// Read the second filename
	cout << endl;
	printCenteredText("Nom del fitxer amb la sequencia de figures: ", 12, consoleWidth);
	cout << endl;
	printCenteredText("", 12, consoleWidth + strlen("Nom del fitxer amb la sequencia de figures: ")); // Adjust the padding as needed
	getline(cin, nomFigures);
	nomFigures = "./data/Games/" + nomFigures;

	// Read the third filename
	cout << endl;
	printCenteredText("Nom del fitxer amb la sequencia de moviments: ", 14, consoleWidth);
	cout << endl;
	printCenteredText("", 14, consoleWidth + strlen("Nom del fitxer amb la sequencia de moviments: ")); // Adjust the padding as needed
	getline(cin, nomMoviments);
	nomMoviments = "./data/Games/" + nomMoviments;
	system("cls");
}

int main(int argc, char* argv[])
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	Screen pantalla(AMPLADA_PANTALLA, ALCADA_PANTALLA);

	Tetris tetris("./data/Games/puntuacions.txt");
	bool sortir = false;
	string nomInicial, nomFigures, nomMoviments, nomJugador;
	int punts;
	int consoleWidth = 150;

	do {
		int selectedOption = handleMenu();
		switch (selectedOption) {
		case 0: // Play

			system("cls");
			cout << endl;

			printCenteredText("Nickname: ", 14, consoleWidth - 33);
			cout << endl;
			printCenteredText("", 14, consoleWidth - 33 + strlen("Nickname: ")); // Adjust the padding as needed
			getline(cin, nomJugador);

			system("cls");
			punts = tetris.play(pantalla, ModeJoc::MODE_NORMAL, "", "", "");
			tetris.refreshScore(nomJugador, punts);
			break;
		case 1: // Test
			system("cls");
			Sleep(500);
			llegeixNomFitxers(nomInicial, nomFigures, nomMoviments);
			punts = tetris.play(pantalla, ModeJoc::MODE_TEST, nomInicial, nomFigures, nomMoviments);
			break;
		case 2: // Leaderboard
			tetris.coutLeaderboard();
			break;
		case 3: // Exit
			sortir = true;
			exitAction(); // Display exit animation
			break;
		default:
			cout << "ERROR!" << endl;
		}
	} while (!sortir);

	tetris.saveScore("./data/Games/puntuacions.txt");

	SDL_Quit();

	return 0;
}