#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("./input/day1.txt");

  if (!file) {
    std::cerr << "Error opening file" << std::endl;
    return 1;
  }

  std::string line;
  // int i = 0;
  int count = 0;
  int sum = 50;
  while (std::getline(file, line)) {
    // i++;
    char c = line[0];
    int d = std::stoi(line.substr(1));
    if (c == 'R')
      sum += d;
    else
      sum -= d;
    if (sum == 0 || (sum % 100 == 0)) {
      sum = 0;
      count++;
    }
    std::cout << line << " Direction: " << c << " Degree: " << d
              << " sum: " << sum << std::endl;
  }

  std::cout << count << std::endl;
  return 0;
}
