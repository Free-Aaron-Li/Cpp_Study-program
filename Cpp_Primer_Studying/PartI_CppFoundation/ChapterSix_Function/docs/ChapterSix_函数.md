# 第六章 函数

## 前言

何谓函数？

函数就是命了名的代码块😄。通过调用函数执行对应代码，实现目标效果。函数可以通过重载的方式，实现同一个名字多种实现。

介绍：

- 函数的定义
- 函数的声明
- 重载函数
- 编译器如何选择与之匹配的函数版本

---

## 6.1 函数基础

典型的函数：

```cpp
void test(int n){
    /* ... */
}

int main(){
    int x;      /* 实参 */
    test(x);    /* 调用函数 */
    return 0;   /* 返回值 */
}
```

`void`，返回类型（return type）；`test`函数名；`(int n)`，括号内存放形参（parameter），一个函数可以有0个或多个形参；`{}`
，函数体（function body）。

通过使用**调用运算符**（call
operator）来执行函数。调用运算符形式为一对括号，其作用于一个表达式（可以是函数也可以是指向函数的指针）；括号内用于存放实参（argument）列表，用于初始化函数的形参。调用表达式的类型就是函数的返回类型。

#### 函数调用

函数调用有两项任务：

- 实参初始化函数对应的形参
- 将控制权转移给被调函数

在函数中，return语句也有两项任务：

- 返回return语句中的值（如果有）
- 将控制权从被调函数转移到主调函数

函数的返回值一般用于初始化调用表达式的结果。

#### 形参和实参

- 实参是形参的初始值
- 没有规定实参的求值顺序，所以编译器能够以任意可行顺序对实参求值
- 实参的类型必须与形参类型匹配（不一定一致）
- 实参的数量必须与形参数量一致

#### 函数形参列表

函数的形参列表可以为空，但不能没有。😀

```cpp
/* 隐式定义空形参列表 */
void test_1(){ /* ... */}

/* 显式定义空形参列表 */
void test_2(void){/* ... */}
```

在通常情况下，直接写一个空的空格表示空形参列表。当然，为了与C语言兼容，也可以写一个void显式定义空形参列表。

每个形参都是含有一个声明符的声明，所以哪怕两个形参类型一致，都需要分开写出来。当然也保证每个形参名字都是独一无二的，且函数最外层作用域中的局部变量也不能和函数形参名一致。

```cpp
void test_3(int a,int b){ /* ... */}
```

#### 函数返回类型

如果返回类型为void，则表示不返回任何值。

函数无法返回数组类型或函数类型，但是可以返回数组指针或函数指针。

### 局部对象

> 补充
>
> 名字有作用域，对象有生命周期。
>
> - 名字的作用域是程序文本的一部分，名字在其中可见。
> - 对象的生命周期是程序执行过程中该对象存在的一段时间。

函数体本质上是一个语句块，其自构成一个作用域。形参和函数体内定义的变量称为*局部变量*（local
variable）。局部变量自身具有“隐藏性”，对局部变量而言，在外层作用域的同名的所有声明都是隐藏的。

关于局部变量的生命周期，其依赖于定义方式。

#### 自动对象

对当函数的控制路径经过变量定义语句时创建该对象，当到达定义所在的块末尾时销毁它。只存在与块执行期间的对象称为*自动对象*
（automatic object）。当块执行结束后，块中创建的自动对象的值就变成未定义的。

对于局部变量对应的自动对象来说，分为两种情况：

- 如果变量定义本身含有初始值，就使用该初始值初始化
- 如果变量定义不含初始值，执行默认初始化

那么存在这种情况：内置类型的未初始化局部变量就会产生未定义的值。

