#ifndef INFO_JOC_H
#define INFO_JOC_H

// Constants generals del joc
const int NUM_TIPUS_FIGURES = 7;

// Enumeració dels colors de les figures del joc
typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;

// Enumeració dels diferents tipus de figures del joc
typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;

// Enumeració de les direccions de gir de les figures
typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

// Enumeració dels diferents tipus de moviments que poden fer les figures
typedef enum
{
	MOVIMENT_ESQUERRA = 0,
	MOVIMENT_DRETA,
	MOVIMENT_GIR_HORARI,
	MOVIMENT_GIR_ANTI_HORARI,
	MOVIMENT_BAIXA,
	MOVIMENT_BAIXA_FINAL
} TipusMoviment;

// Constants de configuració de la pantalla
const int AMPLADA_PANTALLA = 600;
const int ALCADA_PANTALLA = 700;
const int MIDA_QUADRAT = 26;

// Constants de configuració del tauler de joc
const int NUM_FILES_TAULER = 21;
const int NUM_COLUMNES_TAULER = 11;

const int POSICIO_X_TAULER = 120;
const int POSICIO_Y_TAULER = 100;

// Constants de configuració de la puntuació i nivell
const int POSICIO_X_PUNTUACIO = 120;
const int POSICIO_Y_PUNTUACIO = 50;

const int POSICIO_X_NIVELL = 300;
const int POSICIO_Y_NIVELL = 50;

// Constants per a la posició del missatge de final de joc
const int POSICIO_X_FINAL_JOC = 120;
const int POSICIO_Y_FINAL_JOC = 300;

// Funció per a dibuixar un quadrat de color en una posició específica
void dibuixaQuadrat(ColorFigura color, int posX, int posY);

#endif
