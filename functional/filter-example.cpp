//
// Created by cds on 2020/10/6.
//
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;

int main()
{
  auto print_value = [](auto v){ for (auto e : v) cout << " " << int(e); cout << endl; };
#define DISPLAY_VALUE(v) do { cout << #v ":"; print_value(v); } while (0);
  std::vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> b;
  std::copy_if(a.begin(), a.end(), std::back_inserter(b),
               [](int _){ return _ % 2; });
  DISPLAY_VALUE(a); // => a: 1 2 3 4 5 6 7 8 9 10
  DISPLAY_VALUE(b); // => b: 1 3 5 7 9
  a.erase(std::remove_if(a.begin(), a.end(), [](int _){ return _ % 2; }),
          a.end());
  DISPLAY_VALUE(a); // => a: 2 4 6 8 10
#undef DISPLAY_VALUE
  return 0;
}
