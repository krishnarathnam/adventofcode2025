#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("../input/day9.txt");
  std::string line;

  std::vector<std::vector<long long>> coords;

  while (std::getline(file, line)) {
    size_t index = line.find(',');
    std::vector<long long> temp;
    int x = std::stoi(line.substr(0, index));
    int y = std::stoi(line.substr(index + 1));
    temp.push_back(x);
    temp.push_back(y);
    coords.push_back(temp);
    temp.clear();
  }

  long long area = 0;
  for (int i = 0; i < coords.size(); i++) {
    for (int j = 0; j < coords.size(); j++) {
      if (i == j)
        continue;
      long long length = std::llabs((coords[i][0] - coords[j][0])) + 1;
      long long height = std::llabs((coords[i][1] - coords[j][1])) + 1;
      long long curr = length * height;
      if (curr > area) {
        area = curr;
      }
    }
  }

  std::cout << area << std::endl;
}
