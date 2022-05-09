#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

int SortedMap::h(TKey k, int i) const
{
	return (k % capacity + i * (2 * k + 1) % capacity) % capacity;
}

void SortedMap::resizeAndRehash()
{
}

SortedMap::SortedMap(Relation r) {
	capacity = 64;
	elements = new TElem[capacity];
	for (int i = 0; i < capacity; i++)
		elements[i] = NULL_TPAIR;
	nrOfElements = 0;
	relation = r;
}

TValue SortedMap::add(TKey k, TValue v) {
	int i = 0;
	int pos = h(k, i);
	while (i < capacity && elements[pos].second != NULL_TVALUE)
	{
		if (elements[pos].first == k)
		{
			TValue old_value = elements[pos].second;
			elements[pos].second = v;
			return old_value;
		}
		i++;
		pos = h(k, i);
	}
	if (i == capacity)
		resizeAndRehash();
	else
		elements[pos] = TElem(k, v);
	nrOfElements++;
	return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
	int i = 0;
	int pos = h(k, i);
	while (i < capacity && elements[pos].first != k)
	{
		i++;
		pos = h(k, i);
	}
	if (i == capacity)
		return NULL_TVALUE;
	return elements[pos].second;
}

TValue SortedMap::remove(TKey k) {
	int i = 0;
	int pos = h(k, i);
	while (i < capacity && elements[pos].first != k)
	{
		i++;
		pos = h(k, i);
	}
	if (i == capacity)
		return NULL_TVALUE;
	TValue old_value = elements[pos].second;
	elements[pos] = NULL_TPAIR;
	nrOfElements--;
	return old_value;
}

int SortedMap::size() const {
	//TODO - Implementation
	return nrOfElements;
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation
	return nrOfElements == 0;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	//TODO - Implementation
}
