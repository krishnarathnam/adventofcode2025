#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("./input/day6.txt");
  std::vector<std::vector<long long>> matrix;
  std::vector<char> oper;
  if (!file) {
    std::cout << "Cannot read file at specific location" << std::endl;
    return 0;
  }
  std::string line;
  std::vector<long long> temp;
  while (std::getline(file, line)) {
    for (char c : line) {
      if (c == '*' || c == '+') {
        oper.push_back(c);
        continue;
      }
      if (c == ' ')
        temp.push_back(-999);
      else
        temp.push_back(c - '0');
    }

    matrix.push_back(temp);
    temp.clear();
  }

  matrix.pop_back();

  long long col = matrix[0].size();
  long long row = matrix.size();
  long long next = 0;
  char op = oper[next];
  long long temp_total = (op == '+') ? 0 : 1;
  long long total = 0;
  std::vector<long long> total_vec;

  for (long long j = 0; j < col; j++) {

    bool emptyCol = true;
    for (long long i = 0; i < row; i++) {
      if (matrix[i][j] != -999) {
        emptyCol = false;
        break;
      }
    }

    if (emptyCol) {
      total_vec.push_back(temp_total);
      next++;
      if (next >= oper.size())
        break;
      op = oper[next];
      temp_total = (op == '+') ? 0 : 1;
      continue;
    }

    long long num = 0;
    for (long long i = 0; i < row; i++) {
      if (matrix[i][j] != -999) {
        num = num * 10 + matrix[i][j];
      }
    }

    if (op == '+')
      temp_total += num;
    else if (op == '*')
      temp_total *= num;

    if (j == col - 1) {
      total_vec.push_back(temp_total);
      next++;
      if (next >= oper.size())
        break;
      op = oper[next];
      temp_total = (op == '+') ? 0 : 1;
      continue;
    }
  }

  for (auto element : total_vec) {
    std::cout << element << "+";
    total += element;
  }
  std::cout << "\n";
  std::cout << total << std::endl;
}
