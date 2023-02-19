/**
 * @author AaronLi
 * @date 2023-02-15-上午11:29
 * @license GPL-3.0
 */

#include "work_manager.h"

WorkManager::WorkManager() {
    /* 初始化属性 */
    this->worker_number_ = 0;
    this->worker_array_  = nullptr;

    std::ifstream if_stream;
    if_stream.open(FILENAME, std::ios::in);

    /* 文件不存在情况 */
    if (!if_stream.is_open()) {
        std::cerr << "文件不存在！" << std::endl;
        /* 初始化人数 */
        this->worker_number_ = 0;
        /* 文件为空 */
        this->file_is_empty  = true;
        /* 初始化文件为空标志 */
        this->worker_array_  = nullptr;
        if_stream.close();
        return;
    }

    /* 文件存在且数据为空 */
    char is_eof;
    if_stream >> is_eof;
    if (if_stream.eof()) {
        std::cerr << "文件为空！" << std::endl;
        this->worker_number_ = 0;
        this->file_is_empty  = true;
        this->worker_array_  = nullptr;
        if_stream.close();
        return;
    }

    /* 文件存在且数据不为空 */
    this->file_is_empty = false;
    int worker_number   = WorkManager::get_WorkerNumber();
    std::cout << "职工人数为：" << worker_number << std::endl;
    this->worker_number_ = worker_number;
    /* 开辟空间 */
    this->worker_array_  = new Worker*[this->worker_number_];
    /* 将原文件中数据存放数组中 */
    this->InitWorkerArray();
}

// 展示菜单
void WorkManager::ShowMenu() {
    std::cout << "****************************************" << std::endl;
    std::cout << "********** 欢迎使用职工管理系统 ***********" << std::endl;
    std::cout << "***********  0、退出管理系统  ************" << std::endl;
    std::cout << "***********  1、增加职工信息  ************" << std::endl;
    std::cout << "***********  2、显示职工信息  ************" << std::endl;
    std::cout << "***********  3、删除职工信息  ************" << std::endl;
    std::cout << "***********  4、修改职工信息  ************" << std::endl;
    std::cout << "***********  5、查找职工信息  ************" << std::endl;
    std::cout << "***********  6、按照编号排序  ************" << std::endl;
    std::cout << "***********  7、清空所有文档  ************" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << std::endl;
}

/* 选择 */

[[noreturn]] void WorkManager::ChoiceMenu() {
    int choice = 0;
    while (true) {
        ShowMenu();
        std::cout << "请输入您的选项：";
    choice_one:
        std::cin >> choice;
        switch (choice) {
            /* 退出系统*/
        case 0: {
            ExitSystem();
            break;
        }
            /* 添加职工 */
        case 1: {
            AddWorker();
            break;
        }
            /* 显示职工 */
        case 2: {
            ShowWorkerInfo();
            break;
        }
            /* 删除职工 */
        case 3: {
            DeleteWorker();
            break;
        }
            /* 修改职工 */
        case 4: {
            RemoveWorkerInfo();
            break;
        }
            /* 查找职工 */
        case 5: {
            FindWorker();
            break;
        }
            /* 排序职工 */
        case 6: {
            SortWorker();
            break;
        }
            /* 清空文件 */
        case 7: {
            CleanFile();
            break;
        }
        default: std::cerr << "抱歉，您输入的选项有误，请重新输入："; goto choice_one;
        }
    }
}

void WorkManager::ExitSystem() {
    std::cout << "欢迎您的下一次使用！" << std::endl;
    exit(0);
}

/**
 * @description
 * <pre>int      :新添加职员人数</pre>
 * <pre>Worker** :新建空间</pre>
 */
void WorkManager::AddNewWorker(int add_worker_number, Worker** newSpace) const {
    for (int i = 0; i < add_worker_number; ++i) {
        int         worker_id = 0;
        std::string worker_name;
        /* 工作岗位 */
        int         worker_post = 0;

        std::cout << "请输入第" << i + 1 << "个新职员编号：";
        std::cin >> worker_id;

        std::cout << "请输入第" << i + 1 << "个新职工姓名：";
        std::cin >> worker_name;

        std::cout << "****岗位分类****" << std::endl;
        std::cout << "****1、职员****" << std::endl;
        std::cout << "****2、经理****" << std::endl;
        std::cout << "****3、老板****" << std::endl;
        std::cout << "请选择该职工的岗位（1、2、3）：";
        std::cin >> worker_post;

        Worker* worker = nullptr;

        switch (worker_post) {
        case 1: {
            worker = new Employee(worker_id, worker_name, 1);
            break;
        }
        case 2: {
            worker = new Manager(worker_id, worker_name, 2);
            break;
        }
        case 3: {
            worker = new Boss(worker_id, worker_name, 3);
            break;
        }
        default: break;
        }

        newSpace[this->worker_number_ + i] = worker;
    }
}

