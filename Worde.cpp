/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Word.cpp
 * Author: andre
 * 
 * Created on 17 March 2018, 4:02 PM
 */
#include "stdafx.h"
#include "Worde.h"

using namespace std;

string definition, word;



Worde::Worde(string wordIn, string defIn, typeo typeB) {
     this->word = wordIn;
     this->definition = defIn;
     this->theType = typeB;
     
     
}

//Word::Word(const Word& orig) {
//}

Worde::~Worde() {
}

enum typeo {misc, n, adj, v};

typeo theType;
string Worde::getWord(){
return this->word;
}

string Worde::getDefinition(){
return this->definition;
}



void Worde::printDefinition(){
    // remember this needs to be added to, as assignment asks for it to be prepending with type, following a certain scheme.
    // NOT FINSIHED THIS NEEDS TO MEET SOM CRITERIA LIKE THEY APPENDED...
    cout << "Name of word: " << this->word << endl;
	
        switch (this->theType){
            case 0: cout <<"Type of word: " << "misc" << endl;
            break;
            case 1: cout << "Type of word: " << "n" << endl;
            break;
            case 2: cout << "Type of word: " << "adj" << endl;
            break;
            case 3: cout << "Type of word: " << "v" << endl;
            break;
                    
        }
        cout << "Definition: " << endl << this->definition << endl;
}

   
 