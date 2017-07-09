#include "MainPQ.h"

#include "iostream"
#include "string"
#include <fstream>
#include <cstddef>
#include "GraphType.h"
#include "VertexType.h"
//#include "QueType.h"
//#include "PQType.h"
#include "ItemType.h"

MainPQ::MainPQ(void)
{
}

MainPQ::~MainPQ(void)
{
}

int main() {
	
	/*
	PQType<ItemType>* pq = new PQType<ItemType>(10); 
	ItemType it1;
	it1.distance = 10;
	ItemType it2;
	it2.distance = 5;
	ItemType it3;
	it3.distance = 12;
	ItemType itRes;

	pq->Enqueue(it1);
	pq->Enqueue(it2);
	pq->Enqueue(it3);
	pq->Print();
	system("pause");
	pq->Dequeue(itRes);
	cout << "Got dequeued item  " << itRes.distance << endl;
	pq->Print();
	system("pause");
	QueType<VertexType>* qt = new QueType<VertexType>();
	VertexType* vt1 = new VertexType(string("Austin"));
	VertexType* vt2 = new VertexType(string("Dallas"));
	
	qt->Enqueue((*vt1));
	qt->Enqueue((*vt2));
	cout << "Added to queue " << vt1->getName() << " and " << vt2->getName() << endl;
	*/
	GraphType<VertexType>* graph = new GraphType<VertexType>(30);
	VertexType* vAustin = new VertexType(string("Austin"));
	VertexType* vDallas = new VertexType(string("Dallas"));
	VertexType* vDenver = new VertexType(string("Denver"));
	VertexType* vWashington = new VertexType(string("Washington"));
	VertexType* vAtlanta = new VertexType(string("Atlanta"));
	VertexType* vHouston = new VertexType(string("Houston"));
	VertexType* vChicago = new VertexType(string("Chicago"));

	graph->AddVertex((*vAustin));
	graph->AddVertex((*vDallas));
	graph->AddVertex((*vDenver));
	graph->AddVertex((*vWashington));
	graph->AddVertex((*vAtlanta));
	graph->AddVertex((*vHouston));
	graph->AddVertex((*vChicago));

	graph->AddEdge((*vAustin), (*vDallas), 200);
	graph->AddEdge((*vDallas), (*vAustin), 200);
	graph->AddEdge((*vDallas), (*vDenver), 780);
	graph->AddEdge((*vDallas), (*vChicago), 900);

	graph->AddEdge((*vAtlanta), (*vWashington), 600);
	graph->AddEdge((*vWashington), (*vAtlanta), 600);
	graph->AddEdge((*vWashington), (*vDallas), 1300);

	graph->AddEdge((*vAustin), (*vHouston), 160);

	graph->AddEdge((*vDenver), (*vAtlanta), 1400);
	graph->AddEdge((*vDenver), (*vChicago), 1000);
	graph->AddEdge((*vChicago), (*vDenver), 1000);

	ShortestPath((*graph), (*vWashington));
	system("pause");
	return 0;
}

