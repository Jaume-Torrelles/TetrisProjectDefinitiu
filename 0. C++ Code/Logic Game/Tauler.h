#ifndef TAULER_H
#define TAULER_H

#include "Figura.h"

// Constants per a les dimensions del tauler
const int NUM_MAXIM_FILES = 21;
const int NUM_MAXIM_COLUMNES = 11;

class Tauler
{
public:
	// Constructor per defecte
	Tauler();

	// Inicialitza el tauler amb els colors inicials
	void inicialitzarTauler(ColorFigura taulerInicial[NUM_MAXIM_FILES][NUM_MAXIM_COLUMNES]);

	// Comprova si una figura col·lisiona amb altres figures o els límits del tauler
	bool comprovarColisioFigura(const Figura& figura);

	// Col·loca una figura en el tauler i retorna el nombre de files completades
	int collocarFigura(const Figura& figura);

	// Dibuixa una figura en la seva posició actual
	void dibuixarFigura(const Figura& figura);

	// Obté els valors del tauler actual
	void getValorsTauler(ColorFigura tauler[NUM_MAXIM_FILES][NUM_MAXIM_COLUMNES]);

	// Dibuixa el tauler actual
	void dibuixarTauler();

private:
	ColorFigura m_tauler[NUM_MAXIM_FILES + 2][NUM_MAXIM_COLUMNES + 4]; // Matriu del tauler amb espai extra per límits
	int m_filesLliures[NUM_MAXIM_FILES]; // Nombre de files lliures en cada fila del tauler

	// Baixa una fila després de completar-la
	void baixarFila(int fila);
};

#endif
