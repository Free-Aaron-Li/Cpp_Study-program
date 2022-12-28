/**
 * @file Test1_8.cpp
 * @author AaronLi
 * @date 2022-12-28-下午7:29
 * @description
 * <p> 练习1.8 </p>
 * <p></p>
 * <p>
 * switch语句让我们得以根据用户打错的次数提供不同的安慰语句。请以array存储四种不同的字符串信息，并以用户打错
 * 次数作为array的索引值，以此方式显示安慰语句。
 * </p>
 * @link 
 */
#include <iostream>
using namespace std;

const char* msg_to_usr(int num_tries){
    const int rsp_cnt=5;
    static const char* usr_msgs[rsp_cnt]={
            "Go on, make a guess!",
            "Oops! Nice guess but not quite it.",
            "Hmm, Sorry, Wrong a second time.",
            "Ah, this is harder than it looks, no?",
            "It must be getting pretty frustrating by now"
    };
    if(num_tries<0){
        num_tries=0;
    }else if(num_tries>=rsp_cnt){
        num_tries=rsp_cnt-1;
    }
   return usr_msgs[num_tries];
}
int main(){
    cout << msg_to_usr(3);
}













