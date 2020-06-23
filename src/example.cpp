#include <iostream>
#include "shlex.h"

int main(int argc, char** argv) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    args = shlex::shlex(argv[i]);
    for (auto a: args) {
      std::cout << a << std::endl;
    }
  }
}
