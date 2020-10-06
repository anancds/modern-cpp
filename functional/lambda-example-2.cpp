//
// Created by cds on 2020/10/6.
//
#include <iostream>

using namespace std;

int main()
{
  int j = 1;
  auto by_val_lambda = [=]{ return j + 1; };
  auto by_ref_lambda = [&]{ return j + 1; };
  auto print = [=]{
    cout << "print by val lambda: " << by_val_lambda() << ", ";
    cout << "by ref lambda: " << by_ref_lambda() << endl;
  };
  print();
  j += 10; print();
  return 0;
}