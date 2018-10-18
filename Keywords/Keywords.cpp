//Name: Keywords
//Author: Isaac Richards.
//Date: 18OCT18.

//Header.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); //Uses the current date and time as a seed for rand().
	enum constants { KEYWORD, HINT, NUM_FIELDS_CONSTANTS };
	const string KEYWORDS[][NUM_FIELDS_CONSTANTS] =
	{
		{ "ostrich", "Hint: Become one with the sand.;asldkdhf;slkfas;ldkhg;lshg;sda;sdhg;lhsag;dshg;ahg;dshg;dshg;ldsgg;ahg;lahg;lsajhg;ajkhg;ajkshdg;jlkashdg;jahsdg;kjhsg;jkhasd;kjgh;ajksdhg;jkshdg;jkhsad;glkjhsa;lkjdhg;lkjsha;glkjhsa;kdljhg;sajlkhdg;jksahg;lkhsad;lgkhsd;lkgh;dslahg;lkashdg;lakjshdgggggggggjjjjjjksssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss" },
		{ "ember", "Hint: Just a wee flame.  Nothing to fear." },
		{ "odor", "Hint: You can pass through, but you cannot open." },
		{ "opt", "Hint: Choose carefully now." },
		{ "elastic", "Hint: Always falls back into its old habbits." },
		{ "alive", "Hint: What more could you ask for?" },
		{ "torment", "Hint: Dont   yourself over this." },
		{ "friction", "Hint: Try putting your hands together for some inspiration." },
		{ "fester", "Hint: You better solve this one before it gets worse." },
		{ "supercalifragilisticexpialidocious", "Hint: The sound of it is something quite atrocious.umfkllsa;lkjs;dfja;slidjg;laijg;oihsad;oiggha;oijg;oaisg;osaidhhg;oaishg;osiadhg;oisahdg;oiashg;oihsasdg;ioh" },
		{ "hint",  },
		{ "skip", "You might want to skip this one..." },
		{ "help", "You are helpless." }
	};
	
	cout << "initializing Keywords...";

	bool repeatProgram = false;
	/*
	=================================================================================================================================================
	|																																				|
	|	Program loop																																|
	|																																				|
	=================================================================================================================================================
	*/
	//Repeats the entire program if desired by the user.
	do //(repeatProgram)
	{
		cout << "===============================================================\n";
		int randomKeywordNumber = rand() % (sizeof KEYWORDS / sizeof KEYWORDS[0]); //Choose a random keyword number.
		string randomKeyword = KEYWORDS[randomKeywordNumber][KEYWORD];
		string temporaryKeyword = randomKeyword;
		string scrambledKeyword = "";
		for (int i = 0; temporaryKeyword.length(); i++)
		{
			int randomLetter = rand() % temporaryKeyword.length();
			scrambledKeyword += temporaryKeyword[randomLetter];
			temporaryKeyword.erase(randomLetter, 1);
		}
		for (int wordsRemaining = 2; wordsRemaining; wordsRemaining--)
		{
			cout << "Scrambled word #" << 3 - wordsRemaining << ": " << scrambledKeyword << "\n"
				 << "You may enter \"hint\" to recieve a hint, \"skip\" to recieve a new scrambled word, or \"help\" to re-display the scrambled word and this message.\n";

			bool correct = false;

			do
			{
				cout << "Enter the keyword: ";
				string guess;
				cin >> guess;
				if (guess == randomKeyword)
				{
					correct = true;
				}
				else if (guess == "hint")
				{
					cout << KEYWORDS[randomKeywordNumber][HINT] << "\n";
				}
				else if (guess == "help")
				{
					cout << "Scrambled word #" << 3 - wordsRemaining << ": " << scrambledKeyword << "\n"
						 << "You may enter \"hint\" to recieve a hint or \"skip\" to recieve a new scrambled word.";
				}
				else if (guess == "skip")
				{
					int randomKeywordNumber = rand() % (sizeof KEYWORDS / sizeof KEYWORDS[0]); //Choose a random keyword number.
					string randomKeyword = KEYWORDS[randomKeywordNumber][KEYWORD];
					string temporaryKeyword = randomKeyword;
					string scrambledKeyword = "";
					for (int i = 0; temporaryKeyword.length(); i++)
					{
						int randomLetter = rand() % temporaryKeyword.length();
						scrambledKeyword += temporaryKeyword[randomLetter];
						temporaryKeyword.erase(randomLetter, 1);
					}
					cout << "New scrambled word #" << 3 - wordsRemaining << ": " << scrambledKeyword << "\n";
				}
				else
				{
					cout << "Incorrect.\n";
				}
			} while (!correct);
		}

		/*
		=================================================================================================================================================
		|	 loop																												|
		=================================================================================================================================================
		*/

		cout << "===============================================================\n";
		bool waitingForValidInput = true; //Used to determine if the waitingForValidInput loop needs to repeat.

		/*
		=================================================================================================================================================
		|	waitingForValidInput loop																													|
		=================================================================================================================================================
		*/
		while (waitingForValidInput) //Repeat until a valid input is entered.
		{
			cout << "Would you like to try again? (type yes or no)\n";
			string userAnswer; //Stores the user's answer to the above question.
			cin >> userAnswer; //Obtain input from the user.
			if (userAnswer == "yes" || userAnswer == "Yes" || userAnswer == "YES") //If yes is entered, repeat the Program loop.
			{
				repeatProgram = true;
				waitingForValidInput = false;
			}
			else if (userAnswer == "no" || userAnswer == "No" || userAnswer == "NO") //If no is entered, end the Program loop and exit the program.
			{
				repeatProgram = false;
				waitingForValidInput = false;
			}
			else //If anything other than yes or no is entered, repeat the waitingForValidInput loop.
			{
				cout << "\nInvalid input.\n\n";
			}
		}
		/*
		=================================================================================================================================================
		|	End of waitingForValidInput loop																											|
		=================================================================================================================================================
		*/
	} while (repeatProgram);
	/*
	=================================================================================================================================================
	|																																				|
	|	End of Program loop																															|
	|																																				|
	=================================================================================================================================================
	*/
}