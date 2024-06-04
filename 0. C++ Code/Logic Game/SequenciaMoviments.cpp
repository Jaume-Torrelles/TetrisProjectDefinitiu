#include "SequenciaMoviments.h"

SequenciaMoviments::~SequenciaMoviments()
{
	while (!esBuida())
	{
		eliminaNode();
	}
}

SequenciaMoviments::SequenciaMoviments(const SequenciaMoviments& seq)
{
	m_primer = nullptr;
	m_ultim = nullptr;
	NodeMoviment* aux = seq.m_primer;
	while (aux != nullptr)
	{
		insereixNode(aux->getValorMoviment());
		aux = aux->getSeguentNode();
	}
}

SequenciaMoviments& SequenciaMoviments::operator=(const SequenciaMoviments& seq)
{
	if (this != &seq)
	{
		while (!esBuida())
			eliminaNode();
		NodeMoviment* aux = seq.m_primer;
		while (aux != nullptr)
		{
			insereixNode(aux->getValorMoviment());
			aux = aux->getSeguentNode();
		}
	}
	return *this;
}

NodeMoviment* SequenciaMoviments::insereixNode(const TipusMoviment& valor)
{
	NodeMoviment* aux = new NodeMoviment;
	if (aux != nullptr)
	{
		aux->setValorMoviment(valor);
		aux->setSeguentNode(nullptr);
		if (m_primer == nullptr)
		{
			m_primer = aux;
		}
		else
		{
			m_ultim->setSeguentNode(aux);
		}
		m_ultim = aux;
	}
	return aux;
}

void SequenciaMoviments::eliminaNode()
{
	NodeMoviment* aux;
	if (m_primer == m_ultim)
	{
		delete m_primer;
		m_primer = nullptr;
		m_ultim = nullptr;
	}
	else
	{
		aux = m_primer->getSeguentNode();
		delete m_primer;
		m_primer = aux;
	}
}