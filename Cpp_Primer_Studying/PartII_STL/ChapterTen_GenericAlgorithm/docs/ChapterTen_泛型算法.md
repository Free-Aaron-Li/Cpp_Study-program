## 第10章

## 前言

在前面我们学习容器的时候，是否发现标准库下的对容器的操作并不是太多（或许，初学时已经觉得好多了😅），其实C++将大量的功能操作集成在泛型算法中。泛型（generic），即通用，意为其独立于任何特定的容器，操作于不同类型的容器和不同类型的元素。

回想一下，在学习顺序容器的过程中，我们学习了哪些容器操作？

添加、删除容器元素；容器是否为空；获取容器元素的迭代器；访问首尾元素；

以上的操作仅仅只是对容器的基础操作，我们并不满足。有时候我们希望能够对容器进行排序、搜索、替换等等操作。如果对每个特定的容器都设置对应的操作算法，这显然会使得对容器的操作变得复杂、杂乱。所以，这就是为什么容器仅提供少量的操作，因为标准库将大量的操作进行集合，形成泛型算法。

---

## 10.1 概述

大多数的算法都定义在`algorithm`中，其中在`numeric`头文件中定义了一组数值泛型算法。

算法是如何独立于特定的容器的呢？回想一下，每个容器都存在迭代器，通过迭代器我们可以自由访问、操作容器。所以，实际上算法并不会直接操作容器，而是通过迭代器**间接**操作容器。

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

但是，虽然通过迭代器算法不依赖于容器，但是算法**依赖于元素类型的操作**。这听起来挺奇怪的，为什么呢？正像上面例子一样，`result==vector.cend()`，find算法在实际运行中，使用`==`运算符对元素进行判断。类似于find，大多数算法都会使用到一个（或者多个）元素类型的操作，所以算法依赖于元素类型的操作，但并不依赖于容器。

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

该算法定义在`numeric`头文件中。其接受三个参数，前两个参数确定输入范围，第三个参数作为和的初值。第三个参数类型**决定函数该使用哪种加法运算符以及返回值类型**。

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

accumulate算法中第三个参数作为求和起点，正如上面所描述的代码，其蕴含一个编程**假设**：该第三参数类型必须能够与输入范围内元素相加，也就是必须能与之匹配（或者转换）。如：输入范围内元素类型为int，那么第三参数类型可以为double、long long等等。

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

这里同样存在一个隐含编程假设：那就是**假设第二序列的长度与第一序列长度一致**，因为equal算法仅确定第二序列的首元素，并没有确定其尾元素。

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




