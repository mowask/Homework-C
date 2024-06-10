#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h> 
#include <fstream>

#include "FileHendler.h"

using namespace std;


vector <string> wordsA;// = { "fish" , "dog", "cat", "elephant", "lion", "tiger", "monkey", "zebra", "giraffe", "bear", "kangaroo", "koala", "penguin", "seal", "hippo", "chiken", "wolf", "panda", "frog", "owl", "bunny", "ladybug", "fox", "dragonfly", "sheep", "octopus", "butterfly", "whale", "sheep", "horse", "goat", "pig", "snake" };
vector <string> wordsC;// = { "dress", "shirt", "pants", "skirt", "jeans", "sweater", "jacket", "hat", "shoes", "socks", "gloves", "scarf", "bra", "panties", "boots", "junper", "blouse" };
vector <string> wordsF;// = { "apple", "peach", "banana", "orange", "strawberry", "grapefruit", "carrot", "potato", "sandwich", "chicken", "beef", "salad", "cake" };
vector <string> wordsI;// = { "pencil", "book", "chair", "table", "computer", "desk", "notebook", "pen", "calculator", "clock", "backpack", "ruler", "scissors", "marker", "board" };
vector <string> wordsP;// = { "flower", "tree", "grass", "sunflower", "rose", "cactus", "lily", "dandelion", "tulip",  "oak", "birch", "pine", "iris", "lotus", "violet", "dandelion" };

string word, guessedLetters;

int key;

                //  функция выбора случайной темы
void randomTheme () {
    vector <int> themeKey = { 1, 2 ,3 ,4 ,5 };

    while (!(key == 'a' || key == 'A' || key == 'p' || key == 'P' || key == 'f' || key == 'F' || key == 'c' || key == 'C' || key == 'i' || key == 'I')) {
      
            key = _getch();
            if (key == 'r' || key == 'R') {
                key = themeKey[rand() % themeKey.size()];
                break;
            }
           
    }
    //cout << " -*-" << key << "-*-";
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
        word = wordsA[rand() % wordsC.size()];       
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
       cout << endl;
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
    //system("cls");
}

int main() {

    FileHandler animal("d:\\animals.txt");
    FileHandler cloth("d:\\clothes.txt");
    FileHandler food("d:\\food.txt");
    FileHandler item("d:\\items.txt");
    FileHandler plant("d:\\plants.txt");
    
    animal.readThemeAnimals(wordsA);
    cloth.readThemeClothes(wordsC);
    food.readThemeFood(wordsF);
    item.readThemeItems(wordsI);
    plant.readThemePlans(wordsP);

    //for (auto word : wordsA)
    //    cout << word<< " ";
       
   /* ofstream fout;
    fout.open("d:\\plants.txt", ios::out);
    if (fout) {    
        for (auto i : wordsP) {
            fout << i;
            fout << "\n";
        }
    }*/

    srand(time(NULL));   

    while (true) {

        Start();
        clearScreen();

        chooseWord();        

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
       key = 0;
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