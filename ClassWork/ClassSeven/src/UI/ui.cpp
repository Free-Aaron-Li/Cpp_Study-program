/** @author AaronLi
 * @data 2023-05-29-下午3:33
 * @license GPL-3.0
 */
#include "ui.hpp"

void UI::homePage() {
    std::cout << "\n_______________________________\n"
                 "_______ 学生信息存储系统 ______\n"
                 "_______________________________\n"
                 "_______  学生成绩输入   _______\n"
                 "________    打印列表    _______\n"
                 "________    降序排序    _______\n"
                 "________     查找      ________\n"
                 "________     退出      ________\n"
                 "______________________________\n";
}

int UI::selectNumber() {
    int number = 0;
    std::cin >> number;
    if (std::cin.fail())return -1;
    return number;
}

int UI::selectChar() {
    char character;
    std::cin >> character;
    if (std::cin.fail())return -1;
    if (character == 'Y' || character == 'y') return 1;
    else return 0;
}

void UI::printList(Students *students, int tab_number) const {
    std::cout << "\n_______________________________\n"
                 "_______    打印列表     _______\n"
                 "_______________________________\n";

    print(tab_number);
    for (int i = 0; i < flag; ++i) {
        Student::printInformation(students[i], tab_number);
    }
    std::cout << "\n_______________________________\n";
}

void UI::print(int tab_number) {
    std::string tab_1, tab_2;
    for (int i = 0; i < tab_number; ++i) {
        tab_1 += "\t";
    }
    for (int i = 0; i < tab_number - 1; ++i) {
        tab_2 += "\t";
    }
    std::cout << "学号" << tab_1 << "姓名" << tab_1 << "语文成绩" << tab_2 << "数学成绩" << tab_2 << "英语成绩" << tab_2
              << "总成绩\n";
}

bool checkNumber(const std::string &target_number) {
    /* 定义，1~12位数字 */
    std::regex repPattern("[0-9]{1,12}", std::regex_constants::extended);
    /* 声明匹配结果变量 */
    std::match_results<std::string::const_iterator> rerResult;
    /* 匹配 */
    return std::regex_match(target_number, rerResult, repPattern);
}


bool checkName(const std::string &target_name) {
    /* 定义，1~12位数字 */
    std::regex repPattern("[0-9a-zA-Z]{1,20}", std::regex_constants::extended);
    /* 声明匹配结果变量 */
    std::match_results<std::string::const_iterator> rerResult;
    /* 匹配 */
    return std::regex_match(target_name, rerResult, repPattern);
}

int UI::inputInformation(Students *students) {
    std::cout << "请在下方输入学生信息：\n";
    while (flag < 40) {
        char number[12], name[20];
        double chinese, math, english;
        std::cout << "学生" << flag + 1 << "的信息：\n";

        NUMBER:
        std::cout << "学号（格式：00x，12位以内）：";   /* TODO 23-5-29 添加学号和姓名的判断 */
        std::cin >> number;
        if (std::cin.fail())return -1;
        if (!checkNumber(number)) {
            std::cerr << "学号格式不正确，请重新输入！\n";
            goto NUMBER;
        }

        NAME:
        std::cout << "姓名（20位以内）：";
        std::cin >> name;
        if (std::cin.fail())return -1;
        if (!checkName(name)) {
            std::cerr << "姓名格式不正确，请重新输入！\n";
            goto NAME;
        }

        std::cout << "语文成绩：";
        std::cin >> chinese;
        std::cout << "数学成绩：";
        std::cin >> math;
        std::cout << "英语成绩：";
        std::cin >> english;
        Student::getInformation(students[flag], number, name, chinese, math, english);
        flag++;
        std::cout << "是否确认退出：";
        if (selectChar())break;
    }
    if (flag == 0) {
        char number[12] = {'0', '0', '0'};
        char name[20] = {'N', 'o', ' ', 'N', 'a', 'm', 'e'};
        double chinese = 0.0, math = 0.0, english = 0.0;
        Student::getInformation(students[flag], number, name, chinese, math, english);
        flag++;
    }
    if (flag >= 40) {
        std::cerr << "\n最多只能存放40名学生信息!\n";
        flag = 40;
        return 0;
    }
    return 1;
}

