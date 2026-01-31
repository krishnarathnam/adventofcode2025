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

  while (std::getline(file, line)) {
    std::pair<long long, long long> temp;
    if (line.empty()) {
      break;
    }

    int index = line.find('-');
    temp.first = std::stoll(line.substr(0, index));
    temp.second = std::stoll(line.substr(index + 1));
    range.push_back(temp);
  }

  long long total = 0;
  // for (auto &element : range) {
  //   std::cout << element.first << "-" << element.second << std::endl;
  // }

  std::vector<std::pair<long long, long long>> unionrange;
  std::sort(range.begin(), range.end());

  unionrange.push_back(range[0]);

  for (int i = 1; i < range.size(); i++) {
    if (range[i].first <= unionrange.back().second) {
      unionrange.back().second =
          std::max(unionrange.back().second, range[i].second);
    } else {
      unionrange.push_back(range[i]);
    }
  }

  for (auto &element : unionrange) {
    total += (element.second - element.first) + 1;
  }

  std::cout << total << std::endl;
}
