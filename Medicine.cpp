#include "Medicine.h"
Medicine::Medicine(pair<int, int> coordinates) : Item(coordinates) {

}
void Medicine::Buff(Agent* agent) {
	agent->Heal(healthPoints);
}
char Medicine::GetChar() {
	return 'm';
}