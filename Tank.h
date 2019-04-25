#ifndef TANK_H
#define TANK_H
#include "Agent.h"
class Tank : public Agent {
private:
	static const int tankDamage = 3;
	static const int tankHealth = 7;
public:
	Tank(pair<int, int> coordinates);
	void Move();
	char GetChar();
};
#endif // !TANK_H
