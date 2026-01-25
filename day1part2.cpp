
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("./input/day1part2.txt");

  if (!file) {
    std::cerr << "Error opening file" << '\n';
    return 1;
  }

  std::string line;
  int count = 0;
  int sum = 50;

  while (std::getline(file, line)) {
    char c = line[0];
    int d = 0;
    for (size_t t = 1; t < line.size(); t++) {
      d = d * 10 + (line[t] - '0');
    }

    if (c == 'R') {
      for (int i = 0; i < d; i++) {
        sum++;
        if (sum == 100)
          sum = 0;
        if (sum == 0)
          count++;
      }
    } else if (c == 'L') {
      for (int i = 0; i < d; i++) {
        sum--;
        if (sum == -1)
          sum = 99;
        if (sum == 0)
          count++;
      }
    }

    if ((sum % 100 == 0)) {
      // count++;
    }
    std::cout << line << " Direction: " << c << " Degree: " << d
              << " sum: " << sum << '\n';
  }

  std::cout << count << '\n';
  return 0;
}
