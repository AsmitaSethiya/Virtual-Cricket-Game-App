#include "game.h"
using namespace std;

int main() {
	Game game;
	game.Welcome();

	//cin.ignore(numeric_limits<streamsize>::max(),'\n');

	setbuf(stdout,NULL);
	cout << "\nPress Enter to continue\n";
	getchar();

	game.showAllPlayers();

	//cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "\nPress Enter to continue\n";
	getchar();

	game.selectPlayers();
	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "\nPress Enter to toss";
	getchar();

	game.toss();

	game.startFirstInnings();

	game.startSecondInnings();

	game.showMatchSummary();
	return 0;
}