void WorkManager::AddWorker() {
    int add_worker_number = 0;
    std::cout << "请输入添加职工数量：";
AddWorker:
    std::cin >> add_worker_number;

    if (add_worker_number > 0) {
        /* 计算新空间的大小 */
        int new_worker_number = this->worker_number_ + add_worker_number;

        /* 开辟新空间 */
        auto** newSpace = new Worker*[new_worker_number];

        /* 将原空间下内容存放到新空间下 */
        if (this->worker_array_ != nullptr) {
            for (int i = 0; i < this->worker_number_; ++i) { newSpace[i] = this->worker_array_[i]; }
        }

        AddNewWorker(add_worker_number, newSpace);

        /* 释放原有空间 */
        delete[] this->worker_array_;

        /* 更改新空间的指向 */
        this->worker_array_ = newSpace;

        /* 更改职员个数 */
        this->worker_number_ = new_worker_number;

        /* 职员空间不为空 */
        this->file_is_empty = false;

        /* 保存到文件中 */
        this->Save();

        /* 提示信息 */
        std::cout << "成功添加：" << add_worker_number << "名新职工！" << std::endl;
    } else {
        std::cout << "输入有误，请重新输入：";
        goto AddWorker;
    }
}

void WorkManager::Save() const {
    std::ofstream of_stream;
    of_stream.open(FILENAME, std::ios::out);

    for (int i = 0; i < this->worker_number_; ++i) {
        of_stream << this->worker_array_[i]->worker_id_ << " " << this->worker_array_[i]->worker_name_ << " "
                  << this->worker_array_[i]->worker_department_id_ << std::endl;
    }

    of_stream.close();
}

/* 获取记录中的职工人数 */
int WorkManager::get_WorkerNumber() {
    std::ifstream if_stream;
    if_stream.open(FILENAME, std::ios::in);

    int         worker_id = 0;
    std::string worker_name;
    int         worker_department_id = 0;

    int worker_number = 0;

    while (if_stream >> worker_id && if_stream >> worker_name && if_stream >> worker_department_id) { worker_number++; }

    if_stream.close();

    return worker_number;
}

void WorkManager::InitWorkerArray() const {
    std::ifstream if_stream;
    if_stream.open(FILENAME, std::ios::in);

    int         worker_id = 0;
    std::string worker_name;
    int         worker_department_id = 0;

    int index = 0;
    while (if_stream >> worker_id && if_stream >> worker_name && if_stream >> worker_department_id) {
        Worker* worker;
        if (worker_department_id == 1) {
            worker = new Employee(worker_id, worker_name, worker_department_id);
        } else if (worker_department_id == 2) {
            worker = new Manager(worker_id, worker_name, worker_department_id);
        } else if (worker_department_id == 3) {
            worker = new Boss(worker_id, worker_name, worker_department_id);
        } else {
            std::cerr << "部门编号错误！" << std::endl;
            return;
        }

        this->worker_array_[index] = worker;
        index++;
    }
    if_stream.close();
}

void WorkManager::ShowWorkerInfo() const {
    if (this->file_is_empty) {
        std::cerr << "文件不存在或记录为空！" << std::endl;
    } else {
        for (int i = 0; i < this->worker_number_; ++i) { this->worker_array_[i]->ShowInfo(); }
    }
}

