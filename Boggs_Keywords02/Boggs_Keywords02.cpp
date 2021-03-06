// Boggs_Keywords02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // include the standard library
#include <iostream> // include the input - output stream
#include <vector> // include the defintion for vector containers
#include <string> //include the use of strings
#include <algorithm> // include definitions of the algorithms to use with containers
#include <ctime> // include the time of the console for randomization
#include <cctype> //a section of the standard library to convert characters into uppercase

using namespace std; // use the standard library namespace (no abrev. necessary)


int main() // main function
{
	// Display Title of program to user
	cout << "Welcome to Code Breaker 2, Special Agent!\n\n";

	// Ask the recruit to login using thier name
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string username; // an empty string variable for the username
	cout << "Please enter your username.\n";
	cout << "Username: ";
	cin >> username; // assign the user's input to the string variable 'username'
	cout << "\n\nWelcome, " << username; // welcome the player personally

	// Display an overview of what Keywords II is to the recruit 
	cout << "\nIn this training simulation, you will be identifying enemy keywords\n";
	cout << "through the process of elimination. Use your best strategies to discern what the \n";
	cout << "keyword is.\n";
	cout << "You must solve 3 code words in each simulation.\n\n";
		
	// Display directions to the recruit on how to use Keywords
	cout << "Enter the letters of the keyword one letter at a time.\n";
	cout << "If you are correct, the keyword will be updated with your guessed letter.\n";
	cout << "But be careful! Making too many incorrect guesses will result in mission failure.\n";
	cout << "Code Breaker 2 will keep track of your guesses and stats.";
	cout << "\n\nDo not fail this mission.";
	cout << "\n\nGood luck, Special Agent " << username << "!";
	
	// Create a collection of 10 words you had wrote down manually
	vector<string> words; //a vector containter called 'words', holding string objects, which are the possible words to use in the simulation
	words.push_back("ADLER"); //add word to end of vector container
	words.push_back("HIRSCH"); //add word to end of vector container
	words.push_back("FRIEDE"); //add word to end of vector container
	words.push_back("MAUS"); //add word to end of vector container
	words.push_back("GESUNDHEIT"); //add word to end of vector container
	words.push_back("STURM"); //add word to end of vector container
	words.push_back("WEIHNACHTSMANN"); //add word to end of vector container
	words.push_back("GESCHENK"); //add word to end of vector container
	words.push_back("GIFT"); //add word to end of vector container
	words.push_back("FERNWEH"); //add word to end of vector container

	// Create an int var to count the number of simulations being run starting at 1
	int simNumber;
	simNumber = 1;
	char playAgainChar; //create an empty character variable to repeat the simulation with input
	bool playAgainBool; // a boolean for playAgain to control when it returns to the top

	//START DO/WHILE
	do
	{ 

	// Display the simulation # is staring to the recruit. 
	if ((simNumber == 1) || (simNumber == 21) || (simNumber == 31) || (simNumber == 41)) // if the simulation number ends in 1, use 'st'
	{
		cout << "\n\nThis is your " << simNumber << "st simulation.";
	}

	else if ((simNumber == 2) || (simNumber == 22) || (simNumber == 32) || (simNumber == 42)) // if the simulation number ends in 2, use 'nd'
	{
		cout << "\n\nThis is your " << simNumber << "nd simulation.";
	}

	else if ((simNumber == 3) || (simNumber == 23) || (simNumber == 33) || (simNumber == 43)) // if the simulation number ends in 3, use 'rd'
	{
		cout << "\n\nThis is your " << simNumber << "rd simulation.";
	}

	else if (simNumber > 3) // if the simulation number ends in any number not listed above, use 'th' 
	{
		cout << "\n\nThis is your " << simNumber << "th simulation.";
	}

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	srand(static_cast<unsigned int>(time(0))); // seed the randomizer
	random_shuffle(words.begin(), words.end()); //randomly shuffle the vector 'words' for all positions in the vector

	const string THE_FIRST = words[0]; //pick the first position of randomly shuffled vector and assign it to the string for the first word
	const string THE_SECOND = words[1]; //pick the second position of randomly shuffled vector and assign it to the string for the second word
	const string THE_THIRD = words[2]; //pick the third position of randomly shuffled vector and assign it to the string for the third word
	int wrong = 0; // number of incorrect guesses
	string soFarFirst(THE_FIRST.size(), '-'); //first word guessed so far (create a string the size of the word, but with dashes instead of letters)
	string soFarSecond(THE_SECOND.size(), '-'); // second word guessed so far (create a string the size of the word, but with dashes instead of letters)
	string soFarThird(THE_THIRD.size(), '-'); //third word guessed so far (create a string the size of the word, but with dashes instead of letters)

	const string THE_WORD = THE_FIRST + " " + THE_SECOND + " " + THE_THIRD; // a string to easily search all 3 code words. I will auto fill the spaces for the player
	string soFar = soFarFirst + " " + soFarSecond + " " + soFarThird; //a string to more easily display the three code word phrase

	const int MAX_WRONG = 8; //the player is allowed 8 incorrect guesses
	string used = ""; // letters already guessed (an empty string to hold these letters)

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		//     Tell recruit how many incorrect guesses he or she has left
		cout << "You have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";

		//     Show recruit the letters he or she has guessed
		cout << "\nYou've used the following letters:\n" << used << endl;

		//     Show player how much of the secret word he or she has guessed
		cout << "\nSo far, the 3 word code phrase is:\n" << soFar << endl;

		//     Get recruit's next guess
		char guess; //char variable to hold the player's guess
		cout << "\n\nEnter your guess: "; // tell the player to enter a guess
		cin >> guess; // assign player's input to the char variable 'guess'
		guess = toupper(guess); //make uppercase since secret word is in uppercase

		//     While recruit has entered a letter that he or she has already guessed
		while (used.find(guess) != string::npos) //if the guess is found in the string variable 'used', tell the player to pick another guess
		{
			//          Get recruit ’s guess
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: "; // tell them to guess again
			cin >> guess; // get the new guess
			guess = toupper(guess); //make the new guess uppercase and check again
		}
		
		//     Add the new guess to the group of used letters
		used += guess; //add the guess to the string of letters the player has already used

		//     If the guess is in the secret word
		if (THE_WORD.find(guess) != string::npos) //if the guess is in the word
		{
			//          Tell the recruit the guess is correct
			cout << "That's right! " << guess << " is in the word.\n";
			//          Update the word guessed so far with the new letter
			for (unsigned int i = 0; i < THE_WORD.length(); ++i) //for each letter of the word
			{
				if (THE_WORD[i] == guess) //if the letter of the word is the same as their guess
				{
					soFar[i] = guess; //set the position in soFar equal to the guess
				}
			}
		}		
		//     Otherwise
		else // the guess is not in the word
		{
			//          Tell the recruit the guess is incorrect
			cout << "Sorry, " << guess << " isn't in the word.\n"; //tell the player the guess is wrong
			
			//          Increment the number of incorrect guesses the recruit has made
			++wrong; //increment wrong guesses by 1
		}
	}



	// If the recruit has made too many incorrect guesses
	if (wrong == MAX_WRONG) // if the total wrong is the same as the maximum wrong
	{
		//     Tell the recruit that he or she has failed the Keywords II course.
		cout << "\nYou have failed the mission, Special Agent" << username << "!";
		cout << "\nYou have been demoted.";
	}

	// Otherwise
	else // the player has guessed the word
	{
		//     Congratulate the recruit on guessing the secret words
		cout << "\nCongratulations, Special Agent " << username << "!";
		cout << "\nThe secret 3 word code phrase was: " << THE_WORD << endl;
		cout << "\nYou have successfully completed this training simulation.";
	}

	// Ask the recruit if they would like to run the simulation again
	cout << "\n\nWould you like to repeat the simulation with a new 3 word code phrase?"; 
	cout << "\nPlease type y or n: ";
	cin >> playAgainChar;

	// If the recruit wants to run the simulation again
	if (playAgainChar == 'y')
	{
		//     Increment the number of simiulations ran counter
		simNumber += 1;
		//     Move program execution back up to // Display the simulation # is staring to the recruit. 
		playAgainBool = true;

	}
	// Otherwise 
	else
	{
		//     Display End of Simulations to the recruit
		cout << "\n\nYou have completed " << simNumber << " training simulations.";
		cout << "\nGood work, Special Agent " << username << "!";
		playAgainBool = false;
	}

	//END DO/WHLE LOOP
	}while (playAgainBool == true);

	//     Pause the Simulation with press any key to continue
	system("pause"); // pause the console to remain on the screen
    return 0; // return to the OS
}

