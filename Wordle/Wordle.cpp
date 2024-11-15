#include <iostream>
#include <string>
#include <vector>

#include "Randomiser.hpp"

int main() {
    std::string words[100] = {
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
    bool correct = false;
    const int maxAttempts = 6;
    int attempts = 0;
    std::string guess;
    std::string answer = words[random(0,99)];
    std::vector<char> answerVector(answer.begin(), answer.end());
    std::cout << "Welcome to Legally Distinct Wordle! You have " << maxAttempts << " attempts to guess the 5 letter word.\n";
    std::cout << "If a letter is cyan, like this: (" << "\033[1;36m" << "a" << "\033[0m" << "), that means the letter is correct and in the right position.\n";
    std::cout << "If a letter is yellow, like this: (" << "\033[1;33m" << "b" << "\033[0m" << "), that means the letter is in the answer but it's in the wrong position.\n";
    std::cout << "If a letter has no special colour, like this: (c), that means it is not in the answer";
    std::cout << answer << '\n';
    while (attempts < maxAttempts && !correct){
        std::cout << "Enter a word: ";
        std::cin >> guess;
        std::vector<char> guessVector(guess.begin(), guess.end());
        if (guess.length() != answer.length()) {
            std::cerr << "Your guess is not a 5 letter word!\n";
            continue;
        }
        if (std::cin.fail()) {
            std::cerr << "Invalid input!\n";
            continue;
        }
        for (size_t counter = 0; counter < guess.length(); counter++) {
            if (guess [counter] == answer [counter]) {
                std::cout << "\033[1;36m" << guess[counter] << "\033[0m\n";
            }
            else if (answer.find(guess[counter]) != std::string::npos) {
                std::cout << "\033[1;33m" << guess[counter] << "\033[0m\n";
            }
            else {
                std::cout << guess[counter];
            }
        }
    }
    std::cout << '\n';
}
