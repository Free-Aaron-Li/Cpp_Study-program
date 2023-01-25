/**
 * @file test2_5.cpp
 * @author AaronLi
 * @date 2023-01-24-下午2:31
 * @description
 * <p> 练习2.5 </p>
 * <p></p>
 * <p>
 * 实现一个重载的max()函数，让它接受一下参数：<br/>
 * a.两个整数，b.两个浮点数，c.两个字符串，d.一个整数vector，e.一个浮点数vector，f.一个字符串vector，g.一个整数组，以及一个表示数组大小的整数组，
 * h.一个浮点数数组，以及一个表示数组大小的整数组，i.一个字符串数组，以及一个表示数组大小的整数组。<br/>
 * 最后，编写main()测试这些函数。
 * </p>
 * @link
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @date 23-1-25 下午1:27
 * @description
 * <p> 暂时无法解决 </P>
 */

template<typename Type>
inline Type max(Type t1, Type t2) { return t1 > t2 ? t1 : t2; }

template<typename elemType>
inline elemType max(const vector<elemType> &vec) { return *max_element(vec.begin(), vec.end()); }

template<typename arrayType>
inline arrayType max(const arrayType *parray, int size) { return *max_element(parray, parray + size); }

// note: no changes required of main()!
int main() {
   int t1=23,t2=12;
}
