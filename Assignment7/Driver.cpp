#include <iostream>
#include "assign_obj.h"

using namespace std;

/*
* @Author Alexander Kemos 100375966
* @Version 1.0
* @since 2022-11-10
*/
/*
* Generate instances of assign_obj class and call
* it's methods to compact, print, add two instances,
* and insert char:value pairs to these instances.
*/

int main(){
    assign_obj ao1("dsdfdfshfbdfmjykiuuy");
    assign_obj ao2("pqwecmasdckjldjf");
    std::cout << ao1 << std::endl;
    ao1.compact();
    std::cout << ao1 << std::endl;
    assign_obj ao3 = ao1;
    ao3 = ao3 + ao2;
    std::cout << ao2 << std::endl;
    std::cout << ao3 << std::endl;
    ao3.e_add('z');
    ao3.f_add('g');
    ao3.f_add('t');
    ao3.e_add('z');
    ao3.f_add('u');
    ao3.e_add('i');
    ao3.f_add('Z');
    std::cout << ao3 << std::endl;
    ao3.compact();
    std::cout << ao3 << std::endl;
    return 0;
}
