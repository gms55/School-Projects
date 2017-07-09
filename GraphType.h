#include "ItemType.h"
#include "QueType.h"
#include "PQType.h"
#include<iomanip>

template<class VertexType>
class GraphType
{
public:
	GraphType();
	GraphType(int maxV);
	~GraphType();
	void AddVertex(VertexType);
	void AddEdge(VertexType, VertexType, int);
	int GetWeight(VertexType, VertexType);
	void GetToVertices(VertexType, QueType<VertexType>&);
	void ClearMarks();
	void MarkVertex(VertexType);
	bool IsMarked(VertexType);
private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int edges[50][50];
	bool* marks;
};

template<class VertexType>
void ShortestPath(GraphType<VertexType> graph, VertexType startVertex);

template<class VertexType>
GraphType<VertexType>::GraphType()
{
	numVertices = 0;
	maxVertices = 50;
	vertices = new VertexType[50];
	marks = new bool[50];
	for(int i = 0; i<50; i++) marks[i] = false;
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
	marks = new bool[maxV];
	for(int i = 0; i<maxV; i++) marks[i] = false;
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
	delete [] vertices;
	delete [] marks;
}

const int NULL_EDGE = 0;

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
	vertices[numVertices] = vertex;
	for(int i = 0; i < numVertices; i++)
	{
		edges[numVertices][i] = NULL_EDGE;
		edges[i][numVertices] = NULL_EDGE;
	}
	numVertices++;
}

template<class VertexType>
int IndexIs(VertexType* vertes, VertexType vertex)
{
	int i = 0;
	while( !(vertex == vertes[i]) ) i++;
	return i;
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromV, VertexType toV, int w)
{
	int row;
	int col;

	row = IndexIs(vertices, fromV);
	col = IndexIs(vertices, toV);
	edges[row][col] = w;
}

template<class VertexType>
int GraphType<VertexType>::GetWeight(VertexType fromV, VertexType toV)
{
	int row;
	int col;
	row = IndexIs(vertices, fromV);
	col = IndexIs(vertices, toV);
	return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType v, QueType<VertexType>& adjV)
{
	int fromInd;
	int toInd;
	fromInd = IndexIs(vertices, v);
	for(toInd = 0; toInd < numVertices; toInd++)
	{
		if(edges[fromInd][toInd] != NULL_EDGE) adjV.Enqueue(vertices[toInd]);
	}
}

template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
	delete [] marks;
	marks = new bool[maxVertices];
	for(int i = 0; i<maxVertices; i++) marks[i] = false;
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vert)
{
	int ind = IndexIs(vertices, vert);
	marks[ind] = true;
}

template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vert)
{
	int ind = IndexIs(vertices, vert);
	return marks[ind];
}

template<class VertexType>
void ShortestPath(GraphType<VertexType> graph,
VertexType startVertex)
{
   using namespace std;
   ItemType item;
   int minDistance;
   PQType<ItemType> pq(10);
   QueType<VertexType> vertexQ;
   VertexType vertex;
   
   graph.ClearMarks();
   item.fromVertex = startVertex;
   item.toVertex = startVertex;
   item.distance = 0;
   pq.Enqueue(item);
   cout << setw(10) << "Last Vertex" << setw(14) << "Destination" << setw(11)
        << "Distance" << endl << "--------------------------------------"
        << endl;
   
   do {
      pq.Dequeue(item);
      if(!graph.IsMarked(item.toVertex)) {
         graph.MarkVertex(item.toVertex);
         cout << setw(11) << item.fromVertex.getName() << setw(13)
              << item.toVertex.getName() << setw(10) << item.distance << endl;
         item.fromVertex = item.toVertex;
         minDistance = item.distance;
         graph.GetToVertices(item.fromVertex, vertexQ);
         
         while(!vertexQ.IsEmpty()) {
            vertexQ.Dequeue(vertex);
            if(!graph.IsMarked(vertex)) {
               item.toVertex = vertex;
               item.distance = minDistance + graph.GetWeight(item.fromVertex,
                  vertex);
               pq.Enqueue(item);
            }
         }
      }
   }while(!pq.IsEmpty());
}


