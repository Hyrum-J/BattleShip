#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

//This function chooses a game based off user input
void gamePicker();

//These are the functions for BattleShip
void battleShip();
int spaceGiver(int findSpace);
bool battleShipPlacementChecker(string placement1, string placement2, string placement3, string placement4, string placement5);
bool carrierPlacementChecker(string placement1, string placement2, string placement3, string placement4);
bool destroyerPlacementChecker(string placement1, string placement2, string placement3);
bool submarinePlacementChecker(string placement1, string placement2, string placement3);
bool cruiserPlacementChecker(string placement1, string placement2);
int aiShipPlacer();
void playerTurn();
void aiTurn();
void updateMapHit(string whichPlayer, int whichSpot);
void updateMapMiss(string whichPlayer, int whichSpot);
int coorToGrid(string coordinate);
string gridToCoor(int gridNum);
void shipToMap();
void alreadyGuessed(string whichPlayer, int shot);
bool edgeChecker(int coordinant);

//These are the functions for Tic Tak Toe
void ticTakToe();
bool hasWon(string player);
char ticTakToeAI();

//These are the functions for Hangman
void hangMan();
char hangManUpdater(int incorrectGuess);
int wordPicker();
bool wasUsed(int wantedNum);
bool wasGuessed(char guess);

//Quits the program
void quit();

//Stores the player's name for the entire game. 
string playerName;

//Shows the where the players ships are and where the player has guessed
string playerBattleMap[9][9] = {
		{"[A 1]","[A 2]","[A 3]","[A 4]","[A 5]","[A 6]","[A 7]","[A 8]","[A 9]"},
		{"[B 1]","[B 2]","[B 3]","[B 4]","[B 5]","[B 6]","[B 7]","[B 8]","[B 9]"},
		{"[C 1]","[C 2]","[C 3]","[C 4]","[C 5]","[C 6]","[C 7]","[C 8]","[C 9]"},
		{"[D 1]","[D 2]","[D 3]","[D 4]","[D 5]","[D 6]","[D 7]","[D 8]","[D 9]"},
		{"[E 1]","[E 2]","[E 3]","[E 4]","[E 5]","[E 6]","[E 7]","[E 8]","[E 9]"},
		{"[F 1]","[F 2]","[F 3]","[F 4]","[F 5]","[F 6]","[F 7]","[F 8]","[F 9]"},
		{"[G 1]","[G 2]","[G 3]","[G 4]","[G 5]","[G 6]","[G 7]","[G 8]","[G 9]"},
		{"[H 1]","[H 2]","[H 3]","[H 4]","[H 5]","[H 6]","[H 7]","[H 8]","[H 9]"},
		{"[I 1]","[I 2]","[I 3]","[I 4]","[I 5]","[I 6]","[I 7]","[I 8]","[I 9]"},
};
string aiBattleMap[9][9] = {
		{"[A 1]","[A 2]","[A 3]","[A 4]","[A 5]","[A 6]","[A 7]","[A 8]","[A 9]"},
		{"[B 1]","[B 2]","[B 3]","[B 4]","[B 5]","[B 6]","[B 7]","[B 8]","[B 9]"},
		{"[C 1]","[C 2]","[C 3]","[C 4]","[C 5]","[C 6]","[C 7]","[C 8]","[C 9]"},
		{"[D 1]","[D 2]","[D 3]","[D 4]","[D 5]","[D 6]","[D 7]","[D 8]","[D 9]"},
		{"[E 1]","[E 2]","[E 3]","[E 4]","[E 5]","[E 6]","[E 7]","[E 8]","[E 9]"},
		{"[F 1]","[F 2]","[F 3]","[F 4]","[F 5]","[F 6]","[F 7]","[F 8]","[F 9]"},
		{"[G 1]","[G 2]","[G 3]","[G 4]","[G 5]","[G 6]","[G 7]","[G 8]","[G 9]"},
		{"[H 1]","[H 2]","[H 3]","[H 4]","[H 5]","[H 6]","[H 7]","[H 8]","[H 9]"},
		{"[I 1]","[I 2]","[I 3]","[I 4]","[I 5]","[I 6]","[I 7]","[I 8]","[I 9]"},
};

//Checks if the player/ai ships have been destroyed
bool allPlayerShipsDestroyed;
bool allAiShipsDestroyed;

//Checks and stores the placement of all of the player's ships
bool battleShipPlacementChecker1;
int battleShipGridSpace1;
int battleShipGridSpace2;
int battleShipGridSpace3;
int battleShipGridSpace4;
int battleShipGridSpace5;
bool carrierPlacementChecker1;
int carrierGridSpace1;
int carrierGridSpace2;
int carrierGridSpace3;
int carrierGridSpace4;
bool destroyerPlacementChecker1;
int destroyerGridSpace1;
int destroyerGridSpace2;
int destroyerGridSpace3;
bool submarinePlacementChecker1;
int submarineGridSpace1;
int submarineGridSpace2;
int submarineGridSpace3;
bool cruiserPlacementChecker1;
int cruiserGridSpace1;
int cruiserGridSpace2;

vector<int> illegalSpots;

//Stores the placement of the ai's ships
int aiBattleShip1;
int aiBattleShip2;
int aiBattleShip3;
int aiBattleShip4;
int aiBattleShip5;
int aiCarrier1;
int aiCarrier2;
int aiCarrier3;
int aiCarrier4;
int aiDestroyer1;
int aiDestroyer2;
int aiDestroyer3;
int aiSubmarine1;
int aiSubmarine2;
int aiSubmarine3;
int aiCruiser1;
int aiCruiser2;

//How the ai shoots and countinues to shoot at a hit target
int aiShot;
bool aiHit = false;
int lastGuess = 0;
int initailHit = 0;
int secondHit = 0;
int thirdHit = 0;
int fourthHit = 0;
bool isDestroyed = false;

//Checks to see if the last hit was on an edge
bool onLeftEdge = false;
bool onRightEdge = false;
bool onTopEdge = false;
bool onBottomEdge = false;

//Stores the amount of times a ship has been hit
int playerBattleShipHitCounter = 0;
bool playerBattleShipDestroyed = false;
int playerCarrierHitCounter = 0;
bool playerCarrierDestroyed = false;
int playerDestroyerHitCounter = 0;
bool playerDestroyerDestroyed = false;
int playerSubmarineHitCounter = 0;
bool playerSubmarineDestroyed = false;
int playerCruiserHitCounter = 0;
bool playerCruiserDestroyed = false;

//Stores the amount of times an ai's ship was hit
int aiBattleShipHitCounter = 0;
bool aiBattleShipDestroyed = false;
int aiCarrierHitCounter = 0;
bool aiCarrierDestroyed = false;
int aiDestroyerHitCounter = 0;
bool aiDestroyerDestroyed = false;
int aiSubmarineHitCounter = 0;
bool aiSubmarineDestroyed = false;
int aiCruiserHitCounter = 0;
bool aiCruiserDestroyed = false;

//Check to make sure a spot has not already been guessed by a player
vector<int> playerGuesses;

//Checks to make sure the ai has not already guessed a space
vector<int> aiGuesses;
vector<string> sidesGuessed;
bool switchDirections = false;

//Stores the ai's guess as a coordinate


//Checks to make sure a word has not already been selected to be used in hangman
/*
Could be replaced with a vector like the other ones. Kept in to show the progress
*/
int hmGuessed1 = 0;
int hmGuessed2 = 0;
int hmGuessed3 = 0;
int hmGuessed4 = 0;
int hmGuessed5 = 0;
int hmGuessed6 = 0;
int hmGuessed7 = 0;
int hmGuessed8 = 0;
int hmGuessed9 = 0;
int hmGuessed10 = 0;

//The Tic Tak Toe Board
char ticTakToeBoard[5][5] = {
		{'1' , '|' , '2' , '|' , '3'},
		{'-' , '-' , '-' , '-' , '-'},
		{'4' , '|' , '5' , '|' , '6'},
		{'-' , '-' , '-' , '-' , '-'},
		{'7' , '|' , '8' , '|' , '9'},
};

//Taken spaces in Tic Tac Toe
vector<int> takenSpaces;

//The Hangman's Post
char hangManGrid[5][4] = {
		{'_' , '_' , '_' , ' ' },
		{'|' , ' ' , '|' , ' ' },
		{'|' , ' ' , ' ' , ' ' },
		{'|' , ' ' , ' ' , ' ' },
		{'|' , ' ' , ' ' , ' ' }
};

//Letters already Guessed in hangman
vector<char> lettersGuessed;

//Checks to see if something has already been guessed
bool guessed = false;

//The Main Function. It all begins here
int main()
{

	srand(time(0));

	//Get's the players name and then sends it to the game picker
	cout << "Welcome! Please type your name" << endl;

	cin >> playerName;

	gamePicker();

}

//Picks the games
void gamePicker()
{

	//Asks the player which game they would like to play
	string gameChoice;

	cout << "Welcome " << playerName << " to the games. Please type what you would like to play!" << endl;
	
	cout << "Please type BS for Battleship, TTT for Tic Tak Toe, or HM for Hangman! To Quit type Q" << endl;

	cin >> gameChoice;

	//Sends the player to either battleShip, Tic Tak Toe, Hangman, or to quits
	if (gameChoice == "BS")
	{

		battleShip();

	}
	else if (gameChoice == "TTT")
	{

		ticTakToe();

	}
	else if (gameChoice == "HM")
	{

		hangMan();

	}
	else if (gameChoice == "Q")
	{

		quit();

	}

}

//The main Battleship game function
void battleShip()
{

	//Tracks the amount of ships destroyed both ai and player
	int numOfPlayerShipsDestroyed = 0;
	int numOfAiShipsDestroyed = 0;
	
	//Grid Coordinants for the Battleship
	string battleShip1;
	string battleShip2;
	string battleShip3;
	string battleShip4;
	string battleShip5;
	
	//Grid Coordinants for the Destroyer
	string carrier1;
	string carrier2;
	string carrier3;
	string carrier4;

	//Grid Coordinants for the Destroyer
	string destroyer1;
	string destroyer2;
	string destroyer3;

	//Grid Coordinants for the Submarine
	string submarine1;
	string submarine2;
	string submarine3;

	//Grid Coordinants for the Cruiser
	string cruiser1;
	string cruiser2;

	//Prints out the initial map
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (j == 8)
			{

				cout << playerBattleMap[i][j] << " " << endl;

			}
			else if (j < 8)
			{

				cout << playerBattleMap[i][j] << " ";

			}

		}

	}

	//Instructions
	cout << "It is recommended that CAPS lock be turned on while playing this game." << endl;

	cout << "For this game you will be using a series of coordinates to attack your opponent. Please type your answers with a capital letter followed by the number" << endl;

	cout << "Do not put ships right next to each other. There must be a gap inbetween. It will not let you progress unless this is true." << endl;

	cout << "Do not put a space inbetween them. EX A2 G6 I7" << endl;

	//Asks the player for battleship coordinants and then checks to make sure its a legal position
	while (true) {

		cout << "Please select five consecutive coordinants for your Battleship" << endl;

		cin >> battleShip1;
		cin >> battleShip2;
		cin >> battleShip3;
		cin >> battleShip4;
		cin >> battleShip5;

		battleShipPlacementChecker(battleShip1, battleShip2, battleShip3, battleShip4, battleShip5);

		if (battleShipPlacementChecker1 == true)
		{

			break;

		}

	}

	//Asks the player for carrier coordinants and then checks to make sure they are legal positions
	while (true)
	{

		cout << "Please select four consecutive coordinants that are not on your other ships for your Carrier" << endl;

		cin >> carrier1;
		cin >> carrier2;
		cin >> carrier3;
		cin >> carrier4;

		carrierPlacementChecker(carrier1, carrier2, carrier3, carrier4);

		if (carrierPlacementChecker1 == true)
		{

			break;

		}

	}

	//Asks the player for destroyer coordinants and then checks to make sure they are in legal positions
	while (true)
	{

		cout << "Please select three consecutive coordinants that are not on your other ships for your Destroyer" << endl;

		cin >> destroyer1;
		cin >> destroyer2;
		cin >> destroyer3;

		destroyerPlacementChecker(destroyer1, destroyer2, destroyer3);

		if (destroyerPlacementChecker1 == true)
		{

			break;

		}

	}

	//Asks the player for submarine coordinants, and then checks to make sure they are legal placements
	while (true)
	{

		cout << "Please select three consecutive coordinants that are not on your other ships for your Submarine" << endl;

		cin >> submarine1;
		cin >> submarine2;
		cin >> submarine3;

		submarinePlacementChecker(submarine1, submarine2, submarine3);

		if (submarinePlacementChecker1 == true)
		{

			break;

		}

	}

	//Asks the user for Cruiser placement, and checks to make sure it is a legal move
	while (true)
	{

		cout << "Please select two consecutive coordinants that are not on your other ships for your Cruiser" << endl;

		cin >> cruiser1;
		cin >> cruiser2;

		cruiserPlacementChecker(cruiser1, cruiser2);

		if (cruiserPlacementChecker1 == true)
		{

			break;

		}

	}

	shipToMap();

	//Prints out the map
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (j == 8)
			{

				cout <<	aiBattleMap[i][j] << " " << endl;

			}
			else if (j < 8)
			{

				cout << aiBattleMap[i][j] << " ";

			}

		}

	}

	cout << "-----------------------------------------------------" << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (j == 8)
			{

				cout << playerBattleMap[i][j] << " " << endl;

			}
			else if (j < 8)
			{

				cout << playerBattleMap[i][j] << " ";

			}

		}

	}

	//Chooses the AI's positions
	aiShipPlacer();

	//Continues until either the player or the AI wins. Cycles through players turn, AI's turn, and printing the map out
	while (true)
	{

		//The players turn
		playerTurn();

		//Checks to see if the player has won
		if (aiBattleShipDestroyed == true && aiCarrierDestroyed == true && aiDestroyerDestroyed == true && aiSubmarineDestroyed == true && aiCruiserDestroyed == true)
		{

			allAiShipsDestroyed = true;

		}

		//Informs the player that they have won
		if (allAiShipsDestroyed == true)
		{

			cout << "Captain " << playerName << ", we did it! We sunk all of their ships! It's all thanks to you!" << endl;

			break;

		}

		//The AI's Turn
		aiTurn();

		//Prints out the updated map
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{

				if (j == 8)
				{

					cout << aiBattleMap[i][j] << " " << endl;

				}
				else if (j < 8)
				{

					cout << aiBattleMap[i][j] << " ";

				}

			}

		}

		cout << "-----------------------------------------------------" << endl;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{

				if (j == 8)
				{

					cout << playerBattleMap[i][j] << " " << endl;

				}
				else if (j < 8)
				{

					cout << playerBattleMap[i][j] << " ";

				}

			}

		}

		//Checks to see if the AI has won
		if (playerBattleShipDestroyed == true && playerCarrierDestroyed == true && playerDestroyerDestroyed == true && playerSubmarineDestroyed == true && playerCruiserDestroyed == true)
		{

			allPlayerShipsDestroyed = true;

		}
		
		//Informs the player they have lost
		if (allPlayerShipsDestroyed == true)
		{

			cout << "Captain! All our ships have been destroyed! We've lost!" << endl;

			break;

		}

	}

	//Prints out the final map!
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (j == 8)
			{

				cout << aiBattleMap[i][j] << " " << endl;

			}
			else if (j < 8)
			{

				cout << aiBattleMap[i][j] << " ";

			}

		}

	}

	cout << "-----------------------------------------------------" << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (j == 8)
			{

				cout << playerBattleMap[i][j] << " " << endl;

			}
			else if (j < 8)
			{

				cout << playerBattleMap[i][j] << " ";

			}

		}

	}

	//Counts up the amount of player ships that were destroyed
	if (playerBattleShipDestroyed == true)
	{

		numOfPlayerShipsDestroyed++;

	}
	if (playerCarrierDestroyed == true)
	{

		numOfPlayerShipsDestroyed++;

	}
	if (playerDestroyerDestroyed == true)
	{

		numOfPlayerShipsDestroyed++;

	}
	if (playerSubmarineDestroyed == true)
	{

		numOfPlayerShipsDestroyed++;

	}
	if (playerCruiserDestroyed == true)
	{

		numOfPlayerShipsDestroyed++;

	}

	//Counts up the amount of destroyed enemy ships
	if (aiBattleShipDestroyed == true)
	{

		numOfAiShipsDestroyed++;

	}
	if (aiCarrierDestroyed == true)
	{

		numOfAiShipsDestroyed++;

	}
	if (aiDestroyerDestroyed == true)
	{

		numOfAiShipsDestroyed++;

	}
	if (aiSubmarineDestroyed == true)
	{

		numOfAiShipsDestroyed++;

	}
	if (aiCruiserDestroyed == true)
	{

		numOfAiShipsDestroyed++;

	}

	cout << "Number of Your Ships Destroyed: " << numOfPlayerShipsDestroyed << endl;
	cout << "Number of Enemy Ships Destroyed: " << numOfAiShipsDestroyed << endl;

	system("pause");

	sidesGuessed.clear();
	playerGuesses.clear();
	aiGuesses.clear();
	illegalSpots.clear();

	gamePicker();

}

/*
For the Checkers
Need to try to spread out the ships so they cannot be placed right next to each other.
Game still technically works, but it could throw off the ai if all the ships are right next to each other

Resolved
*/

int spaceGiver(int findSpace)
{

	int rightSpace = findSpace + 1;
	int leftSpace = findSpace - 1;
	int topSpace = findSpace - 9;
	int bottomSpace = findSpace + 9;

	edgeChecker(findSpace);

	if (onLeftEdge == true)
	{

		if (onTopEdge == true)
		{

			illegalSpots.push_back(rightSpace);
			illegalSpots.push_back(bottomSpace);

		}
		else if (onBottomEdge == true)
		{

			illegalSpots.push_back(rightSpace);
			illegalSpots.push_back(topSpace);

		}
		else
		{

			illegalSpots.push_back(rightSpace);
			illegalSpots.push_back(bottomSpace);
			illegalSpots.push_back(topSpace);

		}

	}
	else if (onRightEdge == true)
	{

		if (onTopEdge == true)
		{

			illegalSpots.push_back(leftSpace);
			illegalSpots.push_back(bottomSpace);

		}
		else if (onBottomEdge == true)
		{

			illegalSpots.push_back(leftSpace);
			illegalSpots.push_back(topSpace);

		}
		else
		{

			illegalSpots.push_back(leftSpace);
			illegalSpots.push_back(bottomSpace);
			illegalSpots.push_back(topSpace);

		}

	}
	else if (onTopEdge == true)
	{

		illegalSpots.push_back(rightSpace);
		illegalSpots.push_back(bottomSpace);
		illegalSpots.push_back(leftSpace);

	}
	else if (onBottomEdge == true)
	{

		illegalSpots.push_back(rightSpace);
		illegalSpots.push_back(leftSpace);
		illegalSpots.push_back(topSpace);

	}
	else
	{

		illegalSpots.push_back(rightSpace);
		illegalSpots.push_back(bottomSpace);
		illegalSpots.push_back(leftSpace);
		illegalSpots.push_back(topSpace);

	}

	for (int i = 0; i < illegalSpots.size(); i++)
	{

		return illegalSpots[i];

	}

	onRightEdge = false;
	onBottomEdge = false;
	onLeftEdge = false;
	onTopEdge = false;

}

//Checks the placement of the battleship
bool battleShipPlacementChecker(string placement1, string placement2, string placement3, string placement4, string placement5)
{

	//Turns the battleships grid spaces into numbers the computer can understand
	battleShipGridSpace1 = coorToGrid(placement1);
	battleShipGridSpace2 = coorToGrid(placement2);
	battleShipGridSpace3 = coorToGrid(placement3);
	battleShipGridSpace4 = coorToGrid(placement4);
	battleShipGridSpace5 = coorToGrid(placement5);

	//Gets the distance between the coordinants
	int battleShipChecker1 = battleShipGridSpace2 - battleShipGridSpace1;
	int battleShipChecker2 = battleShipGridSpace3 - battleShipGridSpace2;
	int battleShipChecker3 = battleShipGridSpace4 - battleShipGridSpace3;
	int battleShipChecker4 = battleShipGridSpace5 - battleShipGridSpace4;

	//Makes sure that the placements are an appropriate number away. If one fails, they all fail.
	if (battleShipChecker1 == 1 && battleShipGridSpace1 != 9 || battleShipChecker1 == -1 && battleShipGridSpace1 != 10 || battleShipChecker1 == 9 || battleShipChecker1 == -9)
	{

		battleShipPlacementChecker1 = true;

		if (battleShipChecker2 == 1 && battleShipGridSpace2 != 9 || battleShipChecker2 == -1 && battleShipGridSpace2 != 10 || battleShipChecker2 == 9 || battleShipChecker2 == -9)
		{

			battleShipPlacementChecker1 = true;

			if (battleShipChecker3 == 1 && battleShipGridSpace3 != 9 || battleShipChecker3 == -1 && battleShipGridSpace3 != 10 || battleShipChecker3 == 9 || battleShipChecker3 == -9)
			{

				battleShipPlacementChecker1 = true;

				if (battleShipChecker4 == 1 && battleShipGridSpace4 != 9 || battleShipChecker4 == -1 && battleShipGridSpace4 != 10 || battleShipChecker4 == 9 || battleShipChecker4 == -9)
				{

					battleShipPlacementChecker1 = true;

				}
				else
				{

					battleShipPlacementChecker1 = false;

				}

			}
			else
			{

				battleShipPlacementChecker1 = false;

			}

		}
		else
		{

			battleShipPlacementChecker1 = false;

		}

	}
	else
	{

		battleShipPlacementChecker1 = false;

	}

	//Gives space on every side that cannot be placed on
	if (battleShipPlacementChecker1 == true)
	{

		spaceGiver(battleShipGridSpace1);
		spaceGiver(battleShipGridSpace2);
		spaceGiver(battleShipGridSpace3);
		spaceGiver(battleShipGridSpace4);
		spaceGiver(battleShipGridSpace5);

	}

	//Returns true or false whether the check succeeded or failed.
	return battleShipPlacementChecker1;

}

