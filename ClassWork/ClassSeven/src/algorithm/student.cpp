/**
 * @author AaronLi
 * @data 2023-05-29-下午1:14
 * @license GPL-3.0
 */
#include "student.hpp"

#include <cmath>


void Student::getInformation(Students &students, const char student_number[12], const char student_name[20],
                             double chinese, double math, double english) {
    for (int i = 0; i < 12; ++i) {
        students.student_number[i] = student_number[i];
    }
    for (int i = 0; i < 20; ++i) {
        students.student_name[i] = student_name[i];
    }

    students.score_chinese = scoreCarry(chinese);
    students.score_math = scoreCarry(math);
    students.score_english = scoreCarry(english);
    std::cout << "";
}

double Student::scoreCarry(double score) {
    return round(score * 10) / 10.0;
}

void Student::printInformation(Students &students, int tab_number) {
    std::string name = students.student_name, number = students.student_number, tab;
    for (int i = 0; i < tab_number; ++i) {
        tab += "\t";
    }
    students.total_scores = scoreCarry(students.score_chinese + students.score_math + students.score_english);
    std::cout << number << tab << name << tab << students.score_chinese << tab << students.score_math << tab
              << students.score_english << tab << students.total_scores << "\n";
}
