#include <iostream>
#include <vector>

#include "ufo.hpp"

int main()
{
  char play_again;

  //loops though while player wishes to keep playing
  do
  {
    //tracks the number of missed letters
    int misses = 0;
    
    //gives the user a welcome message with instructions
    welcom_message();
  
    //sets a codeword for the user to guess
    std::string codeword = get_codeword();
    std::string answer;
    std::vector<char> incorrect;
    bool guess = false;
    char letter;
    int index;

    //provides graphic for player to guess off of
    for (int l = 0; l < codeword.size(); l++)
      {
        answer += "_";
      }
  
    //some more instuction
    std::cout << "You have managed to gain acess to remote that powers the ship however it requires a codeword what will you guess. It appears you have six misses and it is a five letter word\n";

    //repeates until out of guesses
    while (answer != codeword && misses < 7)
      {
        display_misses(misses);
        display_status(incorrect, answer);

        //recieves geuss from player
        std::cout << "\n\nPlease enter your guess: ";
        std::cin >> letter;
        letter = tolower(letter);
  
        //checks if letter is in codeword
        for (int k = 0; k < codeword.size(); k++)
          {
            if (letter == codeword[k])
            {
              answer[k] = letter;
              guess = true;
            }
          }
       
    
        if (guess == true)
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
