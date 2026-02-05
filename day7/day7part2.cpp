#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("../input/day7.txt");
  if (!file)
    return 0;

  std::vector<std::vector<char>> matrix;
  std::string line;
  int sPosition = -1;

  while (std::getline(file, line)) {
    std::vector<char> row;
    for (char c : line) {
      if (c == 'S')
        sPosition = row.size();
      row.push_back(c);
    }
    matrix.push_back(row);
  }

  int rows = matrix.size();
  int cols = matrix[0].size();

  std::vector<long long> beam(cols, 0);
  beam[sPosition] = 1;

  for (int i = 1; i < rows; i++) {
    std::vector<long long> nextBeam(cols, 0);

    for (int j = 0; j < cols; j++) {
      if (beam[j] == 0)
        continue;

      if (matrix[i][j] == '^') {
        if (j > 0)
          nextBeam[j - 1] += beam[j];
        if (j + 1 < cols)
          nextBeam[j + 1] += beam[j];
      } else {
        nextBeam[j] += beam[j];
      }
    }

    beam.swap(nextBeam);
  }

  long long total = 0;
  for (long long v : beam)
    total += v;

  std::cout << total << std::endl;
}
