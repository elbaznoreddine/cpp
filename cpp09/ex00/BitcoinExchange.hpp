#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, double> _db;
        bool isValidDate(std::string date);
        bool isValidValue(std::string str, double& value);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& b);
        BitcoinExchange& operator=(const BitcoinExchange& b);
        ~BitcoinExchange();

        void loadDatabase(std::string filename);
        void processInput(std::string filename);
};

#endif