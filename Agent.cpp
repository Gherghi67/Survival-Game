#include "Agent.h"
Agent::Agent(pair<int, int> coordinates) {
	this->coordinates = coordinates;
}
void Agent::SetCoordinates(pair<int, int> p) {
	coordinates = p;
}
pair<int, int> Agent::GetCoordinates() const {
	return coordinates;
}
int Agent::Attack() const {
	return damage;
}
int Agent::GetHealth() const {
	return health;
}
void Agent::TakeDamage(int x) {
	health -= x;
}
void Agent::ModifyAttack(int x) {
	damage += x;
}
void Agent::Heal(int x) {
	health += x;
}
bool Agent::GetWasMoved() const {
	return wasMoved;
}
void Agent::SetWasMoved(bool x) {
	wasMoved = x;
}