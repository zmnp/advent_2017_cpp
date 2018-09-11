#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> joffsets;
  int offset;

  while (std::cin >> offset) {
    joffsets.push_back(offset);
  }

  int next;
  std::uint64_t steps = 0;
  for (int indx = 0; indx >= 0 && indx < (int)joffsets.size();) {
    next = joffsets[indx];
    if (next >= 3) {
      --joffsets[indx];
    } else {
      ++joffsets[indx];
    }
    indx += next;
    ++steps;
  }
  std::cout << steps << "\n";
  return 0;
}
