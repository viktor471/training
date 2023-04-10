#include <iostream>
#include <ctime>
#include <fstream>


time_t get_actual_limit(int imp_limit, time_t seconds_today) {
    return (imp_limit * seconds_today) / (24 * 3600l);
}

int main(int argc, char** argv) {
    int imp_limit = 200;

    if (argc > 1)
        imp_limit = std::stoi(std::string(argv[1]));

    std::ofstream file;
    file.open("limits", std::ios::out);

    for (int i = 0; i <= 24 * 3600; i++) {
        file << get_actual_limit(imp_limit, i) << "\n";
    }

    file.close();
}