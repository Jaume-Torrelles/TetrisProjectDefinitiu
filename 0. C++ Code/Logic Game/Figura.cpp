#include "Figura.h"

// Reinicialitza la màscara de la figura a zeros
void Figura::resetForma()
{
	for (int i = 0; i < alcadaFigura; i++)
		for (int j = 0; j < ampladaFigura; j++)
			mascaraFigura[i][j] = 0;
}

// Inicialitza la màscara de la figura segons el tipus especificat
void Figura::inicialitzaForma(TipusFigura tipusFigura)
{
	switch (tipusFigura)
	{
	case FIGURA_J:
		ampladaFigura = 3;
		alcadaFigura = 3;
		resetForma();
		mascaraFigura[0][0] = 1;
		mascaraFigura[1][0] = 1;
		mascaraFigura[1][1] = 1;
		mascaraFigura[1][2] = 1;
		colorFigura = COLOR_BLAUFOSC;
		break;
	case FIGURA_L:
		ampladaFigura = 3;
		alcadaFigura = 3;
		resetForma();
		mascaraFigura[0][2] = 1;
		mascaraFigura[1][0] = 1;
		mascaraFigura[1][1] = 1;
		mascaraFigura[1][2] = 1;
		colorFigura = COLOR_TARONJA;
		break;
	case FIGURA_S:
		ampladaFigura = 3;
		alcadaFigura = 3;
		resetForma();
		mascaraFigura[0][1] = 1;
		mascaraFigura[0][2] = 1;
		mascaraFigura[1][0] = 1;
		mascaraFigura[1][1] = 1;
		colorFigura = COLOR_VERD;
		break;
	case FIGURA_Z:
		ampladaFigura = 3;
		alcadaFigura = 3;
		resetForma();
		mascaraFigura[0][0] = 1;
		mascaraFigura[0][1] = 1;
		mascaraFigura[1][1] = 1;
		mascaraFigura[1][2] = 1;
		colorFigura = COLOR_VERMELL;
		break;
	case FIGURA_T:
		ampladaFigura = 3;
		alcadaFigura = 3;
		resetForma();
		mascaraFigura[0][1] = 1;
		mascaraFigura[1][0] = 1;
		mascaraFigura[1][1] = 1;
		mascaraFigura[1][2] = 1;
		colorFigura = COLOR_MAGENTA;
		break;
	case FIGURA_I:
		ampladaFigura = 4;
		alcadaFigura = 4;
		resetForma();
		mascaraFigura[1][0] = 1;
		mascaraFigura[1][1] = 1;
		mascaraFigura[1][2] = 1;
		mascaraFigura[1][3] = 1;
		colorFigura = COLOR_BLAUCEL;
		break;
	case FIGURA_O:
		ampladaFigura = 2;
		alcadaFigura = 2;
		resetForma();
		mascaraFigura[0][0] = 1;
		mascaraFigura[0][1] = 1;
		mascaraFigura[1][0] = 1;
		mascaraFigura[1][1] = 1;
		colorFigura = COLOR_GROC;
		break;
	}
}

// Inicialitza la figura amb el tipus, fila i columna especificats
void Figura::inicialitza(TipusFigura tipusFigura, int filaInicial, int columnaInicial)
{
	this->tipusFigura = tipusFigura;
	filaFigura = filaInicial;
	columnaFigura = columnaInicial;
	girFigura = 0;
	inicialitzaForma(tipusFigura);
}

// Obté la màscara de la figura
void Figura::getMascaraFigura(int mascara[MAX_ALCADA_FIGURA][MAX_AMPLADA_FIGURA]) const
{
	for (int i = 0; i < alcadaFigura; i++)
		for (int j = 0; j < ampladaFigura; j++)
			mascara[i][j] = this->mascaraFigura[i][j];
}

// Mou la figura en la direcció horitzontal especificada
void Figura::mou(int direccioX)
{
	columnaFigura += direccioX;
}

// Baixa la figura una fila
void Figura::baixa()
{
	filaFigura += 1;
}

// Puja la figura una fila
void Figura::puja()
{
	filaFigura -= 1;
}

// Gira la figura en la direcció especificada
void Figura::gira(DireccioGir direccioGir)
{
	transposaMascara();
	if (direccioGir == GIR_HORARI)
	{
		inverteixMascaraVertical();
		girFigura = (girFigura + 1) % 4;
	}
	else
	{
		inverteixMascaraHorizontal();
		girFigura = (girFigura - 1) % 4;
	}
}

// Transposa la màscara de la figura
void Figura::transposaMascara()
{
	int auxiliar;
	for (int i = 1; i < alcadaFigura; i++)
		for (int j = 0; j < i; j++)
		{
			auxiliar = mascaraFigura[i][j];
			mascaraFigura[i][j] = mascaraFigura[j][i];
			mascaraFigura[j][i] = auxiliar;
		}
}

// Inverteix la màscara de la figura verticalment
void Figura::inverteixMascaraVertical()
{
	int columnaEsquerra, columnaDreta;
	if (ampladaFigura != 2)
	{
		if (ampladaFigura == 3)
		{
			columnaEsquerra = 0;
			columnaDreta = 2;
		}
		else
		{
			columnaEsquerra = 1;
			columnaDreta = 2;
		}
		int auxiliar;
		for (int i = 0; i < alcadaFigura; i++)
		{
			auxiliar = mascaraFigura[i][columnaEsquerra];
			mascaraFigura[i][columnaEsquerra] = mascaraFigura[i][columnaDreta];
			mascaraFigura[i][columnaDreta] = auxiliar;
		}
	}
}

// Inverteix la màscara de la figura horitzontalment
void Figura::inverteixMascaraHorizontal()
{
	int filaSuperior, filaInferior;
	if (alcadaFigura != 2)
	{
		if (alcadaFigura == 3)
		{
			filaSuperior = 0;
			filaInferior = 2;
		}
		else
		{
			filaSuperior = 1;
			filaInferior = 2;
		}
		int auxiliar;
		for (int i = 0; i < ampladaFigura; i++)
		{
			auxiliar = mascaraFigura[filaSuperior][i];
			mascaraFigura[filaSuperior][i] = mascaraFigura[filaInferior][i];
			mascaraFigura[filaInferior][i] = auxiliar;
		}
	}
}

// Dibuixa la figura en la seva posició actual
void Figura::dibuixa()
{
	for (int i = 0; i < alcadaFigura; i++)
		for (int j = 0; j < ampladaFigura; j++)
		{
			if (mascaraFigura[i][j] != 0)
				dibuixaQuadrat(colorFigura, POSICIO_X_TAULER + ((columnaFigura + j) * MIDA_QUADRAT),
					POSICIO_Y_TAULER + ((filaFigura - 1 + i) * MIDA_QUADRAT));
		}
}