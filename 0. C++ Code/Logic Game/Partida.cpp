#include "Partida.h"

void Partida::inicialitza(const string& nomFitxerInicial, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
	// Inicialitza la partida segons el mode de joc
	if (m_mode == ModeJoc::MODE_NORMAL)
	{
		m_isFinalJoc = m_joc.creaNovaFiguraAleatoria();
	}
	else
	{
		m_joc.inicialitza(nomFitxerInicial);
		inicialitzaFigures(nomFitxerFigures);
		inicialitzaMoviments(nomFitxerMoviments);
	}
}

void Partida::actualitza(double deltaTime)
{
	// Actualitza l'estat de la partida si no ha acabat
	if (!m_isFinalJoc)
	{
		if (m_mode == ModeJoc::MODE_NORMAL)
		{
			actualitzaModeNormal(deltaTime);
		}
		else
		{
			actualitzaModeTest(deltaTime);
		}
	}

	// Dibuixa els elements gràfics de la partida
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 400, 0, false);
	m_joc.dibuixaJoc();
	string punts = "Score: " + to_string(m_puntuacio);
	string nivell = "Level: " + to_string(m_nivell);
	string novaFigura = "Next:";
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POSICIO_X_TAULER - 280, POSICIO_Y_TAULER + 80, 0.9, novaFigura);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POSICIO_X_PUNTUACIO, POSICIO_Y_PUNTUACIO, 0.7, punts);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POSICIO_X_NIVELL, POSICIO_Y_NIVELL, 0.7, nivell);
	if (m_isFinalJoc)
	{
		string gameOver = "GAME OVER";
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POSICIO_Y_FINAL_JOC, POSICIO_Y_FINAL_JOC, 1.5, gameOver);
	}
}

void Partida::inicialitzaFigures(const string& fitxer)
{
	ifstream fitxerLectura;
	fitxerLectura.open(fitxer);
	if (fitxerLectura.is_open())
	{
		Figura figura;
		int tipus, fila, columna, gir;
		fitxerLectura >> tipus >> fila >> columna >> gir;
		figura.setTipusFigura(TipusFigura(tipus));
		figura.setFilaFigura(fila);
		figura.setColumnaFigura(columna);
		figura.setGirFigura(gir);
		while (!fitxerLectura.eof())
		{
			m_figures.insereixNode(figura);
			fitxerLectura >> tipus >> fila >> columna >> gir;
			figura.setTipusFigura(TipusFigura(tipus));
			figura.setFilaFigura(fila);
			figura.setColumnaFigura(columna);
			figura.setGirFigura(gir);
		}
		fitxerLectura.close();
	}
}

void Partida::inicialitzaMoviments(const string& fitxer)
{
	ifstream fitxerLectura;
	fitxerLectura.open(fitxer);
	if (fitxerLectura.is_open())
	{
		int tipus;
		fitxerLectura >> tipus;
		while (!fitxerLectura.eof())
		{
			m_moviments.insereixNode(TipusMoviment(tipus));
			fitxerLectura >> tipus;
		}
		fitxerLectura.close();
	}
}

void Partida::actualitzaPuntuacio(int nFilesEliminades)
{
	if (nFilesEliminades == 0)
	{
		m_puntuacio += PUNTS_PER_FIGURA;
	}
	else
	{
		m_puntuacio += PUNTS_PER_FILA_X1;
		switch (nFilesEliminades)
		{
		case 2:
			m_puntuacio += PUNTS_PER_FILA_X2;
			break;
		case 3:
			m_puntuacio += PUNTS_PER_FILA_X3;
			break;
		case 4:
			m_puntuacio += PUNTS_PER_FILA_X4;
			break;
		}
	}
	if (m_puntuacio > (m_nivell * CANVI_NIVELL))
	{
		m_nivell += 1;
		m_velocitat *= INCREMENT_VELOCITAT;
	}
}

void Partida::actualitzaModeNormal(double deltaTime)
{
	// Mou la figura lateralment
	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
	{
		m_joc.mouFiguraActual(1);
	}
	else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
	{
		m_joc.mouFiguraActual(-1);
	}

	// Girs de la figura
	if (Keyboard_GetKeyTrg(KEYBOARD_UP))
	{
		m_joc.giraFiguraActual(GIR_HORARI);
	}
	else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
	{
		m_joc.giraFiguraActual(GIR_ANTI_HORARI);
	}
	// Baixa la figura fins al final
	int nFilesEliminades;
	if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
	{
		nFilesEliminades = m_joc.colocaFiguraActual();
		actualitzaPuntuacio(nFilesEliminades);
		m_isFinalJoc = m_joc.creaNovaFiguraAleatoria();
		m_temps = 0.0;
	}
	else
	{
		m_temps += deltaTime;
		if (m_temps > m_velocitat)
		{
			nFilesEliminades = m_joc.baixaFiguraActual();
			if (nFilesEliminades != -1)
			{
				m_isFinalJoc = m_joc.creaNovaFiguraAleatoria();
				actualitzaPuntuacio(nFilesEliminades);
			}
			m_temps = 0.0;
		}
	}
}

void Partida::actualitzaModeTest(float deltaTime)
{
	m_temps += deltaTime;
	if (m_temps > m_velocitat)
	{
		m_temps = 0.0;
		TipusMoviment moviment;
		if (m_moviments.esBuida())
		{
			m_isFinalJoc = true;
		}
		else
		{
			moviment = m_moviments.getPrimer();
			m_moviments.eliminaNode();
			int nFilesEliminades;
			switch (moviment)
			{
			case MOVIMENT_DRETA:
				m_joc.mouFiguraActual(1);
				break;
			case MOVIMENT_ESQUERRA:
				m_joc.mouFiguraActual(-1);
				break;
			case MOVIMENT_GIR_HORARI:
				m_joc.giraFiguraActual(GIR_HORARI);
				break;
			case MOVIMENT_GIR_ANTI_HORARI:
				m_joc.giraFiguraActual(GIR_ANTI_HORARI);
				break;
			case MOVIMENT_BAIXA_FINAL:
				nFilesEliminades = m_joc.colocaFiguraActual();
				actualitzaPuntuacio(nFilesEliminades);
				if (!m_figures.isEmpty())
				{
					Figura figura = m_figures.getPrimer();
					m_figures.eliminaNode();
					m_joc.creaNovaFigura(figura);
				}
				else
					m_isFinalJoc = true;
				break;
			case MOVIMENT_BAIXA:
				nFilesEliminades = m_joc.baixaFiguraActual();
				if (nFilesEliminades != -1)
				{
					actualitzaPuntuacio(nFilesEliminades);
					if (!m_figures.isEmpty())
					{
						Figura figura = m_figures.getPrimer();
						m_figures.eliminaNode();
						m_joc.creaNovaFigura(figura);
					}
					else
						m_isFinalJoc = true;
				}
			}
		}
	}
}