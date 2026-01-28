#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::ifstream file("./input/day5.txt");
  std::string line;
  std::vector<std::pair<long long, long long>> range;
  std::vector<long long> avail;
  bool turn = false;

  while (std::getline(file, line)) {
    std::pair<long long, long long> temp;

    if (line.empty()) {
      turn = true;
      continue;
    }

    if (!turn) {
      int index = line.find('-');
      temp.first = std::stoll(line.substr(0, index));
      temp.second = std::stoll(line.substr(index + 1));
      range.push_back(temp);
    } else {
      avail.push_back(std::stoll(line));
    }
  }

  int count = 0;
  for (auto &element : avail) {
    for (auto ranges : range) {
      if (element >= ranges.first && element <= ranges.second) {
        count++;
        break;
      }
    }
  }

  std::cout << count << std::endl;

}
