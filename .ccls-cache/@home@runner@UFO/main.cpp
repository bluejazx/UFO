#include <iostream>
#include <vector>

#include "ufo.hpp"

int main()
{
  char play_again;
  
  do
  {
    int misses = 0;
    
    //gives the user a welcome message with instructions
    welcom_message();
  
    //sets a codeword for the user to guess
    std::string codeword = get_codeword();
    std::string answer;
    std::vector<char> incorrect;
    bool guess = false;
    char letter;
    
    for (int l = 0; l < codeword.size(); l++)
      {
        answer += "_";
      }
  
  
    std::cout << "You have managed to gain acess to remote that powers the ship however it requires a codeword what will you guess. It appears you have six misses and it is a five letter word\n";
    while (answer != codeword)
      {
        display_misses(misses);
        display_status(incorrect, answer);
  
        std::cout << "\n\nPlease enter your guess: ";
        std::cin >> letter;
        letter = tolower(letter);
  
  
        for (int k = 0; k < codeword.size(); k++)
          {
            if (letter == codeword[k])
            {
              answer[k] = letter;
              guess = true;
            }
          }
  
        if (guess)
          {
            std::cout << "Correct!\n\n";
          }
          else
          {
            std::cout << "Incorrect! The tractor beam pulls the person in further.\n\n";
            incorrect.push_back(letter);
            misses++;
          }
  
          guess = false;
  
        }
    game_over(answer, codeword);
  
      std::cout << "Would you like to play again?\n\nType y for yes and n for no\n\n";
      std::cin >> play_again;
      play_again = tolower(play_again);
      std::cout << "\n\n";
  } 
  while(play_again == 'y');
}
