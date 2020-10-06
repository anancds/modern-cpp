//
// Created by cds on 2020/10/6.
//
#include <cmath>
#include <functional>
#include <iostream>
#include <map>

using std::cout;
using std::endl;

int main() {
  std::map<char, std::function<double(double, double)> > host;
  host['+'] = [](double a, double b) -> double { return a + b; };
  host['-'] = [](double a, double b) -> double { return a - b; };
  host['*'] = [](double a, double b) -> double { return a * b; };
  host['/'] = [](double a, double b) -> double { return a / b; };
  host['^'] = [](double a, double b) -> double { return pow(a, b); };
  cout << "1.1 + 2.2= " << host['+'](1.1, 2.2) << endl;  // => 3.3
  cout << "1.1 - 2.2= " << host['-'](1.1, 2.2) << endl;  // => -1.1
  cout << "1.1 * 2.2= " << host['*'](1.1, 2.2) << endl;  // => 2.42
  cout << "1.1 / 2.2= " << host['/'](1.1, 2.2) << endl;  // => 0.5
  cout << "1.1 ^ 2.2= " << host['^'](1.1, 2.2) << endl;  // => 1.23329
  return 0;
}
