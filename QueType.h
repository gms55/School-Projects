#include <cstddef>
#include <new>
#include "NodeType.h"

using namespace std;

template<class T>
class QueType
{
public:
	QueType();
	virtual ~QueType();
	void MakeEmpty();
	void Enqueue(T);
	void Dequeue(T&);
	bool IsEmpty() const;
	bool IsFull();
private:
	NodeType<T>* front;
	NodeType<T>* rear;
};

template<class T>
QueType<T>::QueType()
{
	front = NULL;
	rear = NULL;
}

template<class T>
void QueType<T>::MakeEmpty()
{
	NodeType<T>* tmpPtr;
	while(front != NULL)
	{
		tmpPtr = front;
		front = front->next;
		delete tmpPtr;
	}
	rear = NULL;
}

template<class T>
QueType<T>::~QueType()
{
	MakeEmpty();
}

template<class T>
bool QueType<T>::IsFull()
{
	NodeType<T>* loc;
	try {
		loc = new NodeType<T>;
		delete loc;
		return false;
	}
	catch(std::bad_alloc exception)
	{
		return true;
	}
}

template<class T>
bool QueType<T>::IsEmpty() const
{
	return (front == NULL);
}

template<class T>
void QueType<T>::Enqueue(T newItem)
{
	if(!IsFull())
	{
		NodeType<T>* newNode;
		newNode = new NodeType<T>;
		newNode->info = newItem;
		newNode->next = NULL;
		if(rear == NULL) front = newNode;
		else rear->next = newNode;
		rear = newNode;
	}
}

template<class T>
void QueType<T>::Dequeue(T& item)
{
	if(!IsEmpty())
	{
		NodeType<T>* tmpPtr;
		tmpPtr = front;
		item = front->info;
		front = front->next;
		if(front == NULL) rear = NULL;
		delete tmpPtr;
	}
}