![内置类型-未定义](https://s3.bmp.ovh/imgs/2023/06/09/8ddbc126accc5ad1.png)

#### 局部静态变量

对于哪些希望函数结束，函数内定义的变量依旧有效，那么便可以使用*局部静态对象*（local static object）。

如果局部静态变量没有显式的初始值，那么该对象将执行值初始值。

### 函数声明

函数名字必须在使用前声明（这似乎是常理😉）。

函数的声明用于函数的定义类似，唯一区别在于函数无需函数体，用分号代替。

函数声明可以不用写形参的名字（笔者我之前就经常忽略形参的名字，但这并不是个好习惯。现在使用CLion编写时，一般编写函数声明，再由CLion自动生成函数定义头部）。但是，写上形参的名字还是有好处的，它可以帮助使用者更好地理解函数的功能。

**函数三要素**:

- 返回类型
- 函数名
- 形参类型

函数的三要素已经就可以描述函数的接口了，能够说明该函数所需的全部信息。因此，函数声明也被称为*函数原型*（function prototype）。

#### 在头文件中进行函数声明

函数声明应该存放在头文件中，同时函数定义应该在源文件中。

*含有函数声明的头文件应该被包含到定义函数的源文件中*。

### 分离式编译

分离式编译（separate compilation），其编译允许我们把程序分割到几个文件中去，每个文件独立编译。

这里使用Linux平台下的GCC下的g++（GUN C++ Compiler）编译器完成分离式编译：

首先创建三个文件：`fact.cpp`、`factMain.cpp`和`Chapter6.hpp`，`fact.cpp`文件用于存放fact函数的定义;`factMain.cpp`
文件用于存放main函数并调用fact函数；`Chapter6.hpp`文件用于存放fact函数声明和导入iostream库。

下面给出文件内容：

Chapter6.hpp

```cpp
#ifndef CHAPTER6_HPP
#define CHAPTER6_HPP

#include <iostream>

int fact(int value);

#endif // !CHAPTER6_HPP
```

fact.cpp:

```cpp
#include "Chapter6.hpp"

int fact(int value){
  return value;
}
```

factMain.cpp:

```cpp
#include "Chapter6.hpp"
#include <cstdlib>
#include <iostream>

int main(){
  int value=10;
  std::cout<<fact(value)<<"\n";
}
```

编译过程：

①、使用g++编译器编译fact.cpp和factMain.cpp生成中间代码文件：

```bash
$ g++ -c fact.cpp && g++ -c factMain.cpp
```

②、使用g++将中间代码文件链接在一起形成可执行文件：

```bash
$ g++ fact.o factMain.o -o main
```

③、执行可执行文件，得到结果：

```bash
$ ./main
10
```

这个时候，查看当前文件夹下，应该存在如下文件：

```bash
$ ls
Chapter6.hpp  fact.cpp  factMain.cpp  factMain.o  fact.o  main*
```

其中，`.hpp`表示C++头文件，`.cpp`表示C++源文件，`.o`表示Linux平台下的中间代码文件（Windows下为`.obj`），`mian*`
表示Linux平台下的可执行文件（Windows下为`.exe`）

## 6.2 参数传递

形参初始化的机理和变量初始化一致。

形参的类型决定了形参和实参交互的方式。如果形参是引用类型，那么它将被绑定到对应的实参上；否则，将实参的值拷贝后赋给形参。

由此，我们可以说如果形参是引用类型，那么其对应的实参被*引用传递*（passed by reference）或者说函数被*传引用调用*（called by
reference）。如果实参的值被拷贝给形参，那么说这样的实参被*值传递*（passed by value）或者函数被*传值调用*（called by value）。

### 传值参数

在之前我们使用变量的初始化时，如果不使用引用类型的变量，其初始化仅是将变量值拷贝给被初始化对象，其本身并未变化。

```cpp
int i=10;
int j=i;
j=1;    /* j的值发生改变，为1，但是i的值并未改变。*/
```

传值参数类似，函数对形参所做的所有操作并不会影响到实参。

#### 指针形参

指针的行为和其他非引用类型一致。当执行指针拷贝操作时，拷贝的是指针的值（也就是指针指向对象的地址）。拷贝后，两个指针是不同的指针。

```cpp
void reset(int *ip){
    *ip=0;  /* 指针所指向的对象值改为0 */
    ip=0;   /* 仅能改变ip的局部拷贝，其实参并未发生改变 */
}


int main(){
    int i=42;
    reset(&i);      /* 改变的是i的值，i的地址并未改变 */
    cout<<i<<endl;  /* 输出0 */
```

> 补充
>
> 对于熟悉C的程序员来说，其常常使用指针类型的形参来访问函数外部的对象。建议在C++中，使用引用类型的指针来代替指针。

### 传引用参数

引用实际上是为对象起别名。

所以在函数形参中使用引用方式，这样可以利用形参改变实参，同时使用引用方式还可以避免拷贝。


> 实际开发
>
> 使用引用参数时，如果函数无须改变形参的值（例如读取形参内容），最后将其声明为常量引用。
>
> 虽然函数仅能够返回一个值，但是可以通过引用参数的方式返回额外的值。

## const 形参和实参

在前文提到过，顶层const和底层const，其中顶层const作用于对象本身，同样和其他初始化过程一样，当实参初始化形参时会忽略掉顶层const。也就是说形参的const忽略掉了。

```cpp
#include <iostream>

void functinon(int a){
    a=20;       /* 我们可以修改a的值，但是如果形参为 const int a，则函数仅能够读取a，无法向a写值 */
}

void functinon();
int main(){
  const int b=10;
  functinon(b);
}
```

由于形参的初始化具有这种特性，所以如果形参为const，那么传给它的实参无论是否是const都可以。但是，这种特性也会出现一种意想不到的效果：

```cpp
void function(const int a){ ... }
void function(int a){ ... } /* 错误：重复定义function(int) */
```

因为，形参中的const被忽略，那么传入它的实参可以为const也可以为普通对象，那么对于上述两个函数，其本质是一样的。所以第二个函数会报重复定义错误。

关于指针或引用的底层const，提到过可以使用非常量初始化一个底层const对象，但是不能使用一个底层const对象初始化一个非常量对象。

```cpp
int i=42;
const int *ip=&i;   //true
const int &ir=i;    //true
const int &ir_2=42; //true
int *ip_2=ip;       //false
int &ir_3=ir;       //false
int &ir_4=42;       //false
```

这样的规则同样适用于形参的参数传递上：

```cpp
int i=0;
const int ci=i;     // 顶层const
string::size_type str=0;
reset(&i);          // 形参类型是int指针类型
reset(&ci);         // 错误，无法使用const int 对象的指针初始化int *
reset(i);           // 调用形参类型为int&的reset对象
reset(ci);          // 错误，无法将普通引用绑定到const对象ci上
reset(42);          // 错误，无法引用字面值
reset(ctr);         // 错误，类型不匹配，ctr属于无符号类型
```

在实际开发中，我们应该尽量使用常量引用，将函数不会改变的形参定义为常量引用是一个很好的习惯，这样不会误导调用者认为该值可以被修改。

同时，使用普通引用而非常量引用也会极大地限制函数所能够接受的实参类型，例如：无法将const对象、字面值或者需要类型转换的对象传递给普通地引用形参。

除此之外，还存在一个问题，如果在一个形参为const对象的函数中调用将该形参作为实参传给普通引用的函数，那么编译则会失败：

```cpp
void function_1(string &s){ ... }

void function(const string &s){
function_1(s);      /* 编译失败 */
}
```

### 数组形参

数组相较于我们之前看到的对象具有两个特殊性：

- 不允许拷贝数组
- 使用数组（通常）会将其转换为指针（且该指针指向数组首元素）

因此，使用数组参数时，无法使用值传递的方式使用数组参数、传递数组时，实际上传递的是指向数组首元素的指针。

```cpp
void print(const int *)
void print(const int[])
void print(const int[10])
```

虽然C++中无法直接将数组进行拷贝，但是可以写成类型形式（如上式）方便调用者理解。上述的三种方式函数均是等价的，其函数的形参都是const
int *类型。我们写成const int[]或者const int[10]形式只是我们的意图和期望。
在编译器处理过程中，只检查传入的参数是否是const int *类型。

由于我们使用数组作为形参，那么我们也要考虑将数组的越界问题。

针对这种情况，管理指针形参有三种常见的技术：

1. 使用标记指定数组长度

    ```cpp
    void print(const char *point_array){
    if(point_array)                 /* 判断是否是空指针 */
    while(*point_array)         /* 判断指针所指向的对象是否为空 */
            cout<<*point_array++;   /* 输出 */
    }
    ```

   这种方式要求数组的末尾存在一个结束标记，典型便是：C风格字符串，C风格字符串在结尾处包含一个空字符。

2. 使用标准库规范

    ```cpp
        void print(const int *begin,const int *end){
            while(begin!=end)
                cout<<*begin++<<endl;
        }
        
        int main(){
            int array[2]={1,2};
            print(begin(array),end(array);
        }
    ```

   通过使用数组的首元素指针和尾元素指针来确定数组的大小

3. 显式传递一个表示数组大小的形参

    ```cpp
        void print(const int array[],size_t size){
            for(size_t i=0;i!=size;++i)
                cout<<array[i]<<endl;
        }    
    ```

   这种方式在C程序中很常见，笔者开始也是从这种方式描述数组大小。当然，为了方便直接确定数组大小，也可以将`size_t size`
   的实参写为`end(array)-begin(array)`。

在之前介绍引用的时候，提到过数组引用。数组本身是对象，所以可以对数组进行引用：

```cpp
void print(int (&arr)[10]){
    for(auto elem:arr)
        cout<<elem<<" ";
}
```

其相当于为数组起一个别名，但是注意一定要将引用名括起来。如果不括起来相当于将arr声明成了引用的数组。

但是这种引用本身包含数组的维度，也就是大小。所以当调用者输入的实参数组的维度不等于10时，编译错误。

### main：处理命令行选项

在大多数时候，我们在之前的练习中main()函数只有空形参列表。

在某些时候，我们确定需要给main传递实参，一种常见的情况是用户通过设置一组选项来确定函数所要执行的操作，那么我们通过两个可选形参传递给main()
函数：

```cpp
int main(int argc,char *argv[]){ ... }
int main(int argc,char **argv){ ... }
```

第一个形参argc表示数组中字符串的数量，第二个形参argv是一个数组，其元素指向C风格字符串的指针。

由于argv是一个数组，所以也可以写成第二种方式。

假设存在一个可执行文件print，其main函数在其可执行文件之内，其存在下面命令：

```bash
print -o -x hello home
```

那么，根据上面命令，得到argc等于5，argv为：

```markdown
argv[0]="print"; 
argv[1]="-o";
argv[2]="-x";
argv[3]="hello";
argv[4]="home";
argv[5]=0;
```

其可选的参数便是从argv[1]开始到argv[4];

### 含有可变参数的函数

函数的参数在某些时候，我们并不能够准确预知正确数目，或者某些时候，我们需要输出特定的但是并未明确写出的参数。这种使用环境下，我们就可以使用可变参数的函数。

可变参数函数在C++11标准下提供两种主要的方法：

- initializer-list
    - 如果传入的所有实参类型相同
- 可变参数模型
    - 实参类型不同

除此之外，C++还存在一种特殊的形参类型：省略符。但请注意：该类型一般只用于与C函数交互的接口程序。

#### initializer_list形参

该类型定义在同名头文件下，其具体用法：

```cpp
initializer_list<T> list;  /* 默认初始化：T类型的空列表 */ 
initializer_list<T> list{a,b,c ... };  /* list的元素数量和初始值一样多；list的元素是对应初始值的副本；列表中的元素是const */
list_2(list)   /* 拷贝或赋值一个initializer_list对象不会拷贝列表中的元素。拷贝后，原始列表和副本共享元素 */
list_2=list    /* 与上述一致 */
list.size()    /* 获得列表中的元素 */
list.begin()   /* 返回指向list中首元素的指针 */
list.end()     /* 返回指向list中尾元素下一位置的指针 */
```

initializer_list本身也是模板类型，所以其和vector类型一致，在定义该类型时，必须说明列表中所含元素的类型：

```cpp
initializer_list<int> list;   /* 其元素类型为int */
```

与vector不同是，initializer_list中**所有元素都为常量**！

当然，initializer_list可以通过使用begin()和end()方法获得其内参数：

```cpp
void print(initializer_list<int> list){
    for(auto begin=list.begin();begin!=list.end();++begin)
        cout<<*begin<<" ";
    cout<<"\n";
}
```

在使用initializer_list形参时，我们可以这样使用：

```cpp
/* 打印信息 */
void print(ID id，initializer_list<string> list){    /* 假设存在一个类ID，其中meg()函数用于输出id值 */
    cout<<id.meg()<<": ";
    for(auto &elem : list)
        cout<<elem<<" ";
    cout<<"\n";
}

void error(ID id,const int i,const int j){
    if(i!=j)
        print(id,{"hello","well"}); /* 使用大括号包住值序列 */
    else
        print(id,{"okay"});
```

注意点：

- 如果想要在initializer_list形参中传入值**序列**，那么必须使用大括号括起来。
- 由于列表中的元素为const，所以只能读取initializer_list对象中元素，无法修改。
- initializer_list队形中只能传入同一类型元素

#### 省略符形参

我们需要注意的是：省略符形参是为了便于C++程序能欧访问某些特殊C代码而设定的（这些代码使用varargs的C标准库功能）。所以，*
*大多数类类型的对象在传递给省略符形参时都无法正确拷贝**。

省略符形参只能出现在形参列表的最后一个位置：

```cpp
void print_1(List list,...);
void print_2(...);
```

其无外乎只有上述两种形式。省略符形参所对应的实参无需进行类型检查。

## 6.3 返回类型和return语句

在前面我们提到过，return语句实际上是终止当前正在执行的函数并将控制权返回到调用该函数的地方。
return语句的形式有两种：

```cpp
return;
return expression;
```

### 无返回值函数

只有在返回类型为void的函数中才能实现没有返回值的return语句，返回类型为void的函数非必须添加return语句，该函数会在最后一条语句后隐式执行return。

如果想要使用`return expression`形式，则`expression`必须为返回类型为void的函数，否则编译失败。

### 有返回值函数

只要函数的返回类型不是void，那么必须在该函数中存在return语句且必须返回一个值。（但是有例外：main函数可以不写return语句，编译器会隐式插入一条返回值为0的return语句）

注意：在含有return语句的循环中也必须存在一条return语句，也就是说：必须考虑所有情况下return语句都能够被执行。

**不要返回局部变量的引用或指针**：在函数完成后，其所占的存储空间也被释放掉。因此，函数终止意味着局部变量所占的内存区域不再有效，使用局部变量的引用则是无效的，使用局部变量的指针则是“野指针”。

**函数的返回类型决定函数调用是否是左值**：调用返回引用的函数得到左值，其他类型得到右值。特别的，我们能够将非常量引用的函数结果赋值：

```cpp
char & get_value(string &str,string::size_type i){
    return str[i];
}

int main(){
    string str="hello";
    get_value(str,0)=b;     /* str变为bello */
```

#### 列表初始化返回值

C++11 规定，函数可以返回花括号包围的值的列表。此处的列表用来对表示函数返回的临时量进行初始化。

```cpp
vector<string> print(const string &str1,const string &str2){
   if(str1.size()!=str2.size()) return {"no"};
   else return {"yes","equal","size"};
}
```

在这个例子中，使用vector对象来存储返回信息。

当然，列表初始化返回值其实也是有条件的，如果函数返回的是内置类型，那么列表中仅存在一个值，且该值所占空间不应该大于目标类型的空间：

```cpp
#include <iostream>
#include <string>

int print(const int & i){
  return {i};   /* 不能返回return {i,10} */
}

int main(){
  std::string str="hello";
  int i=10;
  std::cout<<print(i);
}
```

如果返回类型为类类型，则根据类本身定义初始值如何使用。

### 返回数组指针

数组并不支持拷贝，所以函数本身并不能够返回数组。但是函数能够返回数组的指针或者引用。根据这种思路，我们就可以得到：

```cpp
/* 使用类型别名方式 */
typedef int array[10];      /* array为类型别名，表示含有10个整数的数组 */
using array=int[10];        /* array的等价声明 */
array* functinon(int i);    /* function则返回一个指向含有10个整数的数组的指针 */
```

我们通过将返回类型定义成数组的指针。

上述我么通过类型别名方式声明，除此之外还有三种方式得到数组指针：

1. 声明一个返回数组指针的函数

    格式：`Type (*function(parameter_list))[dimension]`，Type表示元素类型，dimension表示数组大小。
    注意点：函数两端的括号必须存在，例如：`int (*f(int i))[10]`。
2. 使用尾置返回类型

    尾置返回类型跟在形参列表后面并以->符号开头。例如：
    `auto f(int i) -> int(*)[10]`，表示f函数返回的是一个指针，且该指针指向含有10个int类型元素的数组
3. 使用decltype
    
    如果我们知道函数返回的指针指向哪个数组，那么我们就可以根据decltype关键字声明返回类型。例如：
    
    ```cpp
    int array_1[10];
    int array_2[10];
    decltype(array_1) *select(int i){
        return (i%2)? &array_1:&array_2;
    }    
    ```
   由于decltype并不会将数组类型转换为相应指针，所以还需要手动添加。

## 6.4 函数重载


    

