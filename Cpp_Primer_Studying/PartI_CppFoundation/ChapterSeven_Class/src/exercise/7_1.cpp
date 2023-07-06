// This file is part of Cpp_Primer_Studying project.
// This program is called:7_1.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "7_1.hpp"

void Exercise_7_1::exercise_7_1() {
    Sales_data total;
    double sold_price;       /* 销售单价 */

    if (std::cin >> total.bookNo >> total.units_sold >> sold_price) {
        total.revenue = total.units_sold * sold_price;

        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> sold_price) {
            trans.revenue = trans.units_sold * sold_price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << "********************\n"
                          << total.bookNo << "\t" << total.units_sold << "\t" << total.revenue << "\t";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << "\n"
                              << "********************\n";
                else
                    std::cout << "no sales!\n"
                              << "********************\n";
                total.bookNo     = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue    = trans.revenue;
            }
        }

        std::cout << "********************\n"
                  << total.bookNo << "\t" << total.units_sold << "\t" << total.revenue << "\t";
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << "\n"
                      << "********************\n";
        else
            std::cout << "no sales!\n"
                      << "********************\n";
    } else
        std::cerr << "no data?!\n";
}
