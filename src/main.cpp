#include <iostream>

void control_motor(bool enable) {
    if (enable) {
        std::cout << "Motor enabled\n";
    } else {
        std::cout << "Motor disabled\n";
    }
}

int main() {
    control_motor(true);
    control_motor(false);
    return 0;
}
