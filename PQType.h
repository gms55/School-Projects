#pragma once

#include "iostream"
#include "HeapType.h"
//class FullPQ(){};
//class EmptyPQ(){};
using namespace std; 

template<class ItemType>
class PQType
{
public:
	PQType(int);
	~PQType(void);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType);
	void Dequeue(ItemType& item);
	void Print();
private:
	int length;
	HeapType<ItemType> items;
	int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
	maxItems = max;
	items.elements = new ItemType[max];
	length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
	delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty() 
{
	length = 0;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
{
	return length == 0;
}

template<class ItemType>
bool PQType<ItemType>::IsFull() const
{
	return length == maxItems;
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
{
	//if(length == 0) throw EmptyPQ();
	//else
	if(length > 0)
	{
		item = items.elements[0];
		items.elements[0] = items.elements[length - 1];
		length--;
		items.ReheapDown(0, length-1);
		//cout << "Dequeued item with " << item.distance << endl;
	}
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
	//if(length == maxItems) throw FullPQ();
	//else
	if(length < maxItems)
	{
		length++;
		items.elements[length-1] = newItem;
		items.ReheapUp(0, length-1);
		//cout << "Enqueued item with " << newItem.distance << endl;
	}
}

template<class ItemType>
void PQType<ItemType>::Print() 
{
	for(int i=0; i<length; i++){
		cout << "PQ item[" << i << "] = " << items.elements[i].distance << endl;
	}
}

