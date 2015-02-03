#include "dynamicArray.h"

DynamicArray::DynamicArray(int _capacite)
{
	if (_capacite < 1) throw invalid_argument("pas bien");
	capacite = _capacite;
	tabElements = new int[_capacite];
	for (int i = 0; i < capacite; ++i){
		tabElements[i] = 0;
	}

}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

unsigned int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setElement(unsigned int _index, int _valeur)
{
	
	if (_index >= capacite)
	{
		setCapacite(_index + 1);
		
	}
	
	tabElements[_index] = _valeur;
	

}

int DynamicArray::getElement(unsigned int _index)
{
	if (_index < 0 || _index > capacite) throw out_of_range("pas bien");
	return tabElements[_index];
}

void DynamicArray::setCapacite(unsigned int _capacite)

{
	if (_capacite < 1)
	{
		throw invalid_argument("pas bien");
	}
	else{

		int *tempTab = new int[_capacite];
		for (int i = 0; i < _capacite; ++i){
			if (i < capacite){
				tempTab[i] = tabElements[i];
			}
			else{
				tempTab[i] = 0;
			}

		}
		capacite = _capacite;
		delete[] tabElements;
		tabElements = tempTab;
	}
	
}