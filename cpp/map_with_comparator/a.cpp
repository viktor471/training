#include <iostream>
#include <map>
#include <boost/algorithm/string.hpp>

struct ICaseCompare {
    using is_transparent = void;

    bool operator()(const auto& lhs, const auto& rhs) const { return boost::ilexicographical_compare(lhs, rhs); }
};

struct my_less {
    using is_transparent = void;

    bool operator()(const auto& a, const auto& b) const {
        return a < b;
    }
};

using my_less = std::less<void>;

struct my_more {
    using is_transparent = void;

    bool operator()(const auto& a, const auto& b) const {
        return a > b;
    }
};


int main() {
    std::map<std::string, int, ICaseCompare> my_map;

    my_map["HELLO"] = 44;
    my_map["hello"] = 33;
    my_map["aaaa"] = 55;

    for (auto & [key, value] : my_map) {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }
    std::cout << "my_map[\"hello\"]: " << my_map["hello"] << std::endl;
    std::cout << "my_map[\"HELLO\"]: " << my_map["HELLO"] << std::endl;

    std::map<int, int, my_less> int_map;

    int_map[3] = 7;
    int_map[4] = 6;
    int_map[6] = 5;
    int_map[8] = 7;
    int_map[8] = 99;

    std::cout << "\n";
    for (auto & [key, value]: int_map) {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }

    std::map<std::string, int, my_less> str_map_less;
    str_map_less["hello"] = 33;
    str_map_less["HELLO"] = 44;
    str_map_less["b"] = 55;
    str_map_less["c"] = 66;

    std::cout << "\n";
    std::cout << "str map with less" << "\n";
    for (auto & [key, value]: str_map_less) {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }

    std::cout << "\n";
    std::map<std::string, int, my_more> str_map_more;
    str_map_more["hello"] = 33;
    str_map_more["HELLO"] = 44;
    str_map_more["b"] = 55;
    str_map_more["c"] = 66;

    std::cout << "str map with more" << "\n";
    for (auto & [key, value]: str_map_more) {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }
}