#include "ItemType.h"

bool ItemType::operator<(ItemType other) const {
	if(distance < other.distance) return true;
	else return false;
}

bool ItemType::operator>(ItemType other) const {
	if(distance > other.distance) return true;
	else return false;
}

bool ItemType::operator==(ItemType other) const {
	if(distance == other.distance) return true;
	else return false;
}

bool ItemType::operator<=(ItemType other) const {
	if(distance <= other.distance) return true;
	else return false;
}

bool ItemType::operator>=(ItemType other) const {
	if(distance >= other.distance) return true;
	else return false;
}
