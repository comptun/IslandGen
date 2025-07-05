#include <iostream>

#include "LuauRandom.h"
#include "Application.h"

int main() {
    Application app;

    app.Run();

    LuauRandom rand(1234);

    for (int i = 0; i < 10000; ++i) {
        std::cout << rand.NextNumber(0, 10) << " ";
    }

    return 0;
}