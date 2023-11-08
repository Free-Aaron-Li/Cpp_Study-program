// This file is part of Cpp_Primer_Studying project.
// This program is called:7_5.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_5_HPP
#define CPP_PRIMER_STUDYING_7_5_HPP

/**
 * @title
 * 7.5 构造函数再探
 */

#include "7.hpp"
#include "sales_data_private.hpp"

class Exercise_7_5 {
 public:
    /**
     * @title
     * 7.5.1节练习
     */

    /**
     * @title
     * 练习7.36
     * @description
     * 下面的初始值是错误的，请找出问题所在并尝试修改它。
     * @code
     * struct X{
     *      X(int i,int j):base(i),rem(base%j){}
     *      int rem,base;
     * };
     */
    /*
     * 由于rem与base在类中声明的顺序是rem在前，base在后。所以rem先初始化，但是在构造函数中定义的顺序为base在前，rem在后。
     * 所以导致，使用未定义值初始化rem。
     * 修改为：
     * 1| struct X{
     * 2|      X(int i,int j):rem(i),base(i%j){}
     * 3|      int rem,base;
     * 4| };
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.37
     * @description
     * 使用本节提供的Sales_data类（这里笔者使用的是SalesData类），确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有数据成员的值。
     * @code
     * 1| Sales_data first_item(cin);
     * 2|
     * 3| int main(){
     * 4|      Sales_data next;
     * 5|      Sales_data last("9-999-99999-9");
     * 6| }
     */
    /*
     * 行号1：使用了SalesData(std::istream &istream) { read(istream, *this); }，
     * 数据成员：使用输入流中的输入值；
     * 行号4：使用了SalesData(std::string s = "") : _bookNo(std::move(s)){}; ，
     * 数据成员：__bookNo:""，_units_sold：0，_revenue：0.0；
     * 行号5：使用了SalesData(std::string &str) : _bookNo(std::move(str)) {}，
     * 数据成员：__bookNo:str，_units_sold：0，_revenue：0.0；
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.38
     * @description
     * 有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。
     */
    /* SalesData(std::istream &istream=std::cin) { read(istream, *this); }*/
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习7.39
     * @description
     * 如果接受string的构造函数和接受istream&的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？
     */
    /* 不合法，这个时候重载构造函数将会不明确，存在二义性，编译器无法确认是选择使用string对象还是istream对象 */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习7.40
     * @description
     * 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
     * @code
     * (a) Book         (b) Date        (c) Employee
     * (d) Vehicle      (e) Object      (d) Tree
     */
    /*
     * 我选择a项。
     * 作为Book，其必然少不了ISBN编码、同时还可以加入单价、出版社、作者、版次等等
     * 那么数据成员可以有：_isbn、_unit_price、_publishing_house、_author、_edition_number。
     * 构造函数可以有：
     * Book(std::istream& is){read(is,*this);}
     * Book(std::string bookNo,unsigned long price,std::string house,std::string author,std::string number):
     *     _isbn(bookNo),_unit_price(price),_publishing_house(house),_author(author),_edition_number(number){};
     * Book(std::string bookNo,unsigned long price,std::string house,std::string author="xxx",std::string number):
     *     *     _isbn(bookNo),_unit_price(price),_publishing_house(house),_author(author),_edition_number(number){};
     * */
    static void meaninglessFunction_5();

    /**
     * @title
     * 7.5.2节练习
     */

    /**
     * @title
     * 练习7.41
     * @description
     * 使用委托构造函数重写编写你的Sales_data类，给每个构造函数体添加一条语句，令其一旦执行就打印这条信息。
     * 用各种可能的方式分别创建Sales_data对象，认真研究每种输出的信息直到确实理解了构造函数的执行顺序。
     */
    /* 具体查看include/sales_data_private.hpp文件 */
    static void exercise_7_41();

    /**
     * @title
     * 练习7.42
     * @description
     * 对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。
     * 如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
     */
    /*
     * 构造函数可以写成：
     * Book(std::string bookNo,unsigned long price,std::string house,std::string author,std::string number):
     *     _isbn(bookNo),_unit_price(price),_publishing_house(house),_author(author),_edition_number(number){};
     * Book():Book("",0,"","",""){};
     * Book(std::istream& is):Book(){read(is,*this);}
     * Book(std::string bookNo,unsigned long price,std::string house,std::string author="xxx",std::string number):
     *     Book(bookNo,price,house,author,number){};
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 7.5.3节练习
     */

