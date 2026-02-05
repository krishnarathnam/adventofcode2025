#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("../input/day7.txt");
  std::string line;
  std::vector<std::vector<char>> matrix;
  int sPosition;
  std::vector<char> temp;

  while (std::getline(file, line)) {
    for (char c : line) {
      if (c == 'S') {
        sPosition = line.find('S');
      }

      temp.push_back(c);
    }
    matrix.push_back(temp);
    temp.clear();
  }

  std::vector<int> beam(matrix[0].size());
  beam[sPosition] = 1;

  int count = 0;
  for (int i = 1; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (beam[j] == 1) {
        if (matrix[i][j] == '^') {
          if (j == 0)
            beam[j + 1] = 1;
          else if (j == matrix[i].size() - 1)
            beam[j - 1] = 1;
          else {
            beam[j + 1] = 1;
            beam[j - 1] = 1;
          }

          beam[j] = 0;
          count++;
        }
      }
    }
  }

  std::cout << count << std::endl;
}
