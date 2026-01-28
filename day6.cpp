#include <cctype>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("./input/day6.txt");
  std::vector<std::vector<long long>> matrix;
  std::vector<char> op;
  if (!file) {
    std::cout << "Cannot read file at specific location" << std::endl;
    return 0;
  }
  std::string line;
  long long num = 0;
  std::vector<long long> temp;
  bool isNumber = false;

  while (std::getline(file, line)) {
    for (char c : line) {
      if (std::isdigit(c)) {
        num = num * 10 + (c - '0');
        isNumber = true;
      } else {
        if (isNumber) {
          temp.push_back(num);
          num = 0;
          isNumber = false;
        } else if (c == '*' || c == '+') {
          op.push_back(c);
        }
      }
    }

    if (isNumber) {
      temp.push_back(num);
      num = 0;
      isNumber = false;
    }

    matrix.push_back(temp);
    temp.clear();
  }

  long long row = matrix.size();
  long long col = matrix[0].size();

  // for (int j = 0; j < col; j++) {
  //   for (int i = 0; i < row; i++) {
  //     if (j < matrix[i].size()) {
  //       std::cout << matrix[i][j] << " ";
  //     }
  //   }
  //   std::cout << op[j] << "\n";
  // }

  std::vector<long long> result;
  for (long long j = 0; j < col; j++) {
    char oper = op[j];
    long long acc = (oper == '+') ? 0 : 1;
    for (long long i = 0; i < row; i++) {
      if (j < matrix[i].size()) {
        if (oper == '+')
          acc += matrix[i][j];
        else
          acc *= matrix[i][j];
      }
    }

    result.push_back(acc);
  }

  long long res = 0;
  for (auto &element : result) {
    res += element;
  }

  std::cout << res << std::endl;
}
