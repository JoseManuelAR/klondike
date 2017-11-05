#ifndef __PILELIST_HPP__
#define __PILELIST_HPP__

#include <algorithm>
#include <string>
#include <vector>

class Pile;
class Deck;

class PileList {
 public:
  PileList();

  void deal(Deck& deck);

  Pile* getPile(const std::string& name) const;

  void add(Pile* pile) { list.push_back(pile); }

  const std::vector<Pile*>& getList() const { return list; }

  std::size_t size() const { return list.size(); };

  bool won() const;

 private:
  std::vector<Pile*> list;
};

#endif  //__DECK_HPP__