#include <random>
#include <string>

std::string generateRandomString(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, characters.size() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += characters[dist(generator)];
    }
    return result;
}

double generateRandomPrice() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> dist(1.0, 100.0); // Prices between $1 and $100
    return dist(generator);
}

int generateRandomQuantity() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(1, 50); // Quantity between 1 and 50
    return dist(generator);
}