## 第10章

## 前言

在前面我们学习容器的时候，是否发现标准库下的对容器的操作并不是太多（或许，初学时已经觉得好多了😅），其实C++将大量的功能操作集成在泛型算法中。泛型（generic），即通用，意为其独立于任何特定的容器，操作于不同类型的容器和不同类型的元素。

回想一下，在学习顺序容器的过程中，我们学习了哪些容器操作？

添加、删除容器元素；容器是否为空；获取容器元素的迭代器；访问首尾元素；

以上的操作仅仅只是对容器的基础操作，我们并不满足。有时候我们希望能够对容器进行排序、搜索、替换等等操作。如果对每个特定的容器都设置对应的操作算法，这显然会使得对容器的操作变得复杂、杂乱。所以，这就是为什么容器仅提供少量的操作，因为标准库将大量的操作进行集合，形成泛型算法。

---

## 10.1 概述

大多数的算法都定义在`algorithm`中，其中在`numeric`头文件中定义了一组数值泛型算法。

算法是如何独立于特定的容器的呢？回想一下，每个容器都存在迭代器，通过迭代器我们可以自由访问、操作容器。所以，实际上算法并不会直接操作容器，而是通过迭代器
**间接**操作容器。

例如，find算法（用于查找某项值），其算法便是通过迭代器指定一个元素范围，通过**遍历**范围进行查找。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vector{1,2,3,4,5,6,7};
    int value=2;
    auto result=std::find(vector.cbegin(),vector.cend(),value);
    std::cout   << "The result "<< value <<" "
                << (result==vector.cend()? "does not exist in this vector":"does exist in this vector")
                << std::endl;
}
```

从上例中，我们可以看出，find算法是直接操作迭代器，所以除了可以使用find算法查找vector中元素，我们还可以查找string中的元素，甚至是内置数组中元素。

```cpp
// find character
std::string str("hi good morning!");
char value('h');
auto result=std::find(str.cbegin(),str.cend(),value);

// find number
int assemble[]={1,2,3,4,5,6,7};
int value=3;
int *result=std::find(std::begin(assemble),std::end(assemble),value);
```

### find算法的工作原理

1. 访问序列中的首元素
2. 比较此元素与目标元素
3. 与目标元素匹配，返回标识此元素的值
4. 若没有匹配，find查找下一个元素，重复步骤2和3
5. 若到达序列尾，find停止
6. 若到达序列尾，依旧没有找到目标元素，返回指出元素未找到的值。且此值和步骤3中返回值具有相容类型

从上面步骤我们可以看出，find算法在所有步骤上都**不依赖**容器中所保存的元素类型。因此，只要通过迭代器访问元素，find算法就完全不依赖容器类型，甚至无需理会其是否是不是容器。

但是，虽然通过迭代器算法不依赖于容器，但是算法**依赖于元素类型的操作
**。这听起来挺奇怪的，为什么呢？正像上面例子一样，`result==vector.cend()`，find算法在实际运行中，使用`==`运算符对元素进行判断。类似于find，大多数算法都会使用到一个（或者多个）元素类型的操作，所以算法依赖于元素类型的操作，但并不依赖于容器。

### 算法永远不会执行容器操作

**泛型算法本身不会执行容器的操作，它们指挥运行于迭代器之上，执行迭代器的操作**。

正因为如此，算法永远不会改变底层容器的大小，算法可以删除、添加、移动容器中的元素，但其都是基于迭代器实现，算法本身并不会做出这样的操作。

## 10.2 初识泛型算法

在标准库中存在100余种算法，想要通过死记的方式显然是困难的。但是这些算法都具有一致的结构（也就是统一原则），通过理解此结构无疑是事半功倍。

大多数的标准库算法都是对一个范围的元素（即“输入范围”）进行操作。如前面所学的find算法，接受输入范围的算法总是通过前两个参数（一般是两个表示指向范围边界元素的迭代器）表示此范围。

大多数标准库算法对输入范围的遍历类似（一般结构），只不过对范围内的元素操作不同。

### 只读算法

如其名，某些算法仅读取输入范围中的元素，并不会改变元素，则成为只读算法。如我们在前面所学到的find和count算法。下面我们继续学习两个只读算法：用于求和的accumulate算法和用于比较两序列的equal算法。

#### accumulate算法

该算法定义在`numeric`头文件中。其接受三个参数，前两个参数确定输入范围，第三个参数作为和的初值。第三个参数类型*
*决定函数该使用哪种加法运算符以及返回值类型**。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

int main(){
    std::vector<int> assemble{1,2,3,4,5,6,7};
    int sum=std::accumulate(assemble.cbegin(),assemble.cend(),0);
    std::cout << "the sum for assemble is :"<<sum << std::endl;
}
```

