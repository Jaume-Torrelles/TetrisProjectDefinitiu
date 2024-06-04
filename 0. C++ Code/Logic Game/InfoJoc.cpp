// InfoJoc.cpp

#include "InfoJoc.h"
#include "GraphicManager.h"

// Dibuixa un quadrat de la figura en una posició específica
void dibuixaQuadrat(ColorFigura colorFigura, int posicioX, int posicioY)
{
	IMAGE_NAME nomGrafic;

	// Assigna el nom del gràfic segons el color de la figura
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
		return; // Si el color és invàlid, no es dibuixa res
	}

	// Dibuixa el gràfic del quadrat en la posició especificada
	GraphicManager::getInstance()->drawSprite(nomGrafic, posicioX, posicioY, false);
}