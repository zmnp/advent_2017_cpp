#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr std::uint64_t pinput = 289326;
constexpr std::size_t rows = 2000;
constexpr std::size_t cols = 2000;

std::uint64_t calc_sum(const std::vector<std::vector<std::uint64_t>> &grid,
                       const std::size_t i, const std::size_t j) {
  return grid[i - 1][j] + grid[i - 1][j + 1] + grid[i - 1][j - 1] +
         grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j - 1] +
         grid[i][j - 1] + grid[i][j + 1];
}

int main() {
  std::vector<std::vector<std::uint64_t>> grid(
      rows, std::vector<std::uint64_t>(cols, 0));

  int ci = (int)grid.size() / 2;
  int cj = (int)grid.size() / 2;

  grid[(std::size_t)ci][(std::size_t)cj] = 1;
  ++cj;
  grid[(std::size_t)ci][(std::size_t)cj] = 1;

  int up = 1;
  int left = 2;
  int down = 2;
  int right = 3;

  std::uint64_t final_sum = 0;

  bool err = false;
  for (;;) {
    // up
    for (int i = 0; i < up; ++i) {
      --ci;
      if (ci - 1 < 0 || ci + 1 >= (int)grid.size()) {
        err = true;
        goto endloop;
      }
      final_sum = calc_sum(grid, (std::size_t)ci, (std::size_t)cj);
      grid[ci][cj] = final_sum;
      if (final_sum >= pinput) {
        goto endloop;
      }
    }

    // left
    for (int i = 0; i < left; ++i) {
      --cj;

      if (cj - 1 < 0 || cj + 1 >= (int)grid[0].size()) {
        err = true;
        goto endloop;
      }

      final_sum = calc_sum(grid, (std::size_t)ci, (std::size_t)cj);
      grid[ci][cj] = final_sum;
      if (final_sum >= pinput) {
        goto endloop;
      }
    }

    // down
    for (int i = 0; i < down; ++i) {
      ++ci;
      if (ci - 1 < 0 || ci + 1 >= (int)grid.size()) {
        err = true;
        goto endloop;
      }

      final_sum = calc_sum(grid, (std::size_t)ci, (std::size_t)cj);
      grid[ci][cj] = final_sum;
      if (final_sum >= pinput) {
        goto endloop;
      }
    }

    // right
    for (int i = 0; i < right; ++i) {
      ++cj;
      if (cj - 1 < 0 || cj + 1 >= (int)grid[0].size()) {
        err = true;
        goto endloop;
      }
      final_sum = calc_sum(grid, (std::size_t)ci, (std::size_t)cj);
      grid[ci][cj] = final_sum;
      if (final_sum >= pinput) {
        goto endloop;
      }
    }
    up += 2;
    left += 2;
    down += 2;
    right += 2;
  }
endloop:
  if (!err) {
    std::cout << final_sum << '\n';
  } else {
    std::cout << "Current grid(rows: " << rows << ", columns: " << cols
              << ") is too small."
                 " Resize it and try again.\n";
    return 1;
  }
  return 0;
}
