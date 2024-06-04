#include "NodeMoviment.h"

class SequenciaMoviments
{
public:
	SequenciaMoviments() { m_primer = nullptr; }
	~SequenciaMoviments();
	SequenciaMoviments(const SequenciaMoviments& seq);

	SequenciaMoviments& operator=(const SequenciaMoviments& seq);

	NodeMoviment* insereixNode(const TipusMoviment& node);
	void eliminaNode();
	bool isEmpty() const { return m_primer == nullptr; }

	TipusMoviment getPrimer() const { return m_primer->getValorMoviment(); }
	bool esBuida() const { return m_primer == nullptr; }

private:
	NodeMoviment* m_primer;
	NodeMoviment* m_ultim;
};
