#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstring>
#include <sstream>

class BitcoinExchange {
private: 
    std::ifstream DataBase, inputFile; 
    std::map<std::string ,std::string> data;
    std::map<std::string ,std::string> file;
    std::map<int , std::pair<std::string, std::string> > _File;
    bool check_file(std::map<int , std::pair<std::string, std::string> >::iterator& it);
    bool check_date(const std::string &time);
    bool check_atof(std::string value);
    void processDatabase();
    void processInput();
public:
    BitcoinExchange(const std::string& Filename);
    BitcoinExchange(BitcoinExchange const &copy);
    BitcoinExchange &operator=(BitcoinExchange const &copy);
	~BitcoinExchange();
    void processInputFile(void);
};