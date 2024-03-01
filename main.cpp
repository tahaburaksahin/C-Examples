#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto idontknowhowtonameit(std::vector<int> v) -> void {
    v.push_back(1);
}

auto fun(int x) -> void {
    x += 10;
}

auto main() -> int {
/*//    std::cout << "Hello world";

//    auto x = int();
//    auto x = 17;
//    int x = 0;
//    std::cout << x;

    auto text = std::string("some text");
//    std::cout << text;
    auto x = int();

    std::cin >> text;
    std::cin >> x;

    text += " there";

    std::cout << text << ' ' << x;*/

/*//    auto s1 = std::string();
//    auto s2 = std::string();
//
//    std::cin >> s1 >> s2;
////    std::cout << s1 << " --- " << s2;
//    std::cout << (s1 == s2);

//    auto numbers = std::vector<int>();
//    numbers.push_back(3);
//    numbers.push_back(1);
//    numbers.push_back(2);
//
//    for (auto e : numbers) {
//        std::cout << e << ' ';
//    }
//    std::cout << '\n';
//
//    numbers.pop_back();
//
//    for (auto e : numbers) {
//        std::cout << e << ' ';
//    }
//    std::cout << '\n';

//    auto vec1 = std::vector<int>{1, 2, 3};
//    auto vec2 = std::vector<int>{1, 2};
////    vec2.push_back(3);
//
////    std::cout << (vec1 == vec2);
//    std::cout << (vec1 > vec2);*/

/*    auto words = std::vector<std::string>{
        "hello", "and", "zebra", "some", "text"
    };

    std::ranges::sort(words);

//    for (auto str : words) {
//        std::cout << str << ' ';
//    }

    std::cout << words;*/

    auto v = std::vector<int>{1, 2, 3};
    idontknowhowtonameit(v);
    std::cout << v.size();

    auto x = 10;
    fun(x);
    std::cout << x;
}