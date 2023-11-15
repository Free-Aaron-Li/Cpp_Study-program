# 第十一章 关联容器

## 前言

关联容器和顺序容器有着本质的不同：关联容器中的元素是按关键字来保存和访问的。与之相对，顺序容器中的元素是按它们在容器中的位置来顺序保存和访问的。(MySQL中元素就是按照关联容器进行保存）

关联容器支持高效的关键字查找和访问。两个主要的**关联容器**（associative-container）类型是map和set。

map中元素以[关键字-值]（key-vale）方式存在，关键字起到索引的作用，值则表示与索引相关联的数据。

set中元素仅包含一个关键字，其支持高效的关键字查询操作。

标准库提供8个关联容器：

| 按关键字有序保存元素 |        解释        |
|:----------:|:----------------:|
|    map     | 关联数组：保存`关键字-值`对  |
|    set     | 关键字即值，即只保留关键字的容器 |
|  multimp   |   关键字可重复出现的map   |
|  multiset  |   关键字可重复出现的set   |

|        无序集合        |          解释           |
|:------------------:|:---------------------:|
|   unordered_map    |      用哈希函数组织的map      |
|   unordered_set    |      用哈希函数组织的set      |
| unordered_multimap | 用哈希函数组织的map：关键字可以重复出现 |
| unordered_multiset | 用哈希函数组织的set：关键字可以重复出现 |

以上的8个容器的不同体现在三个维度：

1. 每个容器要么是map,要么是set
2. 容器要求要么是不重复的关键字，要么允许重复关键字
3. 容器按照要么按照顺序存储，要么以无序存储

> map与multimap定义在`map`头文件中；set和multiset定义在`set`头文件中；无序容器定义在`unordered_map`和`unordered_set`中。

## 11.1 使用关联容器

简单举例：

map类型通常被称为<b>关联数组</b>（associative array）。与一般数组类似，只不过其下标为关键字。例如：给定一个名字到电话号码的map，我们可以使用一个人的名字作为下标来获取此人的电话号码。

set本质就是关键字的**简单集合**。

#### 使用map

示例：

```cpp
#include <iostream>
#include <string>
#include <map>

int main(){
    std::map<std::string,std::size_t> word_count;
    std::string word;
    while(std::cin>>word)
        ++word_count[word];
    cout<<"\n";
    for(const auto& w : word_count)
        std::cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times\n":" time\n");
    return 0;
}
```

> RUN
>
> ```cpp
> $ g++ -o main -g main.cpp
> $ ./main
> hello world !
> this is good !
> this is bad !
> 
> ! occurs 3 times
> bad occurs 1 time
> good occurs 1 time
> hello occurs 1 time
> is occurs 2 times
> this occurs 2 times
> world occurs 1 time
> ```

在上述示例代码中，map保存的每个元素中，关键字类型为`std::string`，值类型为`std::size_t`。 该示例中，将一个string作为下标，与此string相关联的size_t类型作为计数器。

当我们从map中**提取**一个元素时，会得到一个pair类型的对象。pair是一个模板类型，保存两个数据成员（first和second）。map所使用的pair用first成员保留关键字，second成员保存对应的值。

#### 使用set

对于上面的扩展：合理忽略一些常见单词，如“the”、“and”、“or”、“is”等。

```cpp
#include <iostream>
#include <string>
#include <map>
#include <set>

int main(){
    std::map<std::string,std::size_t> word_count{};
    std::set<std::string> exclude{  "The","But","And","Or","An","A","Is","!",
                                    "the","but","and","or","an","a","is"};
    std::string word;
    while(std::cin>>word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    std::cout<<"\n";
    for(const auto& w : word_count)
        std::cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times\n":" time\n");
    return 0;
}
```

> RUN
>
> ```cpp
> $ g++ -o main -g main.cpp
> $ ./main
> hello world !
> this is bad !
> this is good 
> 
> bad occurs 1 time
> good occurs 1 time
> hello occurs 1 time
> this occurs 2 times
> world occurs 1 time
> ```

调用find函数会返回一个迭代器，如果找到word迭代器指向该关键字，否则返回一个尾后迭代器。

## 11.2 关联容器概述

常规的[容器操作](../../ChapterNine_SeqContainer/docs/ChapterNine_顺序容器.md#92-容器库概览) 关联容器能够支持，但是，对于顺序容器位置相关的操作（如：push_front、push_back）、插入操作等不支持。

关联容器的迭代器都是双向的。

### 定义关联容器

每个关联容器都定义了一个默认构造函数，它创建一个指定类型的空容器。

初始化关联容器必须能够将初始化器转换为容器中元素的类型。特别的：初始化map,必须提供关键字类型和值类型，且将每个关键字——值对包围在花括号中。

示例：

```cpp
// 空容器
std::map<std::string,std::size_t> word_count;
// 列表初始化
std::set<std::string> filter = { "The","But","And","Or","An","A","Is","!",
                                 "the","but","and","or","an","a","is"};
// map初始化
std::map<std::string,std::string> authors = {   {"Joyce","James"},
												{"Austen","Jane"},
												{"Dickens","Charles"}};
```

#### 初始化multimap或multiset

对于map和set来说，对于一个给定的关键字，只能有一个元素的关键字等于它。但是，对于multimap和multiset则没有此限制。例如：在统计单词数量时，每个单词最多拥有一个元素。但在词典中，特定单词可能含有多重释义。

示例：

```cpp
#include <iostream>
#include <set>
#include <vector>

int main(){
    std::vector<int> i_vec;
    for(std::vector<int>::size_type i=0;i!=10;++i){
        i_vec.push_back(i);
        i_vec.push_back(i);
    }
    std::set<int> i_set(i_vec.cbegin(),i_vec.cend());
    std::multiset<int> i_mset(i_vec.cbegin(),i_vec.cend());

    std::cout<<"vector size: "<<i_vec.size()<<" set size: "
        <<i_set.size()<<" multiset size: "<<i_mset.size()<<"\n";
}
```

> RUN
>
> ```cpp
> $ g++ -o main -g main.cpp
> $ ./main
> vector size: 20 set size: 10 multiset size: 20
> ```

在上述示例中，multiset允许重复关键字。

### 关键字类型的要求

关联容器对关键字类型有一些限制。对于有序容器（这里及以下均指代关联有序容器）来说关键字类型必须定义元素比较的方法，默认情况下，标准库使用关键字类型的<运算符来比较两个关键字。

#### 有序容器的关键字类型

与算法类似，有序容器也可以通过自定义操作替代关键字的<运算符。但是必须遵循**严格弱序
**（strict weak ordering）。可以将严格弱序看作“小于等于”，其必须具备如下性质：

- 两个关键字不能同时“小于等于”对方；如果k1“小于等于”k2,那么k2绝不能“小于等于”k1。
- 如果k1“小于等于”k2,且k2“小于等于”k3,那么k1必须“小于等于”k3。
- 如果存在两个关键字，任何一个都不“小于等于”另一个，那么我们称这两个关键字是“等价”的。如果k1“等价于”k2,且k2“等价于”k3,那么k1必须“等价于”k3。

如果两个关键字是等价的，那么容器将它们视为相等来处理。

> 在实际编程中，重要的是，如果一个类型定义了“行为正常”的<运算符，则它可以用作关键字类型。

**如果选择自定义操作，则必须在定义关联容器类型时提供此操作的类型**，自定义操作类型必须在尖括号中紧跟着元素类型。

### pair类型

pair：标准库类型，定义在`utility`头文件中

一个pair保存两个数据成员，类似容器。pair作为一个模板用来生成特定类型。创建一个pair,必须提供两个类型名（不要求一致），pair的数据成员将具有对应的类型。

pair的默认构造函数对数据成员进行值初始化，当然可以手动提供初始化器。
示例：

```cpp
std::pair<std::string,std::string> a;
std::pair<std::string,std::size_t> b;
std::pair<std::string,std::string> c{"hello","world"};
```

pair的数据成员为public,其成员分别命名为first和second。

详细操作：

|        pair上的操作        |                       解释                        |
|:----------------------:|:-----------------------------------------------:|
|     pair<T1,T2> p;     |        p是一个pair,两个类型分别为T1和T2的成员都进行了值初始化         |
|  pair<T1,T2> p(v1,v2)  | p是一个成员类型为T1和T2的pair；first和second成员分别用v1和v2进行初始化 |
| pair<T1,T2> p={v1,v2}; |                   等价于p(v1,v2)                   |
|    make_pair(v1,v2)    |     返回一个用v1和v2初始化的pair。pair的类型从v1和v2的类型推断出来     |
|        p.first         |              返回p的名为first的（公有）数据成员               |
|        p.second        |              返回p的名为second的（公有）数据成员              |
|   p1==p2<br/>p1!=p2    | 当first和second成员分别相等时，两个pair相等。相等性判断利用元素的==运算符实现 |

## 11.3 关联容器操作

| 关联容器额外的类型别名 |                              解释                               |
|:-----------:|:-------------------------------------------------------------:|
|  key_type   |                          此容器类型的关键字类型                          |
| mapped_type |                      每个关键字关联的类型；只适用于map                       |
| value_type  | 对于set,与key_type相同<br/>对于map,为pair<const key_type,mapped_type> |

需要注意到：对于value_type,我们不能改变一个元素的关键字，所以这些pair的关键字部分是const的。

```cpp
set<std::string>::key_type v1; // string
set<std::string>::value_type v2; // string
map<std::string,int>::key_type v3; // string
map<std::string,int>::mapped_type v4; // int
map<std::string,int>::value_type v5; // pair<const string,int>
```

### 关联容器迭代器

对于解引用一个关联迭代器时，我们会得到一个类型为容器的value_type的值的引用。

```cpp
map<std::string,std::size_t> word_count;
auto map_iter=word_count.begin(); // 指向pair<const string,size_t>对象的引用
std::cout<<map_iter->first; // string
std::cout<<" "<<map_iter->second; // size_t
map_iter->first="new key"; // error
++map_iter->second; // true
```

虽然set类型同时定义了iterator和const_iterator类型，但是两种类型都只允许只读访问set中的元素。一个set中的关键字也是const。

在进行常规编历时，使用迭代器进行遍历一个map、multimap、set和multiset时，迭代器按照**关键字升序**遍历元素。

示例：

```cpp
#include <iostream>
#include <iterator>
#include <map>

int main(){
    std::map<std::string,int> word_count{{"c",1},{"b",2},{"a",3}};
    auto map_iter=word_count.cbegin();
    while(map_iter!=word_count.cend()){
        std::cout<<map_iter->first<<" "<<map_iter->second<<"\n";
        ++map_iter;
    }
}
```

> RUN
>
> ```cpp
> $ g++ main.cpp
> $ ./a.out
> a 3
> b 2
> c 1
> ```

通常来说，不会对关联容器使用泛型算法。在实际编程中，如果我们真要对一个关联容器使用算法，要么是将它当作一个<b>源序列</b>，要么当作一个<b>目的位置</b>。例如：使用泛型copy算符拷贝一个关联容器到另一个序列，或是使用inserter将一个插入器绑定到一个关联容器，依次将关联容器当作一个目的位置来调用另一个算法。

### 添加元素

关联容器中insert成员会向容器中添加一个元素或一个元素范围。insert有两个版本，「1」接受一对迭代器，「2」接受一个初始化列表。

```cpp
set_1.insert(vec.cbegin(),vec.cend());
set_2.insert({1,2,3,4});
```

对于map、set极其对应的无序列表来说，对于一个给定的关键字，只有第一个带此关键字的元素才能被插入到容器中。

示例：

```cpp
#include <iostream>
#include <iterator>
#include <map>

int main(){
    std::map<std::string,int> word_count{{"c",1},{"b",2},{"a",3}};
    word_count.insert({"c",4});
    auto map_iter=word_count.cbegin();
    while(map_iter!=word_count.cend()){
        std::cout<<map_iter->first<<" "<<map_iter->second<<"\n";
        ++map_iter;
    }
}
```

> ```cpp
> $ g++ main.cpp
> $ ./a.out
> a 3
> b 2
> c 1
> ```

#### 向map添加元素

向map插入元素，注意元素类型为pair。

```cpp
map_1.insert({1,2});
map_2.insert(std::make_pair(1,2));
map_3.insert(std::pair<int,int>(1,2));
map_4.insert(std::map<int,int>::value_type(1,2));
```

|  关联容器insert操作   |                      解释                       |
|:---------------:|:---------------------------------------------:|
|   c.insert(v)   |        v是value_type类型的对象；args用来构造一个元素         |
| c.emplace(args) | 对于map和set,只有当元素的关键字不在c中时才插入（或构造）元素。函数返回一个pair |

