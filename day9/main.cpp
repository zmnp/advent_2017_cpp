#include <cstdio>
#include <iostream>

int main() {
  int c; // current character
  int total_score = 0;
  int cgr = 0;              // groups counter
  int chars_in_garbage = 0; // number of characters in garbage
  bool within_garbage = false;
  int opened_braces = 0; // number of braces currently opened

  while ((c = std::getchar()) != EOF) {
    if (!within_garbage) {
      if (c == '{') { // group begins there
        ++opened_braces;
      } else if (c == '<') { // garbage begins
        within_garbage = true;
      } else if (c == '}') {
        total_score += opened_braces;
        ++cgr;
        --opened_braces;
      }
    } else { // this this garbage
      if (c == '!') {
        std::getchar();      // next character is ignored, so just skip it
      } else if (c == '>') { // end of garbage
        within_garbage = false;
      } else { // other characters in garbage
        ++chars_in_garbage;
      }
    }
  }
  std::cout << "Number of groups: " << cgr << "\n";
  std::cout << "Total score: " << total_score << "\n";
  std::cout << "Non-canceled characters within the garbage: "
            << chars_in_garbage << "\n";
  return 0;
}
