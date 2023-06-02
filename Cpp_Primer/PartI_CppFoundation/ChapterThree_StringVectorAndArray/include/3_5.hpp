/**
 * @author AaronLi
 * @data 2023-06-02-下午2:10
 * @license GPL-3.0
 */
#ifndef CPP_PRIMER_3_5_HPP
#define CPP_PRIMER_3_5_HPP

/**
 * @title
 * 3.5 数组
 */

#include <iostream>
#include <vector>

class Exercise_3_5 {
 public:
    /**
     * @title
     * 3.5.1节练习
     */

    /**
     * @title
     * 练习3.27
     * @description
     * 假设txt_size是一个无参数的函数，它的返回值是int。请回答下列那个定义是非法的？为什么？
     * @code
     * unsigned buf_size=1024;
     * (a) int ia[buf_size];        (b) int ia[4*7-14];
     * (c) int ia[txt_size()];      (d) char st[11]="fundamental";
     */

    /* a：非法，buf_size不是常数，无法作为数组ia的维度。
     * b：合法，4*7-14等于0，在定义时使用gcc编译并无问题，但是数组维度为0是无法初始化。
     * c：不一定非法，若txt_size函数为constexpr则为合法，反之非法。
     * d：非法，由于st的维度指定了数组个数为11个，但是字符串字面值个数为11个，加上空白字符共12个字符，无法对该数组进行初始化。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习3.28
     * @description
     * 下列数组中元素的值是什么？
     * @code
     * string sa[10];
     * int ia[10];
     * int main(){
     *      string  sa2[10];
     *      int     ia2[10];
     * }
     */
    /* ①：空字符串
     * ②：0
     * ③：空字符串
     * ④：不确定值
     * 具体原因解释：和内置类型的变量一样，如果在函数内部定义了某种内置类型的数组，那么默认初始化会令数组含有未定义的值。如果想要实现默认初始化，应当设置为“int
     * ia2[10]={}”
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习3.28
     * @description
     * 相比于vector来说，数组有哪些缺点，请列举一些。
     */
    /* ①：数组的维度必须为常量表达式
     * ②：数组不允许拷贝和赋值，一些编译器扩展除外，只考虑标准特性
     * ③：在使用数组的过程中容易产生数组越界，而vector有多种机制控制此情况，例如迭代器
     * ④：获取数组的长度不方便，vector可以直接使用size()方法获取
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 3.5.2节练习
     */

    /**
     * @title
     * 练习3.30
     * @description
     * 指出下面代码中的索引错误。
     * @code
     * constexpr size_t array_size=10;
     * int ia[array_size];
     * for(size_t ix=1;ix<=array_size;++ix)
     *      ia[ix]=ix;
     */
    /* 在对ix进行判断时，判断为ix<=array_size，那么会造成数组下标越界。虽然最终也能够执行，但是我们必须避免该项错误! */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习3.31
     * @description
     * 编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
     */
    static void exercise_3_31();

    /**
     * @title
     * 练习3.32
     * @description
     * 将上一题刚刚创建的数组拷贝给另一个数组。利用vector重写程序，实现类似的功能。
     */
    static void exercise_3_32();

    /**
     * @title
     * 练习3.33
     * @description
     * 对于104页的程序来说，如果不初始化scores将发生什么?
     */
    /* 如果不初始化scores，那么其数组中的元素便是不确定值，无法直接通过递增运算符对分数段进行计数。 */
    static void meaninglessFunction_5();

    /**
     * @title
     * 3.5.3节练习
     */

    /**
     * @title
     * 练习3.34
     * @description
     * 假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
     * @code
     * p1+=p2-p1;
     */
    /* ①：将p1移动到离p1长度为p2与p1距离值的位置
     * ②：当p1或p2所对应元素的位置不在数组内时非法
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 练习3.35
     * @description
     * 编写一段程序，利用指针将数组中的元素置为0
     */
    static void exercise_3_35();

    /**
     * @title
     * 练习3.36
     * @description
     * 编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。
     */
    static void exercise_3_36();
};
#endif  // CPP_PRIMER_3_5_HPP