accumulate算法中第三个参数作为求和起点，正如上面所描述的代码，其蕴含一个编程**假设
**：该第三参数类型必须能够与输入范围内元素相加，也就是必须能与之匹配（或者转换）。如：输入范围内元素类型为int，那么第三参数类型可以为double、long long等等。

另外一个例子：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

int main(){
    std::vector<std::string> assemble{"hello ","world! ","welcome ","to ","new ","home!"};
    std::string sum=std::accumulate(assemble.cbegin(),assemble.cend(),std::string(""));
    std::cout << "the sum for assemble is :"<<sum << std::endl;
}
```

第三参数定义为`string("")`，那么其实就告诉accumulate算法我的初值是string类型的空串，我要将vector中string类型元素加起来，并且返回为string。

那么为什么第三参数不直接写成`""`，首先在学习string时我们知道`""`是一个字符串字面值，其不能作为第一参数与其他string类型的字符串相加。因为字符串字面值其类型为`const char*`，该类型并没有“+”运算符，怎么能够相加呢？（但是我们可以这样`string+const char*`，这是为C做出的妥协）

#### equal算法

equal，译为平等。该算法作用为比较两个序列是否相等。同样该算法具有三个参数，前两个参数用于确定第一个序列的输入范围，第三个参数则用于确定第二个序列的首元素。

这里同样存在一个隐含编程假设：那就是**假设第二序列的长度至少和第一序列长度一样长**，或者更长，因为equal算法仅确定第二序列的首元素，并没有确定其尾元素。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){
    std::vector<int> vector_1{1,2,3};
    std::vector<int> vector_2{1,2,3};
    bool result=std::equal(vector_1.cbegin(),vector_1.cend(),vector_2.cbegin());
    std::cout << (result==true?"there two vector is equal":"there two vector isn't equal") << std::endl;
}
```

> 迭代器参数
>
> 1. 算法仅要求能够比较两个序列中的元素，并不会对序列属于那种类型做出要求，同时也不会严格要求两比较序列中元素相同。
> 2. 在操作两个序列的算法中，如果某些算法仅接受三个迭代器，那么默认前两个参数确定第一序列的元素范围，第三个参数确定第二个序列中的首元素。如果接受四个迭代器，则前两个参数确定第一个序列元素范围，后两个参数确定第二个序列的元素范围。
> 3. 仅接受单一迭代器表示第二个序列的算法都**假定**第二个序列至少和第一个序列一样长，算法并不做出保证（这是程序员的责任）。

一个很有趣的现象是在完成10.5练习题时，会发现equal算法其实对“==”运算符做了重载，所以无论是对string还是C风格字符串进行比较都是可行的。

在早些版本的标准库中，equal算法并不能对C风格字符串中元素进行比较，其比较的是指针位置。

### 写容器元素的算法

一些算法会将新值赋予序列中的元素（注意：不是改变容器的大小，所以赋予新值数目必定会比原容器中元素数目小，或者相等）。

这些算法本质上仅仅改变容器中已存在的元素，不会越界所以并不危险。

例如，fill（填满）算法就是将第三参数替换输入范围内所有元素。

```cpp
#include <vector>
#include <list>
#include <string>
#include <iostream>

int main(){
    std::vector<int> vector{1,2,3,4,5,6,7};
    std::fill(vector.begin(),vector.end(),0);
    for(auto const &c:vector)
        std::cout << c << " ";
}
```

#### 算法不检查写操作

如标题所言，算法在执行过程中都会假定参数是正确的，例如：fill_n算法（其接受一个目的位置，并向该序列中赋予指定数目的新值）。

```cpp
#include <vector>
#include <list>
#include <string>
#include <iostream>

int main(){
    std::vector<int> vector(10);
    // 向vector序列中赋予10个1
    std::fill_n(vector.begin(),10,1);
    for(auto const &c:vector)
        std::cout << c << " ";
}
```

在上面的代码中，我们写明了vector容器中含有10个元素，但是假如我们将vector设置为空呢：

```bash
 './main' terminated by signal SIGSEGV (Address boundary error)
```

g++给出如上的提示，告诉我们越界了，说明fill_n算法执行（同样说明算法并不会检查写操作）。

#### 介绍back_inserter

在前面我们学习的迭代器都是为了指向一个确切元素，但是显然在某些情况下并不能满足实际需求，这个时候我们就需要使用到
**插入迭代器**（insert_iterator）。插入迭代器的目的就是向容器中添加元素。

使用插入迭代器，我们需要通过**back_inserter**函数，其定义在iterator文件中。

