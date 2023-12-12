// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_5_2_HPP
#define CPP_PRIMER_STUDYING_5_2_HPP

/**
 * @title
 * 5.2节练习
 */

#include "5.hpp"

class Exercise_5_2 {
 public:
    /**
     * @title
     * 练习5.4
     * @description
     * 说明下列例子的含义，如果存在问题，试着修改它
     * @code
     * (a) while (string::iterator iter!=s.end()) { ... }
     * (b) while (bool status=find(word)) { ... }
     *      if (! status) { ... }
     */
    /* a：修改为：string::iterator iter;    while(iter!=s.send()) { ... };
     * b：修改为：bool status;  while(status=find(word)) { ... };   if(!status){ ... };
     * */
    static void meaninglessFunction_1();
};
#endif  // CPP_PRIMER_STUDYING_5_2_HPP
