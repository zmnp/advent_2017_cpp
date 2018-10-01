#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> banks;
  std::vector<std::vector<int>> seen;

  for (int blocks; std::cin >> blocks;)
    banks.push_back(blocks);

  seen.push_back(banks);

  int cycles = 0;
  for (bool found = false; !found; ++cycles) {
    // find bank with the most blocks
    int max_bank = banks[0];
    std::size_t max_bank_indx = 0;
    for (std::size_t i = 0; i < banks.size(); ++i) {
      if (banks[i] > max_bank) {
        max_bank = banks[i];
        max_bank_indx = i;
      }
    }
    banks[max_bank_indx] = 0; // remove all blocks from the selected bank

    // redistribute removed blocks among the banks
    for (std::size_t i = (max_bank_indx + 1) % banks.size(); max_bank > 0;
         i = (i + 1) % banks.size()) {
      ++banks[i];
      --max_bank;
    }

    // check if we've seen before this current blocks-in-banks
    // configuration
    for (std::size_t i = 0; i < seen.size(); ++i) {
      bool have_seen = true;
      for (std::size_t j = 0; j < seen[i].size(); ++j) {
        if (banks[j] != seen[i][j]) {
          have_seen = false;
          break;
        }
      }
      if (have_seen) {
        found = true;
        break;
      }
    }
    if (!found) {
      seen.push_back(banks);
    }
  }
  std::cout << cycles << '\n';
  return 0;
}
