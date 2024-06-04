#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include "SequenciaFigures.h"
#include "SequenciaMoviments.h"
#include "GraphicManager.h"
#include <fstream>
#include <ctime>

using namespace std;

// Enumeraci� que defineix els modes de joc
enum class ModeJoc
{
	MODE_NORMAL = 0,
	MODE_TEST
};

// Constantes per als punts i els increments de puntuaci�
const int PUNTS_PER_FIGURA = 10;
const int PUNTS_PER_FILA_X1 = 100;
const int PUNTS_PER_FILA_X2 = 50;
const int PUNTS_PER_FILA_X3 = 75;
const int PUNTS_PER_FILA_X4 = 100;
const int CANVI_NIVELL = 200;
const double VELOCITAT_INICIAL = 1.0;
const double INCREMENT_VELOCITAT = 0.75;

class Partida
{
public:
	// Constructor per defecte
	Partida() : m_mode(ModeJoc::MODE_NORMAL), m_temps(0.0), m_puntuacio(0), m_nivell(1), m_velocitat(VELOCITAT_INICIAL), m_isFinalJoc(false)
	{
		srand(time(0)); // Inicialitzaci� de la llavor per a la generaci� de nombres aleatoris
	}

	// Constructor amb par�metre ModeJoc
	Partida(ModeJoc mode) : m_mode(mode), m_temps(0.0), m_puntuacio(0), m_nivell(1), m_velocitat(VELOCITAT_INICIAL), m_isFinalJoc(false)
	{
		srand(time(0)); // Inicialitzaci� de la llavor per a la generaci� de nombres aleatoris
	}

	// Inicialitza la partida amb els fitxers proporcionats
	void inicialitza(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);

	// Actualitza l'estat de la partida amb el temps transcorregut
	void actualitza(double deltaTime);

	// Retorna la puntuaci� actual de la partida
	int getPuntuacio() const { return m_puntuacio; }

private:
	// Inicialitza la sequ�ncia de figures a partir del fitxer proporcionat
	void inicialitzaFigures(const string& fitxer);

	// Inicialitza la sequ�ncia de moviments a partir del fitxer proporcionat
	void inicialitzaMoviments(const string& fitxer);

	// Actualitza la puntuaci� de la partida basada en el nombre de files eliminades
	void actualitzaPuntuacio(int filesEliminades);

	// Actualitza l'estat de la partida en el mode de joc normal
	void actualitzaModeNormal(double deltaTime);

	// Actualitza l'estat de la partida en el mode de joc de prova
	void actualitzaModeTest(float deltaTime);

	double m_temps; // Temps transcorregut des de l'�ltima actualitzaci�
	Joc m_joc; // Inst�ncia del joc Tetris
	ModeJoc m_mode; // Mode de joc actual
	int m_puntuacio; // Puntuaci� acumulada de la partida
	int m_nivell; // Nivell actual de la partida
	double m_velocitat; // Velocitat de caiguda de les peces
	bool m_isFinalJoc; // Indica si la partida ha acabat
	SequenciaFigures m_figures; // Sequ�ncia de figures per al mode de joc de prova
	SequenciaMoviments m_moviments; // Sequ�ncia de moviments per al mode de joc de prova
};

#endif
