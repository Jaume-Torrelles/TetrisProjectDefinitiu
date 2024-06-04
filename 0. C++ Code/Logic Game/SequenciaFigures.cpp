#include "SequenciaFigures.h"

SequenciaFigures::~SequenciaFigures()
{
	while (!isEmpty())
	{
		eliminaNode();
	}
}

SequenciaFigures::SequenciaFigures(const SequenciaFigures& seq)
{
	m_primera = nullptr;
	m_ultima = nullptr;
	NodeFigura* aux = seq.m_primera;
	while (aux != nullptr)
	{
		insereixNode(aux->getValorFigura());
		aux = aux->getSeguentNode();
	}
}

SequenciaFigures& SequenciaFigures::operator=(const SequenciaFigures& seq)
{
	if (this != &seq)
	{
		while (!isEmpty())
		{
			eliminaNode();
		}
		NodeFigura* aux = seq.m_primera;
		while (aux != nullptr)
		{
			insereixNode(aux->getValorFigura());
			aux = aux->getSeguentNode();
		}
	}
	return *this;
}

NodeFigura* SequenciaFigures::insereixNode(const Figura& figura)
{
	NodeFigura* aux = new NodeFigura(figura);
	if (aux != nullptr)
	{
		if (m_primera == nullptr)
		{
			m_primera = aux;
		}
		else
		{
			m_ultima->setSeguentNode(aux);
		}
		m_ultima = aux;
	}
	return aux;
}

void SequenciaFigures::eliminaNode()
{
	if (m_primera == nullptr)
	{
		return;
	}

	NodeFigura* aux = m_primera;
	if (m_primera == m_ultima)
	{
		m_primera = nullptr;
		m_ultima = nullptr;
	}
	else
	{
		m_primera = m_primera->getSeguentNode();
	}
	delete aux;
}

int SequenciaFigures::getNElements() const
{
	int nElements = 0;
	NodeFigura* aux = m_primera;
	while (aux != nullptr)
	{
		nElements++;
		aux = aux->getSeguentNode();
	}
	return nElements;
}