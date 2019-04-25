#ifndef HYBRID_H
#define HYBRID_H
#include "Item.h"
class Hybrid : public Item {
private:
	static const int damagePoints = 1;
	static const int healthPoints = 1;
public:
	Hybrid(pair<int, int> coordinates);
	void Buff(Agent* agent);
	char GetChar();
};
#endif // !HYBRID_H
