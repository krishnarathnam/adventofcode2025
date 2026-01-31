#include <fstream>
#include <iostream>
#include <string>
long long makeRepeated(long long x) {
  std::string s = std::to_string(x);
  return std::stoll(s + s);
}

long long sumInvalid(long long L, long long R) {
  long long sum = 0;

  for (long long i = 1; i <= 1'000'000; i++) {
    long long v = makeRepeated(i);
    if (v > R)
      break;
    if (v >= L)
      sum += v;
  }

  return sum;
}
int main() {
  std::ifstream file("./input/day2_real.txt");

  if (!file.is_open()) {
    std::cerr << "Cannot open file\n";
    return 1;
  }

  long long totalSum = 0;

  std::string token;
  while (std::getline(file, token, ',')) {
    auto dash = token.find('-');

    long long L = std::stoll(token.substr(0, dash));
    long long R = std::stoll(token.substr(dash + 1));

    totalSum += sumInvalid(L, R);
  }

  std::cout << totalSum << std::endl;
}
