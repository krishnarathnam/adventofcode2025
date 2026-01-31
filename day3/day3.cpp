#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("./input/day3.txt");
  std::string line;
  std::vector<int> res;
  int sum = 0;
  while (std::getline(file, line)) {
    int largest = INT_MIN;
    int num = 0;
    for (int i = 0; i < line.size() - 1; i++) {
      for (int j = i + 1; j < line.size(); j++) {
        num = (line.at(i) - '0') * 10 + (line.at(j) - '0');
        if (num > largest) {
          largest = num;
        }
      }
    }
    res.push_back(largest);
  }
  for (auto x : res) {
    sum += x;
  }

  std::cout << sum << std::endl;
}
