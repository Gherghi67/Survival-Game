#include "Tank.h"
Tank::Tank(pair<int, int> coordinates) : Agent(coordinates) {
	damage = tankDamage;
	health = tankHealth;
}
void Tank::Move() {
	coordinates.first--;
}
char Tank::GetChar() {
	return 'T';
}