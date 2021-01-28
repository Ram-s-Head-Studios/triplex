// preprocessor directive: instruction to compiler. Always at the start of file
// compiler ignores whitespace
# include <iostream> // #<preprocessor directive> <header>
#include <ctime>

void PrintIntroduction(int Difficulty) // parameter
{
    // <namespace>::<myfunction> 
    std::cout << "\nRUNE DELVE\n";
    std::cout << "\nYou are an adventurer trying to delve into level " << Difficulty << " of a dungeon vault locked by a series of numeric runes...\n";
    std::cout << "You need to enter the correct sequence of numeric runes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);
    // Variables // UNREAL CODING STANDARD is UpperCamelCase
    //// <data type> <variable_name> = <value>
    const int RuneA = rand() % Difficulty + Difficulty;
    const int RuneB = rand() % Difficulty + Difficulty;
    const int RuneC = rand() % Difficulty + Difficulty;

    const int RuneSum = RuneA + RuneB + RuneC;
    const int RuneProduct = RuneA * RuneB * RuneC;
    
    std::cout << std::endl;
    std::cout << "+ There are 3 runes in the code\n";
    std::cout << "+ The runes add-up to: " << RuneSum;
    std::cout << "\n+ The runes multiply to give: " << RuneProduct << "\n";

    int GuessA, GuessB, GuessC;

    // Store Player Guess
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if guess is correct
    if (GuessSum == RuneSum && GuessProduct == RuneProduct){
        std::cout << "\n*** The vault shutters loudly as the runes begin to glow and the door slowly opens to the next chamber! ***\n";
        return true;
    } else {
        std::cout << "\n*** The vault's runes pulse with a glow three times before going dark once more. Try again! ***\n";
        return false;
    }
}


int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

     
    while (LevelDifficulty <= MaxDifficulty) // loops until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); // boolean variable names should start with b (convention)
        std::cin.clear(); // clear any errors
        std::cin.ignore(); // discards the buffer // won't need to do this in Unreal

        if (bLevelComplete)
        {
            // increase the level of difficulty
            ++LevelDifficulty; // increment
        } // don't need ; at end of functions/conditionals
        
    }

    std::cout << "The faint glow of gold and precious rocks grows every brighter as the way to the inner vault opens entirely... You win!";
    
    return 0;
}