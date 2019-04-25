#include "Blade.h"
Blade::Blade(pair<int, int> coordinates) : Item(coordinates) {

}
void Blade::Buff(Agent* agent) {
	agent->ModifyAttack(damagePoints);
}
char Blade::GetChar() {
	return 'B';
}