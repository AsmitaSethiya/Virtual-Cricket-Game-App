#include "game.h"
using namespace std;

Game::Game(){

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Hardik";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Rohit";
	players[5] = "Karthik";
	players[6] = "Jadeja";
	players[7] = "Bumrah";
	players[8] = "Dhoni";
	players[9] = "Ishant";
	players[10] = "BKumar";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}

void Game::Welcome(){

	cout << "******************************************" << endl;
	cout << "|================CRIC-IN==================" << endl;
	cout << "|                                         |" << endl;
	cout << "*****WELCOME TO VIRTUAL CRICKET GAME******" << endl;

	cout << endl << endl;
	cout << "******************************************" << endl;
	cout << "******************************************" << endl;
	cout << "|===============INSTRUCTIONS===============" << endl;
    cout << "                                           " << endl;
    cout << "|1. Create 2 teams (Team-A and Tam-B with 4|" << endl;
    cout << "|   players each from a given pool of 11   |" << endl;
    cout << "|   players.                               |" << endl;
    cout << "|2. Lead the toss and decide the choice of |" << endl;
    cout << "|   play.                                  |" << endl;
    cout << "|3. Each innings will be of 6 balls.       |" << endl;
    cout << "******************************************" << endl;
    cout << "******************************************" << endl;



}


void Game::showAllPlayers(){

	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|==============POOL OF PLAYERS==============" << endl;
	cout << "--------------------------------------------" << endl;

	for(int i = 0; i < totalPlayers; i++)
	{
		cout << "\t\t[" << i << "]" << players[i] << endl;
	}
}

int Game::takeIntegerInput(){

	int n;

	while (!(cin >> n)){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid input! Please try again with valid input: ";
	}
	return n;

}

bool Game::validateSelectedPlayer(int index){

	int n;
	vector<Player
	> players;

	players = teamA.players;
	n = players.size();
	for(int i = 0; i < n; i++)
	{
		if(players[i].id == index)
		{
			return false;
		}
	}

	players = teamB.players;
	n = players.size();
	for (int i = 0; i < n; i++)
	{
		if (players[i].id == index)
		{
			return false;
		}
	}

	return true;
}

void Game::sel
ectPlayers(){

	cout << endl;
	cout << "**********************************************" << endl;
	cout << "========== Create Team-A and Team-B ==========" << endl;
	cout << "**********************************************" << endl;

	for ( int i = 0; i < playersPerTeam; i++){

		//Add player to Team A
		teamASelection:
			cout << endl << "Select player " << i + 1 << " of Team A -";

			int playerIndexTeamA = takeIntegerInput();

			if(playerIndexTeamA < 0 || playerIndexTeamA > 10)
			{
				cout << endl << "Please select from the given players" << endl;
				goto teamASelection;
			}
			else if (!validateSelectedPlayer(playerIndexTeamA))
			{
				cout << endl << "Player has been already selected.Please select other player" << endl;
				goto teamASelection;;
			}
			else
			{
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);

			}



		//Add player to team B
		teamBSelection:
			cout << endl << "Select player " << i + 1 << " of Team B -";

			int playerIndexTeamB = takeIntegerInput();

			if (playerIndexTeamB < 0 || playerIndexTeamB > 10)
			{
				cout << endl << "Please select from the given index" << endl;
				goto teamBSelection;
			}
			else if (!validateSelectedPlayer(playerIndexTeamB))
			{
				cout << endl << "Player has been already selected.Please select ither player" << endl;
				goto teamBSelection;;
			}
			else
			{
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
	}
}

void Game::showTeamPlayers(){

	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout << endl << endl;
	cout << "----------------------\t\t-----------------------" << endl;
	cout <<"|======= Team-A=======|\t\t|======= Team-B =======|" << endl;
	cout << "--------------------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam ; i++)
	{
		cout << "|\t" << "[" << i << "]" << teamAPlayers[i].name << "\t |"
			<< "\t\t"
			<< "|\t" << "[" << i << "]" << teamBPlayers[i].name << "\t |" << endl;

	}
	cout << "----------------------\t\t-----------------------" << endl << endl;
}

void Game::toss(){

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|================ Let's Toss ==================|" << endl;
	cout << "------------------------------------------------" << endl << endl;

	cout << "Tossing the coin..................." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2;

	switch (randomValue){
	case 0:
		cout << "Team - A won the toss" << endl << endl;
		tossChoice(teamA);
		break;
	case 1:
		cout << "Team - B won the toss" << endl << endl;
		tossChoice(teamB);
		break;
	}

}

