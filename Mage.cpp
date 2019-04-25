#include "Mage.h"
Mage::Mage(pair<int, int> coordinates) : Agent(coordinates) {
	damage = mageDamage;
	health = mageHealth;
}
void Mage::Move() {
	coordinates.second -= 2;
}
char Mage::GetChar() {
	return 'M';
}