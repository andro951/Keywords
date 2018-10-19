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
	/*
	----Program loop setup--------------------------------------------------------------------------------------------------------------------------|
	*/
	cout << "initializing Keywords...\n";
	srand(static_cast<unsigned int>(time(0))); //Use the current date and time as a seed for rand().

	bool repeatProgram = false; //Repeat condition for the Program loop.

	/*
	=================================================================================================================================================
	|																																				|
	|	Program loop																																|
	|																																				|
	=================================================================================================================================================
	*/
	do //Repeat the entire program if desired by the user.
	{
		/*
		----Body loop setup-----------------------------------------------------------------------------------------------------------------------------|
		*/
		enum constants { KEYWORD, HINT, NUM_FIELDS_CONSTANTS }; //Assign these words to constant values for readability of the code.
		string KEYWORDS[][NUM_FIELDS_CONSTANTS] = //Create the keywords and hints that will be guessed by the user.
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
			{ "hint", "" },
			{ "skip", "You might want to skip this one..." },
			{ "help", "You are helpless." }
		};
		string dontUseKeywordAgain[sizeof KEYWORDS / sizeof KEYWORDS[0]]; //Track keywords that have been answered correctly or been skipped to prevent re-use.

		cout << "===============================================================\n";
		cout << "You may enter \"hint\" to recieve a hint, \"skip\" to recieve a new scrambled word, or \"help\" to re-display the scrambled word and this message.\n";

		const int KEYWORDS_TO_GUESS = 3; //Number of times the user will have to guess a word correctly before the Body loop ends.

		/*
		=================================================================================================================================================
		|	Body loop																																	|
		=================================================================================================================================================
		*/
		for (int keywordsRemaining = KEYWORDS_TO_GUESS; keywordsRemaining; keywordsRemaining--) //Scramble a keyword and ask the user to guess until they guess the keyword correctly.
		{
			/*
			----Make scrambled keyword loop setup-----------------------------------------------------------------------------------------------------------|
			*/
			int randomKeywordNumber;
			string randomKeyword;
			string scrambledKeyword;

			/*
			=================================================================================================================================================
			|	Make scrambled keyword loop																													|
			=================================================================================================================================================
			*/
			do
			{
				/*
				----Scramble loop setup-------------------------------------------------------------------------------------------------------------------------|
				*/
				randomKeywordNumber = rand() % (sizeof KEYWORDS / sizeof KEYWORDS[0]); //Choose a random keyword number from KEYWORDS.
				randomKeyword = KEYWORDS[randomKeywordNumber][KEYWORD]; //Get the keyword correspoding to the randomly chosen number.
				string temporaryKeyword = randomKeyword; //Used to track which letters still need to be added to scrambledKeyword.
				scrambledKeyword = ""; //Holds the scrambled keyword.

				/*
				=================================================================================================================================================
				|	Scramble loop																																|
				=================================================================================================================================================
				*/
				for (int i = 0; temporaryKeyword.length(); i++) //Scramble the keyword by adding one random character from temporaryKeyword to scrambledKeyword then erases the character from temporaryKeyword.
				{
					int randomLetter = rand() % temporaryKeyword.length(); //Choose a random letter from temporaryKeyword to be added to scrambledKeyword.
					scrambledKeyword += temporaryKeyword[randomLetter]; //Add the randomly chosen character to scrambledKeyword.
					temporaryKeyword.erase(randomLetter, 1); //Erase one instance of the randomly chosen character from temporary keyword.
				}
				/*
				=================================================================================================================================================
				|	End of Scramble loop																														|
				=================================================================================================================================================
				*/
			} while (randomKeyword == scrambledKeyword or dontUseKeywordAgain[randomKeywordNumber] == "true"); //Create a new scrambledKeyword if it is not scrambled or was already guessed correctly or skipped.
			/*
			=================================================================================================================================================
			|	End of Make scrambled keyword loop																											|
			=================================================================================================================================================
			*/

			cout << "Scrambled word #" << KEYWORDS_TO_GUESS + 1 - keywordsRemaining << ": " << scrambledKeyword << "\n";

			/*
			----Guessing loop setup-------------------------------------------------------------------------------------------------------------------------|
			*/
			bool correct = false; //Repeat condition for the Guessing loop.

			/*
			=================================================================================================================================================
			|	Guessing loop																																|
			=================================================================================================================================================
			*/
			do //Repeats until the user guesses the keyword correctly.
			{
				cout << "Enter the keyword: ";
				string guess;
				cin >> guess;
				if (guess == randomKeyword) //User is correct.
				{
					correct = true; //Stop repeating the loop.
					dontUseKeywordAgain[randomKeywordNumber] = "true"; //Force the program to create a new scrambledKeyword if it chooses a word that was already quessed correctly.
					cout << "Correct!\n"
						 << "-\n";
				}
				else if (guess == "hint") //Display the hint for the keyword.
				{
					cout << "-\n"
						 << KEYWORDS[randomKeywordNumber][HINT] << "\n";
				}
				else if (guess == "help") //Redisplay the orrigional message.
				{
					cout << "-\n"
						 << "You may enter \"hint\" to recieve a hint, \"skip\" to recieve a new scrambled word, or \"help\" to re-display the scrambled word and this message.\n"
						 << "Scrambled word #" << KEYWORDS_TO_GUESS + 1 - keywordsRemaining << ": " << scrambledKeyword << "\n";
						 
				}
				else if (guess == "skip") //Create a new scrambledKeyword and prevent the skipped keyword from being used again.
				{
					dontUseKeywordAgain[randomKeywordNumber] = "true"; //Force the program to create a new scrambledKeyword if it chooses a word that was already quessed correctly.

					/*
					=================================================================================================================================================
					|	Make scrambled keyword loop																													|
					=================================================================================================================================================
					*/
					do
					{
						/*
						----Scramble loop setup-------------------------------------------------------------------------------------------------------------------------|
						*/
						randomKeywordNumber = rand() % (sizeof KEYWORDS / sizeof KEYWORDS[0]); //Choose a random keyword number from KEYWORDS.
						randomKeyword = KEYWORDS[randomKeywordNumber][KEYWORD]; //Get the keyword correspoding to the randomly chosen number.
						string temporaryKeyword = randomKeyword; //Used to track which letters still need to be added to scrambledKeyword.
						scrambledKeyword = ""; //Holds the scrambled keyword.

						/*
						=================================================================================================================================================
						|	Scramble loop																																|
						=================================================================================================================================================
						*/
						for (int i = 0; temporaryKeyword.length(); i++) //Scramble the keyword by adding one random character from temporaryKeyword to scrambledKeyword then erases the character from temporaryKeyword.
						{
							int randomLetter = rand() % temporaryKeyword.length(); //Choose a random letter from temporaryKeyword to be added to scrambledKeyword.
							scrambledKeyword += temporaryKeyword[randomLetter]; //Add the randomly chosen character to scrambledKeyword.
							temporaryKeyword.erase(randomLetter, 1); //Erase one instance of the randomly chosen character from temporary keyword.
						}
						/*
						=================================================================================================================================================
						|	End of Scramble loop																														|
						=================================================================================================================================================
						*/
					} while (randomKeyword == scrambledKeyword or dontUseKeywordAgain[randomKeywordNumber] == "true"); //Create a new scrambledKeyword if it is not scrambled or was already guessed correctly or skipped.
					/*
					=================================================================================================================================================
					|	End of Make scrambled keyword loop																											|
					=================================================================================================================================================
					*/
					
					cout << "-\n"
						 << "New scrambled word #" << KEYWORDS_TO_GUESS + 1 - keywordsRemaining << ": " << scrambledKeyword << "\n";
				}
				else //Any other input is incorrect.  Reapeat the loop.
				{
					cout << "Incorrect.\n"
						 << "-\n";
				}
			} while (!correct);
			/*
			=================================================================================================================================================
			|	End of Guessing loop																														|
			=================================================================================================================================================
			*/
		}

		/*
		=================================================================================================================================================
		|	Body loop																																	|
		=================================================================================================================================================
		*/

		cout << "===============================================================\n";
		bool waitingForValidInput = true; //Used to determine if the waitingForValidInput loop needs to repeat.

		/*
		=================================================================================================================================================
		|	Ask to repeat program loop																													|
		=================================================================================================================================================
		*/
		while (waitingForValidInput) //Repeats until a valid input is entered.
		{
			cout << "Would you like to try again? (type yes or no)\n";
			string userAnswer; //Stores the user's answer to the above question.
			cin >> userAnswer;
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
		|	End of Ask to repeat program loop																											|
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