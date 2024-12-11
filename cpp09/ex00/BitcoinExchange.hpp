#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstring>


class BitcoinExchange {
private: 
    std::ifstream DataBase, inputFile; 
    std::map<std::string ,std::string> data;
    std::map<std::string ,std::string> file;
    bool check_file(std::map<std::string, std::string>::iterator &it);
    bool string_to_date(const std::string &time);
    bool check_atof(const std::string &value);
    void process();
    void seewdata();
public:
    BitcoinExchange(const std::string& Filename);
    void processInputFile(void);
    ~BitcoinExchange();
};
