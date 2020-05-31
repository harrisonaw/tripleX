#include<iostream>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room..." << "\n" << "Enter the correct code to continue..." << "\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n";
    std::cout << "+ There are 3 numbers in the code" << "\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if players guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "*** File extracted... Advance to next level. ***" << "\n";
        return true;
    }
    else
    {
        std::cout << "*** You entered the wrong code. ***" << "\n";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //loop till game complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears errors
        std::cin.ignore(); // Discards buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n" << "*** Nice work. You extracted all the files. ***" << "\n";
    return 0;
}