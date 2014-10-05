/*

   Author: Tyler Arseneault
   Date: September 29, 2014
   Assignment #1
   Purpose: Reads a text file. Grabs each individual word and stores it 
   into a dictionary, while keeping track of the frequency of occurence 
   of each of those words.

*/


#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

const int NUMWORD  = 10;
const int WORDSIZE = 132;

char dictionary[NUMWORD][WORDSIZE] = {0};
int freq[NUMWORD]  = {0};

int compareString(char, char);
int 

int main() {

  char ch;
  char buffer[WORDSIZE] = 0;
  int newLine = 0;
  int row     = 0;
  int col     = 0;
  int ptr     = 0;

  while( cin.good() ){

     ch = cin.get();      //gets the next character in the text file

     if ( isalpha(ch) ){  

         
         buffer[col] = ch;
         col++;
         newLine = 1;

     }

     else if (newLine){

          buffer[col] = 0;
          newLine = 0;

     }
   }

  return 0;

}
