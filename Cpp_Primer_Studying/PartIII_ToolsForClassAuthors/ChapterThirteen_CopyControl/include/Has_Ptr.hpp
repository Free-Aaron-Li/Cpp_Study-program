// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Has_Ptr'.
// If there are no special instructions, this file is used as an exercise and
// test file.
#ifndef CPP_PRIMER_STUDYING_HAS_PTR_HPP
#define CPP_PRIMER_STUDYING_HAS_PTR_HPP

#include <iostream>
#include <string>

class Has_Ptr {
  friend void swap(Has_Ptr &lhs, Has_Ptr &rhs);

public:
  explicit Has_Ptr(const std::string &str = std::string())
      : _ps(new std::string(str)), _i(0) {}

  Has_Ptr(const Has_Ptr &obj)
      : _ps(new std::string(*obj._ps)), _i(obj._i) {} // copy constructor

  ~Has_Ptr();

  Has_Ptr &operator=(const Has_Ptr &obj);

  // Has_Ptr &operator=(Has_Ptr obj);

  bool operator<(const Has_Ptr &obj) { return *_ps < *obj._ps; }

  void swap(Has_Ptr &rhs) {
    using std::swap;
    swap(_ps, rhs._ps);
    swap(_i, rhs._i);
  }

  /* Test request */
  const std::string &get_str() const { return *_ps; }

  const int &get_int() const { return _i; }

  void set(const std::string &str, const int i) {
    *_ps = str;
    _i = i;
  }

private:
  std::string *_ps;
  int _i;
};

inline void swap(Has_Ptr &lhs, Has_Ptr &rhs) { lhs.swap(rhs); }

class Like_value_HasPtr {
  friend void swap(Like_value_HasPtr &lhs, Like_value_HasPtr &rhs);

public:
  Like_value_HasPtr(const std::string &str = std::string())
      : _ps(new std::string(str)), _i(0) {}

  Like_value_HasPtr(const Like_value_HasPtr &obj)
      : _ps(new std::string(*obj._ps)), _i(obj._i) {}

  Like_value_HasPtr &operator=(const Like_value_HasPtr &);

  bool operator<(const Like_value_HasPtr &obj) const;

  std::string operator*() const;

  ~Like_value_HasPtr() { delete _ps; }

  /* Test request */
  void setI(int i) { _i = i; }

private:
  std::string *_ps;
  int _i{};
};

inline void swap(Like_value_HasPtr &lhs, Like_value_HasPtr &rhs) {
  using std::swap;
  swap(lhs._ps, rhs._ps);
  swap(lhs._i, rhs._i);
  std::cout << "After swap:\n";
  std::cout << "lhs, the ps is: '" << *lhs._ps << "', and the i is: '" << lhs._i
            << "'.\n";
  std::cout << "rhs, the ps is: '" << *rhs._ps << "', and the i is: '" << rhs._i
            << "'.\n";
}

class Like_pointer_HasPtr {
public:
  explicit Like_pointer_HasPtr(const std::string &str = std::string())
      : _ps(new std::string(str)), _i(0), _use(new std::size_t(1)) {}

  Like_pointer_HasPtr(const Like_pointer_HasPtr &obj)
      : _ps(obj._ps), _i(obj._i), _use(obj._use) {
    ++*_use;
  }

  Like_pointer_HasPtr &operator=(const Like_pointer_HasPtr &obj);
  ~Like_pointer_HasPtr();

private:
  std::string *_ps;
  int _i{};
  std::size_t *_use; // reference count
};

#endif // CPP_PRIMER_STUDYING_HAS_PTR_HPP
