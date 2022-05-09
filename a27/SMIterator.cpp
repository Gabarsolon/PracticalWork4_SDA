#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	nrOfElements = 0;
	sortedElements = new TElem[m.nrOfElements];
	for (int i = 0; i < m.capacity; i++)
		if(m.elements[i].second!= NULL_TVALUE)
	{
			int index = nrOfElements - 1;
			while (index >= 0 && m.relation(sortedElements[index].first, m.elements[i].first) == false)
			{
				sortedElements[index + 1] = sortedElements[index];
				index--;
			}
			sortedElements[index + 1] = m.elements[i];
			nrOfElements++;
	}
	current = 0;
}
//Best case: Theta(capacity)
//Worst case: Theta(capacity + nrOfElements^2)
//Total: O(capacity + nrOfElements^2)

SMIterator::~SMIterator()
{
	delete[] sortedElements;
}
//Theta(1)

void SMIterator::first(){
	current = 0;
}
//Theta(1)

void SMIterator::next(){
	if (!valid())
		throw std::exception();
	current++;
}
//Theta(1)

bool SMIterator::valid() const{
	return current != nrOfElements;
}
//Theta(1)

TElem SMIterator::getCurrent() const{
	if (!valid())
		throw std::exception();
	return sortedElements[current];
}
//Theta(1)