int *UI::totalScores_descendingOrder(Students *students) {
    int *flag_array = new int[flag];
    double total_scores[flag];
    for (int i = 0; i < flag; ++i) {
        total_scores[i] = students[i].total_scores;
    }
    for (int i = 0; i < flag; ++i) {
        flag_array[i] = i;
    }

    for (int i = 0; i < flag; ++i) {
        for (int j = 0; j < flag - 1 - i; ++j) {
            if (total_scores[j] < total_scores[j + 1]) {
                double temporary_1;
                int temporary_2;
                temporary_1 = total_scores[j + 1];
                total_scores[j + 1] = total_scores[j];
                total_scores[j] = temporary_1;

                temporary_2 = flag_array[j + 1];
                flag_array[j + 1] = flag_array[j];
                flag_array[j] = temporary_2;
            }
        }
    }

    return flag_array;
}

void UI::sortShow(Students *students, int tab_number) {
    if (flag == 1) {
        std::cout << "\n_______________________________\n"
                     "_______    降序排序     _______\n"
                     "_______________________________\n";

        print(tab_number);
        Student::printInformation(students[0], tab_number);
        std::cout << "\n_______________________________\n";
        return;
    }

    int *flag_array = totalScores_descendingOrder(students);
    std::cout << "\n_______________________________\n"
                 "_______    降序排序     _______\n"
                 "_______________________________\n";

    print(tab_number);
    for (int i = 0; i < flag; ++i) {
        Student::printInformation(students[flag_array[i]], tab_number);
    }
    std::cout << "\n_______________________________\n";
}

int UI::searchStudentNumber(Students *students, const std::string &target_number) const {
    for (int i = 0; i < flag; ++i) {
        std::string tmp = students[i].student_number;
        if (tmp == target_number)return i;
    }
    return -1;
}


int UI::searchStudentName(Students *students, const std::string &target_name) const {
    for (int i = 0; i < flag; ++i) {
        std::string tmp = students[i].student_name;
        if (tmp == target_name)return i;
    }
    return -1;
}

std::string get_str(std::string &str) {
    /* 获取输入串前的换行符，防止getline方法无法使用 */
    std::cin.get();
    getline(std::cin, str);
    return str;
}

void UI::searchShow(Students *students, int tab_number) const {
    std::cout << "\n_______________________________\n"
                 "_______     查找      _______\n"
                 "_______________________________\n";
    std::cout << "查找有两种方式：学号查找(1)或姓名查找(2)：";
    int choice = selectNumber();

    switch (choice) {
        case 1: {
            std::cout << "请输入要查找的学号：";
            std::string target_number;
            int index = searchStudentNumber(students, get_str(target_number));
            if (index != -1) {
                print(tab_number);
                for (int i = 0; i < flag; ++i) {
                    Student::printInformation(students[index], tab_number);
                }
            } else {
                std::cout << "找不到该学号对应学生信息\n";
            }
            break;
        }
        case 2: {
            std::cout << "请输入要查找的姓名：";
            std::string target_name;
            int index = searchStudentName(students, get_str(target_name));
            if (index != -1) {
                print(tab_number);
                for (int i = 0; i < flag; ++i) {
                    Student::printInformation(students[index], tab_number);
                }
            } else {
                std::cout << "找不到该姓名对应学生信息\n";
            }
            break;
        }
        default:
            std::cout << "\n您选择的查找方式不正确，请重新选择！\n";
    }
    std::cout << "\n_______________________________\n";
}

void UI::InterfaceLogic(Students *students, int tab_number) {
    while (true) {
        homePage();
        std::cout << "请选择您想要的操作（1~5）：";
        int choice = selectNumber();
        switch (choice) {
            case 1: {
                inputInformation(students);
                break;
            }
            case 2: {
                printList(students, tab_number);
                break;
            }
            case 3: {
                sortShow(students, tab_number);
                break;
            }
            case 4: {
                searchShow(students, tab_number);
                break;
            }
            case 5: {
                std::cout << "确定退出吗？(Y/N)：";
                if (selectChar())return;
                break;
            }
            default:
                if (choice == -1)return;
                std::cerr << "输入有误！请重新输入\n";
        }
    }
}

