//
// Created by cds on 2020/10/6.
//
#include <functional>
#include <iostream>

using namespace std;

int main() {
  auto addition = [](int _1, int _2) -> int { return _1 + _2; };
  auto add3 = [=](int _1) -> int { return addition(_1, 3); };
  auto addition2 = [](int _1) -> auto {
    return [_1](int _2) -> int { return _1 + _2; };
  };
  auto add5 = addition2(5);
  cout << addition(10, 20) << endl;   // => 30
  cout << addition2(10)(20) << endl;  // => 30
  cout << add3(10) << endl;           // => 13
  cout << add5(10) << endl;           // => 15
  return 0;
}