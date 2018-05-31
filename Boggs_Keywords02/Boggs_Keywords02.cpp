// Boggs_Keywords02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	// Display Title of program to user
	cout << "Welcome to Code Breaker 2, Special Agent!\n\n";

	// Ask the recruit to login using thier name
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string username; // an empty string variable for the username
	cout << "Please enter your username.\n";
	cout << "Username: ";
	cin >> username;
	cout << "\n\nWelcome, " << username;

	// Display an overview of what Keywords II is to the recruit 
	cout << "\nIn this training simulation, you will be identifying enemy keywords\n";
	cout << "through the process of elimination. Use your best strategies to discern what the \n";
	cout << "keyword is.\n\n";
		
	// Display an directions to the recruit on how to use Keywords
	cout << "Enter the letters of the keyword one letter at a time.\n";
	cout << "If you are correct, the keyword will be updated with your guessed letter.\n";
	cout << "But be careful! Making too many incorrect guesses will result in mission failure.\n";
	cout << "Code Breaker 2 will keep track fo your guesses and stats.";
	cout << "\n\nDo not fail this mission.";
	cout << "\n\nGood luck, Special Agent " << username << "!";
	
	// Create a collection of 10 words you had wrote down manually

		//Adler, Hirsch, Friede, Maus, Gesundheit, 
		//Sturm, Weihnachtsmann, Geschenk, Gift, Fernweh
	
	// Create an int var to count the number of simulations being run starting at 1
	int simNumber;
	simNumber = 21;

	// Display the simulation # is staring to the recruit. 
	if ((simNumber == 1) || (simNumber == 21) || (simNumber == 31) || (simNumber == 41)) // if the simulation number ends in 1, use 'st'
	{
		cout << "\n\nThis is your " << simNumber << "st simulation.";
	}

	else if ((simNumber == 2) || (simNumber == 22) || (simNumber == 32) || (simNumber == 42)) // if the simulation number ends in 2, use 'nd'
	{
		cout << "This is your " << simNumber << "nd simulation.";
	}

	else if ((simNumber == 3) || (simNumber == 23) || (simNumber == 33) || (simNumber == 43)) // if the simulation number ends in 3, use 'rd'
	{
		cout << "This is your " << simNumber << "rd simulation.";
	}

	else if (simNumber > 3) // if the simulation number ends in any number not listed above, use 'th'
	{
		cout << "This is your " << simNumber << "th simulation.";
	}

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 



	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

	//     Tell recruit how many incorrect guesses he or she has left

	//     Show recruit the letters he or she has guessed

	//     Show player how much of the secret word he or she has guessed

	//     Get recruit's next guess

	//     While recruit has entered a letter that he or she has already guessed

	//          Get recruit ’s guess

	//     Add the new guess to the group of used letters

	//     If the guess is in the secret word

	//          Tell the recruit the guess is correct

	//          Update the word guessed so far with the new letter

	//     Otherwise

	//          Tell the recruit the guess is incorrect

	//          Increment the number of incorrect guesses the recruit has made

	// If the recruit has made too many incorrect guesses

	//     Tell the recruit that he or she has failed the Keywords II course.

	// Otherwise

	//     Congratulate the recruit on guessing the secret words

	// Ask the recruit if they would like to run the simulation again

	// If the recruit wants to run the simulation again

	//     Increment the number of simiulations ran counter

	//     Move program execution back up to // Display the simulation # is staring to the recruit. 

	// Otherwise 

	//     Display End of Simulations to the recruit

	//     Pause the Simulation with press any key to continue

	system("pause"); // pause the console to remain on the screen
    return 0; // return to the OS
}

