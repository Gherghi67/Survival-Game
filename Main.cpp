#include <iostream>
#include <process.h>
#include "Game.h"
using namespace std;
int main() {
	Game::Start();
	Game::MapOutput();
	char c = 'f';
	while (c == 'f') {
		Game::Update();
		Game::MapOutput();
		if (Game::isFinished() == true) {
			cout << "Simularea s-a terminat\n";
		}
		cin >> c;
	}
	system("pause");
	return 0;
}