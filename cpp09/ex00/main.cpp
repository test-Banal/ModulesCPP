#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <database_file> <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.readDataBase(argv[1]);
    exchange.readInput(argv[2]);

    return 0;
}

