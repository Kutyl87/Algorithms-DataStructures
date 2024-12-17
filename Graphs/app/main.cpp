#include "../heap/heap.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <functional>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
/*
int dijkstra(std::vector<std::string> &grid, std::pair<int, int> source, std::pair<int, int> target) {
  std::pair<int, int> edges[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  std::vector<std::vector<int>> min_distance(grid.size(), std::vector<int>(grid[0].size(), -1));
  min_distance[source.first][source.second] = 0;
  better_priority_queue::updatable_priority_queue<std::pair<int, int>, int> active_vertices;
  active_vertices.set(source, 0);

  while (!active_vertices.empty()) {
    std::pair<int, int> where = active_vertices.pop_value().key;
    if (where == target) return min_distance[where.first][where.second];
    for (auto edge : edges) {
      std::pair<int, int> to = {where.first + edge.first, where.second + edge.second};
      if(to.first < 0) continue;
      if(to.first >= grid.size()) continue;
      if(to.second < 0) continue;
      if(to.second >= grid[0].size()) continue;
      int weight = grid[to.first][to.second];
      if(weight == 'J' || weight == 'X') {
        weight = 0;
      }
      else {
        weight -= '0';
      }
      if (min_distance[to.first][to.second] == -1 || min_distance[to.first][to.second] > min_distance[where.first][where.second] + weight) {
        min_distance[to.first][to.second] = min_distance[where.first][where.second] + weight;
        active_vertices.set({to.first, to.second}, -min_distance[to.first][to.second]);
      }
    }
  }
  return -1;
}
*/

struct hash_pair
{
  std::size_t operator()(const std::pair<int, int>& p) const noexcept
  {
    return p.first * 29 ^ p.second * 31;
  }
};

int main() {
  std::vector<std::string> grid;
  std::string line;
  while(std::cin >> line) {
    grid.push_back(line);
  }
  for(auto &l : grid) {
    std::cout << l;
  }
  Heap<std::pair<int, int>, int, hash_pair> pq(5);
}
