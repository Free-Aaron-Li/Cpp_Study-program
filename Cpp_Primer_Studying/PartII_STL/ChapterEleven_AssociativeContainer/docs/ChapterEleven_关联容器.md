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
> $ gcc -o main -g main.cpp
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
> $ gcc -o main -g main.cpp
> $ ./main
> hello world !
> this is bad !
> this is good !
> 
> bad occurs 1 time
> good occurs 1 time
> hello occurs 1 time
> this occurs 2 times
> world occurs 1 time

```

调用find函数会返回一个迭代器，如果找到word迭代器指向该关键字，否则返回一个尾后迭代器。

