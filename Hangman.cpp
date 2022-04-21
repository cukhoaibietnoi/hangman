#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cctype>
using namespace std;

void artPrint (char fileName[]) {
	string line;
	ifstream Hangman;
	Hangman.open(fileName);
	while (getline(Hangman, line)) {
		cout << line << "\n";
	}
	cout << "\n\n";
	Hangman.close();
}

int main() {
	
	string word;
	ifstream wordList;
	wordList.open("common_words.txt");
	
	char replay = 'y';
	while (replay == 'y') {
		
	    system("CLS");
    	artPrint("0.txt");
	    cout << "Wrong guesses: \n\n";
	    
	    // word randomizer
	    srand (time(0));
	    int num = rand() % 5008 + 1;
	    for (int i = 0 ; i < num ; i++) getline (wordList, word);
	    for (int i = 0 ; i < word.length() ; i++) cout << "_ ";
	    cout << "\n";
	
    	// main game
    	int correctLetters = 0, wrong = 0, temp, printedLetters = 0;
    	char letter, correct[15], wrongGuess[10], guess[30];
    	while (wrong < 6) {
    		temp = correctLetters;
	    	cin >> letter;
	    	if (isupper(letter)) letter = tolower(letter);
	      	system("CLS");
		
	    	//confirming the letter's existence in the word
	     	for (int i = 0 ; i < word.length() ; i++) {
	    		if (letter == word[i]) {
	    			correct[correctLetters] = letter;
	    			correctLetters++;
	    			break;
	    		} 
	    	}
		
	    	//console screen modifications for wrong guesses
	    	if (temp == correctLetters) {
	    		wrongGuess[wrong] = letter;
	    	    wrong++;
	    	}
	    	switch (wrong) {
	    		case 0 :
	    			artPrint("0.txt");
		    		break;
	    		case 1:
	    			artPrint("1.txt");
		    		break;
		    	case 2:
		    		artPrint("2.txt");
		    		break;
		    	case 3:
		    		artPrint("3.txt");
		    		break;
		    	case 4:
		    		artPrint("4.txt");
		    		break;
		    	case 5:
		    		artPrint("5.txt");
		    		break;
		    	case 6:
		    		artPrint("6.txt");
		    		break;
	    	}
	    	cout << "Wrong guesses:  ";
	    	for (int i = 0 ; i < wrong ; i++) cout << wrongGuess[i] << "  ";
	    	cout << "\n\n";
	   	
	    	//reprinting the word with discovered letters
	    	for (int i = 0 ; i < word.length() ; i++) {
	    		int check = 0;
		    	for (int j = 0 ; j < correctLetters ; j++) {
		    		if (word[i] == correct[j]) {
		    		    cout << word[i] << " ";
		    		    check++;
		    		    printedLetters++;
		    		}
		    	}
		    	if (check == 0) cout << "_ ";
	    		check == 0;
		    }
	    	cout << "\n";
		
	    	//game result check
	    	if (printedLetters == word.length()) {
	    		cout << "\nYou win!\n\n";
	    		break;
	    	}
	    	if (wrong == 6) cout << "\nYou lost. The word was -" << word << "-.\n\n";
		
	    	//system refresh
	    	printedLetters = 0;
    	}
    	cout << "Play again?  y/n  ";
    	cin >> replay;
    	
    	//read the word file from the top
    	wordList.clear();
    	wordList.seekg(0);
    }
    cout << "\nThank you for playing!";
	wordList.close();
	return 0;
}
