/**
 * @author AaronLi
 * @date 2023-02-11-下午4:14
 * @license GPL-3.0
 */
#include "work_manager.h"
#include "worker.h"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

void test(){
     Worker * worker = nullptr;
     worker = new Employee(1, "张三", 1);
     worker->ShowInfo();
     delete worker;

     worker = new Manager(2, "李四", 2);
     worker->ShowInfo();
     delete worker;

     worker = new Boss(3, "王五", 3);
     worker->ShowInfo();
     delete worker;

}

int main(){
    WorkManager workManager;

    //workManager.ChoiceMenu();

    test();

    return 0;
}

