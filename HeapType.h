#pragma once

template<class ItemType>
struct HeapType
{
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	ItemType* elements;
	int numElements;
};

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
	int minChild;
	int rightChild;
	int leftChild;
	ItemType item;

	leftChild = root*2 + 1;
	rightChild = root*2 + 2;
	if(leftChild <= bottom)
	{
		if(leftChild == bottom) minChild = leftChild;
		else {
			if (&elements[leftChild] <= &elements[rightChild])
				minChild = leftChild;
			else minChild = rightChild;
		}
		if( &elements[root] > &elements[minChild] )
		{
			item = elements[root];
			elements[root] = elements[minChild];
			elements[minChild] = item;
			ReheapDown(minChild, bottom);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
	int parent;
	ItemType item;

	if(bottom > root)
	{
		parent = (bottom-1)/2;
		if(&elements[root] > &elements[bottom])
		{
			item = elements[root];
			elements[root] = elements[bottom];
			elements[bottom] = item;
			ReheapUp(root, parent);
		}
	}
}
