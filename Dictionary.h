/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dictionary.h
 * Author: andre
 *
 * Created on 17 March 2018, 9:54 AM
 */
using namespace std;

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <sstream>
#include <string>
#include "Worde.h"
#include <vector>
class Dictionary {
public:
    Dictionary();
	void loadDictionary(string filePath);
	//Dictionary(const Dictionary& orig);
    virtual ~Dictionary();
	int getSize() const; // not sure if this needs to be constant. needs some googling on using const for getters
	vector<string> getWordDetails(int index);
       
	void task1();

	void task2();

	void task3();
	

   
private:
   
	
	ifstream theStream;
	string lineOfText; // should be able to get rid of  this after fixing the getline double for no reason problem
	string word;
	string type;
	string definition;
	vector<Worde> DictionaryWords;
        Worde::typeo convert(string str);
};

#endif /* DICTIONARY_H */