//Checks the placement of the carrier
bool carrierPlacementChecker(string placement1, string placement2, string placement3, string placement4)
{

	//Turns the carrier grid positions into numbers that the computer can understand
	carrierGridSpace1 = coorToGrid(placement1);
	carrierGridSpace2 = coorToGrid(placement2);
	carrierGridSpace3 = coorToGrid(placement3);
	carrierGridSpace4 = coorToGrid(placement4);

	//Gets the distance between boat sections
	int carrierChecker1 = carrierGridSpace2 - carrierGridSpace1;
	int carrierChecker2 = carrierGridSpace3 - carrierGridSpace2;
	int carrierChecker3 = carrierGridSpace4 - carrierGridSpace3;

	//Checks that the boat is all in a line, and that it is not on the same spot as the battleship
	if (carrierChecker1 == 1 && carrierGridSpace1 != 9 || carrierChecker1 == -1 && carrierGridSpace1 != 10 || carrierChecker1 == 9 || carrierChecker1 == -9)
	{

		carrierPlacementChecker1 = true;

		if (carrierChecker2 == 1 && carrierGridSpace2 != 9 || carrierChecker2 == -1 && carrierGridSpace2 != 10 || carrierChecker2 == 9 || carrierChecker2 == -9)
		{

			carrierPlacementChecker1 = true;

			if (carrierChecker3 == 1 && carrierGridSpace3 != 9 || carrierChecker3 == -1 && carrierGridSpace3 != 10 || carrierChecker3 == 9 || carrierChecker3 == -9)
			{

				carrierPlacementChecker1 = true;

				for (int i = 0; i < illegalSpots.size(); i++)
				{

					if (carrierGridSpace1 == illegalSpots[i])
					{

						carrierPlacementChecker1 = false;

					}

				}

				for (int i = 0; i < illegalSpots.size(); i++)
				{

					if (carrierGridSpace2 == illegalSpots[i])
					{

						carrierPlacementChecker1 = false;

					}

				}

				for (int i = 0; i < illegalSpots.size(); i++)
				{

					if (carrierGridSpace3 == illegalSpots[i])
					{

						carrierPlacementChecker1 = false;

					}

				}

				for (int i = 0; i < illegalSpots.size(); i++)
				{

					if (carrierGridSpace4 == illegalSpots[i])
					{

						carrierPlacementChecker1 = false;			

					}

				}

			}
			else
			{

				carrierPlacementChecker1 = false;

			}

		}
		else
		{

			carrierPlacementChecker1 = false;

		}

	}
	else
	{

		carrierPlacementChecker1 = false;

	}

	//Gives a space on every side that cannot be placed on
	if (carrierPlacementChecker1 == true)
	{

		spaceGiver(carrierGridSpace1);
		spaceGiver(carrierGridSpace2);
		spaceGiver(carrierGridSpace3);
		spaceGiver(carrierGridSpace4);

	}
	
	//Returns either true or false depending on whether it succeeded or failed
	return carrierPlacementChecker1;

}

//Checks the placement of the destroyer
bool destroyerPlacementChecker(string placement1, string placement2, string placement3)
{

	//Turns the destroyer grid spaces into numbers the computer can read
	destroyerGridSpace1 = coorToGrid(placement1);
	destroyerGridSpace2 = coorToGrid(placement2);
	destroyerGridSpace3 = coorToGrid(placement3);

	//Gets the distance between boat sections
	int destroyerChecker1 = destroyerGridSpace2 - destroyerGridSpace1;
	int destroyerChecker2 = destroyerGridSpace3 - destroyerGridSpace2;

	//Checks to see if the distance between sections is appropriate and that it is not on the same spot as the battleship or carrier
	if (destroyerChecker1 == 1 && destroyerGridSpace1 != 9 || destroyerChecker1 == -1 && destroyerGridSpace1 != 10 || destroyerChecker1 == 9 || destroyerChecker1 == -9)
	{

		destroyerPlacementChecker1 = true;

		if (destroyerChecker2 == 1 && destroyerGridSpace2 != 9 || destroyerChecker2 == -1 && destroyerGridSpace2 != 10 || destroyerChecker2 == 9 || destroyerChecker2 == -9)
		{

			destroyerPlacementChecker1 = true;

			for (int i = 0; i < illegalSpots.size(); i++)
			{

				if (destroyerGridSpace1 == illegalSpots[i])
				{

					destroyerPlacementChecker1 = false;

				}

			}

			for (int i = 0; i < illegalSpots.size(); i++)
			{

				if (destroyerGridSpace2 == illegalSpots[i])
				{

					destroyerPlacementChecker1 = false;

				}

			}

			for (int i = 0; i < illegalSpots.size(); i++)
			{

				if (destroyerGridSpace3 == illegalSpots[i])
				{

					destroyerPlacementChecker1 = false;

				}
	

			}

		}
		else
		{

			destroyerPlacementChecker1 = false;

		}

	}
	else
	{

		destroyerPlacementChecker1 = false;

	}

	//Gives space on every side of the ship after it is in a legal spot
	if (destroyerPlacementChecker1 == true)
	{

		spaceGiver(destroyerGridSpace1);
		spaceGiver(destroyerGridSpace2);
		spaceGiver(destroyerGridSpace3);

	}

	//Returns either true or false depending on whether it succeeded or failed
	return destroyerPlacementChecker1;

}

//Checks the placement of the submarine
bool submarinePlacementChecker(string placement1, string placement2, string placement3)
{

	//Turns the submarine grid spaces into numbers that the computer can read
	submarineGridSpace1 = coorToGrid(placement1);
	submarineGridSpace2 = coorToGrid(placement2);
	submarineGridSpace3 = coorToGrid(placement3);

	//Gets the distance between the boat placements
	int submarineChecker1 = submarineGridSpace2 - submarineGridSpace1;
	int submarineChecker2 = submarineGridSpace3 - submarineGridSpace2;

	//Check that distances are the appropriate sizes and that it is not on the battleship, carrier, or destroyer
	if (submarineChecker1 == 1 && submarineGridSpace1 != 9 || submarineChecker1 == -1 && submarineGridSpace1 != 10 || submarineChecker1 == 9 || submarineChecker1 == -9)
	{

		submarinePlacementChecker1 = true;

		if (submarineChecker2 == 1 && submarineGridSpace2 != 9 || submarineChecker2 == -1 && submarineGridSpace2 != 10 || submarineChecker2 == 9 || submarineChecker2 == -9)
		{

			submarinePlacementChecker1 = true;

			for (int i = 0; i < illegalSpots.size(); i++)
			{

				if (submarineGridSpace1 == illegalSpots[i])
				{

					submarinePlacementChecker1 = false;

				}

			}

			for (int i = 0; i < illegalSpots.size(); i++)
			{

				if (submarineGridSpace2 == illegalSpots[i])
				{

					submarinePlacementChecker1 = false;

				}

			}

			for (int i = 0; i < illegalSpots.size(); i++)
			{

				if (submarineGridSpace3 == illegalSpots[i])
				{

					submarinePlacementChecker1 = false;

				}		

			}

		}
		else
		{

			submarinePlacementChecker1 = false;

		}

	}
	else
	{

		submarinePlacementChecker1 = false;

	}

	//Gives a space on every side of the ship that cannot be placed on
	if (submarinePlacementChecker1 == true)
	{

		spaceGiver(submarineGridSpace1);
		spaceGiver(submarineGridSpace2);
		spaceGiver(submarineGridSpace3);

	}

	//Returns true or false based on whether the check succeeded or failed
	return submarinePlacementChecker1;

}

//Checks the placemtent of the cruiser
bool cruiserPlacementChecker(string placement1, string placement2)
{

	//Turns the cruiser spaces into numbers so the computer can use them
	cruiserGridSpace1 = coorToGrid(placement1);
	cruiserGridSpace2 = coorToGrid(placement2);

	//Gets the space between boat placements
	int cruiserChecker1 = cruiserGridSpace2 - cruiserGridSpace1;

	//Checks that the space is appropriate and that it is not on the same spot as the battleship, carrier, destroyer, and submarine
	if (cruiserChecker1 == 1 && cruiserGridSpace1 != 9 || cruiserChecker1 == -1 && cruiserGridSpace1 != 10 || cruiserChecker1 == 9 || cruiserChecker1 == -9)
	{

		cruiserPlacementChecker1 = true;

		for (int i = 0; i < illegalSpots.size(); i++)
		{

			if (cruiserGridSpace1 == illegalSpots[i])
			{

				cruiserPlacementChecker1 = false;

			}

		}
		
		for (int i = 0; i < illegalSpots.size(); i++)
		{

			if (cruiserGridSpace2 == illegalSpots[i])
			{

				cruiserPlacementChecker1 = false;

			}		

		}

	}
	else
	{

		cruiserPlacementChecker1 = false;

	}

	//Returns true or false depending on whether it succeeded or failed
	return cruiserPlacementChecker1;

}

//Gets the position of the ai's ships, not placed on the map, just stored in memory
int aiShipPlacer()
{

	//The Ten Variants of ship placements for the ai
	int shipPlacement1[17] = {65,56,47,38,29,17,16,15,14,4,13,22,51,52,53,41,32};
	int shipPlacement2[17] = {31,40,49,58,67,45,36,27,18,1,2,3,81,72,63,64,55};
	int shipPlacement3[17] = {11,12,13,14,15,30,39,48,57,72,71,70,50,41,32,1,2};
	int shipPlacement4[17] = {5,6,7,8,9,24,33,42,51,47,48,49,20,11,2,60,61};
	int shipPlacement5[17] = {46,47,48,49,50,9,18,27,36,66,67,68,79,80,81,10,19};
	int shipPlacement6[17] = {59,50,41,32,23,3,12,21,30,74,75,76,69,70,71,35,36};
	int shipPlacement7[17] = {73,74,75,76,77,9,18,27,36,10,11,12,42,33,24,59,60};
	int shipPlacement8[17] = {41,42,43,44,45,13,22,31,40,1,10,19,79,80,81,66,67};
	int shipPlacement9[17] = {25,34,43,52,61,2,3,4,5,22,23,24,68,69,70,71,80};
	int shipPlacement10[17] = {73,74,75,76,77,72,63,54,45,11,12,13,9,18,27,59,60};

	//The one that will house the actual ship placement
	int masterPlacement[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	//Picks a random one between one and ten
	int mapPicker = (rand() % 10) + 1;

	//Which ever one it is, it then assigns every spot of the masterPlacement to that of the selected ship placement
	if (mapPicker == 1)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement1[i];

		}

	}
	else if (mapPicker == 2)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement2[i];

		}

	}
	else if (mapPicker == 3)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement3[i];

		}

	}
	else if (mapPicker == 4)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement4[i];

		}

	}
	else if (mapPicker == 5)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement5[i];

		}

	}
	else if (mapPicker == 6)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement6[i];

		}

	}
	else if (mapPicker == 7)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement7[i];

		}

	}
	else if (mapPicker == 8)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement8[i];

		}

	}
	else if (mapPicker == 9)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement9[i];

		}

	}
	else if (mapPicker == 10)
	{

		for (int i = 0; i < 17; i++)
		{

			masterPlacement[i] = shipPlacement10[i];

		}

	}

	//Gets the actual coordinants for the ships and stores them
	aiBattleShip1 = masterPlacement[0];
	aiBattleShip2 = masterPlacement[1];
	aiBattleShip3 = masterPlacement[2];
	aiBattleShip4 = masterPlacement[3];
	aiBattleShip5 = masterPlacement[4];
	aiCarrier1 = masterPlacement[5];
	aiCarrier2 = masterPlacement[6];
	aiCarrier3 = masterPlacement[7];
	aiCarrier4 = masterPlacement[8];
	aiDestroyer1 = masterPlacement[9];
	aiDestroyer2 = masterPlacement[10];
	aiDestroyer3 = masterPlacement[11];
	aiSubmarine1 = masterPlacement[12];
	aiSubmarine2 = masterPlacement[13];
	aiSubmarine3 = masterPlacement[14];
	aiCruiser1 = masterPlacement[15];
	aiCruiser2 = masterPlacement[16];

	//Returns all ship placements. They are ready to be played
	return aiBattleShip1;
	return aiBattleShip2;
	return aiBattleShip3;
	return aiBattleShip4;
	return aiBattleShip5;
	return aiCarrier1;
	return aiCarrier2;
	return aiCarrier3;
	return aiCarrier4;
	return aiDestroyer1;
	return aiDestroyer2;
	return aiDestroyer3;
	return aiSubmarine1;
	return aiSubmarine2;
	return aiSubmarine3;
	return aiCruiser1;
	return aiCruiser2;

}

//The Player's turn
void playerTurn()
{

	//The shot that the player inputs turned into numbers
	int playerShotCoor;

	//Gets a grid space from the player and checks to make sure it has not been guessed by the player
	while (true)
	{

		cout << "Where would you like to shoot captain?" << endl;

		string playerShot;

		cin >> playerShot;

		playerShotCoor = coorToGrid(playerShot);

		alreadyGuessed("Player", playerShotCoor);

		if (guessed == false)
		{

			playerGuesses.push_back(playerShotCoor);

			break;

		}
		else
		{

			cout << "We have already shot there captain!" << endl;

		}

	}

	//Checks to see if one of the ai's ships has been hit. Also checks to see if it has been destroyed
	if (playerShotCoor == aiBattleShip1 || playerShotCoor == aiBattleShip2 || playerShotCoor == aiBattleShip3 || playerShotCoor == aiBattleShip4 || playerShotCoor == aiBattleShip5)
	{

		cout << "That is a confirmed hit! Nice shooting captain!" << endl;

		aiBattleShipHitCounter++;

		updateMapHit("Player", playerShotCoor);

		if (aiBattleShipHitCounter == 5)
		{

			aiBattleShipDestroyed = true;

			cout << "We've destroyed their Battleship!" << endl;

		}

	}
	else if (playerShotCoor == aiCarrier1 || playerShotCoor == aiCarrier2 || playerShotCoor == aiCarrier3 || playerShotCoor == aiCarrier4)
	{

		cout << "That is a confirmed hit! Nice shooting captain!" << endl;

		aiCarrierHitCounter++;

		updateMapHit("Player", playerShotCoor);

		if (aiCarrierHitCounter == 4)
		{

			aiCarrierDestroyed = true;

			cout << "We've destroyed their Carrier!" << endl;

		}

	}
	else if (playerShotCoor == aiDestroyer1 || playerShotCoor == aiDestroyer2 || playerShotCoor == aiDestroyer3)
	{

		cout << "That is a confirmed hit! Nice shooting captain!" << endl;

		aiDestroyerHitCounter++;

		updateMapHit("Player", playerShotCoor);

		if (aiDestroyerHitCounter == 3)
		{

			aiDestroyerDestroyed = true;

			cout << "We've destroyed their Destroyer!" << endl;

		}

	}
	else if (playerShotCoor == aiSubmarine1 || playerShotCoor == aiSubmarine2 || playerShotCoor == aiSubmarine3)
	{

		cout << "That is a confirmed hit! Nice shooting captain!" << endl;

		aiSubmarineHitCounter++;

		updateMapHit("Player", playerShotCoor);

		if (aiSubmarineHitCounter == 3)
		{

			aiSubmarineDestroyed = true;

			cout << "We've destroyed their Submarine!" << endl;

		}

	}
	else if (playerShotCoor == aiCruiser1 || playerShotCoor == aiCruiser2)
	{

		cout << "That is a confirmed hit! Nice shooting captain!" << endl;

		aiCruiserHitCounter++;

		updateMapHit("Player", playerShotCoor);

		if (aiCruiserHitCounter == 2)
		{

			aiCruiserDestroyed = true;

			cout << "We've destroyed their Cruiser!" << endl;

		}

	}
	else
	{

		cout << "I think we missed them" << endl;

		updateMapMiss("Player", playerShotCoor);

	}

}

//The AI's shooting pattern
void aiTurn()
{

	//Sides that have been guessed after the initial hit
	bool rightGuessed = false;
	bool leftGuessed = false;
	bool topGuessed = false;
	bool bottomGuessed = false;

	/*
	Does one of four things.If a ship has been hit and not destroyed it tries to find the ship. If there is no ship hit and not destroyed
	but it is not the first turn, it shoots in a grid pattern. If it reaches the end of the grid, it goes back to the begining. 
	Finally if it is the first turn it will shoot in a random location.

	*/
	while (true)
	{

		if (aiHit == true)
		{

			//This is trying to get the direction of the boat
			if (secondHit == 0)
			{

				//Checks to see if the shot is on the edge of the grid
				edgeChecker(aiShot);

				if (onRightEdge == true)
				{

					sidesGuessed.push_back("right");

				}

				if (onBottomEdge == true)
				{

					sidesGuessed.push_back("bottom");

				}

				if (onLeftEdge == true)
				{

					sidesGuessed.push_back("left");

				}

				if (onTopEdge == true)
				{

					sidesGuessed.push_back("top");

				}

				//Checks to see which sides have been guessed in the pass and failed
				for (int i = 0; i < sidesGuessed.size(); i++)
				{

					if ("right" == sidesGuessed[i])
					{

						rightGuessed = true;

					}
					else if ("left" == sidesGuessed[i])
					{

						leftGuessed = true;

					}
					else if ("top" == sidesGuessed[i])
					{

						topGuessed = true;

					}
					else if ("bottom" == sidesGuessed[i])
					{

						bottomGuessed = true;

					}

				}

				//Shoots in a direction based on previous knowledge. In this case it will shoot up
				if (rightGuessed == true && leftGuessed == true && bottomGuessed == true)
				{

					aiShot = initailHit - 9;

					alreadyGuessed("AI", aiShot);

					sidesGuessed.push_back("top");

					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						lastGuess = aiShot;

						break;

					}

				}
				//In this case it will shoot left unless it is on the left edge, in which case it will shoot up
				else if (rightGuessed == true && bottomGuessed == true)
				{

					if (onLeftEdge == false)
					{

						aiShot = initailHit - 1;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("left");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}
					else
					{

						aiShot = initailHit - 9;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("top");

						if (guessed == false) 
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}

				}
				//This will shoot down unless it is on the bottom edge, then it will shoot left unless it is on the left edge. In that case it would shoot up
				else if (rightGuessed == true)
				{

					if (onBottomEdge == false)
					{

						aiShot = initailHit + 9;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("bottom");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}
					else if (onLeftEdge == false)
					{

						aiShot = initailHit - 1;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("left");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}
					else
					{

						aiShot = initailHit - 9;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("top");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}

				}
				//This will shoot down, unless it is on the bottom edge, then it would shoot left unless it is also somehow on the left edge as well. In that case it would shoot up
				else if (onRightEdge == true)
				{

					if (onBottomEdge == false)
					{

						aiShot = initailHit + 9;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("bottom");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}
					else if (onLeftEdge == false)
					{

						aiShot = initailHit - 1;
	
						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("left");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}
					else
					{

						aiShot = initailHit - 9;

						alreadyGuessed("AI", aiShot);

						sidesGuessed.push_back("top");

						if (guessed == false)
						{

							aiGuesses.push_back(aiShot);

							lastGuess = aiShot;

							break;

						}

					}

				}
				//This just shoots right. The default side it will shoot
				else
				{

					aiShot = initailHit + 1;

					alreadyGuessed("AI", aiShot);

					sidesGuessed.push_back("right");

					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						lastGuess = aiShot;

						break;

					}

				}

			}
			//This one just takes the direction it got from the last two shots, and continues on that tragectory, unless it misses
			else if (thirdHit == 0)
			{

			int nextSpot = secondHit - initailHit;
				
				if (switchDirections == false)
				{

					aiShot = secondHit + nextSpot;
	
					alreadyGuessed("AI", aiShot);
	
					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						lastGuess = aiShot;

						switchDirections = true;

						break;

					}

				}
				//This switches directions to go back and get any pieces that were skipped over
				else if (switchDirections == true)
				{

					aiShot = initailHit - nextSpot;

					alreadyGuessed("AI", aiShot);

					secondHit = initailHit;

					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						switchDirections = true;

						break;

					}

				}

			}
			//Similar to the third hit
			else if (fourthHit == 0)
			{

			int nextSpot = thirdHit - secondHit;

				if (switchDirections == false)
				{

					aiShot = thirdHit + nextSpot;

					alreadyGuessed("AI", aiShot);

					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						lastGuess = aiShot;

						switchDirections = true;

						break;

					}

				}
				//Again switches directions to grab any straglers it missed
				else if (switchDirections == true)
				{

					aiShot = initailHit - nextSpot;

					alreadyGuessed("AI", aiShot);

					thirdHit = initailHit;
	
					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						switchDirections = true;

						break;

					}

				}

			}
			//Gets the final piece, unless it misses
			else if (fourthHit != 0)
			{

			int nextSpot = fourthHit - thirdHit;

				if (switchDirections == false)
				{

					aiShot = fourthHit + nextSpot;

					alreadyGuessed("AI", aiShot);

					if (guessed == false)
					{
	
						aiGuesses.push_back(aiShot);

						lastGuess = aiShot;

						switchDirections = true;

						break;

					}

				}
				//Switches to get the final piece
				else if (switchDirections == true)
				{

					aiShot = initailHit - nextSpot;
	
					alreadyGuessed("AI", aiShot);

					if (guessed == false)
					{

						aiGuesses.push_back(aiShot);

						switchDirections = true;

						break;

					}

				}

			}

		}
		//Shoots in a random place to start the game
		else if (lastGuess == 0)
		{

			aiShot = (rand() % 81) + 1;

			alreadyGuessed("AI", aiShot);

			lastGuess = aiShot;

			if (guessed == false)
			{

				aiGuesses.push_back(aiShot);

				break;

			}

		}
		//Shoots in a grid until it reaches the end of the grid
		else if (lastGuess != 0 && lastGuess <=79)
		{

			aiShot = lastGuess + 2;

			alreadyGuessed("AI", aiShot);

			lastGuess = aiShot;

			if (guessed == false)
			{

				aiGuesses.push_back(aiShot);

				break;

			}

		}
		//Moves shot back to the begining of the grid 
		else if (lastGuess >= 80)
		{

			if (lastGuess == 80)
			{

				aiShot = 2;

				alreadyGuessed("AI", aiShot);

				lastGuess = aiShot;

				if (guessed == false)
				{

					aiGuesses.push_back(aiShot);

					break;

				}

			}
			else if (lastGuess == 81)
			{

				aiShot = 1;

				alreadyGuessed("AI", aiShot);

				lastGuess = aiShot;

				if (guessed == false)
				{

					aiGuesses.push_back(aiShot);

					break;

				}

			}

		}

	}

	cout << "AI: " << gridToCoor(aiShot) << endl;

	system("pause");

	//Checks to see if the ai hit a player's ship
	if (aiShot == battleShipGridSpace1 || aiShot == battleShipGridSpace2 || aiShot == battleShipGridSpace3 || aiShot == battleShipGridSpace4 || aiShot == battleShipGridSpace5)
	{

		aiHit = true;

		if (initailHit == 0)
		{

			initailHit = aiShot;

		}
		else if (secondHit == 0)
		{

			secondHit = aiShot;

		}
		else if (thirdHit == 0)
		{

			thirdHit = aiShot;

		}
		else if (fourthHit == 0)
		{

			fourthHit = aiShot;

		}

		cout << "We've been hit captain!" << endl;

		playerBattleShipHitCounter++;

		updateMapHit("AI", aiShot);

		switchDirections = false;

		if (playerBattleShipHitCounter == 5)
		{

			playerBattleShipDestroyed = true;

			cout << "Our Battleship has been destroyed!" << endl;

			sidesGuessed.clear();

			aiHit = false;

			initailHit = 0;
			secondHit = 0;
			thirdHit = 0;
			fourthHit = 0;

		}

	}
	else if (aiShot == carrierGridSpace1 || aiShot == carrierGridSpace2 || aiShot == carrierGridSpace3 || aiShot == carrierGridSpace4)
	{

		aiHit = true;

		if (initailHit == 0)
		{

			initailHit = aiShot;

		}
		else if (secondHit == 0)
		{

			secondHit = aiShot;

		}
		else if (thirdHit == 0)
		{

			thirdHit = aiShot;

		}

		cout << "We've been hit captain!" << endl;

		playerCarrierHitCounter++;

		updateMapHit("AI", aiShot);

		switchDirections = false;

		if (playerCarrierHitCounter == 4)
		{

			playerCarrierDestroyed = true;

			cout << "Our Carrier has been destroyed!" << endl;

			sidesGuessed.clear();

			aiHit = false;

			initailHit = 0;
			secondHit = 0;
			thirdHit = 0;

		}

	}
	else if (aiShot == destroyerGridSpace1 || aiShot == destroyerGridSpace2 || aiShot == destroyerGridSpace3)
	{

		aiHit = true;

		if (initailHit == 0)
		{

			initailHit = aiShot;

		}
		else if (secondHit == 0)
		{

			secondHit = aiShot;

		}

		cout << "We've been hit captain!" << endl;

		playerDestroyerHitCounter++;

		updateMapHit("AI", aiShot);

		switchDirections = false;

		if (playerDestroyerHitCounter == 3)
		{

			playerDestroyerDestroyed = true;

			cout << "Our Destroyer has been destroyed!" << endl;

			sidesGuessed.clear();

			aiHit = false;

			initailHit = 0;
			secondHit = 0;

		}

	}
	else if (aiShot == submarineGridSpace1 || aiShot == submarineGridSpace2 || aiShot == submarineGridSpace3)
	{

		aiHit = true;

		if (initailHit == 0)
		{

			initailHit = aiShot;

		}
		else if (secondHit == 0)
		{

			secondHit = aiShot;

		}

		cout << "We've been hit captain!" << endl;

		playerSubmarineHitCounter++;

		updateMapHit("AI", aiShot);

		switchDirections = false;

		if (playerSubmarineHitCounter == 3)
		{

			playerSubmarineDestroyed = true;

			cout << "Our Submarine has been destroyed!" << endl;

			sidesGuessed.clear();

			aiHit = false;

			initailHit = 0;
			secondHit = 0;

		}

	}
	else if (aiShot == cruiserGridSpace1 || aiShot == cruiserGridSpace2)
	{

		aiHit = true;

		if (initailHit == 0)
		{

			initailHit = aiShot;

		}

		cout << "We've been hit captain!" << endl;

		playerCruiserHitCounter++;

		updateMapHit("AI", aiShot);

		switchDirections = false;

		if (playerCruiserHitCounter == 2)
		{

			playerCruiserDestroyed = true;

			cout << "Our Cruiser has been destroyed!" << endl;

			sidesGuessed.clear();

			aiHit = false;

			initailHit = 0;

		}

	}
	else
	{

		cout << "They missed us!" << endl;

		updateMapMiss("AI", aiShot);

	}

}

