#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("../input/day8_demo.txt");
  std::string line;
  std::vector<std::vector<int>> coordinates;

  std::vector<int> temp;
  while (std::getline(file, line)) {
    int num = 0;
    for (char c : line) {
      if (c == ',') {
        temp.push_back(num);
        num = 0;
      } else {
        num = num * 10 + (c - '0');
      }
    }
    temp.push_back(num);
    coordinates.push_back(temp);
    temp.clear();
  }

  // for (auto co : coordinates) {
  //   std::cout << co[0] << "," << co[1] << "," << co[2] << "\n";
  // }
  //
  std::vector<std::vector<int>> matrix(coordinates.size(),
                                       std::vector<int>(coordinates.size(), 0));

  for (int i = 0; i < coordinates.size(); i++) {
    for (int j = 0; j < coordinates.size(); j++) {
      if (i == j)
        continue;

      int dist = dist = std::sqrt((coordinates[i][0] - coordinates[j][0]) *
                                      (coordinates[i][0] - coordinates[j][0]) +
                                  (coordinates[i][1] - coordinates[j][1]) *
                                      (coordinates[i][1] - coordinates[j][1]) +
                                  (coordinates[i][2] - coordinates[j][2]) *
                                      (coordinates[i][2] - coordinates[j][2]));

      matrix[i][j] = dist;
    }
  }

  for (auto rows : matrix) {
    for (auto col : rows) {
      std::cout << col << " ";
    }

    std::cout << "\n";
  }

  return 0;
}
