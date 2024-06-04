#ifndef NODEFIGURA_H
#define NODEFIGURA_H

#include <stdlib.h>
#include "InfoJoc.h"
#include "Figura.h"  // Ensure Figura.h is included

class NodeFigura
{
public:
	// Default constructor
	NodeFigura() : seguentNode(nullptr) {}

	// Destructor
	~NodeFigura() {}

	// Constructor with initial value
	NodeFigura(const Figura& valorInicial) : valorFigura(valorInicial), seguentNode(nullptr) {}

	// Get the next node in the list
	NodeFigura* getSeguentNode() const { return seguentNode; }

	// Set the next node in the list
	void setSeguentNode(NodeFigura* nodeSeguent) { seguentNode = nodeSeguent; }

	// Get the value of the current node
	Figura getValorFigura() const { return valorFigura; }

	// Set the value of the current node
	void setValorFigura(const Figura& valorNou) { valorFigura = valorNou; }

private:
	Figura valorFigura; // Value of the current node
	NodeFigura* seguentNode; // Pointer to the next node in the list
};

#endif // NODEFIGURA_H
