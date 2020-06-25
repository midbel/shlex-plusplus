#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "shlex.h"

std::string join(std::vector<std::string> parts, char blank = ' ') {
  std::ostringstream str;
  for (int i = 0; i < parts.size(); i++) {
    if (i > 0) {
      str << blank;
    }
    str << parts[i];
  }
  return str.str();
}

TEST_CASE("basic lexing", "basic") {
  std::vector<std::string> words = {"shlex", "-n", "1234", "-v", "foo", "bar"};
  std::string str = join(words);
  REQUIRE(str == "shlex -n 1234 -v foo bar");

  std::vector<std::string> parts = shlex::shlex(str);
  REQUIRE(parts.size() == words.size());
  for (int i = 0; words.size(); i++) {
    INFO("want: " << words[i] << " - got: " << parts[i]);
    CHECK(words[i] == parts[i]);
  }
}
