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
	enum constants { KEYWORD, HINT, NUM_FIELDS_CONSTANTS };
	const string KEYWORDS[][NUM_FIELDS_CONSTANTS] =
	{
		{ "ostrich", "Hint: Become one with the sand." },
		{ "ember", "Hint: Just a wee flame.  Nothing to fear." },
		{ "odor", "Hint: You can pass through, but you cannot open." },
		{ "opt", "Hint: Choose carefully now." },
		{ "elastic", "Hint: Always falls back into its old habbits." },
		{ "alive", "Hint: What more could you ask for?" },
		{ "torment", "Hint: Dont   yourself over this." },
		{ "friction", "Hint: Try putting your hands together for some inspiration." },
		{ "fester", "Hint: You better solve this one before it gets worse." },
		{ "supercalifragilisticexpialidocious", "Hint: The sound of it is something quite atrocious." },
		{ "hint",  },
		{ "skip", "You might want to skip this one..." },
		{ "help", "You are helpless." }
	};
	
	cout << "initializing Keywords...\n";

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
		cout << "You may enter \"hint\" to recieve a hint, \"skip\" to recieve a new scrambled word, or \"help\" to re-display the scrambled word and this message.\n";
		const int WORDS_TO_GUESS = 3;
		for (int wordsRemaining = WORDS_TO_GUESS; wordsRemaining; wordsRemaining--)
		{
			srand(static_cast<unsigned int>(time(0))); //Uses the current date and time as a seed for rand().
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
			cout << "Scrambled word #" << WORDS_TO_GUESS + 1 - wordsRemaining << ": " << scrambledKeyword << "\n";

			bool correct = false;

			do
			{
				cout << "Enter the keyword: ";
				string guess;
				cin >> guess;
				if (guess == randomKeyword)
				{
					correct = true;
					cout << "Correct!\n"
						 << "-\n";
				}
				else if (guess == "hint")
				{
					cout << "-\n"
						 << KEYWORDS[randomKeywordNumber][HINT] << "\n";
				}
				else if (guess == "help")
				{
					cout << "-\n"
						 << "You may enter \"hint\" to recieve a hint, \"skip\" to recieve a new scrambled word, or \"help\" to re-display the scrambled word and this message.\n"
						 << "Scrambled word #" << WORDS_TO_GUESS + 1 - wordsRemaining << ": " << scrambledKeyword << "\n";
						 
				}
				else if (guess == "skip")
				{
					srand(static_cast<unsigned int>(time(0))); //Uses the current date and time as a seed for rand().
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
					cout << "-\n"
						 << "New scrambled word #" << WORDS_TO_GUESS + 1 - wordsRemaining << ": " << scrambledKeyword << "\n";
				}
				else
				{
					cout << "Incorrect.\n"
						 << "-\n";
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



//Prevent the same keyword being used if it has been guessed correctly.   resets every program run.  Erase that keyword when correct.  re-initialize the whole list of keywords each time the program runs.