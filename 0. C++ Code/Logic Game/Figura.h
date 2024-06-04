#ifndef FIGURA_H
#define FIGURA_H

#include "InfoJoc.h"

// Constants per a les dimensions màximes de les figures
const int MAX_ALCADA_FIGURA = 4;
const int MAX_AMPLADA_FIGURA = 4;

// Classe que representa una figura del joc
class Figura
{
public:
	Figura()
		: tipusFigura(NO_FIGURA), colorFigura(NO_COLOR), ampladaFigura(MAX_AMPLADA_FIGURA),
		alcadaFigura(MAX_ALCADA_FIGURA), filaFigura(0), columnaFigura(0), girFigura(0)
	{
		resetForma();
	}

	// Inicialitza la figura amb el tipus, fila i columna especificats
	void inicialitza(TipusFigura nouTipusFigura, int filaInicial, int columnaInicial);

	// Gira la figura en la direcció especificada
	void gira(DireccioGir direccioGir);

	// Mou la figura en la direcció horitzontal especificada
	void mou(int direccioX);

	// Baixa la figura una fila
	void baixa();

	// Puja la figura una fila
	void puja();

	// Dibuixa la figura en la seva posició actual
	void dibuixa();

	// Getters per a les propietats de la figura
	int getFilaFigura() const { return filaFigura; }
	int getColumnaFigura() const { return columnaFigura; }
	ColorFigura getColorFigura() const { return colorFigura; }
	int getAlcadaFigura() const { return alcadaFigura; }
	int getAmpladaFigura() const { return ampladaFigura; }
	void getMascaraFigura(int mascara[MAX_ALCADA_FIGURA][MAX_AMPLADA_FIGURA]) const;
	TipusFigura getTipusFigura() const { return tipusFigura; }
	int getGirFigura() const { return girFigura; }

	// Inline setters for the properties of the figure
	void setFilaFigura(int fila) { filaFigura = fila; }
	void setColumnaFigura(int columna) { columnaFigura = columna; }
	void setColorFigura(ColorFigura color) { colorFigura = color; }
	void setAlcadaFigura(int alcada) { alcadaFigura = alcada; }
	void setAmpladaFigura(int amplada) { ampladaFigura = amplada; }
	void setTipusFigura(TipusFigura tipus) { tipusFigura = tipus; }
	void setGirFigura(int gir) { girFigura = gir; }

private:
	TipusFigura tipusFigura; // Tipus de la figura
	ColorFigura colorFigura; // Color de la figura
	int ampladaFigura; // Amplada de la figura
	int alcadaFigura; // Alçada de la figura
	int mascaraFigura[MAX_ALCADA_FIGURA][MAX_AMPLADA_FIGURA]; // Màscara de la figura
	int filaFigura; // Fila de la figura
	int columnaFigura; // Columna de la figura
	int girFigura; // Grau de gir de la figura

	// Reinicialitza la forma de la figura
	void resetForma();

	// Inicialitza la forma de la figura segons el tipus especificat
	void inicialitzaForma(TipusFigura tipus);

	// Transposa la màscara de la figura
	void transposaMascara();

	// Inverteix la màscara de la figura horitzontalment
	void inverteixMascaraHorizontal();

	// Inverteix la màscara de la figura verticalment
	void inverteixMascaraVertical();
};

#endif