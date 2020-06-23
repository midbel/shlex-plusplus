#include "shlex.h"

namespace shlex {

  const char space = ' ';
  const char tab = '\t';

  bool is_space(char ch) {
    return ch == space || ch == tab;
  }

  std::vector<std::string> shlex(std::string str) {
    std::vector<std::string> vs;
    auto it = str.begin();
    while(it < str.end()) {
      auto prev = it;
      while (it < str.end() && !is_space(*it)) {
        it = next(it);
      }
      vs.push_back(std::string(prev, it));
      while (is_space(*it)) {
        it = next(it);
      }
      prev = it;
    }
    return vs;
  }
}