void Game::tossChoice(Team tossWinnerTeam){

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
			<< "1. Bat " << endl
			<< "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	switch (tossInput){
	case 1:
		cout << endl << tossWinnerTeam.name << " Won the toss and selected to bat first" << endl << endl;

		if (tossWinnerTeam.name.compare("Team-A") == 0)
		{
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}
		else
		{
			battingTeam  = &teamB;
			bowlingTeam = &teamA;
		}
		break;
	case 2:
		cout << endl << tossWinnerTeam.name << " Won the toss and choose to bowl first" << endl << endl;

		break;
	default:
		cout << endl << "Invalid input. Please try again:" << endl << endl;
		tossChoice(tossWinnerTeam);
		break;
 	}
}

void Game::startFirstInnings(){

	cout << "\t\t ||| FIRST INNINGS START |||" << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();

}

void Game::startSecondInnings(){

	cout << "\t\t ||| SECOND INNINGS START ||| " << endl << endl;

	isFirstInnings = false;

	// swap battingTeam and bowling pointers
	Team tempTeam = *battingTeam;
	*battingTeam = *bowlingTeam;
	*bowlingTeam = tempTeam;

	// select the batsman and the bowler for 2nd Innings
	initializePlayers();
	playInnings();
}
void Game::initializePlayers(){

	//Choose batsman and bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling" << endl << endl;


}

void Game::playInnings(){

	for (int i = 0; i < maxBalls; i++)
	{
		cout << "Press Enter to bowl.....\n";
		getchar();
		cout << "Bowling.............." << endl;
		bat();

		if (!validateInningsScore())
		{
			break;
		}
	}
}

void Game::bat(){

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

	if (runsScored != 0)  // run scored 1,2,3,4,5, or 6
	{
		cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
	}
	else   // else eunsscored = 0 and the batsman is 'OUT'
	{
	  	cout << endl << bowler->name << " to " << batsman->name << " OUT! " << endl << endl;

	  	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
	  	bowler->wicketsTaken = bowler->wicketsTaken + 1;

	  	int nextPlayerIndex = battingTeam->wicketsLost;
	  	batsman = &battingTeam->players[nextPlayerIndex];

	}
}






void Game::showGameScorecard(){

	cout << "------------------------------------------------------" << endl;

	cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
			<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
			<< " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
			<< bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

	cout << "------------------------------------------------------" << endl;


}
bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings

    	if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {	//Case1: If batting team score > bowling team score
        	cout << battingTeam->name << " WON THE MATCH" << endl << endl;
        	return false;
        	//Case2: Batting team is all OUT OR Bowling team is done bowling
        } else if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
            if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {
            	cout << bowlingTeam->name << " WON THE MATCH" << endl << endl;
            } else {
            	cout << "MATCH DRAW" << endl << endl;
            }
            return false;
        }
    }

	return true;
}


void Game::showMatchSummary(){

	cout << "\t\t ||| MATCH ENDS ||| " << endl << endl;

	cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost <<
			 " (" << bowlingTeam->totalBallsBowled << ")" << endl;

	cout << "=================================================" << endl;
	cout << "| PLAYER \t BATTING \t BOWLING |" << endl;

	for(int j = 0; j < playersPerTeam; j++)
	{
		Player player = battingTeam->players[j];
		cout << "|--------------------------------------------------|" << endl;
		cout << "| " << "[" << j << "]" << player.name <<" \t"
				<< player.runsScored << "(" << player.ballsPlayed << ")\t\t"
				<< player.ballsBowled << " - " << player.runsGiven << "-"
				<< player.wicketsTaken << "\t |" << endl;
	}
	cout << "=================================================" << endl << endl;

	cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl;


	cout << "=================================================" << endl;
	cout << "| PLAYER \t BATTING \t BOWLING |" << endl;

	for (int i = 0; i < playersPerTeam; i++){

		Player player  = bowlingTeam->players[i];
		cout << "|--------------------------------------------------|" << endl;
				cout << "| " << "[" << i << "]" << player.name <<" \t"
						<< player.runsScored << "(" << player.ballsPlayed << ")\t\t"
						<< player.ballsBowled << " - " << player.runsGiven << "-"
						<< player.wicketsTaken << "\t |" << endl;
	}



}
