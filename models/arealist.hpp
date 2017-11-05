#ifndef __AREALIST_HPP__
#define __AREALIST_HPP__

#include <string>
#include <vector>

class Area;
class Deck;
class Pile;

class AreaList {
 public:
  AreaList();

  void deal(Deck& deck);

  void add(Area* area) { list.push_back(area); }

  const std::vector<Area*>& getList() const { return list; }

  std::size_t size() const { return list.size(); };

  Pile* getPile(const std::string& name) const;

  bool won() const;

 private:
  std::vector<Area*> list;
};

#endif  //__DECK_HPP__