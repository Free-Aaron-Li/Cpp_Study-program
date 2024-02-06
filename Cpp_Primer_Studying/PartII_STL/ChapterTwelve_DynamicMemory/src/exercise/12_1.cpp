// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "12_1.hpp"

void
Exercise_12_1::meaninglessFunction_1() {}
void
Exercise_12_1::meaninglessFunction_2() {}
void
Exercise_12_1::meaninglessFunction_3() {}
void
Exercise_12_1::meaninglessFunction_4() {}
void
Exercise_12_1::meaninglessFunction_5() {}
void
Exercise_12_1::meaninglessFunction_6() {}
void
Exercise_12_1::meaninglessFunction_7() {}
void
Exercise_12_1::meaninglessFunction_8() {}
void
Exercise_12_1::meaninglessFunction_9() {}
void
Exercise_12_1::meaninglessFunction_10() {}
void
Exercise_12_1::meaninglessFunction_11() {}
void
Exercise_12_1::meaninglessFunction_12() {}

//------------------------------------------------------------------------------------------------
//
void
testStrBlob(StrBlob& strBlob) {
    try {
        strBlob.push_back("abc");
        strBlob.push_back("def");
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
        strBlob.pop_back();
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
        strBlob.pop_back();
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
testStrBlob(const StrBlob& strBlob) {
    try {
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
Exercise_12_1::exercise_12_2() {
    StrBlob       strBlob_1;
    StrBlob       strBlob_2{"hello", "world"};
    StrBlob       strBlob_3 = {"wuhu", "best", "ok"};
    const StrBlob const_strBlob_1;
    const StrBlob const_strBlob_2{"yes", "you", "right"};
    StrBlob       strBlob_4({"ni", "hao"});

    std::cout << "strBlob_1 is:\n";
    testStrBlob(strBlob_1);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_2 is:\n";
    testStrBlob(strBlob_2);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_3 is:\n";
    testStrBlob(strBlob_3);
    std::cout << "\n-----------------------------------\n";

    std::cout << "const_strBlob_1 is:\n";
    testStrBlob(const_strBlob_1);
    std::cout << "\n-----------------------------------\n";

    std::cout << "const_strBlob_2 is:\n";
    testStrBlob(const_strBlob_2);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_4 is:\n";
    testStrBlob(strBlob_4);
    std::cout << "\n-----------------------------------\n";
}
//
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
//
std::vector<int>*
factory() {
    return new std::vector<int>;
}

void
set_vector(std::vector<int>* data) {
    int i;
    while (std::cin >> i) {
        data->push_back(i);
        if (std::cin.get() == '\n')
            break;
    }
}

void
print_vector(std::vector<int>* data) {
    for (const auto& val : *data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void
Exercise_12_1::exercise_12_6() {
    auto* data = factory();
    set_vector(data);
    print_vector(data);
    delete data;
    data = nullptr;
}
//
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
//
typedef std::shared_ptr<std::vector<int>> shared_ptr;

shared_ptr
factory_v2() {
    return std::make_shared<std::vector<int>>();
}

void
set_vector(const shared_ptr& data) {
    int i;
    while (std::cin >> i) {
        data->push_back(i);
        if (std::cin.get() == '\n')
            break;
    }
}

void
print_vector(const shared_ptr& data) {
    for (const auto& val : *data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void
Exercise_12_1::exercise_12_7() {
    auto data = factory_v2();
    set_vector(data);
    print_vector(data);
}
//
//------------------------------------------------------------------------------------------------

void
process(const std::shared_ptr<int>& ptr) {
    *ptr += 1;
}

void
Exercise_12_1::exercise_12_12() {
    auto p  = new int();
    auto sp = std::make_shared<int>();

    // (a) OK. Initialize a shared pointer `ptr` inside function `process` as a
    // copy of `sp`, increase the reference count. After the function is
    // executed, destory `ptr` and decrease the reference count.
    process(sp);

    // (b) Error. Cannot implicitly convert an ordinary pointer to a smart pointer.
    // process(new int());

    // (c) Error. Cannot implicitly convert an ordinary pointer to a smart pointer.
    // process(p);

    // (d) Error. Initialize a shared pointer `ptr` inside function `process`
    // using ordinary pointer `p`, increase the reference count to 1. After the
    // function is executed, destory `ptr` and decrease the reference count to 0,
    // thus freed the memory pointed by `ptr`. However, the original ordianry
    // pointer `p` still points to that memory.
    process(std::shared_ptr<int>(p));

    std::cout << "p is: " << *p << ", sp is: " << *sp << "\n";
}

//------------------------------------------------------------------------------------------------
//
/* The target that needs to be connected */
struct Destination {
    unsigned id;
    explicit Destination(unsigned destination_id = 0) : id(destination_id) {}
};

/* information of connection */
struct Connection {
    Destination* destination;
};

Connection
connect(Destination* des) {
    Connection new_connection{};
    new_connection.destination = des;
    std::cout << "Setup connection to " << new_connection.destination->id << "\n";
};

void
disconnect(Connection connection) {
    std::cout << "Stop connection to " << connection.destination->id << "\n";
    connection.destination = nullptr;
}

void
end_connection(Connection* p) {
    disconnect(*p);
}

void
f(Destination& d) {
    Connection                  c = connect(&d);
    std::shared_ptr<Connection> p(&c, end_connection);
}

void
Exercise_12_1::exercise_12_14() {
    Destination destination(5);
    f(destination);
}
//
//------------------------------------------------------------------------------------------------

void
f_v2(Destination& d) {
    Connection                  c = connect(&d);
    std::shared_ptr<Connection> p(&c, [](Connection* p) { disconnect(*p); });
}

void
Exercise_12_1::exercise_12_15() {
    Destination destination(6);
    f_v2(destination);
}

void
Exercise_12_1::exercise_12_16() {
    std::unique_ptr<int> p1(new int(42));
    /*
     *  error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with
     * _Tp = int; _Dp = std::default_delete<int>]’ unique_ptr(const unique_ptr&) = delete;
     *  */
    // std::unique_ptr<int> p2(p1);
    // std::unique_ptr<int> p3;
    // p3 = p1;
}


//------------------------------------------------------------------------------------------------
//
void
testStrBlob_v2(StrBlob& strBlob) {
    try {
        strBlob.push_back("abc");
        std::cout << "front: " << strBlob.front() << " back: " << strBlob.back() << "\n";
        strBlob.pop_back();
        std::cout << "front: " << strBlob.front() << " back: " << strBlob.back() << "\n";
        strBlob.begin().deref() = "transform";
        for (auto val = strBlob.begin();; val.incr())
            std::cout << "dereference: " << val.deref() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
testStrBlob_V3(const StrBlob& strBlob) {
    try {
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
testStrBlobPtr(StrBlobPtr& strBlobPtr) {
    try {
        strBlobPtr.deref() = "transform2";
        for (auto val = strBlobPtr;; val.incr())
            std::cout << "dereference: " << val.deref() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
Exercise_12_1::exercise_12_19() {
    StrBlob strBlob_1;
    StrBlob strBlob_2{"hello", "world"};
    StrBlob strBlob_3 = {"wuhu", "best", "ok"};
    StrBlob strBlob_4({"ni", "hao"});

    std::cout << "strBlob_1 is:\n";
    testStrBlob_v2(strBlob_1);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_2 is:\n";
    testStrBlob_v2(strBlob_2);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_3 is:\n";
    testStrBlob_v2(strBlob_3);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_4 is:\n";
    testStrBlob_v2(strBlob_4);
    std::cout << "\n-----------------------------------\n";

    const StrBlob const_strBlob_1;
    const StrBlob const_strBlob_2{"yes", "you", "right"};
    std::cout << "const_strBlob_1 is:\n";
    testStrBlob_V3(const_strBlob_1);
    std::cout << "\n-----------------------------------\n";

    std::cout << "const_strBlob_2 is:\n";
    testStrBlob_V3(const_strBlob_2);
    std::cout << "\n-----------------------------------\n";

    StrBlobPtr strBlobPtr_1;
    std::cout << "strBlobPtr_1 is:\n";
    testStrBlobPtr(strBlobPtr_1);
    std::cout << "\n-----------------------------------\n";

    StrBlobPtr strBlobPtr_2(strBlob_1);
    std::cout << "strBlobPtr_2 is:\n";
    testStrBlobPtr(strBlobPtr_2);
    std::cout << "\n-----------------------------------\n";
}
//
//------------------------------------------------------------------------------------------------

void
Exercise_12_1::exercise_12_20() {
    std::cout << "Input the file name: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream in(TEST_PATH + filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return;
    }
    StrBlob     words;
    std::string line;
    while (std::getline(in, line))
        words.push_back(line);
    StrBlobPtr begin = words.begin();
    for (StrBlob::size_type pos = 0; pos != words.size(); ++pos, begin.incr())
        std::cout << "line " << pos + 1 << ":\t" << begin.deref() << "\n";
}

//------------------------------------------------------------------------------------------------
//
void
testConstStrBlobPtr(ConstStrBlobPtr& constStrBlobPtr) {
    try {
        for (auto val = constStrBlobPtr;; val.inc())
            std::cout << "deref: " << val.deref() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
Exercise_12_1::exercise_12_22() {
    const StrBlob   csb({"This", "Blob"});
    ConstStrBlobPtr csbp(csb, csb.size());
    testConstStrBlobPtr(csbp);
    std::cout << "\n";
}
//
//------------------------------------------------------------------------------------------------
