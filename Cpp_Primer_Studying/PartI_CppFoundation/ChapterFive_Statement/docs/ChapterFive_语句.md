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

有关case的一个特点，可以将几个case标签写在同一行，用于强调这些case代表的是某个范围的值：》
