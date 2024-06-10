#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h> 

#include "FileHendler.h"

using namespace std;


vector <int> themeKey = { 1, 2 ,3 ,4 ,5 };
//vector <string> wordsA = { "fish", "dog", "cat", "elephant", "lion", "tiger", "monkey", "zebra", "giraffe", "bear", "kangaroo", "koala", "penguin", "seal", "hippo", "chiken", "wolf", "panda", "frog", "owl", "bunny", "ladybug", "fox", "dragonfly", "sheep", "octopus", "butterfly", "whale", "sheep", "horse", "goat", "pig", "snake" };
//vector <string> wordsP = { "flower", "tree", "grass", "sunflower", "rose", "cactus", "lily", "dandelion", "tulip",  "oak", "birch", "pine", "iris", "lotus", "violet", "dandelion" };
//vector <string> wordsF = { "apple", "peach", "banana", "orange", "strawberry", "grapefruit", "carrot", "potato", "sandwich", "chicken", "beef", "salad", "cake" };
//vector <string> wordsC = { "dress", "shirt", "pants", "skirt", "jeans", "sweater", "jacket", "hat", "shoes", "socks", "gloves", "scarf", "bra", "panties", "boots", "junper", "blouse" };
//vector <string> wordsI = { "pencil", "book", "chair", "table", "computer", "desk", "notebook", "pen", "calculator", "clock", "backpack", "ruler", "scissors", "marker", "board" };
string word, guessedLetters;
int length, key;

                //  функция выбора случайной темы
void randomTheme () {
    while (!(key == 'a' || key == 'A' || key == 'p' || key == 'P' || key == 'f' || key == 'F' || key == 'c' || key == 'C' || key == 'i' || key == 'I')) {
      
            key = _getch();
            if (key == 'r' || key == 'R') {
                key = themeKey[rand() % themeKey.size()];
                break;
            }
        }
    }


                //  выбор темы
void Start() {
    cout << "To start the game, select a theme: \n" << endl;

    cout << "Animals    -   'A'" << endl;
    cout << "Clothes    -   'C'" << endl;
    cout << "Food       -   'F'" << endl;
    cout << "Items      -   'I'" << endl;
    cout << "Plants     -   'P'" << endl;

    cout << "Random theme - 'R'\n" << endl;

    cout << "(Press theme key )" << endl;
    randomTheme();
    
}

                //  выбор слова из массива заданной темы
void chooseWord() {                                                             
    if (key == 'a' || key == 'A' || key == 1) {
        word = wordsA[rand() % wordsA.size()];
        cout << "Theme: animals" << endl;
    }    
    else if (key == 'c' || key == 'C' || key == 2) {
        word = wordsC[rand() % wordsC.size()];        
        cout << "Theme: clothes" << endl;
    }
    else if (key == 'i' || key == 'I' || key == 3) {
        word = wordsI[rand() % wordsI.size()];        
        cout << "Theme: item" << endl;
    }
    else if (key == 'f' || key == 'F' || key == 4) {
        word = wordsF[rand() % wordsF.size()];       
        cout << "Theme: food" << endl;
    }
    else if (key == 'p' || key == 'P' || key == 5) {
        word = wordsP[rand() % wordsP.size()];       
        cout << "Theme: plants" << endl;
    } 
}

                //  проверка есть ли буква в слове
