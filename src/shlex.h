#ifndef __SHLEX_H__
#define __SHLEX_H__

#include <vector>
#include <string>

namespace shlex {
  std::vector<std::string> shlex(std::string str);
}

#endif
