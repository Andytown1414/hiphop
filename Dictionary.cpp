/* 
 * File:   Dictionary.cpp
 * Author: andre
 * 
 * Created on 17 March 2018, 9:54 AM
 */


#include "stdafx.h"
#include "Dictionary.h"
#include "Worde.h"


Dictionary::Dictionary() {

}

void Dictionary::loadDictionary(string filePath) {

	string word, definition, tempo;
	Worde::typeo typeA; // only string for now.
	string lineOfText; // should be able to get rid of  this after fixing the getline double for no reason problem

	cout << "Loading Dictionary from source:  " << filePath << " ..." << endl;

	ifstream theStream(filePath);
	if (!theStream.is_open()) exit(EXIT_FAILURE);


	while (theStream >> word >> tempo)
	{
            typeA = this->convert(tempo);
           
            
		getline(theStream, lineOfText); // this needs to replaced with something to get pointer to next line, instead of writing to unused string
		getline(theStream, definition);

		Worde wordObject(word, definition, typeA); // will have to updated to take type also
		DictionaryWords.push_back(wordObject);
	}

	cout << "Dictionary Loaded" << endl;
}

//Dictionary::Dictionary(const Dictionary& orig) {
//}

Dictionary::~Dictionary() {
}

int Dictionary::getSize() const {
	return DictionaryWords.size();
}


Worde::typeo Dictionary::convert(string str){
    if(str == "[misc]") return Worde::misc;
    else if(str == "[n]") return Worde::n;
    else if(str == "[adj]") return Worde::adj;
    else if(str == "[v]") return Worde::v;
}

vector<string> Dictionary::getWordDetails(int index) {
	vector<string> details(2);
	details[0] = this->DictionaryWords[index].getWord();
	details[1] = this->DictionaryWords[index].getDefinition();
	return details;

}

void Dictionary::task1() {
	// prompt user to enter a word
	string searchWord;
	cout << "Please enter the word you would like to search for (lowercase only)" << endl; //check input is valid, so check that its a string and if not then output error message
	cin >> searchWord;
	// search dictionary for word, set found to true if it is found, then exit loop
	int i;
	bool found = false;
	for (i = 0; i < DictionaryWords.size(); i++) {
		if (DictionaryWords[i].getWord() == searchWord) {
			found = true;
			break;
		}
	}

	if (found) {
		DictionaryWords[i].printDefinition();
	}
	else{
		cout << "word not found" << endl;
	}
	// if found call that words printDefinition method
	// if not found, print out "word not found"
}

void Dictionary::task2() {
	int i, currentIndex;
	int currentLongest = 0;
	for (i = 0; i < DictionaryWords.size(); i++) {
		if (DictionaryWords[i].getWord().length() > currentLongest) { // hmmm what about if two words have the greatest length? use greater than or equal to and then..? also, should you count the hyphen?
			currentLongest = DictionaryWords[i].getWord().length();
			currentIndex = i;
		}
	}
	cout << endl;
	cout << "The longest word in this Dictionary is: " << DictionaryWords[currentIndex].getWord() << ", which has " << currentLongest << " characters, although change to deal with hyphen? maybe read requirements see if mentioned." << endl;
}

void Dictionary::task3() {

	vector<string> matches;
	for (Worde i : DictionaryWords) {
		if (i.getWord().length() > 3) {
			if (i.getWord().length() < 8) {
				if ((i.getWord().substr(i.getWord().length() - 4, 4) == "logy")&&(i.getWord() != "-logy")) {
					matches.push_back(i.getWord());
				}
			}
		}
	}
	cout << "Total words found that end in ""logy"" with 7 or less letters: " << matches.size()  << endl;
	for (string j : matches) {
		cout << j << endl;
	}
}


vector<Worde> DictionaryWords;