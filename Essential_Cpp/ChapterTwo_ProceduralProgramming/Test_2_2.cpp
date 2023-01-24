/**
 * @file Test_2_2.cpp
 * @author AaronLi
 * @date 2023-01-23-下午3:30
 * @description
 * <p> 练习 2.2 </p>
 * <p></p>
 * <p>
 * Pentagonal数列的求值公式是P(n)=n(3n-1)/2，借此产生1，5，12，22，35等元素值。试定义一个函数，利用上述公式，将产生的运算放在用户传入的vector之中，<br/>
 * 元素个数由用户指定。请检查运算个数的有效性（太大则可能引发overflow问题）。接下来编写第二个函数，能够将给定的vector的所有元素一一打印出来。则函数的第二个参数 <br/>
 * 接受一个字符串，表示存放在vector内的数列的类型。最后再写一个main()，测试上述两个函数
 * </p>
 * @link 
 */

#include <ostream>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

bool calculation_is_ok(int num);
bool calculation(vector<int> &,int);
bool print(vector<int> &,const string,ostream &);


/**
 * @date 23-1-23 下午4:38
 * @description
 * <p> 判断计算Pentagonal数列是否正确 </P>
 * <p></p>
 * <p>
 * 将练习2.2的Pentagonal数列求值函数拆分为两个函数，其中之一为inline，用来检验元素个数是否合理。如果的确合理，而且尚未被计算，便执行第二个函数，执行实际的求值工作
 * </p>
 */

bool calculation_is_ok(int num){
    if(num<0||num>100){
        cerr<<"Sorry,Beyond the range of calculating pentagonal array!"<<endl;
        return false;
    }
    return true;
}

/**
 * @date 23-1-23 下午3:54
 * @description
 * <p> 计算Pentagonal数列 </P>
 */


inline bool calculation(vector<int> &vec,int num){
    /* 判断计算是否合理 */
    if(!calculation_is_ok(num)){
        return false;
    }

    for (int i = 0; i < num; ++i) {
        vec.push_back((i*(3*i-1))/2);
    }
    return true;
}

/**
 * @date 23-1-23 下午4:05
 * @description
 * <p> 打印vector </P>
 */

bool print(vector<int> &vec,const string title,ostream &os=cout){
    os<<"type is: "<<title<<endl;
    for(int i=0;i<vec.size();++i){
        os<<vec[i]<<"\t";
        if(i%10==0&&i!=0){
            os<<endl;
        }
    }
    return true;
}

int main() {
    /* Pentagonal数列打印文件 */
    ofstream ofil("../test2_2_data.txt");
    vector<int> pentagonal;
    int num=0;

    string title = "Pentagonal array is: ";
    cout<<"Please enter Pentagonal array element of you want: "<<endl;
    cin>>num;
    calculation(pentagonal, num);
    print(pentagonal, title, ofil);

}