//Updates the map for hits. Takes in either player or AI and a number and tells the computer to mark it with an X
void updateMapHit(string whichPlayer, int whichSpot)
{

	//The AI's X's
	if (whichPlayer == "AI")
	{

		if (whichSpot == 1)
		{

			playerBattleMap[0][0] = "[ X ]";

		}
		else if (whichSpot == 2)
		{

			playerBattleMap[0][1] = "[ X ]";

		}
		else if (whichSpot == 3)
		{

			playerBattleMap[0][2] = "[ X ]";

		}
		else if (whichSpot == 4)
		{

			playerBattleMap[0][3] = "[ X ]";

		}
		else if (whichSpot == 5)
		{

			playerBattleMap[0][4] = "[ X ]";

		}
		else if (whichSpot == 6)
		{

			playerBattleMap[0][5] = "[ X ]";

		}
		else if (whichSpot == 7)
		{

			playerBattleMap[0][6] = "[ X ]";

		}
		else if (whichSpot == 8)
		{

			playerBattleMap[0][7] = "[ X ]";

		}
		else if (whichSpot == 9)
		{

			playerBattleMap[0][8] = "[ X ]";

		}
		else if (whichSpot == 10)
		{

			playerBattleMap[1][0] = "[ X ]";

		}
		else if (whichSpot == 11)
		{

			playerBattleMap[1][1] = "[ X ]";

		}
		else if (whichSpot == 12)
		{

			playerBattleMap[1][2] = "[ X ]";

		}
		else if (whichSpot == 13)
		{

			playerBattleMap[1][3] = "[ X ]";

		}
		else if (whichSpot == 14)
		{

			playerBattleMap[1][4] = "[ X ]";

		}
		else if (whichSpot == 15)
		{

			playerBattleMap[1][5] = "[ X ]";

		}
		else if (whichSpot == 16)
		{

			playerBattleMap[1][6] = "[ X ]";

		}
		else if (whichSpot == 17)
		{

			playerBattleMap[1][7] = "[ X ]";

		}
		else if (whichSpot == 18)
		{

			playerBattleMap[1][8] = "[ X ]";

		}
		else if (whichSpot == 19)
		{

			playerBattleMap[2][0] = "[ X ]";

		}
		else if (whichSpot == 20)
		{

			playerBattleMap[2][1] = "[ X ]";

		}
		else if (whichSpot == 21)
		{

			playerBattleMap[2][2] = "[ X ]";

		}
		else if (whichSpot == 22)
		{

			playerBattleMap[2][3] = "[ X ]";

		}
		else if (whichSpot == 23)
		{

			playerBattleMap[2][4] = "[ X ]";

		}
		else if (whichSpot == 24)
		{

			playerBattleMap[2][5] = "[ X ]";

		}
		else if (whichSpot == 25)
		{

			playerBattleMap[2][6] = "[ X ]";

		}
		else if (whichSpot == 26)
		{

			playerBattleMap[2][7] = "[ X ]";

		}
		else if (whichSpot == 27)
		{

			playerBattleMap[2][8] = "[ X ]";

		}
		else if (whichSpot == 28)
		{

			playerBattleMap[3][0] = "[ X ]";

		}
		else if (whichSpot == 29)
		{

			playerBattleMap[3][1] = "[ X ]";

		}
		else if (whichSpot == 30)
		{

			playerBattleMap[3][2] = "[ X ]";

		}
		else if (whichSpot == 31)
		{

			playerBattleMap[3][3] = "[ X ]";

		}
		else if (whichSpot == 32)
		{

			playerBattleMap[3][4] = "[ X ]";

		}
		else if (whichSpot == 33)
		{

			playerBattleMap[3][5] = "[ X ]";

		}
		else if (whichSpot == 34)
		{

			playerBattleMap[3][6] = "[ X ]";

		}
		else if (whichSpot == 35)
		{

			playerBattleMap[3][7] = "[ X ]";

		}
		else if (whichSpot == 36)
		{

			playerBattleMap[3][8] = "[ X ]";

		}
		else if (whichSpot == 37)
		{

			playerBattleMap[4][0] = "[ X ]";

		}
		else if (whichSpot == 38)
		{

			playerBattleMap[4][1] = "[ X ]";

		}
		else if (whichSpot == 39)
		{

			playerBattleMap[4][2] = "[ X ]";

		}
		else if (whichSpot == 40)
		{

			playerBattleMap[4][3] = "[ X ]";

		}
		else if (whichSpot == 41)
		{

			playerBattleMap[4][4] = "[ X ]";

		}
		else if (whichSpot == 42)
		{

			playerBattleMap[4][5] = "[ X ]";

		}
		else if (whichSpot == 43)
		{

			playerBattleMap[4][6] = "[ X ]";

		}
		else if (whichSpot == 44)
		{

			playerBattleMap[4][7] = "[ X ]";

		}
		else if (whichSpot == 45)
		{

			playerBattleMap[4][8] = "[ X ]";

		}
		else if (whichSpot == 46)
		{

			playerBattleMap[5][0] = "[ X ]";

		}
		else if (whichSpot == 47)
		{

			playerBattleMap[5][1] = "[ X ]";

		}
		else if (whichSpot == 48)
		{

			playerBattleMap[5][2] = "[ X ]";

		}
		else if (whichSpot == 49)
		{

			playerBattleMap[5][3] = "[ X ]";

		}
		else if (whichSpot == 50)
		{

			playerBattleMap[5][4] = "[ X ]";

		}
		else if (whichSpot == 51)
		{

			playerBattleMap[5][5] = "[ X ]";

		}
		else if (whichSpot == 52)
		{

			playerBattleMap[5][6] = "[ X ]";

		}
		else if (whichSpot == 53)
		{

			playerBattleMap[5][7] = "[ X ]";

		}
		else if (whichSpot == 54)
		{

			playerBattleMap[5][8] = "[ X ]";

		}
		else if (whichSpot == 55)
		{

			playerBattleMap[6][0] = "[ X ]";

		}
		else if (whichSpot == 56)
		{

			playerBattleMap[6][1] = "[ X ]";

		}
		else if (whichSpot == 57)
		{

			playerBattleMap[6][2] = "[ X ]";

		}
		else if (whichSpot == 58)
		{

			playerBattleMap[6][3] = "[ X ]";

		}
		else if (whichSpot == 59)
		{

			playerBattleMap[6][4] = "[ X ]";

		}
		else if (whichSpot == 60)
		{

			playerBattleMap[6][5] = "[ X ]";

		}
		else if (whichSpot == 61)
		{

			playerBattleMap[6][6] = "[ X ]";

		}
		else if (whichSpot == 62)
		{

			playerBattleMap[6][7] = "[ X ]";

		}
		else if (whichSpot == 63)
		{

			playerBattleMap[6][8] = "[ X ]";

		}
		else if (whichSpot == 64)
		{

			playerBattleMap[7][0] = "[ X ]";

		}
		else if (whichSpot == 65)
		{

			playerBattleMap[7][1] = "[ X ]";

		}
		else if (whichSpot == 66)
		{

			playerBattleMap[7][2] = "[ X ]";

		}
		else if (whichSpot == 67)
		{

			playerBattleMap[7][3] = "[ X ]";

		}
		else if (whichSpot == 68)
		{

			playerBattleMap[7][4] = "[ X ]";

		}
		else if (whichSpot == 69)
		{

			playerBattleMap[7][5] = "[ X ]";

		}
		else if (whichSpot == 70)
		{

			playerBattleMap[7][6] = "[ X ]";

		}
		else if (whichSpot == 71)
		{

			playerBattleMap[7][7] = "[ X ]";

		}
		else if (whichSpot == 72)
		{

			playerBattleMap[7][8] = "[ X ]";

		}
		else if (whichSpot == 73)
		{

			playerBattleMap[8][0] = "[ X ]";

		}
		else if (whichSpot == 74)
		{

			playerBattleMap[8][1] = "[ X ]";

		}
		else if (whichSpot == 75)
		{

			playerBattleMap[8][2] = "[ X ]";

		}
		else if (whichSpot == 76)
		{

			playerBattleMap[8][3] = "[ X ]";

		}
		else if (whichSpot == 77)
		{

			playerBattleMap[8][4] = "[ X ]";

		}
		else if (whichSpot == 78)
		{

			playerBattleMap[8][5] = "[ X ]";

		}
		else if (whichSpot == 79)
		{

			playerBattleMap[8][6] = "[ X ]";

		}
		else if (whichSpot == 80)
		{

			playerBattleMap[8][7] = "[ X ]";

		}
		else if (whichSpot == 81)
		{

			playerBattleMap[8][8] = "[ X ]";

		}

	}
	//The Player's X's
	else if (whichPlayer == "Player")
	{

		if (whichSpot == 1)
		{

			aiBattleMap[0][0] = "[ X ]";

		}
		else if (whichSpot == 2)
		{

			aiBattleMap[0][1] = "[ X ]";

		}
		else if (whichSpot == 3)
		{

			aiBattleMap[0][2] = "[ X ]";

		}
		else if (whichSpot == 4)
		{

			aiBattleMap[0][3] = "[ X ]";

		}
		else if (whichSpot == 5)
		{

			aiBattleMap[0][4] = "[ X ]";

		}
		else if (whichSpot == 6)
		{

			aiBattleMap[0][5] = "[ X ]";

		}
		else if (whichSpot == 7)
		{

			aiBattleMap[0][6] = "[ X ]";

		}
		else if (whichSpot == 8)
		{

			aiBattleMap[0][7] = "[ X ]";

		}
		else if (whichSpot == 9)
		{

			aiBattleMap[0][8] = "[ X ]";

		}
		else if (whichSpot == 10)
		{

			aiBattleMap[1][0] = "[ X ]";

		}
		else if (whichSpot == 11)
		{

			aiBattleMap[1][1] = "[ X ]";

		}
		else if (whichSpot == 12)
		{

			aiBattleMap[1][2] = "[ X ]";

		}
		else if (whichSpot == 13)
		{

			aiBattleMap[1][3] = "[ X ]";

		}
		else if (whichSpot == 14)
		{

			aiBattleMap[1][4] = "[ X ]";

		}
		else if (whichSpot == 15)
		{

			aiBattleMap[1][5] = "[ X ]";

		}
		else if (whichSpot == 16)
		{

			aiBattleMap[1][6] = "[ X ]";

		}
		else if (whichSpot == 17)
		{

			aiBattleMap[1][7] = "[ X ]";

		}
		else if (whichSpot == 18)
		{

			aiBattleMap[1][8] = "[ X ]";

		}
		else if (whichSpot == 19)
		{

			aiBattleMap[2][0] = "[ X ]";

		}
		else if (whichSpot == 20)
		{

			aiBattleMap[2][1] = "[ X ]";

		}
		else if (whichSpot == 21)
		{

			aiBattleMap[2][2] = "[ X ]";

		}
		else if (whichSpot == 22)
		{

			aiBattleMap[2][3] = "[ X ]";

		}
		else if (whichSpot == 23)
		{

			aiBattleMap[2][4] = "[ X ]";

		}
		else if (whichSpot == 24)
		{

			aiBattleMap[2][5] = "[ X ]";

		}
		else if (whichSpot == 25)
		{

			aiBattleMap[2][6] = "[ X ]";

		}
		else if (whichSpot == 26)
		{

			aiBattleMap[2][7] = "[ X ]";

		}
		else if (whichSpot == 27)
		{

			aiBattleMap[2][8] = "[ X ]";

		}
		else if (whichSpot == 28)
		{

			aiBattleMap[3][0] = "[ X ]";

		}
		else if (whichSpot == 29)
		{

			aiBattleMap[3][1] = "[ X ]";

		}
		else if (whichSpot == 30)
		{

			aiBattleMap[3][2] = "[ X ]";

		}
		else if (whichSpot == 31)
		{

			aiBattleMap[3][3] = "[ X ]";

		}
		else if (whichSpot == 32)
		{

			aiBattleMap[3][4] = "[ X ]";

		}
		else if (whichSpot == 33)
		{

			aiBattleMap[3][5] = "[ X ]";

		}
		else if (whichSpot == 34)
		{

			aiBattleMap[3][6] = "[ X ]";

		}
		else if (whichSpot == 35)
		{

			aiBattleMap[3][7] = "[ X ]";

		}
		else if (whichSpot == 36)
		{

			aiBattleMap[3][8] = "[ X ]";

		}
		else if (whichSpot == 37)
		{

			aiBattleMap[4][0] = "[ X ]";

		}
		else if (whichSpot == 38)
		{

			aiBattleMap[4][1] = "[ X ]";

		}
		else if (whichSpot == 39)
		{

			aiBattleMap[4][2] = "[ X ]";

		}
		else if (whichSpot == 40)
		{

			aiBattleMap[4][3] = "[ X ]";

		}
		else if (whichSpot == 41)
		{

			aiBattleMap[4][4] = "[ X ]";

		}
		else if (whichSpot == 42)
		{

			aiBattleMap[4][5] = "[ X ]";

		}
		else if (whichSpot == 43)
		{

			aiBattleMap[4][6] = "[ X ]";

		}
		else if (whichSpot == 44)
		{

			aiBattleMap[4][7] = "[ X ]";

		}
		else if (whichSpot == 45)
		{

			aiBattleMap[4][8] = "[ X ]";

		}
		else if (whichSpot == 46)
		{

			aiBattleMap[5][0] = "[ X ]";

		}
		else if (whichSpot == 47)
		{

			aiBattleMap[5][1] = "[ X ]";

		}
		else if (whichSpot == 48)
		{

			aiBattleMap[5][2] = "[ X ]";

		}
		else if (whichSpot == 49)
		{

			aiBattleMap[5][3] = "[ X ]";

		}
		else if (whichSpot == 50)
		{

			aiBattleMap[5][4] = "[ X ]";

		}
		else if (whichSpot == 51)
		{

			aiBattleMap[5][5] = "[ X ]";

		}
		else if (whichSpot == 52)
		{

			aiBattleMap[5][6] = "[ X ]";

		}
		else if (whichSpot == 53)
		{

			aiBattleMap[5][7] = "[ X ]";

		}
		else if (whichSpot == 54)
		{

			aiBattleMap[5][8] = "[ X ]";

		}
		else if (whichSpot == 55)
		{

			aiBattleMap[6][0] = "[ X ]";

		}
		else if (whichSpot == 56)
		{

			aiBattleMap[6][1] = "[ X ]";

		}
		else if (whichSpot == 57)
		{

			aiBattleMap[6][2] = "[ X ]";

		}
		else if (whichSpot == 58)
		{

			aiBattleMap[6][3] = "[ X ]";

		}
		else if (whichSpot == 59)
		{

			aiBattleMap[6][4] = "[ X ]";

		}
		else if (whichSpot == 60)
		{

			aiBattleMap[6][5] = "[ X ]";

		}
		else if (whichSpot == 61)
		{

			aiBattleMap[6][6] = "[ X ]";

		}
		else if (whichSpot == 62)
		{

			aiBattleMap[6][7] = "[ X ]";

		}
		else if (whichSpot == 63)
		{

			aiBattleMap[6][8] = "[ X ]";

		}
		else if (whichSpot == 64)
		{

			aiBattleMap[7][0] = "[ X ]";

		}
		else if (whichSpot == 65)
		{

			aiBattleMap[7][1] = "[ X ]";

		}
		else if (whichSpot == 66)
		{

			aiBattleMap[7][2] = "[ X ]";

		}
		else if (whichSpot == 67)
		{

			aiBattleMap[7][3] = "[ X ]";

		}
		else if (whichSpot == 68)
		{

			aiBattleMap[7][4] = "[ X ]";

		}
		else if (whichSpot == 69)
		{

			aiBattleMap[7][5] = "[ X ]";

		}
		else if (whichSpot == 70)
		{

			aiBattleMap[7][6] = "[ X ]";

		}
		else if (whichSpot == 71)
		{

			aiBattleMap[7][7] = "[ X ]";

		}
		else if (whichSpot == 72)
		{

			aiBattleMap[7][8] = "[ X ]";

		}
		else if (whichSpot == 73)
		{

			aiBattleMap[8][0] = "[ X ]";

		}
		else if (whichSpot == 74)
		{

			aiBattleMap[8][1] = "[ X ]";

		}
		else if (whichSpot == 75)
		{

			aiBattleMap[8][2] = "[ X ]";

		}
		else if (whichSpot == 76)
		{

			aiBattleMap[8][3] = "[ X ]";

		}
		else if (whichSpot == 77)
		{

			aiBattleMap[8][4] = "[ X ]";

		}
		else if (whichSpot == 78)
		{

			aiBattleMap[8][5] = "[ X ]";

		}
		else if (whichSpot == 79)
		{

			aiBattleMap[8][6] = "[ X ]";

		}
		else if (whichSpot == 80)
		{

			aiBattleMap[8][7] = "[ X ]";

		}
		else if (whichSpot == 81)
		{

			aiBattleMap[8][8] = "[ X ]";

		}

	}

}

