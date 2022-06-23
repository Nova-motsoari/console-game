#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

void PrintIntro(int LevelDifficult)
{
	cout << "You are a secret agent breaking into a Level "<<LevelDifficult<<" secure server room...";
		cout<<"\n you come across a keypad that requires a password..." << endl;

}

bool PlayGame(int LevelDifficult)
{
	
	PrintIntro(LevelDifficult);

	const int CodeA = rand() % LevelDifficult + LevelDifficult;
	const int CodeB = rand() % LevelDifficult + LevelDifficult;
	const int CodeC = rand() % LevelDifficult + LevelDifficult;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProd = CodeA * CodeB * CodeC;

	cout << "\n\n the 3 numbers add up to: " << CodeSum;
	cout << "\nThe 3 numbers product is: " << CodeProd;

	int PlayerGuessA = 0, PlayerGuessB = 0, PlayerGuessC = 0;
	int GuessSum, GuessProd;

	

	cout << "\nEnter the correct password to continue...: ";
	cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;
	
	GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
	GuessProd = PlayerGuessA * PlayerGuessB * PlayerGuessC;

	if (GuessSum == CodeSum && GuessProd == CodeProd)
	{
		cout << "The code ha been cracked!!!\n" << endl;
		return true;
	}
	else
	{
		cout << "The code was incorrect...\n" << endl;
		return false;
	}
}

int main()
{
	int LevelDifficulty = 1;
	const int MaxDifficulty=5;
	srand(time(NULL));

	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete= PlayGame(LevelDifficulty);

		PlayGame(LevelDifficulty);
		cin.ignore();
		cin.clear();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	};

	_getch();
	return 0;
}

