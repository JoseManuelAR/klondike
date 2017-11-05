#include "stacklist.hpp"
#include "stack.hpp"

StackList::~StackList() {
  for (auto stack : stacks) {
    delete stack;
  }
}

void StackList::add(Stack* stack) { stacks.push_back(stack); }