//Updates the map on misses. Takes in either player or ai and a number
void updateMapMiss(string whichPlayer, int whichSpot)
{

	//The AI's Misses. Marks them with an O
	if (whichPlayer == "AI")
	{

		if (whichSpot == 1)
		{

			playerBattleMap[0][0] = "[ O ]";

		}
		else if (whichSpot == 2)
		{

			playerBattleMap[0][1] = "[ O ]";

		}
		else if (whichSpot == 3)
		{

			playerBattleMap[0][2] = "[ O ]";

		}
		else if (whichSpot == 4)
		{

			playerBattleMap[0][3] = "[ O ]";

		}
		else if (whichSpot == 5)
		{

			playerBattleMap[0][4] = "[ O ]";

		}
		else if (whichSpot == 6)
		{

			playerBattleMap[0][5] = "[ O ]";

		}
		else if (whichSpot == 7)
		{

			playerBattleMap[0][6] = "[ O ]";

		}
		else if (whichSpot == 8)
		{

			playerBattleMap[0][7] = "[ O ]";

		}
		else if (whichSpot == 9)
		{

			playerBattleMap[0][8] = "[ O ]";

		}
		else if (whichSpot == 10)
		{

			playerBattleMap[1][0] = "[ O ]";

		}
		else if (whichSpot == 11)
		{

			playerBattleMap[1][1] = "[ O ]";

		}
		else if (whichSpot == 12)
		{

			playerBattleMap[1][2] = "[ O ]";

		}
		else if (whichSpot == 13)
		{

			playerBattleMap[1][3] = "[ O ]";

		}
		else if (whichSpot == 14)
		{

			playerBattleMap[1][4] = "[ O ]";

		}
		else if (whichSpot == 15)
		{

			playerBattleMap[1][5] = "[ O ]";

		}
		else if (whichSpot == 16)
		{

			playerBattleMap[1][6] = "[ O ]";

		}
		else if (whichSpot == 17)
		{

			playerBattleMap[1][7] = "[ O ]";

		}
		else if (whichSpot == 18)
		{

			playerBattleMap[1][8] = "[ O ]";

		}
		else if (whichSpot == 19)
		{

			playerBattleMap[2][0] = "[ O ]";

		}
		else if (whichSpot == 20)
		{

			playerBattleMap[2][1] = "[ O ]";

		}
		else if (whichSpot == 21)
		{

			playerBattleMap[2][2] = "[ O ]";

		}
		else if (whichSpot == 22)
		{

			playerBattleMap[2][3] = "[ O ]";

		}
		else if (whichSpot == 23)
		{

			playerBattleMap[2][4] = "[ O ]";

		}
		else if (whichSpot == 24)
		{

			playerBattleMap[2][5] = "[ O ]";

		}
		else if (whichSpot == 25)
		{

			playerBattleMap[2][6] = "[ O ]";

		}
		else if (whichSpot == 26)
		{

			playerBattleMap[2][7] = "[ O ]";

		}
		else if (whichSpot == 27)
		{

			playerBattleMap[2][8] = "[ O ]";

		}
		else if (whichSpot == 28)
		{

			playerBattleMap[3][0] = "[ O ]";

		}
		else if (whichSpot == 29)
		{

			playerBattleMap[3][1] = "[ O ]";

		}
		else if (whichSpot == 30)
		{

			playerBattleMap[3][2] = "[ O ]";

		}
		else if (whichSpot == 31)
		{

			playerBattleMap[3][3] = "[ O ]";

		}
		else if (whichSpot == 32)
		{

			playerBattleMap[3][4] = "[ O ]";

		}
		else if (whichSpot == 33)
		{

			playerBattleMap[3][5] = "[ O ]";

		}
		else if (whichSpot == 34)
		{

			playerBattleMap[3][6] = "[ O ]";

		}
		else if (whichSpot == 35)
		{

			playerBattleMap[3][7] = "[ O ]";

		}
		else if (whichSpot == 36)
		{

			playerBattleMap[3][8] = "[ O ]";

		}
		else if (whichSpot == 37)
		{

			playerBattleMap[4][0] = "[ O ]";

		}
		else if (whichSpot == 38)
		{

			playerBattleMap[4][1] = "[ O ]";

		}
		else if (whichSpot == 39)
		{

			playerBattleMap[4][2] = "[ O ]";

		}
		else if (whichSpot == 40)
		{

			playerBattleMap[4][3] = "[ O ]";

		}
		else if (whichSpot == 41)
		{

			playerBattleMap[4][4] = "[ O ]";

		}
		else if (whichSpot == 42)
		{

			playerBattleMap[4][5] = "[ O ]";

		}
		else if (whichSpot == 43)
		{

			playerBattleMap[4][6] = "[ O ]";

		}
		else if (whichSpot == 44)
		{

			playerBattleMap[4][7] = "[ O ]";

		}
		else if (whichSpot == 45)
		{

			playerBattleMap[4][8] = "[ O ]";

		}
		else if (whichSpot == 46)
		{

			playerBattleMap[5][0] = "[ O ]";

		}
		else if (whichSpot == 47)
		{

			playerBattleMap[5][1] = "[ O ]";

		}
		else if (whichSpot == 48)
		{

			playerBattleMap[5][2] = "[ O ]";

		}
		else if (whichSpot == 49)
		{

			playerBattleMap[5][3] = "[ O ]";

		}
		else if (whichSpot == 50)
		{

			playerBattleMap[5][4] = "[ O ]";

		}
		else if (whichSpot == 51)
		{

			playerBattleMap[5][5] = "[ O ]";

		}
		else if (whichSpot == 52)
		{

			playerBattleMap[5][6] = "[ O ]";

		}
		else if (whichSpot == 53)
		{

			playerBattleMap[5][7] = "[ O ]";

		}
		else if (whichSpot == 54)
		{

			playerBattleMap[5][8] = "[ O ]";

		}
		else if (whichSpot == 55)
		{

			playerBattleMap[6][0] = "[ O ]";

		}
		else if (whichSpot == 56)
		{

			playerBattleMap[6][1] = "[ O ]";

		}
		else if (whichSpot == 57)
		{

			playerBattleMap[6][2] = "[ O ]";

		}
		else if (whichSpot == 58)
		{

			playerBattleMap[6][3] = "[ O ]";

		}
		else if (whichSpot == 59)
		{

			playerBattleMap[6][4] = "[ O ]";

		}
		else if (whichSpot == 60)
		{

			playerBattleMap[6][5] = "[ O ]";

		}
		else if (whichSpot == 61)
		{

			playerBattleMap[6][6] = "[ O ]";

		}
		else if (whichSpot == 62)
		{

			playerBattleMap[6][7] = "[ O ]";

		}
		else if (whichSpot == 63)
		{

			playerBattleMap[6][8] = "[ O ]";

		}
		else if (whichSpot == 64)
		{

			playerBattleMap[7][0] = "[ O ]";

		}
		else if (whichSpot == 65)
		{

			playerBattleMap[7][1] = "[ O ]";

		}
		else if (whichSpot == 66)
		{

			playerBattleMap[7][2] = "[ O ]";

		}
		else if (whichSpot == 67)
		{

			playerBattleMap[7][3] = "[ O ]";

		}
		else if (whichSpot == 68)
		{

			playerBattleMap[7][4] = "[ O ]";

		}
		else if (whichSpot == 69)
		{

			playerBattleMap[7][5] = "[ O ]";

		}
		else if (whichSpot == 70)
		{

			playerBattleMap[7][6] = "[ O ]";

		}
		else if (whichSpot == 71)
		{

			playerBattleMap[7][7] = "[ O ]";

		}
		else if (whichSpot == 72)
		{

			playerBattleMap[7][8] = "[ O ]";

		}
		else if (whichSpot == 73)
		{

			playerBattleMap[8][0] = "[ O ]";

		}
		else if (whichSpot == 74)
		{

			playerBattleMap[8][1] = "[ O ]";

		}
		else if (whichSpot == 75)
		{

			playerBattleMap[8][2] = "[ O ]";

		}
		else if (whichSpot == 76)
		{

			playerBattleMap[8][3] = "[ O ]";

		}
		else if (whichSpot == 77)
		{

			playerBattleMap[8][4] = "[ O ]";

		}
		else if (whichSpot == 78)
		{

			playerBattleMap[8][5] = "[ O ]";

		}
		else if (whichSpot == 79)
		{

			playerBattleMap[8][6] = "[ O ]";

		}
		else if (whichSpot == 80)
		{

			playerBattleMap[8][7] = "[ O ]";

		}
		else if (whichSpot == 81)
		{

			playerBattleMap[8][8] = "[ O ]";

		}

	}
	//The Player's misses. Marks them with an O
	else if (whichPlayer == "Player")
	{

		if (whichSpot == 1)
		{

			aiBattleMap[0][0] = "[ O ]";

		}
		else if (whichSpot == 2)
		{

			aiBattleMap[0][1] = "[ O ]";

		}
		else if (whichSpot == 3)
		{

			aiBattleMap[0][2] = "[ O ]";

		}
		else if (whichSpot == 4)
		{

			aiBattleMap[0][3] = "[ O ]";

		}
		else if (whichSpot == 5)
		{

			aiBattleMap[0][4] = "[ O ]";

		}
		else if (whichSpot == 6)
		{

			aiBattleMap[0][5] = "[ O ]";

		}
		else if (whichSpot == 7)
		{

			aiBattleMap[0][6] = "[ O ]";

		}
		else if (whichSpot == 8)
		{

			aiBattleMap[0][7] = "[ O ]";

		}
		else if (whichSpot == 9)
		{

			aiBattleMap[0][8] = "[ O ]";

		}
		else if (whichSpot == 10)
		{

			aiBattleMap[1][0] = "[ O ]";

		}
		else if (whichSpot == 11)
		{

			aiBattleMap[1][1] = "[ O ]";

		}
		else if (whichSpot == 12)
		{

			aiBattleMap[1][2] = "[ O ]";

		}
		else if (whichSpot == 13)
		{

			aiBattleMap[1][3] = "[ O ]";

		}
		else if (whichSpot == 14)
		{

			aiBattleMap[1][4] = "[ O ]";

		}
		else if (whichSpot == 15)
		{

			aiBattleMap[1][5] = "[ O ]";

		}
		else if (whichSpot == 16)
		{

			aiBattleMap[1][6] = "[ O ]";

		}
		else if (whichSpot == 17)
		{

			aiBattleMap[1][7] = "[ O ]";

		}
		else if (whichSpot == 18)
		{

			aiBattleMap[1][8] = "[ O ]";

		}
		else if (whichSpot == 19)
		{

			aiBattleMap[2][0] = "[ O ]";

		}
		else if (whichSpot == 20)
		{

			aiBattleMap[2][1] = "[ O ]";

		}
		else if (whichSpot == 21)
		{

			aiBattleMap[2][2] = "[ O ]";

		}
		else if (whichSpot == 22)
		{

			aiBattleMap[2][3] = "[ O ]";

		}
		else if (whichSpot == 23)
		{

			aiBattleMap[2][4] = "[ O ]";

		}
		else if (whichSpot == 24)
		{

			aiBattleMap[2][5] = "[ O ]";

		}
		else if (whichSpot == 25)
		{

			aiBattleMap[2][6] = "[ O ]";

		}
		else if (whichSpot == 26)
		{

			aiBattleMap[2][7] = "[ O ]";

		}
		else if (whichSpot == 27)
		{

			aiBattleMap[2][8] = "[ O ]";

		}
		else if (whichSpot == 28)
		{

			aiBattleMap[3][0] = "[ O ]";

		}
		else if (whichSpot == 29)
		{

			aiBattleMap[3][1] = "[ O ]";

		}
		else if (whichSpot == 30)
		{

			aiBattleMap[3][2] = "[ O ]";

		}
		else if (whichSpot == 31)
		{

			aiBattleMap[3][3] = "[ O ]";

		}
		else if (whichSpot == 32)
		{

			aiBattleMap[3][4] = "[ O ]";

		}
		else if (whichSpot == 33)
		{

			aiBattleMap[3][5] = "[ O ]";

		}
		else if (whichSpot == 34)
		{

			aiBattleMap[3][6] = "[ O ]";

		}
		else if (whichSpot == 35)
		{

			aiBattleMap[3][7] = "[ O ]";

		}
		else if (whichSpot == 36)
		{

			aiBattleMap[3][8] = "[ O ]";

		}
		else if (whichSpot == 37)
		{

			aiBattleMap[4][0] = "[ O ]";

		}
		else if (whichSpot == 38)
		{

			aiBattleMap[4][1] = "[ O ]";

		}
		else if (whichSpot == 39)
		{

			aiBattleMap[4][2] = "[ O ]";

		}
		else if (whichSpot == 40)
		{

			aiBattleMap[4][3] = "[ O ]";

		}
		else if (whichSpot == 41)
		{

			aiBattleMap[4][4] = "[ O ]";

		}
		else if (whichSpot == 42)
		{

			aiBattleMap[4][5] = "[ O ]";

		}
		else if (whichSpot == 43)
		{

			aiBattleMap[4][6] = "[ O ]";

		}
		else if (whichSpot == 44)
		{

			aiBattleMap[4][7] = "[ O ]";

		}
		else if (whichSpot == 45)
		{

			aiBattleMap[4][8] = "[ O ]";

		}
		else if (whichSpot == 46)
		{

			aiBattleMap[5][0] = "[ O ]";

		}
		else if (whichSpot == 47)
		{

			aiBattleMap[5][1] = "[ O ]";

		}
		else if (whichSpot == 48)
		{

			aiBattleMap[5][2] = "[ O ]";

		}
		else if (whichSpot == 49)
		{

			aiBattleMap[5][3] = "[ O ]";

		}
		else if (whichSpot == 50)
		{

			aiBattleMap[5][4] = "[ O ]";

		}
		else if (whichSpot == 51)
		{

			aiBattleMap[5][5] = "[ O ]";

		}
		else if (whichSpot == 52)
		{

			aiBattleMap[5][6] = "[ O ]";

		}
		else if (whichSpot == 53)
		{

			aiBattleMap[5][7] = "[ O ]";

		}
		else if (whichSpot == 54)
		{

			aiBattleMap[5][8] = "[ O ]";

		}
		else if (whichSpot == 55)
		{

			aiBattleMap[6][0] = "[ O ]";

		}
		else if (whichSpot == 56)
		{

			aiBattleMap[6][1] = "[ O ]";

		}
		else if (whichSpot == 57)
		{

			aiBattleMap[6][2] = "[ O ]";

		}
		else if (whichSpot == 58)
		{

			aiBattleMap[6][3] = "[ O ]";

		}
		else if (whichSpot == 59)
		{

			aiBattleMap[6][4] = "[ O ]";

		}
		else if (whichSpot == 60)
		{

			aiBattleMap[6][5] = "[ O ]";

		}
		else if (whichSpot == 61)
		{

			aiBattleMap[6][6] = "[ O ]";

		}
		else if (whichSpot == 62)
		{

			aiBattleMap[6][7] = "[ O ]";

		}
		else if (whichSpot == 63)
		{

			aiBattleMap[6][8] = "[ O ]";

		}
		else if (whichSpot == 64)
		{

			aiBattleMap[7][0] = "[ O ]";

		}
		else if (whichSpot == 65)
		{

			aiBattleMap[7][1] = "[ O ]";

		}
		else if (whichSpot == 66)
		{

			aiBattleMap[7][2] = "[ O ]";

		}
		else if (whichSpot == 67)
		{

			aiBattleMap[7][3] = "[ O ]";

		}
		else if (whichSpot == 68)
		{

			aiBattleMap[7][4] = "[ O ]";

		}
		else if (whichSpot == 69)
		{

			aiBattleMap[7][5] = "[ O ]";

		}
		else if (whichSpot == 70)
		{

			aiBattleMap[7][6] = "[ O ]";

		}
		else if (whichSpot == 71)
		{

			aiBattleMap[7][7] = "[ O ]";

		}
		else if (whichSpot == 72)
		{

			aiBattleMap[7][8] = "[ O ]";

		}
		else if (whichSpot == 73)
		{

			aiBattleMap[8][0] = "[ O ]";

		}
		else if (whichSpot == 74)
		{

			aiBattleMap[8][1] = "[ O ]";

		}
		else if (whichSpot == 75)
		{

			aiBattleMap[8][2] = "[ O ]";

		}
		else if (whichSpot == 76)
		{

			aiBattleMap[8][3] = "[ O ]";

		}
		else if (whichSpot == 77)
		{

			aiBattleMap[8][4] = "[ O ]";

		}
		else if (whichSpot == 78)
		{

			aiBattleMap[8][5] = "[ O ]";

		}
		else if (whichSpot == 79)
		{

			aiBattleMap[8][6] = "[ O ]";

		}
		else if (whichSpot == 80)
		{

			aiBattleMap[8][7] = "[ O ]";

		}
		else if (whichSpot == 81)
		{

			aiBattleMap[8][8] = "[ O ]";

		}

	}

}

//Takes in a coordinant and converts it to a number
int coorToGrid(string coordinate)
{

	//Takes in a coordinant like A1 and turns it into it's number which would be 1 in this case
	if (coordinate == "A1")
	{

		return 1;

	}
	else if (coordinate == "A2")
	{

		return 2;

	}
	else if (coordinate == "A3")
	{

		return 3;

	}
	else if (coordinate == "A4")
	{

		return 4;

	}
	else if (coordinate == "A5")
	{

		return 5;

	}
	else if (coordinate == "A6")
	{

		return 6;

	}
	else if (coordinate == "A7")
	{

		return 7;

	}
	else if (coordinate == "A8")
	{

		return 8;

	}
	else if (coordinate == "A9")
	{

		return 9;

	}
	else if (coordinate == "B1")
	{

		return 10;

	}
	else if (coordinate == "B2")
	{

		return 11;

	}
	else if (coordinate == "B3")
	{

		return 12;

	}
	else if (coordinate == "B4")
	{

		return 13;

	}
	else if (coordinate == "B5")
	{

		return 14;

	}
	else if (coordinate == "B6")
	{

		return 15;

	}
	else if (coordinate == "B7")
	{

		return 16;

	}
	else if (coordinate == "B8")
	{

		return 17;

	}
	else if (coordinate == "B9")
	{

		return 18;

	}
	else if (coordinate == "C1")
	{

		return 19;

	}
	else if (coordinate == "C2")
	{

		return 20;

	}
	else if (coordinate == "C3")
	{

		return 21;

	}
	else if (coordinate == "C4")
	{

		return 22;

	}
	else if (coordinate == "C5")
	{

		return 23;

	}
	else if (coordinate == "C6")
	{

		return 24;

	}
	else if (coordinate == "C7")
	{

		return 25;

	}
	else if (coordinate == "C8")
	{

		return 26;

	}
	else if (coordinate == "C9")
	{

		return 27;

	}
	else if (coordinate == "D1")
	{

		return 28;

	}
	else if (coordinate == "D2")
	{

		return 29;

	}
	else if (coordinate == "D3")
	{

		return 30;

	}
	else if (coordinate == "D4")
	{

		return 31;

	}
	else if (coordinate == "D5")
	{

		return 32;

	}
	else if (coordinate == "D6")
	{

		return 33;

	}
	else if (coordinate == "D7")
	{

		return 34;

	}
	else if (coordinate == "D8")
	{

		return 35;

	}
	else if (coordinate == "D9")
	{

		return 36;

	}
	else if (coordinate == "E1")
	{

		return 37;

	}
	else if (coordinate == "E2")
	{

		return 38;

	}
	else if (coordinate == "E3")
	{

		return 39;

	}
	else if (coordinate == "E4")
	{

		return 40;

	}
	else if (coordinate == "E5")
	{

		return 41;

	}
	else if (coordinate == "E6")
	{

		return 42;

	}
	else if (coordinate == "E7")
	{

		return 43;

	}
	else if (coordinate == "E8")
	{

		return 44;

	}
	else if (coordinate == "E9")
	{

		return 45;

	}
	else if (coordinate == "F1")
	{

		return 46;

	}
	else if (coordinate == "F2")
	{

		return 47;

	}
	else if (coordinate == "F3")
	{

		return 48;

	}
	else if (coordinate == "F4")
	{

		return 49;

	}
	else if (coordinate == "F5")
	{

		return 50;

	}
	else if (coordinate == "F6")
	{

		return 51;

	}
	else if (coordinate == "F7")
	{

		return 52;

	}
	else if (coordinate == "F8")
	{

		return 53;

	}
	else if (coordinate == "F9")
	{

		return 54;

	}
	else if (coordinate == "G1")
	{

		return 55;

	}
	else if (coordinate == "G2")
	{

		return 56;

	}
	else if (coordinate == "G3")
	{

		return 57;

	}
	else if (coordinate == "G4")
	{

		return 58;

	}
	else if (coordinate == "G5")
	{

		return 59;

	}
	else if (coordinate == "G6")
	{

		return 60;

	}
	else if (coordinate == "G7")
	{

		return 61;

	}
	else if (coordinate == "G8")
	{

		return 62;

	}
	else if (coordinate == "G9")
	{

		return 63;

	}
	else if (coordinate == "H1")
	{

		return 64;

	}
	else if (coordinate == "H2")
	{

		return 65;

	}
	else if (coordinate == "H3")
	{

		return 66;

	}
	else if (coordinate == "H4")
	{

		return 67;

	}
	else if (coordinate == "H5")
	{

		return 68;

	}
	else if (coordinate == "H6")
	{

		return 69;

	}
	else if (coordinate == "H7")
	{

		return 70;

	}
	else if (coordinate == "H8")
	{

		return 71;

	}
	else if (coordinate == "H9")
	{

		return 72;

	}
	else if (coordinate == "I1")
	{

		return 73;

	}
	else if (coordinate == "I2")
	{

		return 74;

	}
	else if (coordinate == "I3")
	{

		return 75;

	}
	else if (coordinate == "I4")
	{

		return 76;

	}
	else if (coordinate == "I5")
	{

		return 77;

	}
	else if (coordinate == "I6")
	{

		return 78;

	}
	else if (coordinate == "I7")
	{

		return 79;

	}
	else if (coordinate == "I8")
	{

		return 80;

	}
	else if (coordinate == "I9")
	{

		return 81;

	}
	else
	{

		cout << "Please type a valid corrdinate" << endl;

		return 0;

	}

}

//Takes in a number and spits out a coordinant
string gridToCoor(int gridNum)
{

	//Takes in a number like one and turns it into a coordinant like A1 in this case
	if (gridNum == 1)
	{

		return "A1";

	}
	else if (gridNum == 2)
	{

		return "A2";

	}
	else if (gridNum == 3)
	{

		return "A3";

	}
	else if (gridNum == 4)
	{

		return "A4";

	}
	else if (gridNum == 5)
	{

		return "A5";

	}
	else if (gridNum == 6)
	{

		return "A6";

	}
	else if (gridNum == 7)
	{

		return "A7";

	}
	else if (gridNum == 8)
	{

		return "A8";

	}
	else if (gridNum == 9)
	{

		return "A9";

	}
	else if (gridNum == 10)
	{

		return "B1";

	}
	else if (gridNum == 11)
	{

		return "B2";

	}
	else if (gridNum == 12)
	{

		return "B3";

	}
	else if (gridNum == 13)
	{

		return "B4";

	}
	else if (gridNum == 14)
	{

		return "B5";

	}
	else if (gridNum == 15)
	{

		return "B6";

	}
	else if (gridNum == 16)
	{

		return "B7";

	}
	else if (gridNum == 17)
	{

		return "B8";

	}
	else if (gridNum == 18)
	{

		return "B9";

	}
	else if (gridNum == 19)
	{

		return "C1";

	}
	else if (gridNum == 20)
	{

	return "C2";

	}
	else if (gridNum == 21)
	{

	return "C3";

	}
	else if (gridNum == 22)
	{

	return "C4";

	}
	else if (gridNum == 23)
	{

	return "C5";

	}
	else if (gridNum == 24)
	{

	return "C6";

	}
	else if (gridNum == 25)
	{

	return "C7";

	}
	else if (gridNum == 26)
	{

	return "C8";

	}
	else if (gridNum == 27)
	{

	return "C9";

	}
	else if (gridNum == 28)
	{

	return "D1";

	}
	else if (gridNum == 29)
	{

	return "D2";

	}
	else if (gridNum == 30)
	{

	return "D3";

	}
	else if (gridNum == 31)
	{

	return "D4";

	}
	else if (gridNum == 32)
	{

	return "D5";

	}
	else if (gridNum == 33)
	{

	return "D6";

	}
	else if (gridNum == 34)
	{

	return "D7";

	}
	else if (gridNum == 35)
	{

	return "D8";

	}
	else if (gridNum == 36)
	{

	return "D9";

	}
	else if (gridNum == 37)
	{

	return "E1";

	}
	else if (gridNum == 38)
	{

	return "E2";

	}
	else if (gridNum == 39)
	{

	return "E3";

	}
	else if (gridNum == 40)
	{

	return "E4";

	}
	else if (gridNum == 41)
	{

	return "E5";

	}
	else if (gridNum == 42)
	{

	return "E6";

	}
	else if (gridNum == 43)
	{

	return "E7";

	}
	else if (gridNum == 44)
	{

	return "E8";

	}
	else if (gridNum == 45)
	{

	return "E9";

	}
	else if (gridNum == 46)
	{

	return "F1";

	}
	else if (gridNum == 47)
	{

	return "F2";

	}
	else if (gridNum == 48)
	{

	return "F3";

	}
	else if (gridNum == 49)
	{

	return "F4";

	}
	else if (gridNum == 50)
	{

	return "F5";

	}
	else if (gridNum == 51)
	{

	return "F6";

	}
	else if (gridNum == 52)
	{

	return "F7";

	}
	else if (gridNum == 53)
	{

	return "F8";

	}
	else if (gridNum == 54)
	{

	return "F9";

	}
	else if (gridNum == 55)
	{

	return "G1";

	}
	else if (gridNum == 56)
	{

	return "G2";

	}
	else if (gridNum == 57)
	{

	return "G3";

	}
	else if (gridNum == 58)
	{

	return "G4";

	}
	else if (gridNum == 59)
	{

	return "G5";

	}
	else if (gridNum == 60)
	{

	return "G6";

	}
	else if (gridNum == 61)
	{

	return "G7";

	}
	else if (gridNum == 62)
	{

	return "G8";

	}
	else if (gridNum == 63)
	{

	return "G9";

	}
	else if (gridNum == 64)
	{

	return "H1";

	}
	else if (gridNum == 65)
	{

	return "H2";

	}
	else if (gridNum == 66)
	{

	return "H3";

	}
	else if (gridNum == 67)
	{

	return "H4";

	}
	else if (gridNum == 68)
	{

	return "H5";

	}
	else if (gridNum == 69)
	{

	return "H6";

	}
	else if (gridNum == 70)
	{

	return "H7";

	}
	else if (gridNum == 71)
	{

	return "H8";

	}
	else if (gridNum == 72)
	{

	return "H9";

	}
	else if (gridNum == 73)
	{

	return "I1";

	}
	else if (gridNum == 74)
	{

	return "I2";

	}
	else if (gridNum == 75)
	{

	return "I3";

	}
	else if (gridNum == 76)
	{

	return "I4";

	}
	else if (gridNum == 77)
	{

	return "I5";

	}
	else if (gridNum == 78)
	{

	return "I6";

	}
	else if (gridNum == 79)
	{

	return "I7";

	}
	else if (gridNum == 80)
	{

	return "I8";

	}
	else if (gridNum == 81)
	{

	return "I9";

	}
	else
	{

	return"AA";

	}

}

