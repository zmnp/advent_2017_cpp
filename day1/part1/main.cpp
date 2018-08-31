#include <cstdio>

int main() {
  int c;            // current digit
  int prev_c = 'a'; // previous digit
  char fdigit;      // first digit of the captcha

  unsigned long long result = 0; /* the sum
                                  * of all digits that match the next
                                  * digit in the list */

  for (int i = 0; (c = std::getchar()) != '\n'; ++i) {
    if (i == 0) { // save the first digit
      fdigit = c;
    }
    if (c == prev_c) {
      result += (c - '0');
    }
    prev_c = c;
  }
  if (prev_c == fdigit) {
    result += (fdigit - '0');
  }
  std::printf("%llu\n", result);
}
