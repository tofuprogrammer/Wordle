#include <iostream>
#include <string>
#include <vector>

#include "Checks.hpp"
#include "Clearer.hpp"
#include "Randomiser.hpp"

int main() {
    std::string words[100] = { // Array of words to use
            "apple", "brave", "crisp", "dance", "eagle",
            "flame", "grape", "heart", "igloo", "jolly",
            "kneel", "lucky", "mango", "nerdy", "ocean",
            "piano", "queen", "silly", "smile", "table",
            "unite", "vivid", "whale", "xenon", "youth",
            "zebra", "amber", "bloom", "craft", "dough",
            "flair", "giant", "hatch", "input", "jumps",
            "knack", "lemon", "mirth", "noble", "orbit",
            "pearl", "quill", "rider", "swift", "trunk",
            "upset", "vowel", "wheat", "yeast", "zesty",
            "asset", "blink", "drill", "envoy", "frail",
            "globe", "honey", "irony", "kitty", "latch",
            "medic", "ninja", "otter", "prism", "quack",
            "realm", "siren", "troop", "ultra", "voter",
            "wrist", "xylos", "adore", "bliss", "cabin",
            "dandy", "equal", "frost", "glare", "honour",
            "jewel", "knock", "lodge", "miner", "neigh",
            "oaken", "plaza", "quirk", "react", "stump",
            "tried", "usher", "vigil", "waltz", "xerox",
            "zonal", "crane", "flute", "grasp", "hilly"
        };
    bool gameStart = true;
    while (gameStart == true) {
        bool correct = false;
        const int maxAttempts = 6;
        int attempts = 0;
        
        std::string guess;
        std::string answer = words[random(0,99)];
        std::vector<char> answerVector(answer.begin(), answer.end());
        int answerCounter[26] = {0};
            for (char character : answer) {
                answerCounter[character - 'a']++;
            }
        
        std::cout << "Welcome to Legally Distinct Wordle! You have " << maxAttempts << " attempts to guess the 5 letter word.\n";
        std::cout << "If a letter is cyan, like this: (" << "\033[1;36m" << "a" << "\033[0m" << "), that means the letter is correct and in the right position.\n";
        std::cout << "If a letter is yellow, like this: (" << "\033[1;33m" << "b" << "\033[0m" << "), that means the letter is in the answer but it's in the wrong position.\n";
        std::cout << "If a letter has no special colour, like this: (c), that means you've guessed the character more times than it appears in the answer (if the letter appears in your guess more than once and it shows as blue or yellow earlier) or it doesn't appear in the answer at all.\n";
        std::cout << "Psst, for debugging purposes, the answer is " << answer << ".\n";
        
        while (attempts < maxAttempts && !correct){
            std::cout << "Enter a word: ";
            std::cin >> guess;
            
            if (std::cin.fail() || !isAlphabetic(guess)) {
                std::cerr << "Invalid input!\n";
                continue;
            }
            if (guess.length() != answer.length()) {
                std::cerr << "Your guess is not a 5 letter word!\n";
                continue;
            }
            
            int guessCounter[26] = {0};
            
            std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
            std::vector<char> guessVector(guess.begin(), guess.end());
            
            for (size_t counter = 0; counter < guess.length(); counter++) {
                int characterIndex = guess[counter] - 'a';
                
                if (guess [counter] == answer [counter]) {
                    std::cout << "\033[1;36m" << guess[counter] << "\033[0m";
                    guessCounter[characterIndex]++;
                }
                else if (answer.find(guess[counter]) != std::string::npos) {
                    if (guessCounter[characterIndex] < answerCounter[characterIndex]) {
                        std::cout << "\033[1;33m" << guess[counter] << "\033[0m";
                        guessCounter[characterIndex]++;
                    }
                    else {
                        std::cout << guess[counter];
                    }
                }
                else {
                    std::cout << guess[counter];
                }
            }
            std::cout << '\n';
            attempts++;
            if (guess == answer) {
                correct = !correct;
            }
        }
        if (attempts == maxAttempts){
            std::cout << "You've run out of attempts! The correct word was " << answer << ".\n";
        }
        if (correct) {
            std::cout << "You've guessed correctly!";
        }
        std::cout << '\n';
        std::cout << "Play again? (y/n): ";
        char playerStartChoice;
        std::cin >> playerStartChoice;
        if (playerStartChoice == 'y') {
            clearTerminal();
            gameStart = true;
        }
        else if (playerStartChoice == 'n') {
            gameStart = false;
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Play again? (y/n): ";
            std::cin >> playerStartChoice;
        }
    }
}
