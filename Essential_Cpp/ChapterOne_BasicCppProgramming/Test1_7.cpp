/**
 * @file Test1_7.cpp
 * @author AaronLi
 * @date 2022-12-28-下午4:20
 * @description
 * <p> 练习1.7 </p>
 * <p></p>
 * <p>
 * 使用你最称手的编辑工具，输入两行（或更多）文字并存盘。然后编写；一个程序，打开该文本文件，将其中每个字都取到一个
 * vector<string>对象中。遍历该vector，将内容显示到cout。然后利用泛型算法sort()，对所有文字排序：
 * </p>
 * <p>&ensp;#include <algorithm> </p>
 * <p>&ensp;sort(container.begin(), container.end()); </p>
 * <p>
 * 再将排序后的结果输出到另一个文件。
 * </p>
 * @link 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    /* 需要读取文件 */
    /* 需要注意的是：ifstream和ofstream读取文件的相对路径指的是相对于当前工作目录，而并非相对于当前二进制文件目录 */
    ifstream in_file("../1_7.txt");
    if (!in_file) {
        cerr << "oops! Couldn't open input file. \n";
        return -1;
    }

    /* 需要写入文件 */
    ofstream out_file("../1_7_out.txt");
    if (!out_file) {
        cerr << "oops! Couldn't open output file. \n";
        return -2;
    }

    /* 读取文件中内容 */
    string word;
    vector<string> text;
    while (in_file >> word) {
        text.push_back(word);
    }

    int text_output;
    cout << "This document contains: \n";

    for (text_output = 0; text_output < text.size(); ++text_output) {
        cout << text[text_output] << ' ';
    }
    cout << endl;

    /* 排序 */
    sort(text.begin(), text.end());

    /* 写入到另一个文件 */
    out_file << "sorted text: \n";
    for (const auto & i : text) {
        out_file << i << ' ';
    }
    out_file << endl;
    return 0;
}














