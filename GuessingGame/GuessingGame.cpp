// GuessingGame.cpp : main project file.

#include "stdafx.h"
//#include "stdlib.h"
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
using namespace System;

int prevCategory;
int prevDiff;

void playHotCold(int n, int g);
void playHighLow(int n, int g);

int main()
{
	int choice;
	srand((unsigned)time(0));
	
	cout << "Welcome to the number guessing game!" << endl;
	cout << "\nHow would you like to play? (1=Hot/Cold, 2=High/Low, 0=Quit): ";
	cin >> choice;

	while (choice == 1 || choice == 2) {
		prevCategory = 0;
		prevDiff = 0;
		int number = (rand() % 100) + 1;
		int numGuesses = 0;
		bool keepGoing = true;
		cout << "I am thinking of a number between 1 and 100..." << endl;
		while (keepGoing) {
			int guess;
			numGuesses++;
			while (true) {
				cout << "\nYour Guess? (0=Quit): ";
				if (cin >> guess) {
					break;
				} else {
					cout << "\nEnter a valid number.";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			if (guess == 0) {
				keepGoing = false;
				cout << "The correct answer is: " << number << ". You tried " << --numGuesses << " times. See you next time." << endl;
			} else if (guess == number) {
				keepGoing = false;
				cout << "Correct! You guessed my number of " << number << " in " << numGuesses << " tries." << endl;
			}
			else {
				if (choice == 1) {
					playHotCold(number, guess);
				}
				else {
					playHighLow(number, guess);
				}
			}
		}
		cout << "\nHow would you like to play? (1=Hot/Cold, 2=High/Low, 0=Quit): ";
		cin >> choice;
	}
	
	cout << "Thanks for playing!" << endl;
	system("pause");
    return 0;
}

void playHotCold(int answer, int guess) {
	int category = 0;
	int difference = abs(answer - guess);

	if (difference > 74) {
		category = 1;
		cout << "very cold";
	}
	else if (difference > 49) {
		category = 2;
		cout << "cold";
	}
	else if (difference > 24) {
		category = 3;
		cout << "warm";
	}
	else if (difference > 10) {
		category = 4;
		cout << "very warm";
	}
	else {
		category = 5;
		cout << "hot";
	}

	if (category == prevCategory) {
		if (difference < prevDiff) {
			cout << " - getting hotter";
		}
		else if (difference > prevDiff) {
			cout << " - getting colder";
		}
		else {
			cout << " - same degree";
		}
	}
	cout << endl;
	prevCategory = category;
	prevDiff = difference;
}

void playHighLow(int answer, int guess) {
	if (guess < answer) {
		cout << "Sorry, your guess is too low";
	}
	else {
		cout << "Sorry, your guess is too high";
	}
}
