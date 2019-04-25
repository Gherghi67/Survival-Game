#ifndef BLADE_H
#define BLADE_H
#include "Item.h"
class Blade : public Item {
private:
	static const int damagePoints = 3;
public:
	Blade(pair<int, int> coordinates);
	void Buff(Agent* agent);
	char GetChar();
};
#endif // !BLADE_H
