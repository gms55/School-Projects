#pragma once

#include "string"
using namespace std;
class VertexType
{
public:
	VertexType();
	VertexType(string);
	~VertexType();
	bool operator==(VertexType other) const;
	string getName() const;
private:
	string name;
};
