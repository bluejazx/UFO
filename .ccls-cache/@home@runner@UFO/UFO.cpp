#include <string>
#include <vector>
#include <ctime>

std::string get_keyword()
{
  std::vector<std::string> keywords = {"strip", "refer", "proof", "motif", "laser", "funny", "evoke", "frank", "tribe", "swear"};
  srand(time(0));
  return keywords[rand() % (keywords.size() - 1)];
}

void welcom_message()
{
  
}