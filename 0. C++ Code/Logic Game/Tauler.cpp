#include "Tauler.h"
#include "GraphicManager.h"
#include "InfoJoc.h"
#include <iostream>
using namespace std;

Tauler::Tauler()
{
	for (int i = 0; i < NUM_MAXIM_FILES; i++)
	{
		m_tauler[i][0] = NO_COLOR;
		m_tauler[i][1] = NO_COLOR;
		m_tauler[i][NUM_MAXIM_COLUMNES + 2] = NO_COLOR;
		m_tauler[i][NUM_MAXIM_COLUMNES + 3] = NO_COLOR;
		for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
			m_tauler[i][j + 2] = COLOR_NEGRE;
	}
	for (int j = 0; j < NUM_MAXIM_COLUMNES + 4; j++)
	{
		m_tauler[NUM_MAXIM_FILES][j] = NO_COLOR;
		m_tauler[NUM_MAXIM_FILES + 1][j] = NO_COLOR;
	}
	for (int i = 0; i < NUM_MAXIM_FILES; i++)
		m_filesLliures[i] = NUM_MAXIM_COLUMNES;
}

void Tauler::inicialitzarTauler(ColorFigura taulerInicial[NUM_MAXIM_FILES][NUM_MAXIM_COLUMNES])
{
	for (int i = 0; i < NUM_MAXIM_FILES; i++)
		m_filesLliures[i] = NUM_MAXIM_COLUMNES;
	for (int i = 0; i < NUM_MAXIM_FILES; i++)
		for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
		{
			m_tauler[i][j + 2] = taulerInicial[i][j];
			if (taulerInicial[i][j] != COLOR_NEGRE)
				m_filesLliures[i]--;
		}
}

bool Tauler::comprovarColisioFigura(const Figura& figura)
{
	bool colisiona = false;
	int mascara[MAX_ALCADA_FIGURA][MAX_AMPLADA_FIGURA];

	int filaMascara = 0;
	int filaTauler = figura.getFilaFigura() - 1;
	figura.getMascaraFigura(mascara);
	do
	{
		int colMascara = 0;
		int colTauler = figura.getColumnaFigura() + 1;
		do
		{
			if ((mascara[filaMascara][colMascara] * m_tauler[filaTauler][colTauler]) != 0)
			{
				colisiona = true;
			}
			colMascara++;
			colTauler++;
		} while ((!colisiona) && (colMascara < figura.getAmpladaFigura()));

		filaMascara++;
		filaTauler++;
	} while ((!colisiona) && (filaMascara < figura.getAlcadaFigura()));

	return colisiona;
}

int Tauler::collocarFigura(const Figura& figura)
{
	int mascara[MAX_ALCADA_FIGURA][MAX_AMPLADA_FIGURA];
	int numFilesFetes = 0;

	ColorFigura color = figura.getColorFigura();
	figura.getMascaraFigura(mascara);
	int filaTauler = figura.getFilaFigura() - 1;
	for (int filaMascara = 0; filaMascara < figura.getAlcadaFigura(); filaMascara++)
	{
		int colTauler = figura.getColumnaFigura() + 1;
		for (int colMascara = 0; colMascara < figura.getAmpladaFigura(); colMascara++)
		{
			if (mascara[filaMascara][colMascara] > 0)
			{
				m_tauler[filaTauler][colTauler] = color;
				m_filesLliures[filaTauler]--;
				if (m_filesLliures[filaTauler] == 0)
				{
					numFilesFetes++;
					baixarFila(filaTauler);
				}
			}
			colTauler++;
		}
		filaTauler++;
	}
	return numFilesFetes;
}

void Tauler::dibuixarFigura(const Figura& figura)
{
	int mascara[MAX_ALCADA_FIGURA][MAX_AMPLADA_FIGURA];

	ColorFigura color = figura.getColorFigura();
	figura.getMascaraFigura(mascara);
	int filaTauler = figura.getFilaFigura() - 1;
	for (int filaMascara = 0; filaMascara < figura.getAlcadaFigura(); filaMascara++)
	{
		int colTauler = figura.getColumnaFigura() + 1;
		for (int colMascara = 0; colMascara < figura.getAmpladaFigura(); colMascara++)
		{
			if (mascara[filaMascara][colMascara] > 0)
			{
				m_tauler[filaTauler][colTauler] = color;
			}
			colTauler++;
		}
		filaTauler++;
	}
}

void Tauler::getValorsTauler(ColorFigura tauler[NUM_MAXIM_FILES][NUM_MAXIM_COLUMNES])
{
	for (int i = 0; i < NUM_MAXIM_FILES; i++)
	{
		for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
		{
			tauler[i][j] = m_tauler[i][j + 2];
		}
	}
}

void Tauler::dibuixarTauler()
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POSICIO_X_TAULER, POSICIO_Y_TAULER, false);

	for (int i = 0; i < NUM_MAXIM_FILES; i++)
	{
		for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
		{
			if (m_tauler[i][j + 2] != COLOR_NEGRE)
			{
				dibuixaQuadrat(m_tauler[i][j + 2], POSICIO_X_TAULER + ((j + 1) * MIDA_QUADRAT),
					POSICIO_Y_TAULER + (i * MIDA_QUADRAT));
			}
		}
	}
}

void Tauler::baixarFila(int fila)
{
	if (fila > 0)
	{
		for (int i = fila; i > 0; i--)
		{
			for (int j = 0; j < NUM_MAXIM_COLUMNES; j++)
			{
				m_tauler[i][j + 2] = m_tauler[i - 1][j + 2];
			}
			m_filesLliures[i] = m_filesLliures[i - 1];
		}
	}
	for (int i = 0; i < NUM_MAXIM_COLUMNES; i++)
	{
		m_tauler[0][i + 2] = COLOR_NEGRE;
	}
	m_filesLliures[0] = NUM_MAXIM_COLUMNES;
}