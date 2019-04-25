#ifndef ASSASSIN_H
#define ASSASSIN_H
#include "Agent.h"
class Assassin : public Agent {
private:
	static const int assassinDamage = 5;
	static const int assassinHealth = 5;
public:
	Assassin(pair<int, int> coordinates);
	void Move();
	char GetChar();
};
#endif // !ASSASSIN_H
