#include "Hybrid.h"
Hybrid::Hybrid(pair<int, int> coordinates) : Item(coordinates) {

}
void Hybrid::Buff(Agent* agent) {
	agent->ModifyAttack(damagePoints);
	agent->Heal(healthPoints);
}
char Hybrid::GetChar() {
	return 'H';
}