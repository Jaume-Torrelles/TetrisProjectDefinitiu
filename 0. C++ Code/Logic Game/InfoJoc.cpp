// InfoJoc.cpp

#include "InfoJoc.h"
#include "GraphicManager.h"

// Dibuixa un quadrat de la figura en una posici� espec�fica
void dibuixaQuadrat(ColorFigura colorFigura, int posicioX, int posicioY)
{
	IMAGE_NAME nomGrafic;

	// Assigna el nom del gr�fic segons el color de la figura
	switch (colorFigura)
	{
	case COLOR_GROC:
		nomGrafic = GRAFIC_QUADRAT_GROC;
		break;
	case COLOR_BLAUCEL:
		nomGrafic = GRAFIC_QUADRAT_BLAUCEL;
		break;
	case COLOR_MAGENTA:
		nomGrafic = GRAFIC_QUADRAT_MAGENTA;
		break;
	case COLOR_TARONJA:
		nomGrafic = GRAFIC_QUADRAT_TARONJA;
		break;
	case COLOR_BLAUFOSC:
		nomGrafic = GRAFIC_QUADRAT_BLAUFOSC;
		break;
	case COLOR_VERMELL:
		nomGrafic = GRAFIC_QUADRAT_VERMELL;
		break;
	case COLOR_VERD:
		nomGrafic = GRAFIC_QUADRAT_VERD;
		break;
	default:
		return; // Si el color �s inv�lid, no es dibuixa res
	}

	// Dibuixa el gr�fic del quadrat en la posici� especificada
	GraphicManager::getInstance()->drawSprite(nomGrafic, posicioX, posicioY, false);
}