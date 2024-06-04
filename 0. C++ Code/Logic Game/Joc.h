#ifndef JOC_H
#define JOC_H

#include "Tauler.h"
#include "Figura.h"
#include <string>

using namespace std;

// Classe que representa el joc de Tetris
class Joc
{
public:
	// Constructor per defecte
	Joc() {}

	// Inicialitza el joc amb les dades del fitxer especificat
	void inicialitza(const string& nomFitxerConfiguracio);

	// Crea una nova figura aleatòria i la col·loca en el tauler
	bool creaNovaFiguraAleatoria();

	// Col·loca una nova figura especificada en el tauler
	void creaNovaFigura(Figura novaFigura);

	// Gira la figura actual en la direcció especificada
	bool giraFiguraActual(DireccioGir direccioGir);

	// Mou la figura actual en la direcció horitzontal especificada
	bool mouFiguraActual(int direccioX);

	// Baixa la figura actual una fila
	int baixaFiguraActual();

	// Col·loca la figura actual en la seva posició final
	int colocaFiguraActual();

	// Escriu l'estat actual del tauler en el fitxer especificat
	void escriuEstatTauler(const string& nomFitxerSortida);

	// Dibuixa l'estat actual del joc en la pantalla
	void dibuixaJoc();

private:
	Tauler taulerJoc;            // El tauler del joc
	Figura figuraEnJoc;          // La figura actual en joc
};

#endif // JOC_H
