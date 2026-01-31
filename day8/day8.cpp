#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("../input/day8.txt");
  std::string line;
  std::vector<std::vector<long long>> coords;

  while (std::getline(file, line)) {
    if (line.empty())
      continue;
    std::vector<long long> v;
    long long num = 0;
    for (char c : line) {
      if (c == ',') {
        v.push_back(num);
        num = 0;
      } else if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      }
    }
    v.push_back(num);
    if (v.size() == 3)
      coords.push_back(v);
  }

  std::vector<std::vector<long long>> matrix;

  for (int i = 0; i < coords.size(); i++) {
    std::vector<long long> v;
    for (int j = 0; j < coords.size(); j++) {
      if (i == j) {
        v.push_back(-999);
        continue;
      }
      long long dx = coords[i][0] - coords[j][0];
      long long dy = coords[i][1] - coords[j][1];
      long long dz = coords[i][2] - coords[j][2];

      v.push_back(std::sqrt((dx * dx) + (dy * dy) + (dz * dz)));
    }
    matrix.push_back(v);
  }

  long long r;
  long long c;

  int i = 0;
  std::vector<std::vector<long long>> groups;
  while (i < 1000) {
    long long min_dist = LONG_LONG_MAX;
    for (int i = 0; i < coords.size(); i++) {
      for (int j = 0; j < coords.size(); j++) {
        if (i == j || matrix[i][j] == -999)
          continue;
        if (matrix[i][j] < min_dist) {
          min_dist = matrix[i][j];
          c = j;
          r = i;
        }
      }
    }
    matrix[r][c] = -999;
    matrix[c][r] = -999;
    if (groups.empty()) {
      std::vector<long long> v;
      v.push_back(r);
      v.push_back(c);
      groups.push_back(v);
    } else {
      int gr = -1, gc = -1;
      for (int i = 0; i < groups.size(); i++) {
        if (std::find(groups[i].begin(), groups[i].end(), r) != groups[i].end())
          gr = i;
        if (std::find(groups[i].begin(), groups[i].end(), c) != groups[i].end())
          gc = i;
      }

      if (gr == -1 && gc == -1) {
        std::vector<long long> v;
        v.push_back(r);
        v.push_back(c);
        groups.push_back(v);
      } else if (gr != -1 && gc == -1) {
        groups[gr].push_back(c);
      } else if (gr == -1 && gc != -1) {
        groups[gc].push_back(r);
      } else if (gr != gc) {
        groups[gr].insert(groups[gr].end(), groups[gc].begin(),
                          groups[gc].end());
        groups.erase(groups.begin() + gc);
      }
    }
    std::cout << r << " " << c << std::endl;
    i++;
  }
  std::cout << "\n";
  for (auto row : groups) {
    for (auto col : row) {
      std::cout << col << " ";
    }
    std::cout << "\n";
  }

  std::sort(
      groups.begin(), groups.end(),
      [](const std::vector<long long> &a, const std::vector<long long> &b) {
        return a.size() > b.size();
      });

  std::cout << "\n";
  std::cout << groups[0].size() * groups[1].size() * groups[2].size()
            << std::endl;
}
