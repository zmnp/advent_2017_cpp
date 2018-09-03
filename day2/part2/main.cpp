#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string line; // current line of input
  long long result = 0;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);

    std::vector<int> row; // numbers in the current row
    int num;              // current number in the row
    while (iss >> num) {
      row.push_back(num);
    }

    std::sort(row.begin(), row.end(), std::greater<int>());
    bool found = false;
    // find two numbers in the row where one evenly divides the other
    for (std::size_t i = 0; i < row.size(); ++i) {
      for (std::size_t j = i + 1; j < row.size(); ++j) {
        if (row[i] % row[j] == 0) {
          result += row[i] / row[j];
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }
  }
  std::cout << result << '\n';
  return 0;
}
