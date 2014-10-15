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
#include <iomanip>
#include <locale>

using namespace std;

const int MAXWORD  = 10;
const int WORDSIZE = 132;

char letter;
char dictionary[MAXWORD][WORDSIZE]      = {0};
char buffer[WORDSIZE]                   = {0};
int freq[MAXWORD]  		        = {0};
int wordLengths[MAXWORD]                = {0};
int ptr                                 =  0;
int row                                 =  0;
int col                                 =  0;
int length                              =  0;
int numwords                            =  0;
int sameRow				=  0;

bool compareString();
int insertString();
int printDictionary();

bool compareString(){ /*compares buffer with dictionary to check and see if the word already exists*/

  bool check = false;
  int i;
  int j;
  sameRow = 0;

  for (i = 0; i < ptr ; i++){

    if ((dictionary[i][0] == buffer[0]) && (length == wordLengths[i])){
       
      check = true;
      sameRow = i;

      if (dictionary[i][1] == buffer[1]){
        for (j = 1; j < wordLengths[i]; j++){

          if(dictionary[i][j] != buffer[j]){
            check = false;
            break;

          }
        
        }
        if(check)
          return true;
      }
       
    }

  }

  return false;

}

int insertString(){ //inserts string in buffer into the dictionary

  int i;
  
  for (i = 0; i < length; i++){ //loops through the buffer and inserts each letter into the dictionary

    dictionary[ptr][i] = buffer[i];
    buffer[i] = 0;

  }

  wordLengths[ptr] = length;
  length = 0;
  freq[ptr] = 1;
  ptr++;
  numwords++;

}

int printDictionary(){  //prints out the dictionary and the frequencies of each word

  int i;
  int j;

  cout << "Maximum capacity of the dictionary is 10 words. "
       << "It will only add the first 10"
       << endl << "unique words."
       << endl << endl;
  cout << "Dictionary will only add the first 132 characters in a word." << endl << endl;
  cout << "Word ------------------------------- Frequency" << endl;
  cout << endl;

  for (i = 0; i < numwords; i++){

    for (j = 0; j < 45; j++){

      if(isalpha(dictionary[i][j])){

         cout << dictionary[i][j];
         //dictionary[i][j] = 0;

      }
      else 
         cout << " ";

    }
    
    cout << freq[i] << endl;

  }

}


int main() {


  while( cin.good() ){

     letter = cin.get();      //gets the next character in the text file

     if ( isalpha(letter) && (length < WORDSIZE) && (numwords < MAXWORD)){  

         buffer[col] = letter;
         col++;
         length++;
         

     }

     else if ( !isalpha(letter) || (length == WORDSIZE) ){


         if ((!compareString()) && (ptr < MAXWORD)){

           insertString();
           
           
         }

         else if (compareString()){
           freq[sameRow]++;

         }

         col    = 0;
         length = 0;

     }
   }

  printDictionary();
  return 0;

}
