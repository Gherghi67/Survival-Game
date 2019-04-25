#include "Item.h"
Item::Item(pair<int, int> coordinates) {
	this->coordinates = coordinates;
}
pair<int, int> Item::GetCoordinates() const {
	return coordinates;
}