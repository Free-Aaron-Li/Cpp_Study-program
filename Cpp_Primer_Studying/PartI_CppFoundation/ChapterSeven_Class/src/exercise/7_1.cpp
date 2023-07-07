// This file is part of Cpp_Primer_Studying project.
// This program is called:7_1.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "7_1.hpp"

void Exercise_7_1::meaninglessFunction_1() {}
void Exercise_7_1::meaninglessFunction_2() {}
void Exercise_7_1::meaninglessFunction_3() {}
void Exercise_7_1::meaninglessFunction_4() {}
void Exercise_7_1::meaninglessFunction_5() {}
void Exercise_7_1::meaninglessFunction_6() {}

void Exercise_7_1::exercise_7_1() {
    SalesData total;
    double    sold_price; /* 销售单价 */

    if (std::cin >> total._bookNo >> total._units_sold >> sold_price) {
        total._revenue = total._units_sold * sold_price;

        SalesData trans;
        while (std::cin >> trans._bookNo >> trans._units_sold >> sold_price) {
            trans._revenue = trans._units_sold * sold_price;
            if (total._bookNo == trans._bookNo) {
                total._units_sold += trans._units_sold;
                total._revenue += trans._revenue;
            } else {
                std::cout << "********************\n"
                          << total._bookNo << "\t" << total._units_sold << "\t" << total._revenue << "\t";
                if (total._units_sold != 0)
                    std::cout << total._revenue / total._units_sold << "\n"
                              << "********************\n";
                else
                    std::cout << "no sales!\n"
                              << "********************\n";
                total = trans;
            }
        }

        std::cout << "********************\n"
                  << total._bookNo << "\t" << total._units_sold << "\t" << total._revenue << "\t";
        if (total._units_sold != 0)
            std::cout << total._revenue / total._units_sold << "\n"
                      << "********************\n";
        else
            std::cout << "no sales!\n"
                      << "********************\n";
    } else
        std::cerr << "no data?!\n";
}


void Exercise_7_1::exercise_7_3() {
    SalesData total;
    double    sales_price; /* 销售单价 */

    if (std::cin >> total._bookNo >> total._units_sold >> sales_price) {
        total._revenue = total._units_sold * sales_price;

        SalesData trans;

        while (std::cin >> trans._bookNo >> trans._units_sold >> sales_price) {
            trans._revenue = trans._units_sold * sales_price;

            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                std::cout << "********************\n"
                          << total._bookNo << "\t" << total._units_sold << "\t" << total._revenue << "\t";
                if (total._units_sold != 0)
                    std::cout << total._revenue / total._units_sold << "\n"
                              << "********************\n";
                else
                    std::cout << "no sales!\n"
                              << "********************\n";
                total = trans;
            }
        }

        std::cout << "********************\n"
                  << total._bookNo << "\t" << total._units_sold << "\t" << total._revenue << "\t";
        if (total._units_sold != 0)
            std::cout << total._revenue / total._units_sold << "\n"
                      << "********************\n";
        else
            std::cout << "no sales!\n"
                      << "********************\n";
    } else
        std::cerr << "no data?!\n";
}

void Exercise_7_1::exercise_7_7() {
    SalesData total;
    if (read(std::cin, total)) {
        SalesData trans;
        while (read(std::cin, trans)) {
            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else {
                std::cout << "********************\n";
                print(std::cout, total);
                std::cout << "\n********************\n";
                total = trans;
            }
        }
        std::cout << "********************\n";
        print(std::cout, total);
        std::cout << "\n********************\n";
    } else
        std::cerr << "no data?!\n";
}
