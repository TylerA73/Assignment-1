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

bool compareString();
int insertString();
int printDictionary();

bool compareString(){ /*compares buffer with dictionary to check and see if the word already exists*/

  bool check = false;
  int i;
  int j;

  while ( i < numwords ){

    for ( i = 0; i < numwords; i++ ){

      if ( dictionary[i][0] == buffer[0] ){

        check = true;
        for (j = 1; j < wordLengths[i]; j++ ){

          if ( dictionary[i][j] != buffer[j] ){

            check = false;
            break;

          }else{

            freq[i]++;
            return check;

          }

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
  
  numwords++;
  freq[ptr]++;
  ptr++;

}

int printDictionary(){  //prints out the dictionary and the frequencies of each word

  int i;
  int j;

  for (i = 0; i < numwords; i++){

    for (j = 0; j < wordLengths[i]; j++){

      cout << dictionary[i][j];

    }
    
    cout << "   " << freq[i] << endl;

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

         wordLengths[ptr] = length;

         if ( !compareString() || numwords == 0){

           insertString(); 

         }

         col    = 0;
         length = 0;

     }
   }

  printDictionary();
  return 0;

}