//Takes the player's inputed ships and marks them with a B for battleship, a CA for Carrier, a D for Destroyer, a S for Submarine, and a CR for cruiser
void shipToMap()
{

	//The battleship placer. Marks them with B
	if (battleShipGridSpace1 == 1 || battleShipGridSpace2 == 1 || battleShipGridSpace3 == 1 || battleShipGridSpace4 == 1 || battleShipGridSpace5 == 1)
	{

		playerBattleMap[0][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 2 || battleShipGridSpace2 == 2 || battleShipGridSpace3 == 2 || battleShipGridSpace4 == 2 || battleShipGridSpace5 == 2)
	{

		playerBattleMap[0][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 3 || battleShipGridSpace2 == 3 || battleShipGridSpace3 == 3 || battleShipGridSpace4 == 3 || battleShipGridSpace5 == 3)
	{

		playerBattleMap[0][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 4 || battleShipGridSpace2 == 4 || battleShipGridSpace3 == 4 || battleShipGridSpace4 == 4 || battleShipGridSpace5 == 4)
	{

		playerBattleMap[0][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 5 || battleShipGridSpace2 == 5 || battleShipGridSpace3 == 5 || battleShipGridSpace4 == 5 || battleShipGridSpace5 == 5)
	{

		playerBattleMap[0][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 6 || battleShipGridSpace2 == 6 || battleShipGridSpace3 == 6 || battleShipGridSpace4 == 6 || battleShipGridSpace5 == 6)
	{

		playerBattleMap[0][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 7 || battleShipGridSpace2 == 7 || battleShipGridSpace3 == 7 || battleShipGridSpace4 == 7 || battleShipGridSpace5 == 7)
	{

		playerBattleMap[0][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 8 || battleShipGridSpace2 == 8 || battleShipGridSpace3 == 8 || battleShipGridSpace4 == 8 || battleShipGridSpace5 == 8)
	{

		playerBattleMap[0][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 9 || battleShipGridSpace2 == 9 || battleShipGridSpace3 == 9 || battleShipGridSpace4 == 9 || battleShipGridSpace5 == 9)
	{

		playerBattleMap[0][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 10 || battleShipGridSpace2 == 10 || battleShipGridSpace3 == 10 || battleShipGridSpace4 == 10 || battleShipGridSpace5 == 10)
	{

		playerBattleMap[1][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 11 || battleShipGridSpace2 == 11 || battleShipGridSpace3 == 11 || battleShipGridSpace4 == 11 || battleShipGridSpace5 == 11)
	{

		playerBattleMap[1][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 12 || battleShipGridSpace2 == 12 || battleShipGridSpace3 == 12 || battleShipGridSpace4 == 12 || battleShipGridSpace5 == 12)
	{

		playerBattleMap[1][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 13 || battleShipGridSpace2 == 13 || battleShipGridSpace3 == 13 || battleShipGridSpace4 == 13 || battleShipGridSpace5 == 13)
	{

		playerBattleMap[1][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 14 || battleShipGridSpace2 == 14 || battleShipGridSpace3 == 14 || battleShipGridSpace4 == 14 || battleShipGridSpace5 == 14)
	{

		playerBattleMap[1][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 15 || battleShipGridSpace2 == 15 || battleShipGridSpace3 == 15 || battleShipGridSpace4 == 15 || battleShipGridSpace5 == 15)
	{

		playerBattleMap[1][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 16 || battleShipGridSpace2 == 16 || battleShipGridSpace3 == 16 || battleShipGridSpace4 == 16 || battleShipGridSpace5 == 16)
	{

		playerBattleMap[1][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 17 || battleShipGridSpace2 == 17 || battleShipGridSpace3 == 17 || battleShipGridSpace4 == 17 || battleShipGridSpace5 == 17)
	{

		playerBattleMap[1][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 18 || battleShipGridSpace2 == 18 || battleShipGridSpace3 == 18 || battleShipGridSpace4 == 18 || battleShipGridSpace5 == 18)
	{

		playerBattleMap[1][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 19 || battleShipGridSpace2 == 19 || battleShipGridSpace3 == 19 || battleShipGridSpace4 == 19 || battleShipGridSpace5 == 19)
	{

		playerBattleMap[2][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 20 || battleShipGridSpace2 == 20 || battleShipGridSpace3 == 20 || battleShipGridSpace4 == 20 || battleShipGridSpace5 == 20)
	{

		playerBattleMap[2][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 21 || battleShipGridSpace2 == 21 || battleShipGridSpace3 == 21 || battleShipGridSpace4 == 21 || battleShipGridSpace5 == 21)
	{

		playerBattleMap[2][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 22 || battleShipGridSpace2 == 22 || battleShipGridSpace3 == 22 || battleShipGridSpace4 == 22 || battleShipGridSpace5 == 22)
	{

		playerBattleMap[2][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 23 || battleShipGridSpace2 == 23 || battleShipGridSpace3 == 23 || battleShipGridSpace4 == 23 || battleShipGridSpace5 == 23)
	{

		playerBattleMap[2][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 24 || battleShipGridSpace2 == 24 || battleShipGridSpace3 == 24 || battleShipGridSpace4 == 24 || battleShipGridSpace5 == 24)
	{

		playerBattleMap[2][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 25 || battleShipGridSpace2 == 25 || battleShipGridSpace3 == 25 || battleShipGridSpace4 == 25 || battleShipGridSpace5 == 25)
	{

		playerBattleMap[2][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 26 || battleShipGridSpace2 == 26 || battleShipGridSpace3 == 26 || battleShipGridSpace4 == 26 || battleShipGridSpace5 == 26)
	{

		playerBattleMap[2][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 27 || battleShipGridSpace2 == 27 || battleShipGridSpace3 == 27 || battleShipGridSpace4 == 27 || battleShipGridSpace5 == 27)
	{

		playerBattleMap[2][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 28 || battleShipGridSpace2 == 28 || battleShipGridSpace3 == 28 || battleShipGridSpace4 == 28 || battleShipGridSpace5 == 28)
	{

		playerBattleMap[3][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 29 || battleShipGridSpace2 == 29 || battleShipGridSpace3 == 29 || battleShipGridSpace4 == 29 || battleShipGridSpace5 == 29)
	{

		playerBattleMap[3][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 30 || battleShipGridSpace2 == 30 || battleShipGridSpace3 == 30 || battleShipGridSpace4 == 30 || battleShipGridSpace5 == 30)
	{

		playerBattleMap[3][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 31 || battleShipGridSpace2 == 31 || battleShipGridSpace3 == 31 || battleShipGridSpace4 == 31 || battleShipGridSpace5 == 31)
	{

		playerBattleMap[3][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 32 || battleShipGridSpace2 == 32 || battleShipGridSpace3 == 32 || battleShipGridSpace4 == 32 || battleShipGridSpace5 == 32)
	{

		playerBattleMap[3][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 33 || battleShipGridSpace2 == 33 || battleShipGridSpace3 == 33 || battleShipGridSpace4 == 33 || battleShipGridSpace5 == 33)
	{

		playerBattleMap[3][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 34 || battleShipGridSpace2 == 34 || battleShipGridSpace3 == 34 || battleShipGridSpace4 == 34 || battleShipGridSpace5 == 34)
	{

		playerBattleMap[3][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 35 || battleShipGridSpace2 == 35 || battleShipGridSpace3 == 35 || battleShipGridSpace4 == 35 || battleShipGridSpace5 == 35)
	{

		playerBattleMap[3][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 36 || battleShipGridSpace2 == 36 || battleShipGridSpace3 == 36 || battleShipGridSpace4 == 36 || battleShipGridSpace5 == 36)
	{

		playerBattleMap[3][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 37 || battleShipGridSpace2 == 37 || battleShipGridSpace3 == 37 || battleShipGridSpace4 == 37 || battleShipGridSpace5 == 37)
	{

		playerBattleMap[4][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 38 || battleShipGridSpace2 == 38 || battleShipGridSpace3 == 38 || battleShipGridSpace4 == 38 || battleShipGridSpace5 == 38)
	{

		playerBattleMap[4][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 39 || battleShipGridSpace2 == 39 || battleShipGridSpace3 == 39 || battleShipGridSpace4 == 39 || battleShipGridSpace5 == 39)
	{

		playerBattleMap[4][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 40 || battleShipGridSpace2 == 40 || battleShipGridSpace3 == 40 || battleShipGridSpace4 == 40 || battleShipGridSpace5 == 40)
	{

		playerBattleMap[4][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 41 || battleShipGridSpace2 == 41 || battleShipGridSpace3 == 41 || battleShipGridSpace4 == 41 || battleShipGridSpace5 == 41)
	{

		playerBattleMap[4][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 42 || battleShipGridSpace2 == 42 || battleShipGridSpace3 == 42 || battleShipGridSpace4 == 42 || battleShipGridSpace5 == 42)
	{

		playerBattleMap[4][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 43 || battleShipGridSpace2 == 43 || battleShipGridSpace3 == 43 || battleShipGridSpace4 == 43 || battleShipGridSpace5 == 43)
	{

		playerBattleMap[4][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 44 || battleShipGridSpace2 == 44 || battleShipGridSpace3 == 44 || battleShipGridSpace4 == 44 || battleShipGridSpace5 == 44)
	{

		playerBattleMap[4][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 45 || battleShipGridSpace2 == 45 || battleShipGridSpace3 == 45 || battleShipGridSpace4 == 45 || battleShipGridSpace5 == 45)
	{

		playerBattleMap[4][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 46 || battleShipGridSpace2 == 46 || battleShipGridSpace3 == 46 || battleShipGridSpace4 == 46 || battleShipGridSpace5 == 46)
	{

		playerBattleMap[5][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 47 || battleShipGridSpace2 == 47 || battleShipGridSpace3 == 47 || battleShipGridSpace4 == 47 || battleShipGridSpace5 == 47)
	{

		playerBattleMap[5][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 48 || battleShipGridSpace2 == 48 || battleShipGridSpace3 == 48 || battleShipGridSpace4 == 48 || battleShipGridSpace5 == 48)
	{

		playerBattleMap[5][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 49 || battleShipGridSpace2 == 49 || battleShipGridSpace3 == 49 || battleShipGridSpace4 == 49 || battleShipGridSpace5 == 49)
	{

		playerBattleMap[5][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 50 || battleShipGridSpace2 == 50 || battleShipGridSpace3 == 50 || battleShipGridSpace4 == 50 || battleShipGridSpace5 == 50)
	{

		playerBattleMap[5][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 51 || battleShipGridSpace2 == 51 || battleShipGridSpace3 == 51 || battleShipGridSpace4 == 51 || battleShipGridSpace5 == 51)
	{

		playerBattleMap[5][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 52 || battleShipGridSpace2 == 52 || battleShipGridSpace3 == 52 || battleShipGridSpace4 == 52 || battleShipGridSpace5 == 52)
	{

		playerBattleMap[5][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 53 || battleShipGridSpace2 == 53 || battleShipGridSpace3 == 53 || battleShipGridSpace4 == 53 || battleShipGridSpace5 == 53)
	{

		playerBattleMap[5][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 54 || battleShipGridSpace2 == 54 || battleShipGridSpace3 == 54 || battleShipGridSpace4 == 54 || battleShipGridSpace5 == 54)
	{

		playerBattleMap[5][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 55 || battleShipGridSpace2 == 55 || battleShipGridSpace3 == 55 || battleShipGridSpace4 == 55 || battleShipGridSpace5 == 55)
	{

		playerBattleMap[6][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 56 || battleShipGridSpace2 == 56 || battleShipGridSpace3 == 56 || battleShipGridSpace4 == 56 || battleShipGridSpace5 == 56)
	{

		playerBattleMap[6][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 57 || battleShipGridSpace2 == 57 || battleShipGridSpace3 == 57 || battleShipGridSpace4 == 57 || battleShipGridSpace5 == 57)
	{

		playerBattleMap[6][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 58 || battleShipGridSpace2 == 58 || battleShipGridSpace3 == 58 || battleShipGridSpace4 == 58 || battleShipGridSpace5 == 58)
	{

		playerBattleMap[6][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 59 || battleShipGridSpace2 == 59 || battleShipGridSpace3 == 59 || battleShipGridSpace4 == 59 || battleShipGridSpace5 == 59)
	{

		playerBattleMap[6][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 60 || battleShipGridSpace2 == 60 || battleShipGridSpace3 == 60 || battleShipGridSpace4 == 60 || battleShipGridSpace5 == 60)
	{

		playerBattleMap[6][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 61 || battleShipGridSpace2 == 61 || battleShipGridSpace3 == 61 || battleShipGridSpace4 == 61 || battleShipGridSpace5 == 61)
	{

		playerBattleMap[6][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 62 || battleShipGridSpace2 == 62 || battleShipGridSpace3 == 62 || battleShipGridSpace4 == 62 || battleShipGridSpace5 == 62)
	{

		playerBattleMap[6][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 63 || battleShipGridSpace2 == 63 || battleShipGridSpace3 == 63 || battleShipGridSpace4 == 63 || battleShipGridSpace5 == 63)
	{

		playerBattleMap[6][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 64 || battleShipGridSpace2 == 64 || battleShipGridSpace3 == 64 || battleShipGridSpace4 == 64 || battleShipGridSpace5 == 64)
	{

		playerBattleMap[7][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 65 || battleShipGridSpace2 == 65 || battleShipGridSpace3 == 65 || battleShipGridSpace4 == 65 || battleShipGridSpace5 == 65)
	{

		playerBattleMap[7][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 66 || battleShipGridSpace2 == 66 || battleShipGridSpace3 == 66 || battleShipGridSpace4 == 66 || battleShipGridSpace5 == 66)
	{

		playerBattleMap[7][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 67 || battleShipGridSpace2 == 67 || battleShipGridSpace3 == 67 || battleShipGridSpace4 == 67 || battleShipGridSpace5 == 67)
	{

		playerBattleMap[7][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 68 || battleShipGridSpace2 == 68 || battleShipGridSpace3 == 68 || battleShipGridSpace4 == 68 || battleShipGridSpace5 == 68)
	{

		playerBattleMap[7][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 69 || battleShipGridSpace2 == 69 || battleShipGridSpace3 == 69 || battleShipGridSpace4 == 69 || battleShipGridSpace5 == 69)
	{

		playerBattleMap[7][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 70 || battleShipGridSpace2 == 70 || battleShipGridSpace3 == 70 || battleShipGridSpace4 == 70 || battleShipGridSpace5 == 70)
	{

		playerBattleMap[7][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 71 || battleShipGridSpace2 == 71 || battleShipGridSpace3 == 71 || battleShipGridSpace4 == 71 || battleShipGridSpace5 == 71)
	{

		playerBattleMap[7][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 72 || battleShipGridSpace2 == 72 || battleShipGridSpace3 == 72 || battleShipGridSpace4 == 72 || battleShipGridSpace5 == 72)
	{

		playerBattleMap[7][8] = "[ B ]";

	}
	if (battleShipGridSpace1 == 73 || battleShipGridSpace2 == 73 || battleShipGridSpace3 == 73 || battleShipGridSpace4 == 73 || battleShipGridSpace5 == 73)
	{

		playerBattleMap[8][0] = "[ B ]";

	}
	if (battleShipGridSpace1 == 74 || battleShipGridSpace2 == 74 || battleShipGridSpace3 == 74 || battleShipGridSpace4 == 74 || battleShipGridSpace5 == 74)
	{

		playerBattleMap[8][1] = "[ B ]";

	}
	if (battleShipGridSpace1 == 75 || battleShipGridSpace2 == 75 || battleShipGridSpace3 == 75 || battleShipGridSpace4 == 75 || battleShipGridSpace5 == 75)
	{

		playerBattleMap[8][2] = "[ B ]";

	}
	if (battleShipGridSpace1 == 2 || battleShipGridSpace2 == 76 || battleShipGridSpace3 == 76 || battleShipGridSpace4 == 76 || battleShipGridSpace5 == 76)
	{

		playerBattleMap[8][3] = "[ B ]";

	}
	if (battleShipGridSpace1 == 77 || battleShipGridSpace2 == 77 || battleShipGridSpace3 == 77 || battleShipGridSpace4 == 77 || battleShipGridSpace5 == 77)
	{

		playerBattleMap[8][4] = "[ B ]";

	}
	if (battleShipGridSpace1 == 78 || battleShipGridSpace2 == 78 || battleShipGridSpace3 == 78 || battleShipGridSpace4 == 78 || battleShipGridSpace5 == 78)
	{

		playerBattleMap[8][5] = "[ B ]";

	}
	if (battleShipGridSpace1 == 79 || battleShipGridSpace2 == 79 || battleShipGridSpace3 == 79 || battleShipGridSpace4 == 79 || battleShipGridSpace5 == 79)
	{

		playerBattleMap[8][6] = "[ B ]";

	}
	if (battleShipGridSpace1 == 80 || battleShipGridSpace2 == 80 || battleShipGridSpace3 == 80 || battleShipGridSpace4 == 80 || battleShipGridSpace5 == 80)
	{

		playerBattleMap[8][7] = "[ B ]";

	}
	if (battleShipGridSpace1 == 81 || battleShipGridSpace2 == 81 || battleShipGridSpace3 == 81 || battleShipGridSpace4 == 81 || battleShipGridSpace5 == 81)
	{

		playerBattleMap[8][8] = "[ B ]";

	}

	//Places the player's carrier on the map. Marks it with a CA
	if (carrierGridSpace1 == 1 || carrierGridSpace2 == 1 || carrierGridSpace3 == 1 || carrierGridSpace4 == 1)
	{

		playerBattleMap[0][0] = "[C A]";

	}
	if (carrierGridSpace1 == 2 || carrierGridSpace2 == 2 || carrierGridSpace3 == 2 || carrierGridSpace4 == 2)
	{

		playerBattleMap[0][1] = "[C A]";

	}
	if (carrierGridSpace1 == 3 || carrierGridSpace2 == 3 || carrierGridSpace3 == 3 || carrierGridSpace4 == 3)
	{

		playerBattleMap[0][2] = "[C A]";

	}
	if (carrierGridSpace1 == 4 || carrierGridSpace2 == 4 || carrierGridSpace3 == 4 || carrierGridSpace4 == 4)
	{

		playerBattleMap[0][3] = "[C A]";

	}
	if (carrierGridSpace1 == 5 || carrierGridSpace2 == 5 || carrierGridSpace3 == 5 || carrierGridSpace4 == 5)
	{

		playerBattleMap[0][4] = "[C A]";

	}
	if (carrierGridSpace1 == 6 || carrierGridSpace2 == 6 || carrierGridSpace3 == 6 || carrierGridSpace4 == 6)
	{

		playerBattleMap[0][5] = "[C A]";

	}
	if (carrierGridSpace1 == 7 || carrierGridSpace2 == 7 || carrierGridSpace3 == 7 || carrierGridSpace4 == 7)
	{

		playerBattleMap[0][6] = "[C A]";

	}
	if (carrierGridSpace1 == 8 || carrierGridSpace2 == 8 || carrierGridSpace3 == 8 || carrierGridSpace4 == 8)
	{

		playerBattleMap[0][7] = "[C A]";

	}
	if (carrierGridSpace1 == 9 || carrierGridSpace2 == 9 || carrierGridSpace3 == 9 || carrierGridSpace4 == 9)
	{

		playerBattleMap[0][8] = "[C A]";

	}
	if (carrierGridSpace1 == 10 || carrierGridSpace2 == 10 || carrierGridSpace3 == 10 || carrierGridSpace4 == 10)
	{

		playerBattleMap[1][0] = "[C A]";

	}
	if (carrierGridSpace1 == 11 || carrierGridSpace2 == 11 || carrierGridSpace3 == 11 || carrierGridSpace4 == 11)
	{

		playerBattleMap[1][1] = "[C A]";

	}
	if (carrierGridSpace1 == 12 || carrierGridSpace2 == 12 || carrierGridSpace3 == 12 || carrierGridSpace4 == 12)
	{

		playerBattleMap[1][2] = "[C A]";

	}
	if (carrierGridSpace1 == 13 || carrierGridSpace2 == 13 || carrierGridSpace3 == 13 || carrierGridSpace4 == 13)
	{

		playerBattleMap[1][3] = "[C A]";

	}
	if (carrierGridSpace1 == 14 || carrierGridSpace2 == 14 || carrierGridSpace3 == 14 || carrierGridSpace4 == 14)
	{

		playerBattleMap[1][4] = "[C A]";

	}
	if (carrierGridSpace1 == 15 || carrierGridSpace2 == 15 || carrierGridSpace3 == 15 || carrierGridSpace4 == 15)
	{

		playerBattleMap[1][5] = "[C A]";

	}
	if (carrierGridSpace1 == 16 || carrierGridSpace2 == 16 || carrierGridSpace3 == 16 || carrierGridSpace4 == 16)
	{

		playerBattleMap[1][6] = "[C A]";

	}
	if (carrierGridSpace1 == 17 || carrierGridSpace2 == 17 || carrierGridSpace3 == 17 || carrierGridSpace4 == 17)
	{

		playerBattleMap[1][7] = "[C A]";

	}
	if (carrierGridSpace1 == 18 || carrierGridSpace2 == 18 || carrierGridSpace3 == 18 || carrierGridSpace4 == 18)
	{

		playerBattleMap[1][8] = "[C A]";

	}
	if (carrierGridSpace1 == 19 || carrierGridSpace2 == 19 || carrierGridSpace3 == 19 || carrierGridSpace4 == 19)
	{

		playerBattleMap[2][0] = "[C A]";

	}
	if (carrierGridSpace1 == 20 || carrierGridSpace2 == 20 || carrierGridSpace3 == 20 || carrierGridSpace4 == 20)
	{

		playerBattleMap[2][1] = "[C A]";

	}
	if (carrierGridSpace1 == 21 || carrierGridSpace2 == 21 || carrierGridSpace3 == 21 || carrierGridSpace4 == 21)
	{

		playerBattleMap[2][2] = "[C A]";
	
	}
	if (carrierGridSpace1 == 22 || carrierGridSpace2 == 22 || carrierGridSpace3 == 22 || carrierGridSpace4 == 22)
	{

		playerBattleMap[2][3] = "[C A]";

	}
	if (carrierGridSpace1 == 23 || carrierGridSpace2 == 23 || carrierGridSpace3 == 23 || carrierGridSpace4 == 23)
	{

		playerBattleMap[2][4] = "[C A]";

	}
	if (carrierGridSpace1 == 24 || carrierGridSpace2 == 24 || carrierGridSpace3 == 24 || carrierGridSpace4 == 24)
	{

		playerBattleMap[2][5] = "[C A]";

	}
	if (carrierGridSpace1 == 25 || carrierGridSpace2 == 25 || carrierGridSpace3 == 25 || carrierGridSpace4 == 25)
	{

		playerBattleMap[2][6] = "[C A]";

	}
	if (carrierGridSpace1 == 26 || carrierGridSpace2 == 26 || carrierGridSpace3 == 26 || carrierGridSpace4 == 26)
	{

		playerBattleMap[2][7] = "[C A]";

	}
	if (carrierGridSpace1 == 27 || carrierGridSpace2 == 27 || carrierGridSpace3 == 27 || carrierGridSpace4 == 27)
	{

		playerBattleMap[2][8] = "[C A]";

	}
	if (carrierGridSpace1 == 28 || carrierGridSpace2 == 28 || carrierGridSpace3 == 28 || carrierGridSpace4 == 28)
	{

		playerBattleMap[3][0] = "[C A]";

	}
	if (carrierGridSpace1 == 29 || carrierGridSpace2 == 29 || carrierGridSpace3 == 29 || carrierGridSpace4 == 29)
	{

		playerBattleMap[3][1] = "[C A]";

	}
	if (carrierGridSpace1 == 30 || carrierGridSpace2 == 30 || carrierGridSpace3 == 30 || carrierGridSpace4 == 30)
	{

		playerBattleMap[3][2] = "[C A]";

	}
	if (carrierGridSpace1 == 31 || carrierGridSpace2 == 31 || carrierGridSpace3 == 31 || carrierGridSpace4 == 31)
	{

		playerBattleMap[3][3] = "[C A]";

	}
	if (carrierGridSpace1 == 32 || carrierGridSpace2 == 32 || carrierGridSpace3 == 32 || carrierGridSpace4 == 32)
	{

		playerBattleMap[3][4] = "[C A]";

	}
	if (carrierGridSpace1 == 33 || carrierGridSpace2 == 33 || carrierGridSpace3 == 33 || carrierGridSpace4 == 33)
	{

		playerBattleMap[3][5] = "[C A]";

	}
	if (carrierGridSpace1 == 34 || carrierGridSpace2 == 34 || carrierGridSpace3 == 34 || carrierGridSpace4 == 34)
	{

		playerBattleMap[3][6] = "[C A]";

	}
	if (carrierGridSpace1 == 35 || carrierGridSpace2 == 35 || carrierGridSpace3 == 35 || carrierGridSpace4 == 35)
	{

		playerBattleMap[3][7] = "[C A]";

	}
	if (carrierGridSpace1 == 36 || carrierGridSpace2 == 36 || carrierGridSpace3 == 36 || carrierGridSpace4 == 36)
	{

		playerBattleMap[3][8] = "[C A]";

	}
	if (carrierGridSpace1 == 37 || carrierGridSpace2 == 37 || carrierGridSpace3 == 37 || carrierGridSpace4 == 37)
	{

		playerBattleMap[4][0] = "[C A]";

	}
	if (carrierGridSpace1 == 38 || carrierGridSpace2 == 38 || carrierGridSpace3 == 38 || carrierGridSpace4 == 38)
	{

		playerBattleMap[4][1] = "[C A]";

	}
	if (carrierGridSpace1 == 39 || carrierGridSpace2 == 39 || carrierGridSpace3 == 39 || carrierGridSpace4 == 39)
	{

		playerBattleMap[4][2] = "[C A]";

	}
	if (carrierGridSpace1 == 40 || carrierGridSpace2 == 40 || carrierGridSpace3 == 40 || carrierGridSpace4 == 40)
	{

		playerBattleMap[4][3] = "[C A]";

	}
	if (carrierGridSpace1 == 41 || carrierGridSpace2 == 41 || carrierGridSpace3 == 41 || carrierGridSpace4 == 41)
	{

		playerBattleMap[4][4] = "[C A]";

	}
	if (carrierGridSpace1 == 42 || carrierGridSpace2 == 42 || carrierGridSpace3 == 42 || carrierGridSpace4 == 42)
	{

		playerBattleMap[4][5] = "[C A]";

	}
	if (carrierGridSpace1 == 43 || carrierGridSpace2 == 43 || carrierGridSpace3 == 43 || carrierGridSpace4 == 43)
	{

		playerBattleMap[4][6] = "[C A]";

	}
	if (carrierGridSpace1 == 44 || carrierGridSpace2 == 44 || carrierGridSpace3 == 44 || carrierGridSpace4 == 44)
	{

		playerBattleMap[4][7] = "[C A]";

	}
	if (carrierGridSpace1 == 45 || carrierGridSpace2 == 45 || carrierGridSpace3 == 45 || carrierGridSpace4 == 45)
	{

		playerBattleMap[4][8] = "[C A]";

	}
	if (carrierGridSpace1 == 46 || carrierGridSpace2 == 46 || carrierGridSpace3 == 46 || carrierGridSpace4 == 46)
	{

		playerBattleMap[5][0] = "[C A]";

	}
	if (carrierGridSpace1 == 47 || carrierGridSpace2 == 47 || carrierGridSpace3 == 47 || carrierGridSpace4 == 47)
	{

		playerBattleMap[5][1] = "[C A]";

	}
	if (carrierGridSpace1 == 48 || carrierGridSpace2 == 48 || carrierGridSpace3 == 48 || carrierGridSpace4 == 48)
	{

		playerBattleMap[5][2] = "[C A]";

	}
	if (carrierGridSpace1 == 49 || carrierGridSpace2 == 49 || carrierGridSpace3 == 49 || carrierGridSpace4 == 49)
	{

		playerBattleMap[5][3] = "[C A]";

	}
	if (carrierGridSpace1 == 50 || carrierGridSpace2 == 50 || carrierGridSpace3 == 50 || carrierGridSpace4 == 50)
	{

		playerBattleMap[5][4] = "[C A]";

	}
	if (carrierGridSpace1 == 51 || carrierGridSpace2 == 51 || carrierGridSpace3 == 51 || carrierGridSpace4 == 51)
	{

		playerBattleMap[5][5] = "[C A]";

	}
	if (carrierGridSpace1 == 52 || carrierGridSpace2 == 52 || carrierGridSpace3 == 52 || carrierGridSpace4 == 52)
	{

		playerBattleMap[5][6] = "[C A]";

	}
	if (carrierGridSpace1 == 53 || carrierGridSpace2 == 53 || carrierGridSpace3 == 53 || carrierGridSpace4 == 53)
	{

		playerBattleMap[5][7] = "[C A]";

	}
	if (carrierGridSpace1 == 54 || carrierGridSpace2 == 54 || carrierGridSpace3 == 54 || carrierGridSpace4 == 54)
	{

		playerBattleMap[5][8] = "[C A]";

	}
	if (carrierGridSpace1 == 55 || carrierGridSpace2 == 55 || carrierGridSpace3 == 55 || carrierGridSpace4 == 55)
	{

		playerBattleMap[6][0] = "[C A]";

	}
	if (carrierGridSpace1 == 56 || carrierGridSpace2 == 56 || carrierGridSpace3 == 56 || carrierGridSpace4 == 56)
	{

		playerBattleMap[6][1] = "[C A]";

	}
	if (carrierGridSpace1 == 57 || carrierGridSpace2 == 57 || carrierGridSpace3 == 57 || carrierGridSpace4 == 57)
	{

		playerBattleMap[6][2] = "[C A]";

	}
	if (carrierGridSpace1 == 58 || carrierGridSpace2 == 58 || carrierGridSpace3 == 58 || carrierGridSpace4 == 58)
	{

		playerBattleMap[6][3] = "[C A]";

	}
	if (carrierGridSpace1 == 59 || carrierGridSpace2 == 59 || carrierGridSpace3 == 59 || carrierGridSpace4 == 59)
	{

		playerBattleMap[6][4] = "[C A]";

	}
	if (carrierGridSpace1 == 60 || carrierGridSpace2 == 60 || carrierGridSpace3 == 60 || carrierGridSpace4 == 60)
	{

		playerBattleMap[6][5] = "[C A]";

	}
	if (carrierGridSpace1 == 61 || carrierGridSpace2 == 61 || carrierGridSpace3 == 61 || carrierGridSpace4 == 61)
	{

		playerBattleMap[6][6] = "[C A]";

	}
	if (carrierGridSpace1 == 62 || carrierGridSpace2 == 62 || carrierGridSpace3 == 62 || carrierGridSpace4 == 62)
	{

		playerBattleMap[6][7] = "[C A]";

	}
	if (carrierGridSpace1 == 63 || carrierGridSpace2 == 63 || carrierGridSpace3 == 63 || carrierGridSpace4 == 63)
	{

		playerBattleMap[6][8] = "[C A]";

	}
	if (carrierGridSpace1 == 64 || carrierGridSpace2 == 64 || carrierGridSpace3 == 64 || carrierGridSpace4 == 64)
	{

		playerBattleMap[7][0] = "[C A]";

	}
	if (carrierGridSpace1 == 65 || carrierGridSpace2 == 65 || carrierGridSpace3 == 65 || carrierGridSpace4 == 65)
	{

		playerBattleMap[7][1] = "[C A]";

	}
	if (carrierGridSpace1 == 66 || carrierGridSpace2 == 66 || carrierGridSpace3 == 66 || carrierGridSpace4 == 66)
	{

		playerBattleMap[7][2] = "[C A]";

	}
	if (carrierGridSpace1 == 67 || carrierGridSpace2 == 67 || carrierGridSpace3 == 67 || carrierGridSpace4 == 67)
	{

		playerBattleMap[7][3] = "[C A]";

	}
	if (carrierGridSpace1 == 68 || carrierGridSpace2 == 68 || carrierGridSpace3 == 68 || carrierGridSpace4 == 68)
	{

		playerBattleMap[7][4] = "[C A]";

	}
	if (carrierGridSpace1 == 69 || carrierGridSpace2 == 69 || carrierGridSpace3 == 69 || carrierGridSpace4 == 69)
	{

		playerBattleMap[7][5] = "[C A]";

	}
	if (carrierGridSpace1 == 70 || carrierGridSpace2 == 70 || carrierGridSpace3 == 70 || carrierGridSpace4 == 70)
	{

		playerBattleMap[7][6] = "[C A]";

	}
	if (carrierGridSpace1 == 71 || carrierGridSpace2 == 71 || carrierGridSpace3 == 71 || carrierGridSpace4 == 71)
	{

		playerBattleMap[7][7] = "[C A]";

	}
	if (carrierGridSpace1 == 72 || carrierGridSpace2 == 72 || carrierGridSpace3 == 72 || carrierGridSpace4 == 72)
	{

		playerBattleMap[7][8] = "[C A]";

	}
	if (carrierGridSpace1 == 73 || carrierGridSpace2 == 73 || carrierGridSpace3 == 73 || carrierGridSpace4 == 73)
	{

		playerBattleMap[8][0] = "[C A]";

	}
	if (carrierGridSpace1 == 74 || carrierGridSpace2 == 74 || carrierGridSpace3 == 74 || carrierGridSpace4 == 74)
	{

		playerBattleMap[8][1] = "[C A]";

	}
	if (carrierGridSpace1 == 75 || carrierGridSpace2 == 75 || carrierGridSpace3 == 75 || carrierGridSpace4 == 75)
	{

		playerBattleMap[8][2] = "[C A]";

	}
	if (carrierGridSpace1 == 76 || carrierGridSpace2 == 76 || carrierGridSpace3 == 76 || carrierGridSpace4 == 76)
	{

		playerBattleMap[8][3] = "[C A]";

	}
	if (carrierGridSpace1 == 77 || carrierGridSpace2 == 77 || carrierGridSpace3 == 77 || carrierGridSpace4 == 77)
	{

		playerBattleMap[8][4] = "[C A]";

	}
	if (carrierGridSpace1 == 78 || carrierGridSpace2 == 78 || carrierGridSpace3 == 78 || carrierGridSpace4 == 78)
	{

		playerBattleMap[8][5] = "[C A]";

	}
	if (carrierGridSpace1 == 79 || carrierGridSpace2 == 79 || carrierGridSpace3 == 79 || carrierGridSpace4 == 79)
	{

		playerBattleMap[8][6] = "[C A]";

	}
	if (carrierGridSpace1 == 80 || carrierGridSpace2 == 80 || carrierGridSpace3 == 80 || carrierGridSpace4 == 80)
	{

		playerBattleMap[8][7] = "[C A]";

	}
	if (carrierGridSpace1 == 81 || carrierGridSpace2 == 81 || carrierGridSpace3 == 81 || carrierGridSpace4 == 81)
	{

		playerBattleMap[8][8] = "[C A]";

	}

	//Places the Player's destroyer on the map. Marks it with a D
	if (destroyerGridSpace1 == 1 || destroyerGridSpace2 == 1 || destroyerGridSpace3 == 1)
	{

		playerBattleMap[0][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 2 || destroyerGridSpace2 == 2 || destroyerGridSpace3 == 2)
	{

		playerBattleMap[0][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 3 || destroyerGridSpace2 == 3 || destroyerGridSpace3 == 3)
	{

		playerBattleMap[0][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 4 || destroyerGridSpace2 == 4 || destroyerGridSpace3 == 4)
	{

		playerBattleMap[0][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 5 || destroyerGridSpace2 == 5 || destroyerGridSpace3 == 5)
	{

		playerBattleMap[0][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 6 || destroyerGridSpace2 == 6 || destroyerGridSpace3 == 6)
	{

		playerBattleMap[0][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 7 || destroyerGridSpace2 == 7 || destroyerGridSpace3 == 7)
	{

		playerBattleMap[0][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 8 || destroyerGridSpace2 == 8 || destroyerGridSpace3 == 8)
	{

		playerBattleMap[0][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 9 || destroyerGridSpace2 == 9 || destroyerGridSpace3 == 9)
	{

		playerBattleMap[0][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 10 || destroyerGridSpace2 == 10 || destroyerGridSpace3 == 10)
	{

		playerBattleMap[1][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 11 || destroyerGridSpace2 == 11 || destroyerGridSpace3 == 11)
	{

		playerBattleMap[1][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 12 || destroyerGridSpace2 == 12 || destroyerGridSpace3 == 12)
	{

		playerBattleMap[1][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 13 || destroyerGridSpace2 == 13 || destroyerGridSpace3 == 13)
	{

		playerBattleMap[1][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 14 || destroyerGridSpace2 == 14 || destroyerGridSpace3 == 14)
	{

		playerBattleMap[1][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 15 || destroyerGridSpace2 == 15 || destroyerGridSpace3 == 15)
	{

		playerBattleMap[1][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 16 || destroyerGridSpace2 == 16 || destroyerGridSpace3 == 16)
	{

		playerBattleMap[1][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 17 || destroyerGridSpace2 == 17 || destroyerGridSpace3 == 17)
	{

		playerBattleMap[1][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 18 || destroyerGridSpace2 == 18 || destroyerGridSpace3 == 18)
	{

		playerBattleMap[1][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 19 || destroyerGridSpace2 == 19 || destroyerGridSpace3 == 19)
	{

		playerBattleMap[2][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 20 || destroyerGridSpace2 == 20 || destroyerGridSpace3 == 20)
	{

		playerBattleMap[2][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 21 || destroyerGridSpace2 == 21 || destroyerGridSpace3 == 21)
	{

		playerBattleMap[2][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 22 || destroyerGridSpace2 == 22 || destroyerGridSpace3 == 22)
	{

		playerBattleMap[2][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 23 || destroyerGridSpace2 == 23 || destroyerGridSpace3 == 23)
	{

		playerBattleMap[2][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 24 || destroyerGridSpace2 == 24 || destroyerGridSpace3 == 24)
	{

		playerBattleMap[2][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 25 || destroyerGridSpace2 == 25 || destroyerGridSpace3 == 25)
	{

		playerBattleMap[2][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 26 || destroyerGridSpace2 == 26 || destroyerGridSpace3 == 26)
	{

		playerBattleMap[2][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 27 || destroyerGridSpace2 == 27 || destroyerGridSpace3 == 27)
	{

		playerBattleMap[2][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 28 || destroyerGridSpace2 == 28 || destroyerGridSpace3 == 28)
	{

		playerBattleMap[3][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 29 || destroyerGridSpace2 == 29 || destroyerGridSpace3 == 29)
	{

		playerBattleMap[3][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 30 || destroyerGridSpace2 == 30 || destroyerGridSpace3 == 30)
	{

		playerBattleMap[3][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 31 || destroyerGridSpace2 == 31 || destroyerGridSpace3 == 31)
	{

		playerBattleMap[3][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 32 || destroyerGridSpace2 == 32 || destroyerGridSpace3 == 32)
	{

		playerBattleMap[3][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 33 || destroyerGridSpace2 == 33 || destroyerGridSpace3 == 33)
	{

		playerBattleMap[3][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 34 || destroyerGridSpace2 == 34 || destroyerGridSpace3 == 34)
	{

		playerBattleMap[3][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 35 || destroyerGridSpace2 == 35 || destroyerGridSpace3 == 35)
	{

		playerBattleMap[3][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 36 || destroyerGridSpace2 == 36 || destroyerGridSpace3 == 36)
	{

		playerBattleMap[3][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 37 || destroyerGridSpace2 == 37 || destroyerGridSpace3 == 37)
	{

		playerBattleMap[4][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 38 || destroyerGridSpace2 == 38 || destroyerGridSpace3 == 38)
	{

		playerBattleMap[4][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 39 || destroyerGridSpace2 == 39 || destroyerGridSpace3 == 39)
	{

		playerBattleMap[4][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 40 || destroyerGridSpace2 == 40 || destroyerGridSpace3 == 40)
	{

		playerBattleMap[4][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 41 || destroyerGridSpace2 == 41 || destroyerGridSpace3 == 41)
	{

		playerBattleMap[4][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 42 || destroyerGridSpace2 == 42 || destroyerGridSpace3 == 42)
	{

		playerBattleMap[4][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 43 || destroyerGridSpace2 == 43 || destroyerGridSpace3 == 43)
	{

		playerBattleMap[4][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 44 || destroyerGridSpace2 == 44 || destroyerGridSpace3 == 44)
	{

		playerBattleMap[4][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 45 || destroyerGridSpace2 == 45 || destroyerGridSpace3 == 45)
	{

		playerBattleMap[4][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 46 || destroyerGridSpace2 == 46 || destroyerGridSpace3 == 46)
	{

		playerBattleMap[5][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 47 || destroyerGridSpace2 == 47 || destroyerGridSpace3 == 47)
	{

		playerBattleMap[5][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 48 || destroyerGridSpace2 == 48 || destroyerGridSpace3 == 48)
	{

		playerBattleMap[5][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 49 || destroyerGridSpace2 == 49 || destroyerGridSpace3 == 49)
	{

		playerBattleMap[5][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 50 || destroyerGridSpace2 == 50 || destroyerGridSpace3 == 50)
	{

		playerBattleMap[5][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 51 || destroyerGridSpace2 == 51 || destroyerGridSpace3 == 51)
	{

		playerBattleMap[5][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 52 || destroyerGridSpace2 == 52 || destroyerGridSpace3 == 52)
	{

		playerBattleMap[5][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 53 || destroyerGridSpace2 == 53 || destroyerGridSpace3 == 53)
	{

		playerBattleMap[5][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 54 || destroyerGridSpace2 == 54 || destroyerGridSpace3 == 54)
	{

		playerBattleMap[5][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 55 || destroyerGridSpace2 == 55 || destroyerGridSpace3 == 55)
	{

		playerBattleMap[6][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 56 || destroyerGridSpace2 == 56 || destroyerGridSpace3 == 56)
	{

		playerBattleMap[6][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 57 || destroyerGridSpace2 == 57 || destroyerGridSpace3 == 57)
	{

		playerBattleMap[6][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 58 || destroyerGridSpace2 == 58 || destroyerGridSpace3 == 58)
	{

		playerBattleMap[6][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 59 || destroyerGridSpace2 == 59 || destroyerGridSpace3 == 59)
	{

		playerBattleMap[6][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 60 || destroyerGridSpace2 == 60 || destroyerGridSpace3 == 60)
	{

		playerBattleMap[6][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 61 || destroyerGridSpace2 == 61 || destroyerGridSpace3 == 61)
	{

		playerBattleMap[6][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 62 || destroyerGridSpace2 == 62 || destroyerGridSpace3 == 62)
	{

		playerBattleMap[6][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 63 || destroyerGridSpace2 == 63 || destroyerGridSpace3 == 63)
	{

		playerBattleMap[6][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 64 || destroyerGridSpace2 == 64 || destroyerGridSpace3 == 64)
	{

		playerBattleMap[7][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 65 || destroyerGridSpace2 == 65 || destroyerGridSpace3 == 65)
	{

		playerBattleMap[7][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 66 || destroyerGridSpace2 == 66 || destroyerGridSpace3 == 66)
	{

		playerBattleMap[7][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 67 || destroyerGridSpace2 == 67 || destroyerGridSpace3 == 67)
	{

		playerBattleMap[7][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 68 || destroyerGridSpace2 == 68 || destroyerGridSpace3 == 68)
	{

		playerBattleMap[7][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 69 || destroyerGridSpace2 == 69 || destroyerGridSpace3 == 69)
	{

		playerBattleMap[7][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 70 || destroyerGridSpace2 == 70 || destroyerGridSpace3 == 70)
	{

		playerBattleMap[7][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 71 || destroyerGridSpace2 == 71 || destroyerGridSpace3 == 71)
	{

		playerBattleMap[7][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 72 || destroyerGridSpace2 == 72 || destroyerGridSpace3 == 72)
	{

		playerBattleMap[7][8] = "[ D ]";

	}
	if (destroyerGridSpace1 == 73 || destroyerGridSpace2 == 73 || destroyerGridSpace3 == 73)
	{

		playerBattleMap[8][0] = "[ D ]";

	}
	if (destroyerGridSpace1 == 74 || destroyerGridSpace2 == 74 || destroyerGridSpace3 == 74)
	{

		playerBattleMap[8][1] = "[ D ]";

	}
	if (destroyerGridSpace1 == 75 || destroyerGridSpace2 == 75 || destroyerGridSpace3 == 75)
	{

		playerBattleMap[8][2] = "[ D ]";

	}
	if (destroyerGridSpace1 == 76 || destroyerGridSpace2 == 76 || destroyerGridSpace3 == 76)
	{

		playerBattleMap[8][3] = "[ D ]";

	}
	if (destroyerGridSpace1 == 77 || destroyerGridSpace2 == 77 || destroyerGridSpace3 == 77)
	{

		playerBattleMap[8][4] = "[ D ]";

	}
	if (destroyerGridSpace1 == 78 || destroyerGridSpace2 == 78 || destroyerGridSpace3 == 78)
	{

		playerBattleMap[8][5] = "[ D ]";

	}
	if (destroyerGridSpace1 == 79 || destroyerGridSpace2 == 79 || destroyerGridSpace3 == 79)
	{

		playerBattleMap[8][6] = "[ D ]";

	}
	if (destroyerGridSpace1 == 80 || destroyerGridSpace2 == 80 || destroyerGridSpace3 == 80)
	{

		playerBattleMap[8][7] = "[ D ]";

	}
	if (destroyerGridSpace1 == 81 || destroyerGridSpace2 == 81 || destroyerGridSpace3 == 81)
	{

		playerBattleMap[8][8] = "[ D ]";

	}

	//Places the player's submarine on the map. Marks it with a S
	if (submarineGridSpace1 == 1 || submarineGridSpace2 == 1 || submarineGridSpace3 == 1)
	{

		playerBattleMap[0][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 2 || submarineGridSpace2 == 2 || submarineGridSpace3 == 2)
	{

		playerBattleMap[0][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 3 || submarineGridSpace2 == 3 || submarineGridSpace3 == 3)
	{

		playerBattleMap[0][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 4 || submarineGridSpace2 == 4 || submarineGridSpace3 == 4)
	{

		playerBattleMap[0][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 5 || submarineGridSpace2 == 5 || submarineGridSpace3 == 5)
	{

		playerBattleMap[0][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 6 || submarineGridSpace2 == 6 || submarineGridSpace3 == 6)
	{

		playerBattleMap[0][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 7 || submarineGridSpace2 == 7 || submarineGridSpace3 == 7)
	{

		playerBattleMap[0][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 8 || submarineGridSpace2 == 8 || submarineGridSpace3 == 8)
	{

		playerBattleMap[0][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 9 || submarineGridSpace2 == 9 || submarineGridSpace3 == 9)
	{

		playerBattleMap[0][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 10 || submarineGridSpace2 == 10 || submarineGridSpace3 == 10)
	{

		playerBattleMap[1][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 11 || submarineGridSpace2 == 11 || submarineGridSpace3 == 11)
	{

		playerBattleMap[1][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 12 || submarineGridSpace2 == 12 || submarineGridSpace3 == 12)
	{

		playerBattleMap[1][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 13 || submarineGridSpace2 == 13 || submarineGridSpace3 == 13)
	{

		playerBattleMap[1][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 14 || submarineGridSpace2 == 14 || submarineGridSpace3 == 14)
	{

		playerBattleMap[1][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 15 || submarineGridSpace2 == 15 || submarineGridSpace3 == 15)
	{

		playerBattleMap[1][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 16 || submarineGridSpace2 == 16 || submarineGridSpace3 == 16)
	{

		playerBattleMap[1][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 17 || submarineGridSpace2 == 17 || submarineGridSpace3 == 17)
	{

		playerBattleMap[1][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 18 || submarineGridSpace2 == 18 || submarineGridSpace3 == 18)
	{

		playerBattleMap[1][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 19 || submarineGridSpace2 == 19 || submarineGridSpace3 == 19)
	{

		playerBattleMap[2][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 20 || submarineGridSpace2 == 20 || submarineGridSpace3 == 20)
	{

		playerBattleMap[2][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 21 || submarineGridSpace2 == 21 || submarineGridSpace3 == 21)
	{

		playerBattleMap[2][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 22 || submarineGridSpace2 == 22 || submarineGridSpace3 == 22)
	{

		playerBattleMap[2][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 23 || submarineGridSpace2 == 23 || submarineGridSpace3 == 23)
	{

		playerBattleMap[2][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 24 || submarineGridSpace2 == 24 || submarineGridSpace3 == 24)
	{

		playerBattleMap[2][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 25 || submarineGridSpace2 == 25 || submarineGridSpace3 == 25)
	{

		playerBattleMap[2][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 26 || submarineGridSpace2 == 26 || submarineGridSpace3 == 26)
	{

		playerBattleMap[2][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 27 || submarineGridSpace2 == 27 || submarineGridSpace3 == 27)
	{

		playerBattleMap[2][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 28 || submarineGridSpace2 == 28 || submarineGridSpace3 == 28)
	{

		playerBattleMap[3][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 29 || submarineGridSpace2 == 29 || submarineGridSpace3 == 29)
	{

		playerBattleMap[3][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 30 || submarineGridSpace2 == 30 || submarineGridSpace3 == 30)
	{

		playerBattleMap[3][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 31 || submarineGridSpace2 == 31 || submarineGridSpace3 == 31)
	{

		playerBattleMap[3][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 32 || submarineGridSpace2 == 32 || submarineGridSpace3 == 32)
	{

		playerBattleMap[3][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 33 || submarineGridSpace2 == 33 || submarineGridSpace3 == 33)
	{

		playerBattleMap[3][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 34 || submarineGridSpace2 == 34 || submarineGridSpace3 == 34)
	{

		playerBattleMap[3][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 35 || submarineGridSpace2 == 35 || submarineGridSpace3 == 35)
	{

		playerBattleMap[3][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 36 || submarineGridSpace2 == 36 || submarineGridSpace3 == 36)
	{

		playerBattleMap[3][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 37 || submarineGridSpace2 == 37 || submarineGridSpace3 == 37)
	{

		playerBattleMap[4][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 38 || submarineGridSpace2 == 38 || submarineGridSpace3 == 38)
	{

		playerBattleMap[4][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 39 || submarineGridSpace2 == 39 || submarineGridSpace3 == 39)
	{

		playerBattleMap[4][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 40 || submarineGridSpace2 == 40 || submarineGridSpace3 == 40)
	{

		playerBattleMap[4][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 41 || submarineGridSpace2 == 41 || submarineGridSpace3 == 41)
	{

		playerBattleMap[4][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 42 || submarineGridSpace2 == 42 || submarineGridSpace3 == 42)
	{

		playerBattleMap[4][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 43 || submarineGridSpace2 == 43 || submarineGridSpace3 == 43)
	{

		playerBattleMap[4][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 44 || submarineGridSpace2 == 44 || submarineGridSpace3 == 44)
	{

		playerBattleMap[4][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 45 || submarineGridSpace2 == 45 || submarineGridSpace3 == 45)
	{

		playerBattleMap[4][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 46 || submarineGridSpace2 == 46 || submarineGridSpace3 == 46)
	{

		playerBattleMap[5][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 47 || submarineGridSpace2 == 47 || submarineGridSpace3 == 47)
	{

		playerBattleMap[5][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 48 || submarineGridSpace2 == 48 || submarineGridSpace3 == 48)
	{

		playerBattleMap[5][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 49 || submarineGridSpace2 == 49 || submarineGridSpace3 == 49)
	{

		playerBattleMap[5][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 50 || submarineGridSpace2 == 50 || submarineGridSpace3 == 50)
	{

		playerBattleMap[5][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 51 || submarineGridSpace2 == 51 || submarineGridSpace3 == 51)
	{

		playerBattleMap[5][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 52 || submarineGridSpace2 == 52 || submarineGridSpace3 == 52)
	{

		playerBattleMap[5][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 53 || submarineGridSpace2 == 53 || submarineGridSpace3 == 53)
	{

		playerBattleMap[5][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 54 || submarineGridSpace2 == 54 || submarineGridSpace3 == 54)
	{

		playerBattleMap[5][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 55 || submarineGridSpace2 == 55 || submarineGridSpace3 == 55)
	{

		playerBattleMap[6][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 56 || submarineGridSpace2 == 56 || submarineGridSpace3 == 56)
	{

		playerBattleMap[6][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 57 || submarineGridSpace2 == 57 || submarineGridSpace3 == 57)
	{

		playerBattleMap[6][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 58 || submarineGridSpace2 == 58 || submarineGridSpace3 == 58)
	{

		playerBattleMap[6][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 59 || submarineGridSpace2 == 59 || submarineGridSpace3 == 59)
	{

		playerBattleMap[6][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 60 || submarineGridSpace2 == 60 || submarineGridSpace3 == 60)
	{

		playerBattleMap[6][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 61 || submarineGridSpace2 == 61 || submarineGridSpace3 == 61)
	{

		playerBattleMap[6][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 62 || submarineGridSpace2 == 62 || submarineGridSpace3 == 62)
	{

		playerBattleMap[6][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 63 || submarineGridSpace2 == 63 || submarineGridSpace3 == 63)
	{

		playerBattleMap[6][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 64 || submarineGridSpace2 == 64 || submarineGridSpace3 == 64)
	{

		playerBattleMap[7][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 65 || submarineGridSpace2 == 65 || submarineGridSpace3 == 65)
	{

		playerBattleMap[7][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 66 || submarineGridSpace2 == 66 || submarineGridSpace3 == 66)
	{

		playerBattleMap[7][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 67 || submarineGridSpace2 == 67 || submarineGridSpace3 == 67)
	{

		playerBattleMap[7][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 68 || submarineGridSpace2 == 68 || submarineGridSpace3 == 68)
	{

		playerBattleMap[7][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 69 || submarineGridSpace2 == 69 || submarineGridSpace3 == 69)
	{

		playerBattleMap[7][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 70 || submarineGridSpace2 == 70 || submarineGridSpace3 == 70)
	{

		playerBattleMap[7][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 71 || submarineGridSpace2 == 71 || submarineGridSpace3 == 71)
	{

		playerBattleMap[7][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 72 || submarineGridSpace2 == 72 || submarineGridSpace3 == 72)
	{

		playerBattleMap[7][8] = "[ S ]";

	}
	if (submarineGridSpace1 == 73 || submarineGridSpace2 == 73 || submarineGridSpace3 == 73)
	{

		playerBattleMap[8][0] = "[ S ]";

	}
	if (submarineGridSpace1 == 74 || submarineGridSpace2 == 74 || submarineGridSpace3 == 74)
	{

		playerBattleMap[8][1] = "[ S ]";

	}
	if (submarineGridSpace1 == 75 || submarineGridSpace2 == 75 || submarineGridSpace3 == 75)
	{

		playerBattleMap[8][2] = "[ S ]";

	}
	if (submarineGridSpace1 == 76 || submarineGridSpace2 == 76 || submarineGridSpace3 == 76)
	{

		playerBattleMap[8][3] = "[ S ]";

	}
	if (submarineGridSpace1 == 77 || submarineGridSpace2 == 77 || submarineGridSpace3 == 77)
	{

		playerBattleMap[8][4] = "[ S ]";

	}
	if (submarineGridSpace1 == 78 || submarineGridSpace2 == 78 || submarineGridSpace3 == 78)
	{

		playerBattleMap[8][5] = "[ S ]";

	}
	if (submarineGridSpace1 == 79 || submarineGridSpace2 == 79 || submarineGridSpace3 == 79)
	{

		playerBattleMap[8][6] = "[ S ]";

	}
	if (submarineGridSpace1 == 80 || submarineGridSpace2 == 80 || submarineGridSpace3 == 80)
	{

		playerBattleMap[8][7] = "[ S ]";

	}
	if (submarineGridSpace1 == 81 || submarineGridSpace2 == 81 || submarineGridSpace3 == 81)
	{

		playerBattleMap[8][8] = "[ S ]";

	}

	//Places the player's cruiser on the map. Marks it with a CR
	if (cruiserGridSpace1 == 1 || cruiserGridSpace2 == 1)
	{

		playerBattleMap[0][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 2 || cruiserGridSpace2 == 2)
	{

		playerBattleMap[0][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 3 || cruiserGridSpace2 == 3)
	{

		playerBattleMap[0][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 4 || cruiserGridSpace2 == 4)
	{

		playerBattleMap[0][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 5 || cruiserGridSpace2 == 5)
	{

		playerBattleMap[0][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 6 || cruiserGridSpace2 == 6)
	{

		playerBattleMap[0][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 7 || cruiserGridSpace2 == 7)
	{

		playerBattleMap[0][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 8 || cruiserGridSpace2 == 8)
	{

		playerBattleMap[0][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 9 || cruiserGridSpace2 == 9)
	{

		playerBattleMap[0][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 10 || cruiserGridSpace2 == 10)
	{

		playerBattleMap[1][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 11 || cruiserGridSpace2 == 11)
	{

		playerBattleMap[1][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 12 || cruiserGridSpace2 == 12)
	{

		playerBattleMap[1][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 13 || cruiserGridSpace2 == 13)
	{

		playerBattleMap[1][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 14 || cruiserGridSpace2 == 14)
	{

		playerBattleMap[1][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 15 || cruiserGridSpace2 == 15)
	{

		playerBattleMap[1][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 16 || cruiserGridSpace2 == 16)
	{

		playerBattleMap[1][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 17 || cruiserGridSpace2 == 17)
	{

		playerBattleMap[1][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 18 || cruiserGridSpace2 == 18)
	{

		playerBattleMap[1][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 19 || cruiserGridSpace2 == 19)
	{

		playerBattleMap[2][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 20 || cruiserGridSpace2 == 20)
	{

		playerBattleMap[2][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 21 || cruiserGridSpace2 == 21)
	{

		playerBattleMap[2][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 22 || cruiserGridSpace2 == 22)
	{

		playerBattleMap[2][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 23 || cruiserGridSpace2 == 23)
	{

		playerBattleMap[2][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 24 || cruiserGridSpace2 == 24)
	{

		playerBattleMap[2][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 25 || cruiserGridSpace2 == 25)
	{

		playerBattleMap[2][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 26 || cruiserGridSpace2 == 26)
	{

		playerBattleMap[2][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 27 || cruiserGridSpace2 == 27)
	{

		playerBattleMap[2][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 28 || cruiserGridSpace2 == 28)
	{

		playerBattleMap[3][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 29 || cruiserGridSpace2 == 29)
	{

		playerBattleMap[3][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 30 || cruiserGridSpace2 == 30)
	{

		playerBattleMap[3][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 31 || cruiserGridSpace2 == 31)
	{

		playerBattleMap[3][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 32 || cruiserGridSpace2 == 32)
	{

		playerBattleMap[3][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 33 || cruiserGridSpace2 == 33)
	{

		playerBattleMap[3][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 34 || cruiserGridSpace2 == 34)
	{

		playerBattleMap[3][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 35 || cruiserGridSpace2 == 35)
	{

		playerBattleMap[3][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 36 || cruiserGridSpace2 == 36)
	{

		playerBattleMap[3][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 37 || cruiserGridSpace2 == 37)
	{

		playerBattleMap[4][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 38 || cruiserGridSpace2 == 38)
	{

		playerBattleMap[4][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 39 || cruiserGridSpace2 == 39)
	{

		playerBattleMap[4][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 40 || cruiserGridSpace2 == 40)
	{

		playerBattleMap[4][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 41 || cruiserGridSpace2 == 41)
	{

		playerBattleMap[4][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 42 || cruiserGridSpace2 == 42)
	{

		playerBattleMap[4][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 43 || cruiserGridSpace2 == 43)
	{

		playerBattleMap[4][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 44 || cruiserGridSpace2 == 44)
	{

		playerBattleMap[4][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 45 || cruiserGridSpace2 == 45)
	{

		playerBattleMap[4][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 46 || cruiserGridSpace2 == 46)
	{

		playerBattleMap[5][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 47 || cruiserGridSpace2 == 47)
	{

		playerBattleMap[5][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 48 || cruiserGridSpace2 == 48)
	{

		playerBattleMap[5][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 49 || cruiserGridSpace2 == 49)
	{

		playerBattleMap[5][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 50 || cruiserGridSpace2 == 50)
	{

		playerBattleMap[5][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 51 || cruiserGridSpace2 == 51)
	{

		playerBattleMap[5][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 52 || cruiserGridSpace2 == 52)
	{

		playerBattleMap[5][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 53 || cruiserGridSpace2 == 53)
	{

		playerBattleMap[5][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 54 || cruiserGridSpace2 == 54)
	{

		playerBattleMap[5][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 55 || cruiserGridSpace2 == 55)
	{

		playerBattleMap[6][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 56 || cruiserGridSpace2 == 56)
	{

		playerBattleMap[6][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 57 || cruiserGridSpace2 == 57)
	{

		playerBattleMap[6][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 58 || cruiserGridSpace2 == 58)
	{

		playerBattleMap[6][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 59 || cruiserGridSpace2 == 59)
	{

		playerBattleMap[6][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 60 || cruiserGridSpace2 == 60)
	{

		playerBattleMap[6][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 61 || cruiserGridSpace2 == 61)
	{

		playerBattleMap[6][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 62 || cruiserGridSpace2 == 62)
	{

		playerBattleMap[6][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 63 || cruiserGridSpace2 == 63)
	{

		playerBattleMap[6][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 64 || cruiserGridSpace2 == 64)
	{

		playerBattleMap[7][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 65 || cruiserGridSpace2 == 65)
	{

		playerBattleMap[7][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 66 || cruiserGridSpace2 == 66)
	{

		playerBattleMap[7][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 67 || cruiserGridSpace2 == 67)
	{

		playerBattleMap[7][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 68 || cruiserGridSpace2 == 68)
	{

		playerBattleMap[7][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 69 || cruiserGridSpace2 == 69)
	{

		playerBattleMap[7][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 70 || cruiserGridSpace2 == 70)
	{

		playerBattleMap[7][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 71 || cruiserGridSpace2 == 71)
	{

		playerBattleMap[7][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 72 || cruiserGridSpace2 == 72)
	{

		playerBattleMap[7][8] = "[C R]";

	}
	if (cruiserGridSpace1 == 73 || cruiserGridSpace2 == 73)
	{

		playerBattleMap[8][0] = "[C R]";

	}
	if (cruiserGridSpace1 == 74 || cruiserGridSpace2 == 74)
	{

		playerBattleMap[8][1] = "[C R]";

	}
	if (cruiserGridSpace1 == 75 || cruiserGridSpace2 == 75)
	{

		playerBattleMap[8][2] = "[C R]";

	}
	if (cruiserGridSpace1 == 76 || cruiserGridSpace2 == 76)
	{

		playerBattleMap[8][3] = "[C R]";

	}
	if (cruiserGridSpace1 == 77 || cruiserGridSpace2 == 77)
	{

		playerBattleMap[8][4] = "[C R]";

	}
	if (cruiserGridSpace1 == 78 || cruiserGridSpace2 == 78)
	{

		playerBattleMap[8][5] = "[C R]";

	}
	if (cruiserGridSpace1 == 79 || cruiserGridSpace2 == 79)
	{

		playerBattleMap[8][6] = "[C R]";

	}
	if (cruiserGridSpace1 == 80 || cruiserGridSpace2 == 80)
	{

		playerBattleMap[8][7] = "[C R]";

	}
	if (cruiserGridSpace1 == 81 || cruiserGridSpace2 == 81)
	{

		playerBattleMap[8][8] = "[C R]";

	}

}

//Checks to see if a guess has already been guessed. Turns guessed into true or false
void alreadyGuessed(string whichPlayer, int shot)
{
	
	//Player's Checker
	if (whichPlayer == "Player")
	{

		guessed = false;

		for (int i = 0; i < playerGuesses.size(); i++)
		{

			if (shot == playerGuesses[i])
			{

				guessed = true;

			}

		}

	}
	//AI's checker
	else if (whichPlayer == "AI")
	{

		guessed = false;

		for (int i = 0; i < aiGuesses.size(); i++)
		{

			if (shot == aiGuesses[i])
			{

				guessed = true;

			}

		}

	}

}

//Checks to see if the given coordinant is on the edge of the grid
bool edgeChecker(int coordinant)
{

	 //Any coordinant that is on the right side will equal 0 when moduloused by 9
	 int rightChecker = coordinant % 9;

	 //Same logic. Any on the left side will equal zero 0 after subtracting 1 and modulousing by 9
	 int leftChecker = (coordinant - 1) % 9;

	 if (rightChecker == 0)
	 {

		 onRightEdge = true;

	 }
	 else
	 {

		 onRightEdge = false;

	 }

	 if (leftChecker == 0)
	 {

		 onLeftEdge = true;

	 }
	 else
	 {

		 onLeftEdge = false;

	 }

	 //It is on the top if it is less then 9
	 if (coordinant <= 9)
	 {

		 onTopEdge = true;

	 }
	 else
	 {

		 onTopEdge = false;

	 }

	 //It is on the top if it is between 73 and 81 inclusively
	 if (coordinant <= 81 && coordinant >= 73)
	 {

		 onBottomEdge = true;

	 }
	 else
	 {

		 onBottomEdge = false;

	 }

	 //Returns each edge, whether it be true or false
	 return onRightEdge;
	 return onLeftEdge;
	 return onTopEdge;
	 return onBottomEdge;

}

//The main function for tic tak toe
void ticTakToe()
{

	//A few local variables needed throughout the game
	int playerChoice;
	int roundNum = 1;
	int playerWinCount = 0;
	int aiWinCount = 0;
	string whoWon;
	bool threeInARow = false;

	//Directions
	cout << "Welcome to Tic Tak Toe! The object of this game is to get three in a row. The problem is, you can get blocked by the opponent. ";
	cout << "You will be X's. Your opponent will be O's. It will be best two out of three. You will go first." << endl;

	//Makes the game best two out of three
	while (true) {

		//Plays a round until a tie or someone gets three in a row
		while (threeInARow == false) {

			cout << "Round Number: " << roundNum << endl;

			//Tic Tak Toe Board
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{

					if (j == 4)
					{

						cout << ticTakToeBoard[i][j] << " " << endl;

					}
					else if (j < 4)
					{

						cout << ticTakToeBoard[i][j] << " ";

					}

				}

			}

			//Gets a space from the player and makes sure it is not already taken
			while (true)
			{

				cout << "Where would you like to go?" << endl;
				cin >> playerChoice;

				guessed = false;

				for (int i = 0; i < takenSpaces.size(); i++)
				{

					if (playerChoice == takenSpaces[i])
					{

						guessed = true;

					}

				}

				if (guessed == false)
				{

					break;

				}
				else
				{

					cout << "Please choose an open space." << endl;

				}

			}

			//Updates the map
			if (playerChoice == 1)
			{

				ticTakToeBoard[0][0] = 'X';

				takenSpaces.push_back(1);

			}
			else if (playerChoice == 2)
			{

				ticTakToeBoard[0][2] = 'X';

				takenSpaces.push_back(2);

			}
			else if (playerChoice == 3)
			{

				ticTakToeBoard[0][4] = 'X';

				takenSpaces.push_back(3);

			}
			else if (playerChoice == 4)
			{

				ticTakToeBoard[2][0] = 'X';

				takenSpaces.push_back(4);

			}
			else if (playerChoice == 5)
			{

				ticTakToeBoard[2][2] = 'X';

				takenSpaces.push_back(5);

			}
			else if (playerChoice == 6)
			{

				ticTakToeBoard[2][4] = 'X';

				takenSpaces.push_back(6);

			}
			else if (playerChoice == 7)
			{

				ticTakToeBoard[4][0] = 'X';

				takenSpaces.push_back(7);

			}
			else if (playerChoice == 8)
			{

				ticTakToeBoard[4][2] = 'X';

				takenSpaces.push_back(8);

			}
			else if (playerChoice == 9)
			{

				ticTakToeBoard[4][4] = 'X';

				takenSpaces.push_back(9);

			}

			//Checks to see if it is a tie
			if (takenSpaces.size() > 8)
			{

				whoWon = "tie";

				break;

			}

			//Checks to see if the player has won
			threeInARow = hasWon("player");

			if (threeInARow == true)
			{

				playerWinCount++;

				whoWon = "player";

			}
			//AI's Turn
			else if (threeInARow == false)
			{

				ticTakToeAI();

				threeInARow = false;

				threeInARow = hasWon("ai");


				if (threeInARow == true)
				{

					aiWinCount++;

					whoWon = "ai";

				}

			}

			

		}

		//Announces the winner
		if (whoWon == "player")
		{

			cout << "Congratulations " << playerName << ", that was a round well won!" << endl;

		}
		else if (whoWon == "ai")
		{

			cout << "It looks like you have lost. Shake it off. You have got the next one." << endl;

		}
		else if (whoWon == "tie")
		{

			cout << "It looks like that is a tie!" << endl;

		}

		//Tells the player how many times they and the AI have won
		cout << "Player: " << playerWinCount << endl;
		cout << "AI: " << aiWinCount << endl;

		//Updates the round number
		roundNum++;

		//Resets the board
		ticTakToeBoard[0][0] = '1';
		ticTakToeBoard[0][2] = '2';
		ticTakToeBoard[0][4] = '3';
		ticTakToeBoard[2][0] = '4';
		ticTakToeBoard[2][2] = '5';
		ticTakToeBoard[2][4] = '6';
		ticTakToeBoard[4][0] = '7';
		ticTakToeBoard[4][2] = '8';
		ticTakToeBoard[4][4] = '9';

		//Resets for next round
		takenSpaces.clear();

		threeInARow = false;

		//Checks to see if anyone has won two games
		if (playerWinCount == 2)
		{

			cout << "Congratulations " << playerName << ", you just won best two out of three!" << endl;

			break;

		}
		else if (aiWinCount == 2)
		{

			cout << "Better luck next time, the ai won two out of three." << endl;

			break;

		}

	}

	system("pause");

	gamePicker();

}

//Checks to see if the player or ai has won tic tak toe
bool hasWon(string player)
{

	//Checking for three in a row for the player
	if (player == "player")
	{

		if (ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[0][2] == 'X' && ticTakToeBoard[0][4] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[2][0] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[2][4] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[4][2] == 'X' && ticTakToeBoard[4][4] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[2][0] == 'X' && ticTakToeBoard[4][0] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[0][2] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][2] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[2][4] == 'X' && ticTakToeBoard[4][4] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][4] == 'X')
		{

			return true;

		}
		else if (ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][0] == 'X')
		{

			return true;

		}
		else
		{

			return false;

		}

	}

	//Checking for three in a row for the AI
	if (player == "ai")
	{

		if (ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[0][2] == 'O' && ticTakToeBoard[0][4] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[2][0] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[2][4] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[4][2] == 'O' && ticTakToeBoard[4][4] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[2][0] == 'O' && ticTakToeBoard[4][0] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[0][2] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][2] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[2][4] == 'O' && ticTakToeBoard[4][4] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][4] == 'O')
		{

			return true;

		}
		else if (ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][0] == 'O')
		{

			return true;

		}
		else
		{

			return false;

		}

	}

}

//The Tic Tak Toe's AI
char ticTakToeAI()
{

	//Checking to see if it can get three in a row
	if (ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[0][2] == 'O' && ticTakToeBoard[0][4] != 'X' || ticTakToeBoard[2][4] == 'O' && ticTakToeBoard[4][4] == 'O' && ticTakToeBoard[0][4] != 'X' || ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[0][4] != 'X')
	{

		ticTakToeBoard[0][4] = 'O';

		takenSpaces.push_back(3);

	}
	else if (ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[0][2] != 'X' || ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][2] == 'O' && ticTakToeBoard[0][2] != 'X')
	{

		ticTakToeBoard[0][2] = 'O';

		takenSpaces.push_back(2);

	}
	else if (ticTakToeBoard[0][2] == 'O' && ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[0][0] != 'X' || ticTakToeBoard[2][0] == 'O' && ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[0][0] != 'X' || ticTakToeBoard[4][4] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[0][0] != 'X')
	{

		ticTakToeBoard[0][0] = 'O';

		takenSpaces.push_back(1);

	}
	else if (ticTakToeBoard[2][0] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[2][4] != 'X' || ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[4][4] == 'O' && ticTakToeBoard[2][4] != 'X')
	{

		ticTakToeBoard[2][4] = 'O';

		takenSpaces.push_back(6);

	}
	else if (ticTakToeBoard[2][0] == 'O' && ticTakToeBoard[2][4] == 'O' && ticTakToeBoard[2][2] != 'X' || ticTakToeBoard[4][2] == 'O' && ticTakToeBoard[0][2] == 'O' && ticTakToeBoard[2][2] != 'X' || ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[4][4] == 'O' && ticTakToeBoard[2][2] != 'X' || ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[2][2] != 'X')
	{

		ticTakToeBoard[2][2] = 'O';

		takenSpaces.push_back(5);

	}
	else if (ticTakToeBoard[2][4] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[2][0] != 'X' || ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[2][0] != 'X')
	{

		ticTakToeBoard[2][0] = 'O';

		takenSpaces.push_back(4);

	}
	else if (ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[4][2] == 'O' && ticTakToeBoard[4][4] != 'X' || ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[2][4] == 'O' && ticTakToeBoard[4][4] != 'X' || ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][4] != 'X')
	{

		ticTakToeBoard[4][4] = 'O';

		takenSpaces.push_back(9);

	}
	else if (ticTakToeBoard[4][4] == 'O' && ticTakToeBoard[4][0] == 'O' && ticTakToeBoard[4][2] != 'X' || ticTakToeBoard[0][2] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][2] != 'X')
	{

		ticTakToeBoard[4][2] = 'O';

		takenSpaces.push_back(8);

	}
	else if (ticTakToeBoard[4][2] == 'O' && ticTakToeBoard[4][4] == 'O' && ticTakToeBoard[4][0] != 'X' || ticTakToeBoard[2][0] == 'O' && ticTakToeBoard[0][0] == 'O' && ticTakToeBoard[4][0] != 'X' || ticTakToeBoard[0][4] == 'O' && ticTakToeBoard[2][2] == 'O' && ticTakToeBoard[4][0] != 'X')
	{

		ticTakToeBoard[4][0] = 'O';

		takenSpaces.push_back(7);

	}
	//Checks to see if it has to block the player
	else if (ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[0][2] == 'X' && ticTakToeBoard[0][4] != 'O' || ticTakToeBoard[2][4] == 'X' && ticTakToeBoard[4][4] == 'X' && ticTakToeBoard[0][4] != 'O' || ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[0][4] != 'O')
	{

		ticTakToeBoard[0][4] = 'O';

		takenSpaces.push_back(3);

	}
	else if (ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[0][2] != 'O' || ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][2] == 'X' && ticTakToeBoard[0][2] != 'O')
	{

		ticTakToeBoard[0][2] = 'O';

		takenSpaces.push_back(2);

	}
	else if (ticTakToeBoard[0][2] == 'X' && ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[0][0] != 'O' || ticTakToeBoard[2][0] == 'X' && ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[0][0] != 'O' || ticTakToeBoard[4][4] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[0][0] != 'O')
	{

		ticTakToeBoard[0][0] = 'O';

		takenSpaces.push_back(1);

	}
	else if (ticTakToeBoard[2][0] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[2][4] != 'O' || ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[4][4] == 'X' && ticTakToeBoard[2][4] != 'O')
	{

		ticTakToeBoard[2][4] = 'O';

		takenSpaces.push_back(6);

	}
	else if (ticTakToeBoard[2][0] == 'X' && ticTakToeBoard[2][4] == 'X' && ticTakToeBoard[2][2] != 'O' || ticTakToeBoard[4][2] == 'X' && ticTakToeBoard[0][2] == 'X' && ticTakToeBoard[2][2] != 'O' || ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[4][4] == 'X' && ticTakToeBoard[2][2] != 'O' || ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[2][2] != 'O')
	{

		ticTakToeBoard[2][2] = 'O';

		takenSpaces.push_back(5);

	}
	else if (ticTakToeBoard[2][4] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[2][0] != 'O' || ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[2][0] != 'O')
	{

		ticTakToeBoard[2][0] = 'O';

		takenSpaces.push_back(4);

	}
	else if (ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[4][2] == 'X' && ticTakToeBoard[4][4] != 'O' || ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[2][4] == 'X' && ticTakToeBoard[4][4] != 'O' || ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][4] != 'O')
	{

		ticTakToeBoard[4][4] = 'O';

		takenSpaces.push_back(9);

	}
	else if (ticTakToeBoard[4][4] == 'X' && ticTakToeBoard[4][0] == 'X' && ticTakToeBoard[4][2] != 'O' || ticTakToeBoard[0][2] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][2] != 'O')
	{

		ticTakToeBoard[4][2] = 'O';

		takenSpaces.push_back(8);

	}
	else if (ticTakToeBoard[4][2] == 'X' && ticTakToeBoard[4][4] == 'X' && ticTakToeBoard[4][0] != 'O' || ticTakToeBoard[2][0] == 'X' && ticTakToeBoard[0][0] == 'X' && ticTakToeBoard[4][0] != 'O' || ticTakToeBoard[0][4] == 'X' && ticTakToeBoard[2][2] == 'X' && ticTakToeBoard[4][0] != 'O')
	{

		ticTakToeBoard[4][0] = 'O';

		takenSpaces.push_back(7);

	}
	//Goes in a specific order every time otherwise
	else if (ticTakToeBoard[2][2] == '5')
	{

		ticTakToeBoard[2][2] = 'O';

		takenSpaces.push_back(5);

	}
	else if (ticTakToeBoard[0][0] == '1')
	{

		ticTakToeBoard[0][0] = 'O';

		takenSpaces.push_back(1);

	}
	else if (ticTakToeBoard[0][4] == '3')
	{

		ticTakToeBoard[0][4] = 'O';

		takenSpaces.push_back(3);

	}
	else if (ticTakToeBoard[4][4] == '9')
	{

		ticTakToeBoard[4][4] = 'O';

		takenSpaces.push_back(9);

	}
	else if (ticTakToeBoard[4][0] == '7')
	{

		ticTakToeBoard[4][0] = 'O';

		takenSpaces.push_back(7);

	}
	else if (ticTakToeBoard[0][2] == '2')
	{

		ticTakToeBoard[0][2] = 'O';

		takenSpaces.push_back(2);

	}
	else if (ticTakToeBoard[2][0] == '4')
	{

		ticTakToeBoard[2][0] = 'O';

		takenSpaces.push_back(4);

	}
	else if (ticTakToeBoard[2][4] == '6')
	{

		ticTakToeBoard[2][4] = 'O';

		takenSpaces.push_back(6);

	}
	else if (ticTakToeBoard[4][2] == '8')
	{

		ticTakToeBoard[4][2] = 'O';

		takenSpaces.push_back(8);

	}

	//Updates the map with the AI's move
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			return ticTakToeBoard[i][j];

		}

	}

}

//The main hangman function
void hangMan()
{

	//A few local variables for the game
	char playerGuess;
	string wordOne;
	string wordTwo;
	string wordThree;

	//The list of words. Can be modified to have more than ten. Can also be any word that is less then 12 letters just by changing the word here
	string words[10] = { "ONOMATOPOEIA" , "PHOENIX" , "REDWOODS" , "PAYSON" , "PHILADELPHIA" , "HARLEM" , "BATTISTA" , "CLEARWATER" , "JACKSON" , "ANARCHY" };

	//Keeps track of how much of each word is guessed
	char wordProgressOne[12] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
	char wordProgressTwo[12] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
	char wordProgressThree[12] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };

	//A few more local variables
	int numOfSim = 1;
	int numOfWord;
	int numOfIncorrectGuesses = 0;
	int numOfTimes = 0;
	bool wordGuessed = false;
	char response;
	
	//Directions
	cout << "This is a game of hangman. You will be given a word to solve by guessing letters. ";
	cout << "If you get it wrong, you will get a strike, and a shape will be drawn. If you get it wrong 6 times, the prisoner will die. ";
	cout << "You must complete the simulation three times successfully or else the prisoner will die. ";
	cout << "Please type all guesses in capital letters." << endl;

	//Picks three words and assigns each to the respective word variable
	for (int i = 0; i < 3; i++)
	{

		numOfWord = wordPicker();

		if (i == 0)
		{

			wordOne = words[numOfWord];

		}
		else if (i == 1)
		{

			wordTwo = words[numOfWord];

		}
		else if (i == 2)
		{

			wordThree = words[numOfWord];

		}

	}

	//Gets the length of the word
	int wordOneLength = wordOne.length();
	int wordTwoLength = wordTwo.length();
	int wordThreeLength = wordThree.length();

	//Replaces the spaces with _ to signify the length of a word
	for (int k = 0; k < wordOneLength; k++)
	{

		wordProgressOne[k] = '_';

	}
	for (int l = 0; l < wordTwoLength; l++)
	{

		wordProgressTwo[l] = '_';

	}
	for (int m = 0; m < wordThreeLength; m++)
	{

		wordProgressThree[m] = '_';

	}

	//While it has been 3 games or less
	while (numOfSim < 4)
	{

		//The main part of the game. Gets a guess from the player and makes sure it has not been guessed. If the word is guessed or incorrect guesses goes to 6, the loop ends
		while (numOfIncorrectGuesses < 6 && wordGuessed == false)
		{

			int numOfGuessesLeft = 6;

			numOfGuessesLeft = numOfGuessesLeft - numOfIncorrectGuesses;

			cout << "You have " << numOfGuessesLeft << " guesses left" << endl;

			//Updates the word/hangman post
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{

					if (j == 3)
					{

						cout << hangManGrid[i][j] << " " << endl;

					}
					else if (j < 3)
					{

						cout << hangManGrid[i][j] << " ";

					}

				}

			}

			cout << endl;

			//Prints out the letters guessed
			for (int j = 0; j < lettersGuessed.size(); j++)
			{

				if (j % 6 != 0)
				{

					cout << lettersGuessed[j] << ", ";

				}
				else if (j == 0)
				{

					cout << lettersGuessed[j] << ", ";

				}
				else
				{

					cout << lettersGuessed[j] << endl;

				}

			}

			cout << endl;

			//Prints out the word progress
			if (numOfSim == 1)
			{

				for (int n = 0; n < wordOneLength; n++)
				{

					cout << wordProgressOne[n] << " ";


				}

			}
			else if (numOfSim == 2)
			{

				for (int o = 0; o < wordTwoLength; o++)
				{

					cout << wordProgressTwo[o] << " ";

				}

			}
			else if (numOfSim == 3)
			{

				for (int p = 0; p < wordThreeLength; p++)
				{

					cout << wordProgressThree[p] << " ";

				}

			}

			cout << endl;

			//Gets the guess and checks that it has not already been guessed
			while (true)
			{

				cout << "Ok " << playerName << ", what is your guess?" << endl;
				cin >> playerGuess;

				wasGuessed(playerGuess);

				if (guessed == false)
				{

					break;

				}
				else
				{

					cout << "Please guess a letter that was not previously guessed!" << endl;

				}

			}

			//Adds the guess to those that have been guessed
			lettersGuessed.push_back(playerGuess);

			//Checks to see if it is in the word
			if (numOfSim == 1)
			{

				for (int r = 0; r < wordOneLength; r++)
				{

					if (playerGuess == wordOne[r])
					{

						wordProgressOne[r] = playerGuess;

						numOfTimes++;

					}

				}

				//If it appears in the word, it is not incorrect
				if (numOfTimes != 0)
				{

					cout << "That appears " << numOfTimes << " times in this word" << endl;

				}
				else
				{

					cout << "That is not in the word!" << endl;

					numOfIncorrectGuesses++;

				}

				//Resets
				numOfTimes = 0;

				wordGuessed = true;

				//See if the word has been guessed
				for (int u = 0; u < 12; u++)
				{

					if ('_' == wordProgressOne[u])
					{

						wordGuessed = false;

					}

				}

			}
			else if (numOfSim == 2)
			{

				for (int s = 0; s < wordTwoLength; s++)
				{

					if (playerGuess == wordTwo[s])
					{

						wordProgressTwo[s] = playerGuess;

						numOfTimes++;

					}

				}

				if (numOfTimes != 0)
				{

					cout << "That appears " << numOfTimes << " times in this word" << endl;

				}
				else
				{

					cout << "That is not in the word!" << endl;

					numOfIncorrectGuesses++;

				}

				numOfTimes = 0;

				wordGuessed = true;

				for (int u = 0; u < 12; u++)
				{

					if ('_' == wordProgressTwo[u])
					{

						wordGuessed = false;

					}

				}

			}
			else if (numOfSim == 3)
			{

				for (int t = 0; t < wordThreeLength; t++)
				{

					if (playerGuess == wordThree[t])
					{

						wordProgressThree[t] = playerGuess;

						numOfTimes++;

					}

				}

				if (numOfTimes != 0)
				{

					cout << "That appears " << numOfTimes << " times in this word" << endl;

				}
				else
				{

					cout << "That is not in the word!" << endl;

					numOfIncorrectGuesses++;

				}

				numOfTimes = 0;

				wordGuessed = true;

				for (int u = 0; u < 12; u++)
				{

					if ('_' == wordProgressThree[u])
					{

						wordGuessed = false;

					}

				}

			}

			//Updates the hangman's post
			hangManUpdater(numOfIncorrectGuesses);

		}

		//If they lose
		if (numOfIncorrectGuesses >= 6)
		{

			cout << "I am sorry " << playerName << ", but you have failed and the prisoner has died." << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{

					if (j == 3)
					{

						cout << hangManGrid[i][j] << " " << endl;

					}
					else if (j < 3)
					{

						cout << hangManGrid[i][j] << " ";

					}

				}

			}

			numOfSim = 4;

		}
		//If they win
		else if (wordGuessed == true)
		{

			cout << "Congratulations " << playerName << "! You have successfully completed round " << numOfSim << " of the Simulation!" << endl;

			if (numOfSim == 1)
			{

				cout << "The word was " << wordOne << "!" << endl;

			}
			else if (numOfSim == 2)
			{

				cout << "The word was " << wordTwo << "!" << endl;

			}
			else if (numOfSim == 3)
			{

				cout << "The word was " << wordThree << "!" << endl;

			}

		}

		//Can replay for the other 3 words
		if (numOfSim < 3)
		{

			cout << "Would you like to move on to the next round?" << endl;
			cout << "Please type Y for yes and N for no" << endl;
			cin >> response;

			if (response == 'Y')
			{

				numOfSim++;

				numOfIncorrectGuesses = 0;
				wordGuessed = false;
				lettersGuessed.clear();
				hangManGrid[2][2] = ' ';
				hangManGrid[3][2] = ' ';
				hangManGrid[3][1] = ' ';
				hangManGrid[3][3] = ' ';
				hangManGrid[4][1] = ' ';
				hangManGrid[4][3] = ' ';

			}
			else if (response == 'N')
			{

				numOfSim = 4;

			}

		}
		else if (numOfSim == 3)
		{

			numOfSim++;

		}

	}


	//Ends the game
	cout << "End of Simulation. Goodbye " << playerName << endl;

	system("pause");

	//Resets in case they come to play again
	hmGuessed1 = 0;
	hmGuessed2 = 0;
	hmGuessed3 = 0;
	hmGuessed4 = 0;
	hmGuessed5 = 0;
	hmGuessed6 = 0;
	hmGuessed7 = 0;
	hmGuessed8 = 0;
	hmGuessed9 = 0;
	hmGuessed10 = 0;

	lettersGuessed.clear();

	gamePicker();

} 

//Draws a hangman character
char hangManUpdater(int incorrectGuess)
{

	//Draws the head
	if (incorrectGuess == 1)
	{

		hangManGrid[2][2] = 'O';

		return hangManGrid[2][2];

	}
	//Draws the body
	else if (incorrectGuess == 2)
	{

		hangManGrid[3][2] = '|';

		return hangManGrid[3][2];

	}
	//Draws the left arm
	else if (incorrectGuess == 3)
	{

		hangManGrid[3][1] = '-';

		return hangManGrid[3][1];

	}
	//Draws the right arm
	else if (incorrectGuess == 4)
	{

		hangManGrid[3][3] = '-';

		return hangManGrid[3][3];

	}
	//draws the left leg
	else if (incorrectGuess == 5)
	{

		hangManGrid[4][1] = '/';

		return hangManGrid[4][1];

	}
	//Draws the right leg
	else if (incorrectGuess == 6)
	{

		hangManGrid[4][3] = 'L';

		return hangManGrid[4][3];

	}
	//Doesn't return anything. Kinda like return 0
	else
	{

		return 'a';

	}

}

//Picks the word for hangman
int wordPicker()
{

	//Gets a random number between 1 and 10 and makes sure it has not already been used
	while (true)
	{

		int wantedNumber = (rand() % 10);

		wasUsed(wantedNumber);

		if (guessed == false)
		{

			return wantedNumber;

			break;

		}

	}

}

//The old method of making sure a number was not already used. Still works, just takes more storage, more lines of code, and more time to reset
bool wasUsed(int wantedNum)
{

	//Goes through each number and checks if it's already been through based off 1s and 0s
	if (wantedNum == 1)
	{

		if (hmGuessed1 == 0)
		{

			hmGuessed1 = 1;

			guessed = false;

		}
		else if (hmGuessed1 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 2)
	{

		if (hmGuessed2 == 0)
		{

			hmGuessed2 = 1;

			guessed = false;

		}
		else if (hmGuessed2 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 3)
	{

		if (hmGuessed3 == 0)
		{

			hmGuessed3 = 1;

			guessed = false;

		}
		else if (hmGuessed3 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 4)
	{

		if (hmGuessed4 == 0)
		{

			hmGuessed4 = 1;

			guessed = false;

		}
		else if (hmGuessed4 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 5)
	{

		if (hmGuessed5 == 0)
		{

			hmGuessed5 = 1;

			guessed = false;

		}
		else if (hmGuessed5 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 6)
	{

		if (hmGuessed6 == 0)
		{

			hmGuessed6 = 1;

			guessed = false;

		}
		else if (hmGuessed6 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 7)
	{

		if (hmGuessed7 == 0)
		{

			hmGuessed7 = 1;

			guessed = false;

		}
		else if (hmGuessed7 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 8)
	{

		if (hmGuessed8 == 0)
		{

			hmGuessed8 = 1;

			guessed = false;

		}
		else if (hmGuessed8 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 9)
	{

		if (hmGuessed9 == 0)
		{

			hmGuessed9 = 1;

			guessed = false;

		}
		else if (hmGuessed9 == 1)
		{

			guessed = true;

		}

	}
	else if (wantedNum == 10)
	{

		if (hmGuessed10 == 0)
		{

			hmGuessed10 = 1;

			guessed = false;

		}
		else if (hmGuessed10 == 1)
		{

			guessed = true;

		}

	}

	return guessed;

}

//Checks to see if the letter has already been guessed the new way
bool wasGuessed(char guessed)
{

	guessed = false;

	//Goes through each letter in the vector and compares it to the current guess. If it's not duplicated then it's successful
	for (int q = 0; q < lettersGuessed.size(); q++)
	{

		if (guessed == lettersGuessed[q])
		{

			guessed = true;

		}


	}

	return guessed;

}

//Quits the game
void quit() {

	//Displays a message. Since it does not recall Game Picker, the page will close
	cout << "Goodbye " << playerName << endl;

}