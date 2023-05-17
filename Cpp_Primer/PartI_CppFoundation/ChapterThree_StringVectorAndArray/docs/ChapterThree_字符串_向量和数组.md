# 第三章 字符串、向量和数组

## 前言

标准库是C++必不可少的一部分，作为C++的延伸，标准库的优雅令人陶醉。

如标题所言，在这一章我们将要学习数组、字符串和向量。若学习过其他编程语言，相信对数组并不陌生。其作为固定存储序列，能够为我们提供很多数据结构的解决思路，但是其在灵活性方面的不足使之诞生向量：向量，给定类型对象的可变长序列。

同时，也会对字符串做一些解释。

---

## 3.1 命名空间的using声明

在之前的编写代码的过程中，对std并不陌生：

```cpp
std::cin;
std::cout;
```

“std”属于是命名空间，“::”作用域操作符则表明：编译器应该从操作符左侧名字所示的作用域中寻找右侧名字。

由于每次使用命名空间中的成员都需要显式添加“std::”，较为繁琐。所以C++提供一种方式：使用“using”声明（using declaration）。

其具体形式：`using namespace::name;`，例如：

```cpp
using std::cin; /* 当我们声明后，之后使用cin无需再添加std:: */
```

> 注意
>
> 头文件不应当包含using声明

---

## 3.2 标准库类型 string

string，字符串类型，是一种**可变长**的字符序列。

具体示例：

```cpp
string str_1;           /* 默认初始化，为空串 */
string str_2(str_1);    /* str_2为str_1的副本 */
string str_3=str_1;     /* 等价于str_2(str_1) */
string str_4("this");   /* str_4是字面值“this”的副本（删去字面值最后那个空字符）*/
string str_5="this";    /* 等价于str_4("this") */
string str_6(n,"this"); /* 将str_6初始化为由n个“this”组成的串 */
```

由上面示例可以看出，在string初始化上分为两种：

- “string str_1="1"”的方式称为**拷贝初始化**（copy initialization）
- “string str_1("1")”的方式称为**直接初始化**（direct initialization）

在设计类的时候，我们不光需要规定其初始化对象的方式，还需要定义对象上能够执行的操作。

在这方面，string有如下操作：

|         操作          |             作用             |
|:-------------------:|:--------------------------:|
|        os<<s        |      将s写到输出流os中，返回os       |
|        is>>s        | 从is中读取字符串赋给s，字符串以空白分隔，返回is |
|    getline(is,s)    |      从is中读取一行赋给s，返回is      |
|      s.empty()      |    s为空返回true，反之返回false     |
|      s.size()       |          返回s中字符个数          |
|        s[n]         |     返回s中第n个字符的引用，n从0开始     |
|        s1+s2        |     返回s1和s2的字符串合并的字符串      |
|        s1=s2        |      将s2的副替换s1中原本的字符       |
| s1==s2,!=,<,<=,>,>= |     s1与s2字符串做比较，大小写敏感      |

我们曾通过使用iostream中的标准输出/输出来读写内置类型，同样其也能用于对string类型的读写。

例如：

```cpp
std::string str;
std::cin>>str;
std::cout<<str;
```

需要注意的是：从标准输入流中读取到string对象时，string对象会删除开头空白，同时遇到空白结束读取。

参考上述代码，若输入流为：“ this ”，那么str的内容将是“this”。

若想要读取到空白字符，有两种方式：

```cpp
std::string str;
while (std::cin>>str){	/* 方式① */
	std::cout<<str;
	if (std::cin.get()=='\n')break;
}

while (getline(std::cin, str)){	/* 方式② */
	std::cout<<str;
}
```

> 补充
> 
> 关于“size()”函数，其返回值类型为“string::size_type”类型，可以将其理解为无符号整型数。
> 
> 注意关键点：无符号。所以“str.size()<n”，n为负整数，那么其结果判断几乎是true，因为n将自动转换一个较大的无符号值。（可以查看第二章的基本内置类型）
> 
> 同时注意，如果一个表达式中已经存在size()函数就不要再使用int，这样避免混用int和unsigned可能带来的问题。

关于string对象的对比规则，注意点：

- string对象的对比依赖于对大小写敏感的**字典顺序**
- 在对比两对象大小时，若二者字符相同，则进行串长度对比；若二者字符不同，则对比二者第一处相异字符大小。

例如：

```cpp
string str_1="this";
string str_2="this is good!";
string str_3="thity";
```

在上述例子中，str_1小于str_2，而str_3比str_1和str_2都大。 原因：

- 对比str_1和str_2，二者对比所有字符序列，满足较短者与较长者相同则比较长度，明显str_2更长。
- 将str_3与前两者做对比，“thi”序列都相同，比较“s”和“t”的大小，显然“t”更大，所以str_3大于前两者。

关于将字面值与string对象相加，存在一个注意事项：

我们运行将string对象与字面值相加，但是不允许仅存在字面值：`string str="this"+"is world"`这种方式是错误的！究其原因，“this”和“is world”都不是string对象，不允许相加。

同时，我们也不允许这样的用法：

```cpp
string str_1="word";
string str_2="this"+" is "+str_1;	/* 错误 */
```

其原因和上述的注意一样，我们可以这样看str_2的相加过程：`str_2=("this"+" is ")+str_1;`，这与上述错误一样！

> 补充
> 
> 或许在其他程序设计语言，例如python上可以使用字面值相加的方式为string类型赋值。但是由于历史原因与为了和C兼容，C++的字符串字面值并不是string对象。也就是说：字面值和string是两种类型！，这也就解释上述的注意点。









