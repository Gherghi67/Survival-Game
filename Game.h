#ifndef GAME_H
#define GAME_H
#include "Assassin.h"
#include "Tank.h"
#include "Mage.h"
#include "Blade.h"
#include "Medicine.h"
#include "Hybrid.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
struct Point{
	char c;
	Agent* agent;
	Item* item;
};
class Game {
private:
	static const int WIDTH = 15;             // latimea hartii
	static const int HEIGHT = 15;            // inaltimea hartii
	static int step;                         // pasul curent al simularii
	static Point _2DMap[HEIGHT][WIDTH];      // harta va fi de tip pair deoarece la fiecare indice va fi retinut caracterul,
	                                         // pointerul spre tipul de agent care se afla pe pozitia respectiva si
	                                         // pointerul spre tipul de item care se afla pe pozitia respectiva
	static pair<int, int> DecideWhereToSpawn();
	static void InitialiseMap();             // metoda care initializeaza harta cu caractere 0 si pozitia -1
	static bool isOccupied(pair<int, int> p); // metoda care verifica daca un punct pe harta este ocupat sau nu
	static void SpawnAgent(Agent* agent);    // metoda care spawn-eaza un agent pe harta
	static void SpawnItem(Item* item);       // metoda care spawn-eaza un item pe harta
	static Agent* Conflict(Agent* agent1, Agent* agent2); // metoda care decide invingatorul dintre doi agenti
	static bool isOutOfMap(pair<int, int> p); // metoda care verifica daca agentul a iesit de pe harta
public:
	static void Start();                     // metoda care se va apela la inceputul simularii
	static void Update();                    // metoda care se va apela la fiecare pas al simularii
	static void MapOutput();                 // metoda care va afisa harta
	static bool isFinished();                // ,etoda care ne spune daca simularea s-a terminat sau nu
};
#endif // !GAME_H
