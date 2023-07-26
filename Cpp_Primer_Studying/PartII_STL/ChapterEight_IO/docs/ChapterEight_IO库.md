# 第八章 IO库

## 前言

C++语言并不会直接处理输入输出，而是通过一族定义在标准库中的类型来处理IO。这些类型支持从设备中读取数据、向设备写入数据IO操作。设备可以是文件、控制台窗口等，还有一些类型允许内存IO。

IO库定义了读写内置类型值的操作。

---

## 8.1 IO类

在之前我们使用的IO类型和对象都是操作char数据且这些对象都是关联到用户的控制台窗口。但在实际开发中还不够，所以在C++的IO操作中还包括一下类型供开发者使用。在头文件iostream定义了读写流的基本类型、fstream定义了读写命名文件的类型、sstream定义了读写内存string对象的类型。

|   头文件    |                                                             类型                                                             |
|:--------:|:--------------------------------------------------------------------------------------------------------------------------:|
| iostream |                        istream，wistream 从流读取数据<br/>ostream，wostream向流写入数据<br/>iostream，wiostream读写流                        |
| fstream  |                      ifstream，wifstream从文件读取数据<br/>ofstream，wofstream向文件写入数据<br/>fstream，wfstream读写文件                      |
| sstream  | istringstream，wistringstream从stream读取数据<br/>ostringstream，wostringstream向string写入数据<br/>stringstream，wstringstream读写string |

为了支持宽字符的语言，标准库定义了一组类型与对象来操作wchar_t类型的数据。


