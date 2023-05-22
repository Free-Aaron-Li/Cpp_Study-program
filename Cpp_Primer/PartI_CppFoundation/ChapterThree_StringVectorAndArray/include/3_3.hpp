/**
 * @author AaronLi
 * @data 2023-05-19-下午11:35
 * @license GPL-3.0
 */

#ifndef CPP_PRIMER_3_3_HPP
#define CPP_PRIMER_3_3_HPP

/**
 * @title
 * 3.3 标准库类型vector
 */
class Exercise_3_3{
public:
    /**
     * @title
     * 3.3.1节练习
     */

    /**
     * @title
     * 练习3.12
     * @description
     * 下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果：对于不正确的，请说明其错误的原因。
     * @code
     * (a) vector<vector<int>> ivec;
     * (b) vector<string> svec=ivec;
     * (c) vector<string> svec(10,"null");
     */
     /* b错误，无法将一个类型为vector<int>的vector拷贝初始化string类型的vector */

     /**
      * @title
      * 练习3.13
      * @description
      * 下列的vector对象各包含多少个元素？这些元素的值分别是多少？
      * @code
      * (a) vector<int> v1;         (b) vector<int> v2(10);
      * (c) vector<int> v3(10,42);  (d) vector<int> v4{10};
      * (e) vector<int> v5{10,42};  (f) vector<string> v6{10};
      * (g) vector<string> v7{10,"hi"};
      */
      /* a：空元素
       * b：10个默认初始化为0的int类型元素
       * c：10个值为42的int类型元素
       * d：1个值为10的int类型元素
       * e：值为10，42的2个int类型元素
       * f：10个默认初始化的string类型元素
       * g：10个值为“hi”的string类型元素
       * */

      
};
#endif //CPP_PRIMER_3_3_HPP