back_inserter接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器。当向此迭代器赋值时，赋值运算符会调用push_back将一个具有个顶值的元素添加到容器中。

```cpp
#include <vector>
#include <iostream>
#include <iterator>

int main(){
    std::vector<int> vector;
    auto insert_iterator=std::back_inserter(vector);
    insert_iterator=12;
    for(auto const &c:vector)
        std::cout << c << " ";
}
```

回到我们所讨论的fill_n算法，由于无法通过`vec.begin()`作为目的位置为空容器进行写操作，那么这个时候我们就需要通过back_inserter函数来创建一个迭代器，作为算法的目的位置使用。

```cpp
#include <vector>
#include <iostream>
#include <iterator>

int main(){
    std::vector<int> vector;
    std::fill_n(back_inserter(vector),10,1);
    for(auto const &c:vector)
        std::cout << c << " ";
}
```

每次迭代，back_inserter返回的插入迭代器都会调用push_back成员在容器末尾添加指定函数。

#### 拷贝算法

拷贝（copy）算法作用便是向另一个指定目的位置的迭代器所指向输出序列中的元素中写入数据。

该算法接受三个迭代器，所以隐含被拷贝对象的长度至少比输入序列的长度长，或者相等。

```cpp
#include <iostream>

#include <vector>
#include <list>


int main(){
    std::vector<int> vector{1,2,3,4,5};
    std::list<int> list{0,9,8,7,6,5};

    auto post_tail=copy(vector.cbegin(),vector.cend(),list.begin());
    for(auto const &c:list)
        std::cout << c << " ";
}
```

copy算法返回其目的位置迭代器的值（当然，这个值是经过递增后的），即list的尾后迭代器。

在有些算法中，其“拷贝”版本，并不会将其放在输入序列的末尾，而是创建一个新序列保存。

如，replace算法，其本身是替换序列中元素。

```cpp
replace(vector.begin(),vector.end(),0,1);
```

将vector容器中所有值为0的元素替换为1

如果我们希望原序列不变，那么我们可以使用replace_copy算法。

```cpp
replace_copy(vector.cbegin(),vector.cend(),back_inserter(list),0,1)
```

通过`back_inserter`创建一个新序列，其原序列vector不变，拷贝一份vector中元素于list中，且其中值为0的元素被替换为1。

### 重排容器元素的算法

sort算法，其通过利用元素类型的<运算符实现排序。

unique算法，覆盖重复元素。

## 10.3 定制操作

在前面我们学到的算法大多使用到了元素类型的<或者=运算符进行元素比较。但是有些时候，我们希望自定义运算符，例如：当我们对未定义<运算符的元素类型进行比较。

### 向算法传递函数

**谓词**(predicate)

谓词是一个可调用的表达式，其返回结果是一个能用作条件的值。

标准库算法所使用的谓词分为两类：**一元谓词**(unary predicate) 和**二元谓词**(binary predicate)。

- 一元谓词：意味着它们是接受单一参数
- 二元谓词：意味着它们有两个参数

接受谓词参数的算法对输入序列中的元素调用谓词，因此，元素类型必须能够转换为谓词的参数类型。

### lambda表达式

无论是一元还是二元谓词，我们传递必须严格执行接受参数的数目，显然，在某些情况下这受到了限制。

例如，我们有一种需求：求大于等于一个给定的单词，打印符合要求的单词。

> 从要求，我们可以使用标准库中的find_if算法查找第一个具有特定大小的元素，接下来只需要设定好要求即可。但是如果我们使用谓词作为find_if算法的第三个参数，显然无法满足需求（因为需要对单词进行判断）。

这个时候，我们就需要使用lambda表达式！

在前面我们学过两种可调用对象：函数与函数指针，除此还有：重载了函数调用运算符的类与lambda表达式。

一个lambda表达式表示一个可调用的代码单元，可理解为内联函数。

> 一般的lambda表达式具有一个返回类型、一个参数列表和一个函数体
>
> 一般结构：
>
> [capture list\](parameter list)-> return type{function body}
>
> 示例：
> ```cpp
>   int  a = 10, b = 20;
>   auto c = [a, b](const int &c) -> int { return a + b + c; };
>   std::cout << "a + b + c = " << c(30) << "\n";
> ```
>
> 需要注意的是：
>   1. lambda必须使用尾置返回来指定返回类型
>   2. lambda可以忽略参数列表与返回类型，但是必须包含捕获列表和函数体
>   3. 如果忽略返回类型，那么lambda根据函数体中代码推断返回类型(默认为void)
>   4. lambda不能存在默认参数
>   5. 捕获列表只用于局部非static变量，lambda可以直接使用局部static变量和在它所在函数之外声明的名字

