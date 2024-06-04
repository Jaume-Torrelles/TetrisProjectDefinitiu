#ifndef TETRIS_H
#define TETRIS_H

#include "Partida.h"
#include <list>
#include <string>
using namespace std;

// Definicio necessaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
// Llibreria grafica
#include "../Graphic Lib/libreria.h"

typedef struct
{
	string nom;
	int punts;
} Score;

class Tetris
{
public:
	Tetris(const string& fitxerPuntuacions);
	int play(Screen& pantalla, ModeJoc mode, const string& nomFitxerInicial, const string& nomFitxerFigures, const string& nomFitxerMoviments);
	void refreshScore(const string& nom, int punts);
	void coutLeaderboard();
	void saveScore(const string& nomFitxer);

private:
	Partida m_partida;
	list<Score> m_leaderboard;

	void gotoxy(int x, int y);
	void printCenteredText(const std::string& text, int line, int consoleWidth);
	void setConsoleColor(int color);
};

#endif
