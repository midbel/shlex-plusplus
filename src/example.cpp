#include <iostream>
#include "shlex.h"

int main(int argc, char** argv) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << std::endl;
    args = shlex::shlex(argv[i]);
    for (auto a: args) {
      std::cout << " " << a << std::endl;
    }
    if (i < argc-1) {
      std::cout << "---" << std::endl;
    }
  }
}
