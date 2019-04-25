#include "Game.h"
int Game::step = 1;
Point Game::_2DMap[HEIGHT][WIDTH];
pair<int, int> Game::DecideWhereToSpawn() {
	srand(time(NULL));
	bool ok = false;
	while (ok == false) {
		pair<int, int> p;
		p.first = rand() % HEIGHT;
		p.second = rand() % WIDTH;
		if (isOccupied(p) == false) {
			return p;
		}
	}
}
void Game::MapOutput() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << _2DMap[i][j].c << " ";
		}
		cout << "\n";
	}
}
void Game::InitialiseMap() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			_2DMap[i][j].c = '0';
			_2DMap[i][j].agent = NULL;
			_2DMap[i][j].item = NULL;
		}
	}
}
bool Game::isOccupied(pair<int, int> p) {
	if (p.first < 0 || p.second < 0 || p.first >= HEIGHT || p.second >= WIDTH) {
		return false;
	}
	if (_2DMap[p.first][p.second].c == '0') {
		return false;
	}
	return true;
}
void Game::SpawnAgent(Agent* agent) {
	_2DMap[agent->GetCoordinates().first][agent->GetCoordinates().second].c = agent->GetChar();
	_2DMap[agent->GetCoordinates().first][agent->GetCoordinates().second].agent = agent;
}
void Game::SpawnItem(Item* item) {
	_2DMap[item->GetCoordinates().first][item->GetCoordinates().second].c = item->GetChar();
	_2DMap[item->GetCoordinates().first][item->GetCoordinates().second].item = item;
}
void Game::Start() {
	InitialiseMap();
	// for-ul care spawneaza agentii de fiecare tip
	for (int i = 0; i < 21; i++) {
		pair<int, int> p = DecideWhereToSpawn();
		Agent* agent = new Mage(p);
		SpawnAgent(agent);
		p = DecideWhereToSpawn();
		agent = new Tank(p);
		SpawnAgent(agent);
		p = DecideWhereToSpawn();
		agent = new Assassin(p);
		SpawnAgent(agent);
	}
	// for-ul care spawneaza itemele de fiecare tip
	for (int i = 0; i < 21; i++) {
		pair<int, int> p = DecideWhereToSpawn();
		Item* item = new Blade(p);
		SpawnItem(item);
		p = DecideWhereToSpawn();
		item = new Medicine(p);
		SpawnItem(item);
		p = DecideWhereToSpawn();
		item = new Hybrid(p);
		SpawnItem(item);
	}
}
Agent* Game::Conflict(Agent* agent1, Agent* agent2) {
	while (agent1->GetHealth() > 0 && agent2->GetHealth() > 0) {
		agent2->TakeDamage(agent1->Attack());
		if (agent2->GetHealth() <= 0) {
			return agent1;
		}
		agent1->TakeDamage(agent2->Attack());
		if (agent1->GetHealth() <= 0) {
			return agent2;
		}
	}
}
bool Game::isOutOfMap(pair<int, int> p) {
	if (p.first < 0 || p.second < 0 || p.first >= HEIGHT || p.second >= WIDTH) {
		return true;
	}
	return false;
}
bool Game::isFinished() {
	int numberOfAgents = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (_2DMap[i][j].agent != NULL) {
				numberOfAgents++;
			}
		}
	}
	if (numberOfAgents == 1) {
		return true;
	}
	return false;
}
void Game::Update() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (_2DMap[i][j].agent != NULL) {
				_2DMap[i][j].agent->SetWasMoved(false);
			}
		}
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (_2DMap[i][j].agent != NULL && _2DMap[i][j].agent->GetWasMoved() == false) {
				_2DMap[i][j].agent->Move();
				if (isOutOfMap(_2DMap[i][j].agent->GetCoordinates())) {
					_2DMap[i][j].agent = NULL;
					_2DMap[i][j].c = '0';
					continue;
				}
				pair<int, int> p = _2DMap[i][j].agent->GetCoordinates();
				if (_2DMap[p.first][p.second].agent != NULL) {
					_2DMap[i][j].agent->SetWasMoved(true);
					Agent* agent = Conflict(_2DMap[i][j].agent, _2DMap[p.first][p.second].agent);
					_2DMap[p.first][p.second].agent = agent;
					_2DMap[p.first][p.second].c = agent->GetChar();
					_2DMap[i][j].agent = NULL;
					_2DMap[i][j].c = '0';
				}
				else if (_2DMap[p.first][p.second].item != NULL) {
					_2DMap[i][j].agent->SetWasMoved(true);
					_2DMap[i][j].item->Buff(_2DMap[i][j].agent);
					_2DMap[p.first][p.second].agent = _2DMap[i][j].agent;
					_2DMap[p.first][p.second].item = NULL;
					_2DMap[i][j].agent = NULL;
					_2DMap[p.first][p.second].c = _2DMap[p.first][p.second].agent->GetChar();
					_2DMap[i][j].c = '0';
				}
				else {
					_2DMap[i][j].agent->SetWasMoved(true);
					_2DMap[i][j].c = '0';
					_2DMap[p.first][p.second].agent = _2DMap[i][j].agent;
					_2DMap[p.first][p.second].c = _2DMap[p.first][p.second].agent->GetChar();
					_2DMap[i][j].agent = NULL;
				}
			}
		}
	}
}