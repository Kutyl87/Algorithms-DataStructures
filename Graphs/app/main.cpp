#include "../heap/heap.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

struct hash_pair
{
  std::size_t operator()(const std::pair<int, int>& p) const noexcept
  {
    return p.first * 29 ^ p.second * 31;
  }
};

int dijkstra(std::vector<std::string> &grid, std::pair<int, int> source, std::pair<int, int> target) {
  std::pair<int, int> edges[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  std::vector<std::vector<int>> min_distance(grid.size(), std::vector<int>(grid[0].size(), -1));
  std::vector<std::vector<std::pair<int, int>>> parent(grid.size(), std::vector<std::pair<int, int>>(grid[0].size(), {-1, -1}));
  min_distance[source.first][source.second] = 0;
  Heap<std::pair<int, int>, int, hash_pair> active_vertices(5);
  active_vertices.set(source, 0);

  while (!active_vertices.empty()) {
    std::pair<int, int> where = active_vertices.pop().key;
    if (where == target) break;
    for (auto edge : edges) {
      std::pair<int, int> to = {where.first + edge.first, where.second + edge.second};
      if(to.first < 0) continue;
      if(to.first >= int(grid.size())) continue;
      if(to.second < 0) continue;
      if(to.second >= int(grid[0].size())) continue;
      int weight = grid[to.first][to.second];
      if(weight == 'J' || weight == 'X') {
        weight = 0;
      }
      else {
        weight -= '0';
      }
      if(grid[where.first][where.second] == 'J') {
        weight = 0;
      }
      if (min_distance[to.first][to.second] == -1 || min_distance[to.first][to.second] > min_distance[where.first][where.second] + weight) {
        min_distance[to.first][to.second] = min_distance[where.first][where.second] + weight;
        active_vertices.set({to.first, to.second}, min_distance[to.first][to.second]);
        parent[to.first][to.second] = where;
      }
    }
  }

  auto oldGrid = grid;
  for(auto &l : grid) {
    for(auto &ch : l) {
      ch = ' ';
    }
  }

  std::pair<int, int> where = target;
  while(where != source) {
    grid[where.first][where.second] = oldGrid[where.first][where.second];
    where=parent[where.first][where.second];
  }
  grid[where.first][where.second] = oldGrid[where.first][where.second];

  return min_distance[target.first][target.second];
}

int main(int argc, char** argv) {
  if(argc != 2) {
    std::cout << "Użycie:\ngrafy [plik]\n";
    return 1;
  }
  std::ifstream f(argv[1]);
  std::vector<std::string> grid;
  std::string line;
  std::pair<int, int> source = {-1, -1};
  std::pair<int, int> target = {-1, -1};
  for(int i = 0; f >> line; ++i) {
    if(line.length() == 0) break;
    grid.push_back(line);
    auto pos = std::find(line.begin(), line.end(), 'X');
    if(pos != line.end()) {
      if(source.first == -1) {
        source = {i, pos - line.begin()};
      }
      else {
        target = {i, pos - line.begin()};
      }
    }
  }
  int cost = dijkstra(grid, source, target);
  for(auto &l : grid) {
    std::cout << l << '\n';
  }
  std::cout << "\nKoszt: " << cost << "\n";
}
