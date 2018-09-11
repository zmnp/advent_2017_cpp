#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
  int passphrases = 0;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::unordered_map<std::string, int> words;

    bool is_passphrase = true;
    for (std::string word; iss >> word;) {
      std::sort(word.begin(), word.end());
      if (words.count(word) != 0) {
        is_passphrase = false;
        break;
      }
      words[word]++;
    }
    if (is_passphrase) {
      ++passphrases;
    }
  }
  std::cout << passphrases << "\n";
  return 0;
}
