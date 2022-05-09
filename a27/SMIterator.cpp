#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	int index = 0;
	nrOfElements = m.nrOfElements;
	sortedElements = new TElem[nrOfElements];
	for (int i = 0; i < m.capacity; i++)
		if (m.elements[i].second != NULL_TVALUE)
			sortedElements[index++] = m.elements[i];
	for(int i=0;i<nrOfElements-1;i++)
		for(int j=i+1;j<nrOfElements;j++)
			if (!m.relation(sortedElements[i].first, sortedElements[j].first))
			{
				TElem aux = sortedElements[i];
				sortedElements[i] = sortedElements[j];
				sortedElements[j] = aux;
			}
	current = 0;
}

SMIterator::~SMIterator()
{
	delete[] sortedElements;
}

void SMIterator::first(){
	current = 0;
}

void SMIterator::next(){
	if (!valid())
		throw std::exception();
	current++;
}

bool SMIterator::valid() const{
	return current != nrOfElements;
}

TElem SMIterator::getCurrent() const{
	if (!valid())
		throw std::exception();
	return sortedElements[current];
}


