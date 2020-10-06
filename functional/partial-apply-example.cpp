//
// Created by cds on 2020/10/6.
//
#include <iostream>

using namespace std;

int main()
{
  auto div = [](int a, int b)->int{ return a / b; };
  auto div3 = [div](int a)->int{ return div(a, 3); };
  auto ten_div = [div](int b)->int{ return div(10, b); };
  cout << div(10, 3) << " " << div3(10) << " " << ten_div(3) << endl; // => 3 3 3
  return 0;
}