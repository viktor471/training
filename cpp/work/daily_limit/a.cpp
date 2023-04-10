#include <iostream>

void show_new_limit(size_t daySeconds,
                    size_t limit) {
    std::cout << ((limit * daySeconds) / (24 * 3600l)) << std::endl;
}

int main() {
    size_t daySeconds = 1;
    size_t seconds_in_day = 24 * 3600;
    size_t limit = seconds_in_day;

    limit -= 200;

    show_new_limit(daySeconds, limit);

    limit = seconds_in_day + 200;

    show_new_limit(daySeconds, limit);
}