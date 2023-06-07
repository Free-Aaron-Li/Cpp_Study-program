# 第五章 语句

## 前言

通常情况下，程序是按照顺序执行。但是仅仅依靠顺序执行无法解决一些复杂问题，所以C++提供一组*控制流*
（flow-of-control）永远支持更加复杂的执行路径。

---

## 5.1 简单语句

三种语句：

```cpp
value+5;            /* 表达式语句 */
;                   /* 空语句 */
while(value<10){    /* 复合语句（块） */
cout<<value<<" ";   
++value;
}
```

有一个很好的例子：

```cpp
/* 重复读取数据直到到达文件末尾或者遇到换行 */
while(cin>>s && s!='\n')
    ;   /* 空语句 */
```

当语法上只需要一条语句，但是逻辑上需要多条语句时便可以使用复合语句。

## 5.2 语句作用域

定义在控制结构当中的变量只在相应语句的内部可见。

## 5.3 条件语句

C++提供两种按条件执行的语句。一种是if语句，另一种是switch语句。

### if语句

if语句的形式：

```cpp
if(condition)
    statement
    
/* if-else形式 */
if(condition)
    statement
else
    statement2 
```

condition可以是一个表达式，也可以是一个初始化了的变量声明。但都必须用括号括起来。

### switch语句

当对多个固定选项进行选择时，使用if-else语句就显得冗余，所以C++提出switch语句。

switch语句的形式：

```cpp
switch(condition){
    case option1:
            statement1;
    case option2:
            statement2;
    case optionn:
            statement3;
    default:
            statement4; 
}
```

注意点：case标签必须为整型常量表达式，且任意的两个case标签不能相同；default属于特殊的case标签。

有关case的一个特点，可以将几个case标签写在同一行，用于强调这些case代表的是某个范围的值：

```cpp
char character;
int  number = 0;
std::cin >> character;
switch (character) {
    case 'a':
    case 'b':
    case 'c': number++; break;
    default: std::cout << "error!\n"; break;
}
/* 如果输入的是“a”、“b”、“c”，则返回1，否则返回0 */
std::cout << "number is " << number << "\n";    
```

> 建议
>
> 一般不要遗忘在最后一个case分支上添加break语句，如果有需要，请用注释注明。
>
> 即便不使用default语句，也请定义一个default标签。这样做的目的：表明对switch语句的case分支情况我们已经考虑全面。
>
> 无论是case还是default标签，我们都不应该让其内容为空，哪怕这个分支并未起作用，我们也应该使用空语句或者空块填充内容。


还有个关于在switch内部的变量定义讨论：

例如：

```cpp
bool index = false;
switch (index) {
    case true:
        std::string file_name;
        int         ival = 0;
        int         jval;
        break;
    case false: /* 错误！ */
        jval = 0;
        if (file_name.empty()) {};
        break;
    default: break;
}
```

C++规定：不允许跨过变量的初始化语句直接跳转到该变量作用域内的另一个位置。

## 5.4 迭代语句

迭代语句又叫循环，在之前我们了解过三种循环语句：

- while()
- for()
- do-while()

---

### 5.4.1 while语句

其形式：

```cpp
while(condition)
    statement
```

其条件部分与if语句类型：可以是一个表达式，也可以是一个带初始化的变量声明。

### 5.4.2 传统for语句

其形式：

```cpp
for(init-statement;condition;expression)
    statement
```

注意点：

1. for循环语句中定义的变量仅在该循环语句中有效
2. init-statement仅存在一条声明语句（注意不是仅能声明一个对象），但可以有多个对象
3. for语句头能够省略任何一个语句，即便是全部省略也可以

### 5.4.3 范围for语句

其形式：

```cpp
for (declaration:expression)
    statement
```

### 5.4.4 do while语句

其形式：

```cpp
do
    statement
while(condition);
```

相较于while语句，

- do-while语句会在进行判断语句之前执行一次statement
- do-while语句在括号后会添加一个分号





