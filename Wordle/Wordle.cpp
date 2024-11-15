#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> guessVector;
    std::vector<std::string> answerVector;
    std::cout << "Welcome to Wordle! You have " << maxAttempts << " attempts to guess the 5 letter word.\n";
    std::string answer = words[99];
    std::cout << answer;
    while (attempts < maxAttempts && !correct){
        std::string guess;
        std::cout << "Enter a word: ";
        std::cin >> guess;
        if (guess.length() != answer.length()) {
            std::cerr << "Your guess is not a 5 letter word!\n";
            continue;
        }
        if (std::cin.fail()) {
            std::cerr << "Invalid input!\n";
            continue;
        }
        
    }
}
