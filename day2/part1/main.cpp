#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string line;       // current line of input
  long long checksum = 0; // checksum

  // read line by line and compute min and max values for each row
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);

    int row_min, row_max; // min and max values in the row
    int num;              // current number in the row
    for (std::size_t i = 0; iss >> num; ++i) {
      if (i == 0) {
        row_min = row_max = num;
      }
      row_max = std::max(num, row_max);
      row_min = std::min(num, row_min);
    }
    checksum += (row_max - row_min);
  }
  std::cout << checksum << '\n';
  return 0;
}
