#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("./input/day4_demo.txt");
  std::string line;
  std::vector<std::vector<char>> forklift;
  while (std::getline(file, line)) {
    std::vector<char> column;
    for (char c : line) {
      column.push_back({c});
    }
    forklift.push_back(column);
  }
  int line_size = line.size();

  int sum = 0;
  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int n = forklift.size();
  int m = forklift[0].size();
  for (int i = 0; i < forklift.size(); i++) {
    for (int j = 0; j < forklift[i].size(); j++) {
      int count = 0;
      if (forklift[i][j] == '@') {
        for (int k = 0; k < 8; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];

          if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
            if (forklift[ni][nj] == '@') {
              count++;
              if (count == 4)
                break;
            }
          }
        }
        if (count < 4) {
          sum++;
        }
      }
    }
  }

  for (auto x : forklift) {
    for (auto element : x) {

      std::cout << element << " ";
    }

    std::cout << "\n";
  }

  std::cout << sum << "\n";
}
