#include "VertexType.h"
#include<string>
using namespace std;
VertexType::VertexType()
{
	name = "defaultName";
}
VertexType::VertexType(string str)
{
	name.assign(str);
}

VertexType::~VertexType(void)
{
}
string VertexType::getName() const
{
	return name;
}

bool VertexType::operator==(VertexType other) const {
	if(getName().compare(other.getName()) == 0) return true;
	else return false;
}
