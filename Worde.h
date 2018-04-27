/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Word.h
 * Author: andre
 *
 * Created on 17 March 2018, 4:02 PM
 */

#ifndef WORDE_H
#define WORDE_H

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Worde {
public:
   
    enum typeo {misc, n, adj, v};
    Worde(string wordIn, string defIn, typeo typeB);
    // i think below is copy constructor. i commented out for now cause i dunno why it was giving me an error
    //Word(const Word& orig);
    virtual ~Worde();
    string getWord();
    string getDefinition();
    //string getType();
    void printDefinition();
    
      
   
    
private:
    string word;
    string definition;
  typeo theType;
    
    
   
    };

#endif /* WORD_H */

