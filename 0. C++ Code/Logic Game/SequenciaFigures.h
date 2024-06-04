#ifndef SEQUENCIAFIGURES_H
#define SEQUENCIAFIGURES_H

#include "NodeFigura.h"
#include "Joc.h"

class SequenciaFigures
{
public:
	SequenciaFigures() : m_primera(nullptr), m_ultima(nullptr) {}
	~SequenciaFigures();
	SequenciaFigures(const SequenciaFigures& seq);

	SequenciaFigures& operator=(const SequenciaFigures& seq);

	NodeFigura* insereixNode(const Figura& node);
	void eliminaNode();
	bool isEmpty() const { return m_primera == nullptr; }

	int getNElements() const;
	Figura getPrimer() const { return m_primera->getValorFigura(); }

private:
	NodeFigura* m_primera;
	NodeFigura* m_ultima;
};

#endif // SEQUENCIAFIGURES_H