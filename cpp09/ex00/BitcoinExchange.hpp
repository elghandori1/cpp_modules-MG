#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstring>
#include <sstream>

class BitcoinExchange
{
private: 
    std::ifstream DataBase, inputFile; 
    std::map<std::string ,std::string> data;
    std::map<std::string ,std::string> file;
    std::map<int , std::pair<std::string, std::string> > _File;
    bool check_file(std::map<int , std::pair<std::string, std::string> >::iterator& it);
    bool check_date(std::string time);
    bool check_value(std::string value);
    void processDatabase();
    void processInput();
    void processInputFile(void);
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& Filename);
    BitcoinExchange(BitcoinExchange const &copy);
    BitcoinExchange &operator=(BitcoinExchange const &copy);
	~BitcoinExchange();
};
