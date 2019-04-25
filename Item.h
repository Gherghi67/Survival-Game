#ifndef ITEM_H
#define ITEM_H
#include <utility>
#include "Agent.h"
using namespace std;
class Item {
protected:
	pair<int, int> coordinates;          // coordonatele itemului
public:
	Item(pair<int, int> coordinates);
	virtual void Buff(Agent* agent) = 0;             // metoda virtuala pentru a oferi avantaje agentului care gaseste item-ul
	virtual char GetChar() = 0;
	pair<int, int> GetCoordinates() const;
};
#endif