int WorkManager::WorkerIsExist(int worker_id) const {
    int index = -1;
    for (int i = 0; i < this->worker_number_; ++i) {
        if (this->worker_array_[i]->worker_id_ == worker_id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkManager::DeleteWorker() {
    if (this->file_is_empty) {
        std::cerr << "文件不存在或为空！" << std::endl;
    } else {
        int worker_id = 0;
        std::cout << "请输入你想要删除的职工号：" << std::endl;
        std::cin >> worker_id;

        int index = WorkerIsExist(worker_id);

        if (index != -1) {
            for (int i = index; i < this->worker_number_ - 1; ++i) {
                this->worker_array_[i] = this->worker_array_[i + 1];
            }
            this->worker_number_--;
            this->Save();
            std::cout << "删除成功" << std::endl;
        } else {
            std::cout << "删除失败，未找到该职工！" << std::endl;
        }
    }
}

void WorkManager::RemoveWorkerInfo() const {
    if (this->file_is_empty) {
        std::cerr << "文件不存在或文件为空" << std::endl;
    } else {
        int id = 0;
        std::cout << "请输入想要修改职工的编号：";
        std::cin >> id;

        int index = WorkerIsExist(id);

        if (index == -1) {
            std::cerr << "修改失败，无法找到此人！" << std::endl;
            return;
        } else {
            delete this->worker_array_[index];

            int         new_worker_id = 0;
            std::string new_worker_name;
            int         new_worker_department_id = 0;

            std::cout << "查找到：" << id << "号职工，请输入新职工号：";
            std::cin >> new_worker_id;

            std::cout << "查找到：" << id << "号职工，请输入新职工名字：";
            std::cin >> new_worker_name;

            std::cout << "****岗位分类****" << std::endl;
            std::cout << "****1、职员****" << std::endl;
            std::cout << "****2、经理****" << std::endl;
            std::cout << "****3、老板****" << std::endl;
            std::cout << "请重新选择该新职工的岗位（1、2、3）：";
            std::cin >> new_worker_department_id;

            Worker* worker = nullptr;
            switch (new_worker_department_id) {
            case 1: {
                worker = new Employee(new_worker_id, new_worker_name, new_worker_department_id);
                break;
            }
            case 2: {
                worker = new Manager(new_worker_id, new_worker_name, new_worker_department_id);
                break;
            }
            case 3: {
                worker = new Boss(new_worker_id, new_worker_name, new_worker_department_id);
            }
            default: break;
            }

            this->worker_array_[index] = worker;
            this->Save();
            std::cout << "修改成功！" << std::endl;
        }
    }
}

void WorkManager::FindWorkerById() const {
    int worker_find_id = 0;
    std::cout << "请输入您想要查找的职工编号：";
    std::cin >> worker_find_id;

    int index = WorkerIsExist(worker_find_id);

    if (index == -1) {
        std::cerr << "查找失败，查无此人！" << std::endl;
        return;
    } else {
        std::cout << "成功查询！具体信息如下：" << std::endl;
        this->worker_array_[index]->ShowInfo();
    }
}

void WorkManager::FindWorkerByName() const {
    std::string worker_find_name;
    std::cout << "请输入您想要查找的职工姓名：" << std::endl;
    std::cin >> worker_find_name;

    bool is_exist_tag = false;
    for (int i = 0; i < this->worker_number_; ++i) {
        if (this->worker_array_[i]->worker_name_ == worker_find_name) {
            std::cout << "查找成功，职工编号为：" << this->worker_array_[i]->worker_id_ << "的职工信息如下："
                      << std::endl;
            is_exist_tag = true;
            this->worker_array_[i]->ShowInfo();
        }
    }

    if (!is_exist_tag) {
        std::cerr << "查找失败，查无此人！" << std::endl;
        return;
    }
}

void WorkManager::FindWorker() const {
    if (this->file_is_empty) {
        std::cerr << "文件不存在或文件为空" << std::endl;
    } else {
        int select_tag = 0;
        std::cout << "****************" << std::endl;
        std::cout << "1、按照职工编号查找" << std::endl;
        std::cout << "2、按照职工姓名查找" << std::endl;
        std::cout << "请选择输入查找的方式：（1/2）" << std::endl;
    FindWorker_One:
        std::cin >> select_tag;

        if (select_tag != 1 && select_tag != 2) {
            std::cerr << "输入错误，请重新输入：";
            goto FindWorker_One;
        }

        if (select_tag == 1) {
            FindWorkerById();
        } else if (select_tag == 2) {
            FindWorkerByName();
        } else {
            std::cerr << "输入选项有误！" << std::endl;
            return;
        }
    }
}

void WorkManager::SortWorker() const {
    if (this->file_is_empty) {
        std::cerr << "文件不存在或文件为空" << std::endl;
    } else {
        int select_tag = 0;
        std::cout << "******************" << std::endl;
        std::cout << "1、按照职工编号升序排列" << std::endl;
        std::cout << "2、按照职工编号降序排列" << std::endl;
        std::cout << "请输入您选择的排序方式（1/2）" << std::endl;
    SortWorker_One:
        std::cin >> select_tag;

        if (select_tag != 1 && select_tag != 2) {
            std::cerr << "输入错误，请重新输入：";
            goto SortWorker_One;
        }

        for (int i = 0; i < this->worker_number_; ++i) {
            int index_worker_number = i;
            for (int j = i + 1; j < this->worker_number_; ++j) {
                if (select_tag == 1) {
                    if (this->worker_array_[index_worker_number]->worker_id_ > this->worker_array_[j]->worker_id_) {
                        index_worker_number = j;
                    }
                } else {
                    if (this->worker_array_[index_worker_number]->worker_id_ < this->worker_array_[j]->worker_id_) {
                        index_worker_number = j;
                    }
                }
            }

            if (i != index_worker_number) {
                Worker* temporary                  = this->worker_array_[i];
                this->worker_array_[i]             = this->worker_array_[index_worker_number];
                worker_array_[index_worker_number] = temporary;
            }
        }

        this->Save();
        std::cout << "排序成功！结果为：" << std::endl;
        this->ShowWorkerInfo();
    }
}

void WorkManager::CleanFile() {
    char select_tag;
    std::cout << "确认清空？（Y/N）" << std::endl;
    std::cin >> select_tag;

    if (select_tag != 'Y' && select_tag != 'y') {
        return;
    } else {
        /* 打开模式：ios::trunc 如果文件存在便删除文件并重新创建 */
        std::ofstream of_stream(FILENAME, std::ios::trunc);
        of_stream.close();

        if (this->worker_array_ != nullptr) {
            for (int i = 0; i < this->worker_number_; ++i) {
                if (this->worker_array_[i] != nullptr) { delete this->worker_array_[i]; }
            }
            this->worker_number_ = 0;
            delete[] this->worker_array_;
            this->worker_array_ = nullptr;
            this->file_is_empty = true;
        }

        std::cout << "清空成功！" << std::endl;
    }
}

WorkManager::~WorkManager() {
    delete[] this->worker_array_;
    worker_array_ = nullptr;
}
