#ifndef AGENT_H
#define AGENT_H
#include <utility>
using namespace std;
class Agent {
protected:
	pair<int, int> coordinates;  // coordonatele pozitiei curente ale agentului;
	int damage;                  // damage-ul pe care il va avea agentul in timpul unui conflict
	int health;                  // health-ul pe care il va avea agentul in timpul unui conflict
	bool wasMoved;               // camp boolean care ne spune daca agentul a fost mutat sau nu turul respectiv
public:
	Agent(pair<int, int> coordinates);
	virtual void Move() = 0;     // metoda virtuala de miscare a agentilor care o sa difere in functie de tipul de agent care o apeleaza
	virtual char GetChar() = 0;  // metoda virtuala de returnare a caracterului care defineste tipul de agent pe harta
	void SetCoordinates(pair<int, int> p);
	pair<int, int> GetCoordinates() const;
	int Attack() const;          // metoda care returneaza damage-ul agentului
	int GetHealth() const;       // metoda care returneaza health-ul agentului
	void TakeDamage(int x);      // metoda care scade health-ul agentului in functie de damage-ul primit
	void ModifyAttack(int x);    // metoda care modifica damage-ul agentului in functie de tipul de item pe care il primeste
	void Heal(int x);            // metoda care creste health-ul agentului in functie de tipul de item pe care il primeste;
	bool GetWasMoved() const;
	void SetWasMoved(bool x);
};
#endif // !AGENT_H
