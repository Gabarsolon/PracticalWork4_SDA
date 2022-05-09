#pragma once
#include "SortedMap.h"

//DO NOT CHANGE THIS PART
class SMIterator{
	friend class SortedMap;
private:
	const SortedMap& map;
	SMIterator(const SortedMap& mapionar);
	
	TElem* sortedElements;
	int nrOfElements;
	int current;

public:
	~SMIterator();
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
};

