#pragma once
#include "VertexType.h"


struct ItemType
{
	bool operator<(ItemType other) const;
	bool operator>(ItemType other) const;
	bool operator==(ItemType other) const;
	bool operator<=(ItemType other) const;
	bool operator>=(ItemType other) const;
	VertexType toVertex;
	VertexType fromVertex;
	int distance;
};

