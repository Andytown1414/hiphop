/*
* File:   ???.cpp 
* Author: Andrew Freeman
* Created on 17 March 2018, 9:29 AM
* test test
*/


#include "stdafx.h"
#include "Dictionary.h"

using namespace std;


int main(int argc, char** argv) {

	Dictionary theDictionary; // declaration in this manner gives the object automatic storage duration, so it will be destroyed when it gfoes out of scope.
								// not exactly sure what consititutes out of scope tho. may need to do Dictionary* theDictionary = new Dictionary(). need to figure
								// out difference between the first and the second is apparently a pointer to the obj. the second way wont be destroyed by out of scope.
	theDictionary.loadDictionary("Dictionary.txt");

	cout << endl;
	cout << "Please choose an option from the following menu, by entering the corresponding task number (1, 2 or 3)" << endl;
	cout << endl;
	cout << "Task 1 - Search the dictionary for a word, and print the definition if found" <<  endl;
	cout << "Task 2 - Find the longest word in the dictionary" << endl;
	cout << "Task 3 - Find the word(s) which end in 'logy' and contain seven letters or less" << endl;
	cout << endl;

	//wait for user input. 
	int userChoice;
	cin >> userChoice; // need to add error checking for user input. i wonder if switch statement has an "else" feature, 
	// then if you could set userChoice as a variant, you can take in anything, and if it doesnt match the case, then print error bro try again

	switch (userChoice) {

	case 1 :
		theDictionary.task1();
		break;
	case 2:
		theDictionary.task2();
		break;
	case 3:
		theDictionary.task3();
		break;


	}


	// maybe prompt user if they would like to restart or close?
	
	return 0;
}

