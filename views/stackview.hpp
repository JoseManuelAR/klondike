#ifndef __STACKVIEW_HPP__
#define __STACKVIEW_HPP__

class Stack;

class StackView {
 public:
  void draw(const Stack& theStack, bool isExtended) const;
};

#endif  //__STACKVIEW_HPP__