### lambda捕获和返回

当定义一个lambda时，编译器会生成一个与lambda对应的新的类类型。

所以，当lambda表达式捕获变量时，由此生成的类类型中也会包含对应于捕获变量的数据成员，且lambda的数据成员会随着lambda对象的创建时被初始化。

类似参数传递，变量的捕获也可以是值或者引用。

#### 值捕获

> 采用值捕获的前提是变量可以拷贝

与参数值传递不同的是，被捕获的变量的值是在lambda创建时拷贝，而不是在调用时拷贝。

```cpp
void function_1{
	size_t value=42;
    auto f=[value]{return value;}; // 将value拷贝到f可调用对象中
    value=0;
    auto j=f(); // j仍然为42，f保存了我们在创建它时value的拷贝
}
```

#### 引用捕获

当某些情况下，我们不能够拷贝捕获变量（如IO对象），那么我们就必须使用引用捕获。

与参数引用类似，

``````cpp
void function_2{
    size_t value=42;
    auto f=[&value]{return value;}; // 将value拷贝到f可调用对象中
    value=0;
    auto j=f(); // j仍然为0，f保存了value的引用，而非拷贝
};
``````

> 引用捕获和返回引用都有着相同的问题和限制。
>
> 如果采用引用方式捕获一个变量，就必须确保被引用对象在lambda执行的时候是存在的。

> 建议
>
> 尽量保持lambda的变量捕获简单化
>
> 一般来说，我们应该尽量减少捕获的数据量来避免潜在的捕获导致的问题。如果可能的话，应该避免捕获指针或引用。

#### 隐式捕获

编译器可以根据lambda体中的代码推断我们要使用哪些变量😊。为了指示编译器推断捕获列表，应该在捕获列表中写入&或者=，以表示编译器应该采用哪种捕获方式

例如：

``````cpp
// 隐式捕获
int sz=10;
auto a=[=](const string&s){return s.size()>=sz};
``````

我们还不满足，希望对一部分变来能够采用值捕获，对另外一部分采用引用捕获，可以混合显式与隐式捕获。

那么我们需要：

1. 捕获列表中的第一个元素必须是&或者=，以此指定默认捕获方式为引用还是值。
2. 显示捕获的变量必须使用与隐式捕获不同的方式。

例如：

```cpp
int a=10,b=20;
/* a为隐式捕获，引用捕获方式；b为显式捕获，值捕获方式 */
auto c=[&,b](const string&s){return s.size>=a+b;};
/* a为显式捕获，引用捕获方式；b为隐式捕获，值捕获方式 */
auto c=[=,&a](const string&s){return s.size>=a+b;};
```

综上所述，lambda捕获有一下方式：

|         lambda捕获列表         |                                                          解释                                                          |
|:--------------------------:|:--------------------------------------------------------------------------------------------------------------------:|
|             []             |                                    空捕获列表。lambda不能使用所在函数中的变量。一个lambda只有捕获变量后才能使用它们                                    |
|       [<i>names</i>]       |              <i>names</i>是一个逗号分隔的名字列表，这些名字都是lambda所在函数的局部变量。默认情况下，捕获列表中的变量**都被拷贝**。名字前如果使用了&，则采用引用捕获方式               |
|             &              |                                    隐式捕获列表，采用引用捕获方式。lambda体中所使用的来自所在函数的实体都采用引用方式使用                                    |
|            [=]             |                                       隐式捕获列表，采用值捕获方式。lambda体将拷贝所使用的来所在函数的实体的值                                        |
| [&,<i>identifier_list</i>] | <i>identifier_list</i>是一个逗号分隔的列表，包含0个或多个来自所在函数的变量。这些变量采用值捕获的方式，而任何隐式捕获的变量都采用引用方式捕获。<i>identifier_list</i>中的名字前面不能使用& |
| [=,<i>identifier_list</i>] |      <i>identifier_list</i>中的变量都采用引用方式捕获，而任何隐式捕获的变量都采用值方式捕获。<i>identifier_list</i>中的名字**不能包括this**,且这些名字之前必须使用&      |

#### 可变lambda

默认情况下，对于一个被值捕获的变量，是不会被修改的。但是如果希望修改，则需要在参数列表尾加上关键字mutable。

例如：

```cpp
size_t v1=42;
auto f=[v1]()mutable{return ++v1;};
v1=0;
auto j=f();
std::cout << j << std::endl;
return 0;
```

对于引用捕获的变量是否可以修改依赖于此引用指向的是一个const类型还是非const类型。

例如：

```cpp
size_t v1=42;
auto f=[&v1]{return ++v1;};
v1=0;
auto j=f(); // j为1
```




