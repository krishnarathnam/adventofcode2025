
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("./input/day4part2.txt");
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

  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int n = forklift.size();
  int m = forklift[0].size();
  bool run = true;
  std::vector<std::vector<char>> temp;
  int totalsum = 0;
  int runtime = 0;

  while (run) {
    int sum = 0;
    for (int i = 0; i < forklift.size(); i++) {
      std::vector<char> temp2;
      for (int j = 0; j < forklift[i].size(); j++) {
        int count = 0;
        if (forklift[i][j] == '@') {
          for (int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
              if (forklift[ni][nj] == '@') {
                count++;
              }
            }
          }
          if (count < 4) {
            sum++;
          }
        }

        if (forklift[i][j] == '.')
          temp2.push_back('.');
        else if (forklift[i][j] == '@' && count < 4)
          temp2.push_back('x');
        else if (forklift[i][j] == 'x')
          temp2.push_back('.');
        else if (forklift[i][j] == '@')
          temp2.push_back('@');
      }

      temp.push_back(temp2);
      temp2.clear();
    }
    if (sum == 0) {
      break;
      run = false;
    } else {
      totalsum += sum;
      forklift = temp;
      temp.clear();
    }
    // std::cout << "sum: " << sum << std::endl;
    // std::cout << "total sum: " << totalsum << std::endl;
  }
  std::cout << totalsum << "\n";
}