    /**
     * @title
     * 练习7.43
     * @description
     * 假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。
     * 定义类C,C有一个NoDefault类型的成员，定义C的默认构造函数。
     */
    static void exercise_7_43();

    /**
     * @title
     * 练习7.44
     * @description
     * 下面这条声明合法吗？如果不，为什么？
     * vector<NoDefault> vec(10);
     */
    /* 不合法，NoDefault没有默认构造函数，无法对NoDefault进行值初始化 */
    static void meaninglessFunction_7();

    /**
     * @title
     * 练习7.45
     * @description
     * 如果在上一条练习中定义的vector的元素类型是C,则声明合法吗？为什么？
     */
    /* 合法，C类具有默认构造函数 */
    static void meaninglessFunction_8();

    /**
     * @title
     * 练习7.46
     * @description
     * 下面哪些论断是不正确的？为什么？
     * @code
     * (a) 一个类必须至少提供一个构造函数
     * (b) 默认构造函数是参数列表为空的构造函数
     * (c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数
     * (d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值
     */
    /* TODO 23-7-14 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数？对与否 */
    /*
     * a. 错误，类可以存在一个构造函数不写，类隐式提供默认构造函数
     * b.
     * 错误，如果一个构造函数在初始化列表中包含该类的所有数据成员并且都提供默认值，则该构造函数也可以被认为是默认构造函数
     * c.
     * 错误，在正常的情况下都应该为类提供默认值，哪怕其默认值没有意义（但是，在这里我认为存在争议，在我看来既然默认值没有意义，那么该默认构造函数还有意义吗？）
     * d. 错误，当类没有显式定义构造函数时，编译器才会隐式生成一个默认构造函数
     * */
    static void meaninglessFunction_9();

    /**
     * @title
     * 7.5.4节练习
     */

    /**
     * @title
     * 练习7.47
     * @description
     * 说明接受一个string参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。
     */
    /*
     * 在接受一个string参数的Sales_data构造函数是否应该是explicit的问题上，取决于对该构造函数的用途和设计要求的理解。
     *
     * 显式构造函数：
     *   如果设计要求Sales_data类的用户明确地使用Sales_data类的构造函数来创建对象，而不仅仅是通过对字符串的隐式转换来构造对象，
     *   那么接受string参数的构造函数应该是explicit的。
     *   显式构造函数可以防止通过隐式转换来构造对象，从而提高代码的可读性和明确性，避免了可能的隐式转换带来的错误。
     * 隐式构造函数：
     *   如果设计要求接受string参数的构造函数应该能够隐式地将字符串转换为Sales_data对象，那么构造函数应该是隐式的（默认情况下也是隐式的）。
     *   隐式构造函数允许通过隐式类型转换来构造对象，使得代码更加简洁和自然。它可以在没有显式类型转换的情况下将字符串参数传递给构造函数。
     *   缺点：可能引起一些不必要的隐式类型转换，使得代码更加复杂和难以理解。
     *   同时，如果存在其他参数或需要执行其他操作来构造Sales_data对象，而用户没有意识到需要显式类型转换，可能会导致错误的结果。
     *
     * 综上所述，接受一个string参数的Sales_data构造函数的显式或隐式选择取决于设计要求和对构造函数用途的理解。
     * 如果需要明确地使用构造函数来创建对象并提高代码的可读性和明确性，那么应该选择显式构造函数。
     * 如果希望通过隐式类型转换来构造对象并保持代码的简洁性，那么可以选择隐式构造函数。
     */
    static void meaninglessFunction_10();

    /**
     * @title
     * 练习7.48
     * @description
     * 假定Sales_data的构造函数不是explicit的，则下述定义将执行什么样的操作？
     * 如果Sales_data的构造函数是explicit的，又会发生什么呢？
     * @code
     * 1| string null_isbn("9-999-99999-9");
     * 2| Sales_data item_1(null_isbn);
     * 3| Sales_data item_2("9-999-99999-9");
     */
    /*
     * 如果不是explicit：
     * 2处语句：通过仅存在一个string实参的构造函数创建一个Sales_data对象。
     * 3处语句：首先编译器通过获得string类型对象自动创建一个Sales_data对象，将这个临时Sales_data对象传递item_2对象。
     * 如果是explicit：
     * 2处语句正常执行
     * 3处语句错误，explicit已经抑制了构造函数定义的隐式转换
     * */
    static void meaninglessFunction_11();

