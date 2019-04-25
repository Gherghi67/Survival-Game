#ifndef MEDICINE_H
#define MEDICINE_H
#include "Item.h"
class Medicine : public Item {
private:
	static const int healthPoints = 3;
public:
	Medicine(pair<int, int> coordinates);
	void Buff(Agent* agent);
	char GetChar();
};
#endif // !MEDICINE_H
