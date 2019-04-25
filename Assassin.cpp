#include "Assassin.h"
Assassin::Assassin(pair<int, int> coordinates) : Agent(coordinates) {
	damage = assassinDamage;
	health = assassinHealth;
}
void Assassin::Move() {
	coordinates.second += 3;
}
char Assassin::GetChar() {
	return 'A';
}