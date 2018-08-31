#include <cstddef>
#include <iostream>
#include <string>

int main() {

  unsigned long long result = 0; /* the sum of all
                                  * digits that match the digit
                                  * halfway around the circular list */

  std::string captcha;
  std::cin >> captcha;

  int half_len = captcha.size() / 2;

  for (std::size_t i = 0; i < captcha.size(); ++i) {
    if (captcha[i] == captcha[(i + half_len) % captcha.size()]) {
      result += (captcha[i] - '0');
    }
  }
  std::cout << result << "\n";
  return 0;
}
