#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  // register -> value it contains
  std::unordered_map<std::string, std::int64_t> registers;

  // the highest value held in any register during this process
  std::int64_t max_so_far = std::numeric_limits<std::int64_t>::min();

  for (std::string line; std::getline(std::cin, line);) {

    std::istringstream iss(line);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>());

    std::string register_name = tokens[0];
    std::string func = tokens[1];
    std::int64_t amount = std::stoll(tokens[2]);

    std::string left_operand = tokens[4]; // register
    std::string op = tokens[5];
    std::int64_t right_val = std::stoll(tokens[6]);

    // find register (left operand) in hashmap
    std::int64_t left_val = registers[left_operand];

    // checking condition
    bool condit_res = false;
    if (op == ">") {
      if (left_val > right_val) {
        condit_res = true;
      }
    } else if (op == ">=") {
      if (left_val >= right_val) {
        condit_res = true;
      }
    } else if (op == "<") {
      if (left_val < right_val) {
        condit_res = true;
      }
    } else if (op == "<=") {
      if (left_val <= right_val) {
        condit_res = true;
      }
    } else if (op == "==") {
      if (left_val == right_val) {
        condit_res = true;
      }
    } else if (op == "!=") {
      if (left_val != right_val) {
        condit_res = true;
      }
    }
    if (condit_res) {
      std::int64_t register_val = registers[register_name];
      if (func == "inc") {
        register_val += amount;
      } else if (func == "dec") {
        register_val -= amount;
      }
      max_so_far = std::max(register_val, max_so_far);
      registers[register_name] = register_val;
    }
  }

  std::int64_t final_max_val = std::numeric_limits<std::int64_t>::min();
  for (const auto &[key, value] : registers)
    final_max_val = std::max(final_max_val, value);

  std::cout << "Max value after computation: " << final_max_val << '\n';
  std::cout << "Max value during computation: " << max_so_far << '\n';
  return 0;
}
