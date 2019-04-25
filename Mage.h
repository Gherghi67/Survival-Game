#ifndef MAGE_H
#define MAGE_H
#include "Agent.h"
class Mage : public Agent {
private:
	static const int mageDamage = 7;
	static const int mageHealth = 3;
public:
	Mage(pair<int, int> coordinates);
	void Move();
	char GetChar();
};
#endif // !MAGE_H
