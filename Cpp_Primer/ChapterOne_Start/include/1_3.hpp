//
// Created by AaronLi on 23-4-1.
//

#ifndef CPP_PRIMER_1_3_H
#define CPP_PRIMER_1_3_H

/**
 * @description 
 * <p> 1.3节练习——注释 </P>
 */

#include <iostream>

class Exercise_1_3{
public:
    /**
     * @description 
     * <p> 练习1.7 </P>
     * @def
     *  编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。
     */
   static void ErrorComment();
   /**
    * @description 
    * <p> 练习1.8 </P>
    * @def
    *  指出下列哪些输出语句是合法的（如果有的话）：
    */
    //  std::cout << /* "*/" */;
    //  std::cout << "*/"; 
    //  std::cout << /* "/*" */;
    //  std::cout << /* "*/" /* "/*" */;
    static void LegalComment(); 
    
};

#endif //CPP_PRIMER_1_3_H
