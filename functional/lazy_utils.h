//
// Created by cds on 2020/10/6.
//

#ifndef MODERN_CPP_LAZY_UTILS_H
#define MODERN_CPP_LAZY_UTILS_H
namespace __utils{

template <typename T> class lazy
{
 private:
  T value_;
  std::function<T()> policy_;
  bool initialized_;
  static T default_policy()
  {
    throw std::runtime_error("No lazy initiation policy given.");
  }
 public:
  lazy() : policy_(default_policy), initialized_(false) {}
  explicit lazy(std::function<T()> _) : policy_(_), initialized_(false) {}
  lazy(const lazy<T>& _) : policy_(_.policy_), initialized_(false) {}

  lazy<T>& operator=(const lazy<T>& _)
  {
    policy_ = _.policy_;
    initialized_ = false;
    return *this;
  }

  T& get_value()
  {
    if (!initialized_)
    {
      value_ = policy_();
      initialized_ = true;
    }
    return value_;
  }

  T& operator()() { return get_value(); }

  operator T() { return get_value(); }
};




}
#endif  // MODERN_CPP_LAZY_UTILS_H
