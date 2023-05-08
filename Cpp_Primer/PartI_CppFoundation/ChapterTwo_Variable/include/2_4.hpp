//
// Created by AaronLi on 23-4-20.
//

#ifndef CPP_PRIMER_2_4_HPP
#define CPP_PRIMER_2_4_HPP

/**
 * @title
 * <p> 2.4 const限定符 </P>
 */

#include <iostream>

typedef int ElemType;

class Exercise_2_3 {
public:
    /**
     * @title
     * <p> 2.4节练习 </P>
     */

    /**
     * @title
     * <p> 练习2.26 </P>
     * @description
     *  下面哪些句子是合法的？如果有不合法的句子，请说明为什么？
     * @code
     *  (a) const int buf;       (b) int cnt = 0;
     *  (c) const int sz=cnt;    (d) ++cnt; ++sz; 
     */

    /* 
     * a：不合法，const对象必须初始化
     * b：合法，初始化int类型对象
     * c：合法，初始化const对象
     * d：不合法，const对象无法被修改
     * */

    /**
     * @title
     * <p> 2.4.2节练习 </P>
     */

    /**
     * @title
     * <p> 练习2.27 </P>
     * @description
     *  下面的哪些初始化是合法的？请说明原因。
     * @code
     *  (a) int i = -1, &r = 0;      (b) int *const p2 = &i2;
     *  (c) const int i = -1,&r = 0; (d) const int *const p3 = &i2;
     *  (e) const int *p1 =&i2;      (f) const int &const r2;
     *  (g) const int i2 = i, &r = i;
     */

    /*
     * a：不合法，r作为引用对象，无法直接引用数值
     * b：
     * */
  
    
};

#endif //CPP_PRIMER_2_4_HPP
