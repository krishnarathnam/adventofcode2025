#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool isPrimitive(const std::string &s) {
  int n = s.size();
  for (int len = 1; len <= n / 2; len++) {
    if (n % len != 0)
      continue;
    std::string t = s.substr(0, len);
    bool ok = true;
    for (int i = 0; i < n; i += len) {
      if (s.substr(i, len) != t) {
        ok = false;
        break;
      }
    }
    if (ok)
      return false; // s is not primitive
  }
  return true;
}

long long sumInvalid(long long L, long long R) {
  long long sum = 0;

  for (long long base = 1; base <= 1'000'000; base++) {
    std::string s = std::to_string(base);

    // KEY FIX: only primitive bases
    if (!isPrimitive(s))
      continue;

    std::string cur = s + s; // at least twice
    while (cur.size() <= 19) {
      long long v = std::stoll(cur);
      if (v > R)
        break;
      if (v >= L)
        sum += v;
      cur += s;
    }
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
