//
// Created by cds on 2020/10/7.
//
#include <iostream>
#include <string>
#include <tuple>

template <class Func, class Tuple, int N>
struct TupleHelper {
  static void func(Func f, const Tuple &_) {
    TupleHelper<Func, Tuple, N - 1>::func(f, _);
    f(std::get<N - 1>(_), N - 1);
  }
};

template <class Func, class Tuple>
struct TupleHelper<Func, Tuple, 1> {
  static void func(Func f, const Tuple &_) { f(std::get<0>(_), 0); }
};

template <class Func, class... Args>
void manipulate_tuple(Func f, const std::tuple<Args...> &_) {
  TupleHelper<Func, decltype(_), sizeof...(Args)>::func(f, _);
}

template <class... Args>
void print_tuple(const std::tuple<Args...> &_) {
  std::cout << "(";
  manipulate_tuple(
    [](auto _, std::size_t idx) {
      if (idx != 0) std::cout << ", ";
      std::cout << _;
    },
    _);
  std::cout << ")";
}

int main() {
  print_tuple(std::make_tuple(10, 1.5, 'A'));
  // => (10, 1.5, A)
  return 0;
}