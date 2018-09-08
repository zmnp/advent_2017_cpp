#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>

constexpr std::uint64_t pinput = 289326;

long long calc(std::uint64_t test) {
  long long x = 0;
  long long y = 0;
  std::uint64_t n = 1;

  std::size_t steps = 1;
  while (true) {
    // right
    for (std::size_t i = 0; i < steps; ++i) {
      ++x;
      ++n;
      if (n == test)
        return std::abs(x) + std::abs(y);
    }
    // up
    for (std::size_t i = 0; i < steps; ++i) {
      ++y;
      ++n;
      if (n == test)
        return std::abs(x) + std::abs(y);
    }
    ++steps;
    // left
    for (std::size_t i = 0; i < steps; ++i) {
      --x;
      ++n;
      if (n == test)
        return std::abs(x) + std::abs(y);
    }
    // down
    for (std::size_t i = 0; i < steps; ++i) {
      --y;
      ++n;
      if (n == test)
        return std::abs(x) + std::abs(y);
    }
    ++steps;
  }
  return -1;
}

int main() {
  std::cout << calc(pinput) << '\n';
  return 0;
}
