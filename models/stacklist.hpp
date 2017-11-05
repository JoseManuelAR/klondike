#ifndef __STACKLIST_HPP__
#define __STACKLIST_HPP__

#include "stack.hpp"

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

class StackList {
 public:
  ~StackList();

  void add(Stack*);

  std::size_t size() const { return stacks.size(); };

  Stack* operator[](std::uint8_t position) const {
    assert(position < stacks.size());
    return stacks[position];
  }

  Stack* getStack(const std::string& name) {
    std::vector<Stack*>::iterator it;
    if ((it = std::find_if(stacks.begin(), stacks.end(), [name](Stack* s) {
           return s->getName() == name;
         })) != stacks.end()) {
      return *it;
    }
    return nullptr;
  }

 private:
  std::vector<Stack*> stacks;
};

#endif  //__STACKLIST_HPP__