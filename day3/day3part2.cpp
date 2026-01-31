#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("./input/day3part2.txt");
  if (!file)
    return 1;

  std::string line;
  long long total = 0;

  while (std::getline(file, line)) {
    int remove = line.size() - 12;
    std::string st;

    for (char c : line) {
      while (!st.empty() && remove > 0 && st.back() < c) {
        st.pop_back();
        remove--;
      }
      st.push_back(c);
    }

    while (remove > 0) {
      st.pop_back();
      remove--;
    }

    long long value = 0;
    for (int i = 0; i < 12; i++) {
      value = value * 10 + (st[i] - '0');
    }

    total += value;
  }

  std::cout << total << '\n';
}