bool isWordGuessed() {
    for (char c : word) {
        if (guessedLetters.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

                //  отрисовка виселицы
void printHangman(int attemptsLeft) {
    if (attemptsLeft == 7) {
        //for (int i = 0; i < 7; i++) 
        //    cout << "_";
        
        for (int j = 0; j < 7; j++) 
            cout << "*";        
    }
    else if (attemptsLeft == 6) {        
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||     [ ]         " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;

    }
    else if (attemptsLeft == 5) {          
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||     [ ]         " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;
        cout << "||  _________      " << endl;
        cout << "||  ||     ||      " << endl;
    }
    else if (attemptsLeft == 4) { 
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||     [ ]         " << endl;
        cout << "||                 " << endl;
        cout << "||                 " << endl;
        cout << "||  _________      " << endl;
        cout << "||  ||     ||      " << endl;
        cout << "||  ||     ||      " << endl;        
    }
    else if (attemptsLeft == 3) {     
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||     [ ]         " << endl;
        cout << "||                 " << endl;
        cout << "||  _________      " << endl;
        cout << "||  ||     ||      " << endl;
        cout << "||  ||     ||      " << endl;
        cout << "||  ||     ||      " << endl;
    }
    else if (attemptsLeft == 2) {        
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||     [ ]         " << endl;
        cout << "||                 " << endl;
        cout << "||  __________     " << endl;
        cout << "||  ||     || \\    " << endl;
        cout << "||  ||     ||  \\   " << endl;
        cout << "||  ||     ||   \\  " << endl;
    }
    else if (attemptsLeft == 1) {        
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||    \\[0]/        " << endl;
        cout << "||      |          " << endl;
        cout << "||  ___/_\\___     " << endl;
        cout << "||  ||     || \\    " << endl;
        cout << "||  ||     ||  \\   " << endl;
        cout << "||  ||     ||   \\  " << endl;
    }
    else if (attemptsLeft == 0) {      
        cout << "_________          " << endl;
        cout << "||/     |          " << endl;
        cout << "||     [0]         " << endl;
        cout << "||     /|\\         " << endl;
        cout << "||     / \\         " << endl;
        cout << "||  ||    /||      " << endl;
        cout << "||  ||   / ||      " << endl;
        cout << "||  ||     ||      " << endl;
    }
}

void printGuessedWord() {    
   
    for (char c : word) {
        if (guessedLetters.find(c) != string::npos) 
            cout << c;        
       else { 
            cout << "_"; 
       }
    }
}

void clearScreen() {
    system("cls");
}

int main() {

    srand(time(NULL));   

    while (true) {

        Start();
        clearScreen();

        chooseWord();
        length = word.length();

        int attemptsLeft = 7;

        cout << "Enter the letter: ";
                
        char guess;

        while (attemptsLeft > 0 && !isWordGuessed()) {          
            cout << "You have "<< attemptsLeft<<" attempts to guess the word\n" ;            
           // cout << attemptsLeft;

            printHangman(attemptsLeft);
          
            printGuessedWord();
                       
            cout << endl;
            cin >> guess;

            if (word.find(guess) != string::npos) {                
                cout << "Correct!" << endl;
                guessedLetters += guess;
            }
            else {              
                cout << " Wrong! " << endl;
                attemptsLeft--;
            }
        }

        printHangman(attemptsLeft);

        if (isWordGuessed()) {
            clearScreen();
            cout << "the word:    " << word<<endl;                   
            cout << "Congratulations, you will be alive!" << word << '.' << endl<<endl;
            cout << "   \\0/             " << endl;
            cout << "    |              " << endl;
            cout << "___/_\\____         " << endl;
            cout << "||     || \\        " << endl;
            cout << "||     ||  \\       " << endl;
            cout << "||     ||   \\      " << endl;
        }
        else
        {      
            clearScreen();
            cout << "WASTED!\n";        
            cout << "You couldn't guess the word: " << word << endl;
            cout << "_________          " << endl;
            cout << "||/     |          " << endl;
            cout << "||     [0]         " << endl;
            cout << "||     /|\\         " << endl;
            cout << "||     / \\         " << endl;
            cout << "||                 " << endl;
            cout << "||                 " << endl;
            cout << "||                 " << endl;
        }
                 
        cout << "To Start a new game, press 'S'" << endl;        
        cout << "To Exit, press 'Esc'." << endl;
        while (key != 's' && key != 'S' && key != 27) {            
                key = _getch();
                clearScreen();          
        }
        if (key == 27) break; 
        length, key = 0;
        word = "";
        guessedLetters = "";
    }
}




// // 1
//      _________
//      ||/     |
//      ||     [ ]
//      ||     
//      ||   
//      ||          
//      ||              
//      ||    
// 
// // 2
//      _________
//      ||/     |
//      ||     [ ]
//      ||     
//      ||   
//      ||          
//      ||  _________            
//      ||  ||     ||       
// 
// // 3
//      _________
//      ||/     |
//      ||     [ ]
//      ||     
//      ||   
//      ||  _________        
//      ||  ||     ||          
//      ||  ||     ||    
// 
// // 4
//      _________
//      ||/     |
//      ||     [ ]
//      ||     
//      ||  _________ 
//      ||  ||     ||     
//      ||  ||     ||          
//      ||  ||     ||  
// 
// // 5
//      _________
//      ||/     |           
//      ||     [ ]          
//      ||                  
//      ||  __________          
//      ||  ||     || \          
//      ||  ||     ||  \          
//      ||  ||     ||   \        
// 
// // 6
//      _________
//      ||/     |
//      ||    \[0]/
//      ||      |
//      ||  ___/_\____ 
//      ||  ||     || \    
//      ||  ||     ||  \        
//      ||  ||     ||   \ 
// 
// // 7
//      _________
//      ||/     |
//      ||     [0]
//      ||     /|\
//      ||     / \
//      ||  ||    /||     
//      ||  ||   / ||          
//      ||  ||     ||    
//
// // 0
//      
//      
//             \0/
//              |
//          ___/_\____ 
//          ||     || \    
//          ||     ||  \        
//          ||     ||   \ 