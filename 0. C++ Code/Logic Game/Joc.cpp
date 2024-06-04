// Joc.cpp

#include "Joc.h"
#include <fstream>
using namespace std;

// Genera una nova figura aleatòria i la col·loca en el tauler
bool Joc::creaNovaFiguraAleatoria()
{
	// Selecciona un tipus de figura aleatòriament
	TipusFigura tipusFigura = TipusFigura((rand() % NUM_TIPUS_FIGURES) + 1);
	int columnaMaxima = NUM_COLUMNES_TAULER - 2;

	// Ajusta la columna màxima segons el tipus de figura
	if (tipusFigura == FIGURA_O)
		columnaMaxima = NUM_COLUMNES_TAULER - 1;
	else if (tipusFigura == FIGURA_I)
		columnaMaxima = NUM_COLUMNES_TAULER - 3;

	// Selecciona una columna inicial aleatòriament
	int columnaInicial = (rand() % columnaMaxima) + 1;

	// Selecciona un nombre de girs inicials aleatòriament
	int nombreGirsInicials = (rand() % 4);

	// Inicialitza la figura amb el tipus i posició seleccionats
	figuraEnJoc.inicialitza(tipusFigura, 1, columnaInicial);

	// Gira la figura el nombre de vegades seleccionat
	for (int i = 0; i < nombreGirsInicials; i++)
		figuraEnJoc.gira(GIR_HORARI);

	// Comprova si la nova figura col·lisiona amb alguna existent
	bool colisiona = taulerJoc.comprovarColisioFigura(figuraEnJoc);
	return colisiona;
}

// Col·loca una nova figura especificada en el tauler
void Joc::creaNovaFigura(Figura novaFigura)
{
	figuraEnJoc.inicialitza(novaFigura.getTipusFigura(), novaFigura.getFilaFigura(), novaFigura.getColumnaFigura());
	for (int i = 0; i < novaFigura.getGirFigura(); i++)
		figuraEnJoc.gira(GIR_HORARI);
}

// Inicialitza el joc amb les dades del fitxer especificat
void Joc::inicialitza(const string& nomFitxerConfiguracio)
{
	ifstream fitxerConfiguracio;
	fitxerConfiguracio.open(nomFitxerConfiguracio);

	if (fitxerConfiguracio.is_open())
	{
		int tipus, fila, columna, gir;
		fitxerConfiguracio >> tipus >> fila >> columna >> gir;
		figuraEnJoc.inicialitza(TipusFigura(tipus), fila, columna);

		for (int i = 0; i < gir; i++)
			figuraEnJoc.gira(GIR_HORARI);

		ColorFigura taulerInicial[NUM_MAXIM_FILES][NUM_MAXIM_COLUMNES];
		int color;

		// Llegeix l'estat inicial del tauler des del fitxer
		for (int i = 0; i < NUM_MAXIM_FILES; i++)
			for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
			{
				fitxerConfiguracio >> color;
				taulerInicial[i][j] = ColorFigura(color);
			}

		taulerJoc.inicialitzarTauler(taulerInicial);
		fitxerConfiguracio.close();
	}
}

// Gira la figura actual en la direcció especificada
bool Joc::giraFiguraActual(DireccioGir direccioGir)
{
	figuraEnJoc.gira(direccioGir);
	bool colisiona = taulerJoc.comprovarColisioFigura(figuraEnJoc);

	if (colisiona)
	{
		// Desfà el gir si hi ha col·lisió
		if (direccioGir == GIR_HORARI)
			direccioGir = GIR_ANTI_HORARI;
		else
			direccioGir = GIR_HORARI;

		figuraEnJoc.gira(direccioGir);
	}

	return !colisiona;
}

// Mou la figura actual en la direcció horitzontal especificada
bool Joc::mouFiguraActual(int direccioX)
{
	figuraEnJoc.mou(direccioX);
	bool colisiona = taulerJoc.comprovarColisioFigura(figuraEnJoc);

	if (colisiona)
		figuraEnJoc.mou(-direccioX);

	return !colisiona;
}

// Baixa la figura actual una fila
int Joc::baixaFiguraActual()
{
	int nombreFiles = -1;
	figuraEnJoc.baixa();

	if (taulerJoc.comprovarColisioFigura(figuraEnJoc))
	{
		nombreFiles = 0;
		figuraEnJoc.puja();
		nombreFiles = taulerJoc.collocarFigura(figuraEnJoc);
	}

	return nombreFiles;
}

// Col·loca la figura actual en la seva posició final
int Joc::colocaFiguraActual()
{
	int nombreFiles;

	do
	{
		nombreFiles = baixaFiguraActual();
	} while (nombreFiles == -1);

	return nombreFiles;
}

// Escriu l'estat actual del tauler en el fitxer especificat
void Joc::escriuEstatTauler(const string& nomFitxerSortida)
{
	ofstream fitxerSortida;
	fitxerSortida.open(nomFitxerSortida);

	if (fitxerSortida.is_open())
	{
		if (figuraEnJoc.getTipusFigura() != NO_FIGURA)
			taulerJoc.dibuixarFigura(figuraEnJoc);

		ColorFigura estatTauler[NUM_MAXIM_FILES][NUM_MAXIM_COLUMNES];
		taulerJoc.getValorsTauler(estatTauler);

		for (int i = 0; i < NUM_MAXIM_FILES; i++)
		{
			for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
			{
				fitxerSortida << int(estatTauler[i][j]) << " ";
			}
			fitxerSortida << endl;
		}

		fitxerSortida.close();
	}
}

// Dibuixa l'estat actual del joc en la pantalla
void Joc::dibuixaJoc()
{
	taulerJoc.dibuixarTauler();
	figuraEnJoc.dibuixa();
}