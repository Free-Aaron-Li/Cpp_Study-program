//
// Created by AaronLi on 23-4-20.
//

#ifndef CPP_PRIMER_2_4_HPP
#define CPP_PRIMER_2_4_HPP

/**
 * @title
 * <p> 2.4 const限定符 </P>
 */

class Exercise_2_4 {
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
  
    /**
     * @title
     * <p> 练习2.28 </P>
     * @description
     *  说明下面的这些定义是什么意思，挑出其中不合法的。
     * @code
     *  (a) int i, *const cp;       (b) int *p1,*const p2;
     *  (c) const int ic, &r = ic;  (d) const int *const p3;
     *  (e) const int *p;
     */
     
    /*
     * 不合法，常量指针cp未初始化
     * 不合法，常量指针p2未初始化
     * 不合法，常量ic并未初始化
     * 不合法，常量指针p3未初始化
     * 合法，指向常量的指针可以不初始化
     * */

    /**
     * @title
     * 练习2.29
     * @description
     *  假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
     * @code
     *  (a)i = ic;  (b) p1=p3;
     *  (c)p1=&ic;  (d)p3=&ic;
     *  (e)p2=p1;   (f)ic=*p3;
     */

    /* a. 合法
     * b. 不合法，p3指向int常量
     * c. 不合法，p1位普通指针，无法指向常量。应当采用const int *p1
     * d. 不合法，p3已经被赋值，其为常指针常量，无法再次被赋值
     * e. 不合法，p2为常量指针，无法再次被赋值
     * f. 不合法，ic为int常量，无法再次赋值
     * */

    /**
     * @title
     *  2.4.3节练习
     */

    /**
     * @title
     * 练习2.30
     * @description
     * 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const
     * @code
     *  (a) const int v2=0;     (b) int v1=v2;
     *  (c) int *p1=&v1,&r1=v1; (d) const int *p2=&v2,*const p3=&i,&r2=v2;
     */
    /* a. 底层const
     * b. 都不是
     * c. p1都不是，r1都不是
     * d. p2是底层const，p3既是顶层const也是底层const，r2是底层const
     * */

    /**
     * @title
     * 练习2.31
     * @description
     *  假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
     * @code
     *  (a) r1=v2;
     *  (b) p1=p2;p2=p1;
     *  (c) p1=p3;p2=p3;
     */
    /* a. 合法，v2是顶层const，r1是普通int类型引用
     * b. 不合法，p2拥有底层const，p1为普通指针；合法
     * c. 不合法，p3拥有底层const，p1为普通指针；合法
     * */

    /**
     * @title
     *  2.4.4节练习
     */

    /**
     * @title
     * 练习2.32
     * @description
     *  下面的代码是否合法？如果非法请设法将其修改正确。
     * @code
     *  int null=0,*p=null;
     */
     /* 非法，应该改为：int null=0,*p=&null
      * */
};

#endif //CPP_PRIMER_2_4_HPP
