//
//  Functions.h
//  Wordle
//
//  Created by Sam Hart on 15/11/2024.
//

#ifndef Functions_h
#define Functions_h

void textBox(const std::string& inputText)
{
    const int textWidth = 1 + 4 * inputText.size(); /* Calculate the width of the line of text to be output.
    Each character in the input string is replaced by 4 characters in the output, e.g. "a" becomes " a |".
    The + 1 accounts for the beginning pipe. */

    // Top row.
    for (int i = 0; i < textWidth; i++) // Loops through this code 4 times for every character in the input string.
    {
        if (i % 4 == 0)
        {
            std::cout << "+"; // Every 4th character in the top row is a + to align with the pipes in the middle row.
        }
        else if (i % 2 == 0)
        {
            std::cout << "="; // Every other character, excluding those already filled in with a +, is replaced with an =.
        }
        else
        {
            std::cout << "-"; // All other characters are filled in with -.
        }
    }
    std::cout << '\n';

    // Middle row.
    std::cout << "|"; // Outputs beginning pipe.
    for (const char inputCharacter : inputText) // Every character in the input text is represented by 4 characters as described above.
        // The character being represented is placed in a char type variable with the identifier "input_character".
    {
        std::cout << " " << inputCharacter << " |"; // Outputs the reformatted version of the input character.
    }
    std::cout << '\n';

    // Bottom border.
    // The code for the bottom border is the same as for the top border.
    for (int i = 0; i < textWidth; i++)
    {
        if (i % 4 == 0)
        {
            std::cout << "+";
        }
        else if (i % 2 == 0)
        {
            std::cout << "=";
        }
        else
        {
            std::cout << "-";
        }
    }
    std::cout << '\n';
}

#endif /* Functions_h */
