/*

   Author: Tyler Arseneault
   Date: September 29, 2014
   Assignment #1
   Purpose: Reads a text file. Grabs each individual word and stores it 
   into a dictionary, while keeping track of the frequency of occurence 
   of each of those words.

*/


#include <stdio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

const int NUMWORD  = 10;
const int WORDSIZE = 132;

char letter;
char dictionary[NUMWORD][WORDSIZE]      = {0};
char buffer[WORDSIZE]                   = {0};
int freq[NUMWORD]  		        = {0};
int wordLengths[NUMWORD]                = {0};
int ptr                                 =  0;
int row                                 =  0;
int col                                 =  0;
int length                              =  0;

int compareString(char, char);
int insertString();
int printDictionary();

int insertString(){ //inserts string in buffer into the dictionary

  int i;
  
  for (i = 0; i < length; i++){ //loops through the buffer and inserts each letter into the dictionary

    dictionary[ptr][i] = buffer[i];
    cout << dictionary[ptr][i];
    buffer[i] = 0;

  }

  freq[ptr]++;
  cout << endl;

}

int printDictionary(){  //prints out the dictionary and the frequencies of each word



}


int main() {


  while( cin.good() ){

     letter = cin.get();      //gets the next character in the text file

     if ( isalpha(letter) ){  

         buffer[col] = letter;
         col++;
         length++;
         

     }

     else if ( !isalpha(letter) ){

          insertString();
          wordLengths[ptr] = length;
          col = 0;

     }
   }

  return 0;

}