    /**
     * @title
     * 练习7.49
     * @description
     * 对于combine函数的三种不同声明，当我们调用i.combine(s)时分别发生什么情况？其中i是一个Sales_data，而s是一个string对象。
     * @code
     * (a) Sales_data &combine(Sales_data);
     * (b) Sales_data &combine(Sales_data&);
     * (c) Sales_data &combine(const Sales_data&) const;
     */
    /*
     * a. 合法，通过构造函数将string类型隐式转换为Sales_data类型
     * b. 不合法，因为隐式转换中间量是一个临时对象，非常量引用无法引用临时对象，可以修改为combine(const Sales_data&);
     * c.
     * 不合法，由于combine函数作用是将两个Sales_data对象相结合并返回一个Sales_data对象，如果成员函数为const，那么*this为const，无法进行结合
     * */
    static void meaninglessFunction_12();

    /**
     * @title
     * 练习7.50
     * @description
     * 确定在你的Person类中是否有一些构造函数应该是explicit的
     */
    /* 具体查看include/person.hpp文件 */
    static void meaninglessFunction_13();

    /**
     * @title
     * 练习7.51
     * @description
     * vector将其单参数的构造函数定义成explicit的，而string则不是，你觉得原因何在？
     */
    /*
     * 向量（vector）和字符串（string）是C++标准库中的两个重要容器类型，它们在参数传递和构造函数定义上的不同之处可以从以下几个方面解释：
     *
     * 类型安全：
     * explicit关键字可以防止无意间进行隐式转换。对于向量，将其单参数的构造函数定义为explicit可以防止在无意间将一个不同类型的值转换为向量类型。
     * 例如，如果将一个整数隐式地传递给一个接受向量的构造函数，如果没有使用explicit定义，编译器将自动进行转换，这可能导致出乎意料的结果。
     * 而对于字符串，这种类型的转换通常是有意义的，因此没有将其构造函数定义为explicit。
     *
     * 语义清晰：
     * 向量是一个存储相同类型元素的容器，将构造函数定义为explicit可以明确表示向量的类型，增强代码的语义清晰度。
     * 而字符串是一个存储字符序列的容器，构造函数接受一个字符数组或另一个字符串作为参数，这种转换是合理的，并且不会引起歧义。
     *
     * 性能考虑：
     * 将向量构造函数定义为explicit可以防止隐式转换，这可能会对性能产生一些影响。
     * 然而，对于字符串来说，隐式转换通常是合理的，并且不会对性能产生显著的影响。
     *
     * 综上所述，向量将其单参数的构造函数定义为explicit是为了提高类型安全性、代码清晰度和避免不必要的隐式转换。
     * 而字符串没有定义为explicit是为了保持其在参数传递和构造函数定义上的灵活性和可读性。
     */
    static void meaninglessFunction_14();

    /**
     * @title
     * 7.5.5节练习
     * @description
     * 使用 2.6.1节的Sales_data类，解释下面的初始化过程。如果存在问题，尝试修改它。
     * @code
     * Sales_data item={"978-0590353403",25,15.99};
     * 彩蛋：isbn对应的书为：《 Harry Potter and the Sorcerer's Stone 》
     */
    /*
     * 2.6.1节的Sales_data中units_sold和revenue两个数据成员均被类内初始化，需要删除掉类内初始化值
     * 修改为：
     * struct Sales_data{
     *     std::string     bookNo;
     *     unsigned        units_sold;
     *     double          revenue;
     * };
     * */
    static void meaninglessFunction_15();

    /**
     * @title
     * 7.5.6节练习
     */

    /**
     * @title
     * 练习7.53
     * @description
     * 定义你自己的Debug
     */
    static void exercise_7_53();

    /**
     * @title
     * 练习7.54
     * @description
     * Debug中以set_开头的成员应该被声明成constexpr吗？如果不，为什么？
     */
     /* 在C++11中，constexpr成员函数将会隐式成为const，无法修改数据成员，所以不应该声明 */

    /**
     * @title
     * 练习7.55
     * @description
     * 7.5.5节的Data类是字面值常量类吗？请解释原因。
     */
     /* 不是，std::string类型不是字面值类型 */
};

#endif  // CPP_PRIMER_STUDYING_7_5_HPP
