// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:7_6.
// If there are no special instructions, this file is used as an exercise and test file.

#include "7_6.hpp"

void Exercise_7_6::meaninglessFunction_1() {}
void Exercise_7_6::meaninglessFunction_2() {}

class Account {
 private:
    std::string   _owner;
    double        _amount{};
    static double _interestRate;
    static double initRate();

 public:
    void          calculate() { _amount += _amount * _interestRate; }
    static double rate() { return _interestRate; }
    static void   rate(double);
};
double Account::initRate() { return 0; }
void   Account::rate(double newRate) { _interestRate = newRate; }

void Exercise_7_6::exercise_7_57() { Account account; }
