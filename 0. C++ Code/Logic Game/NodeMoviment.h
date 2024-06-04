// NodeMoviment.h

#include <stdlib.h>
#include "InfoJoc.h"

class NodeMoviment
{
public:
	// Constructor per defecte
	NodeMoviment() : m_seguentNode(nullptr) {}

	// Destructor
	~NodeMoviment() {}

	// Constructor amb valor inicial
	NodeMoviment(const TipusMoviment& valorInicial) : m_valorMoviment(valorInicial), m_seguentNode(nullptr) {}

	// Obt� el seg�ent node de la llista
	NodeMoviment* getSeguentNode() const { return m_seguentNode; }

	// Assigna el seg�ent node de la llista
	void setSeguentNode(NodeMoviment* nodeSeguent) { m_seguentNode = nodeSeguent; }

	// Obt� el valor del node actual
	TipusMoviment getValorMoviment() const { return m_valorMoviment; }

	// Assigna el valor del node actual
	void setValorMoviment(const TipusMoviment& valorNou) { m_valorMoviment = valorNou; }

private:
	TipusMoviment m_valorMoviment; // Valor del node actual
	NodeMoviment* m_seguentNode; // Punter al seg�ent node de la llista
};
