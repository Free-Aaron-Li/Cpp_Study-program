/**
 * @author AaronLi
 * @date 2023-02-06-下午11:28
 * @license GPL-3.0
 */

#include <fstream>
#include <iostream>
#include <string>

class Person {
 public:
    char m_Name[64];
    int  m_Age;
};

void test01() {
    /* 创建流文件 */
    std::ifstream ifs("person.txt", std::ios::in | std::ios::binary);

    /* 判断文件是否打开成功 */
    if (!ifs.is_open()) { std::cout << "文件打开失败" << std::endl; }

    /* 读文件 */
    Person p;
    ifs.read((char *)&p, sizeof(p));

    /* 打印文件 */
    std::cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << std::endl;

    /* 关闭文件 */
    ifs.close();
}

int main() {
    test01();

    return 0;
}