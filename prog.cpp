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

  bool check;
  int i;
  int j;
  sameRow = 0;

  for (i = 0; i < numwords; i++){

    if ((dictionary[i][0] == buffer[0]) && (length == wordLengths[i])){
       
      check = true;
      sameRow = i;

      if (check){
        for (j = 1; j < length; j++){

          if(dictionary[i][j] != buffer[j]){
            check = false;
            break;

          } else check = true;

        }

      }
       
    }

  }

return check;

}

int insertString(){ //inserts string in buffer into the dictionary

  int i;
  
  for (i = 0; i < length; i++){ //loops through the buffer and inserts each letter into the dictionary

    dictionary[ptr][i] = buffer[i];
    buffer[i] = 0;

  }
  wordLengths[ptr] = length;
  freq[ptr] = 1;
  ptr++;
  freq[ptr] = 0;
  numwords++;

}

int printDictionary(){  //prints out the dictionary and the frequencies of each word

  int i;
  int j;

  cout << "Word ------------------------------- Frequency" << endl;
  cout << endl;

  for (i = 0; i < (ptr - 1); i++){

    for (j = 0; j < 45; j++){

      if(isalpha(dictionary[i][j])){

         cout << dictionary[i][j];
         dictionary[i][j] = 0;

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

     if ( isalpha(letter) ){  

         buffer[col] = letter;
         col++;
         length++;
         

     }

     else if ( !isalpha(letter) ){

         //wordLengths[ptr] = length;

         if ( !compareString() || numwords == 0){

           insertString();
           
           
         }

         else if (compareString){
           freq[sameRow]++;
         }

         col    = 0;
         length = 0;

     }
   }

  printDictionary();
  return 0;

}
