#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) : DataBase("data.csv"), inputFile(filename.c_str())
{
    if (!DataBase.is_open() || !inputFile.is_open()) {
        throw std::runtime_error("Error: could not open files.");
    }
    processDatabase();
    processInput();
}

void BitcoinExchange::processDatabase()
{
    std::string line, key, value;
    while (std::getline(DataBase, line))
    {
        if (line != "date,exchange_rate" && !line.empty()) {
            key = line.substr(0, 10);
            value = line.substr(11);
            data[key] = value;
            key.clear();
            value.clear();
        }
        line.clear();
    }
}

void BitcoinExchange::processInput()
{
    std::string line, key, value;
    int index = 0;
    bool firstLine = true;
    bool dataFound = false;
    while (std::getline(inputFile, line))
    { 
            if(line.empty())
                continue;

            else if (firstLine && line != "date | value")
                std::cerr <<"Missing the header date | value\n";

            firstLine = false;
            size_t pos = line.find(" | ");
            if (pos == (size_t)-1) {
                key = line;
                value = "\0";
            } else {
                key = line.substr(0, pos);
                value = line.substr(pos + 3);
            }
            if(key != "date" && value != "value")
            {
             this->file[key] = value;
             dataFound = true;
             _File[index++] = std::make_pair(key, value); 
             key.clear();
             value.clear();
            }
            line.clear();
    }
    if (!dataFound)
        throw std::runtime_error("The file does not contain any data.");
}

std::string formatFloat(float value)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    std::string formatted = oss.str();
    size_t dotPos = formatted.find('.');
    if (dotPos != std::string::npos) {
        while (formatted[formatted.size() - 1] == '0')
        {
            formatted.erase(formatted.size() - 1);
        }
        if (formatted[formatted.size() - 1] == '.') {
            formatted.erase(formatted.size() - 1);
        }
    }
    return formatted;
}

void BitcoinExchange::processInputFile()
{
    std::map<int, std::pair<std::string, std::string> >::iterator it_2 = _File.begin();
    std::map<std::string, std::string>::iterator it;
    std::map<std::string, std::string>::reverse_iterator i_r = data.rbegin();

    while (it_2 != _File.end())
    {
        if (!check_file(it_2))
        {
            it_2++;
            continue;
        }
        it = data.lower_bound(it_2->second.first);
        if ((it != data.end()) && it->first > it_2->second.first)
            it--;

        float val1 = atof(it->second.c_str());
        float val2 = atof(it_2->second.second.c_str());
        if (it_2->second.first > i_r->first)
        {
            val1 = atof(i_r->second.c_str());
            std::cout << it_2->second.first << " => "<< it_2->second.second << " = " <<formatFloat(val1 * val2)<<std::endl;
        }
        else
            std::cout << it_2->second.first << " => "<< it_2->second.second << " = " <<formatFloat(val1 * val2)<<std::endl;
        it_2++;
    }
}

bool BitcoinExchange::check_file(std::map<int , std::pair<std::string, std::string> >::iterator& it)
{
	std::string date = it->second.first;
	std::string value = it->second.second;

    if (!check_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (!check_atof(value))
        return false;

    float numValue = atof(value.c_str());

    if (numValue < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (numValue > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::check_date(const std::string &time)
{
    if (time.size() != 10 || time[4] != '-' || time[7] != '-') {
        return false;
    }
    std::string year_str = time.substr(0, 4);
    std::string month_str = time.substr(5, 2);
    std::string day_str = time.substr(8, 2);

    int year = atoi(year_str.c_str());
    int month = atoi(month_str.c_str());
    int day = atoi(day_str.c_str());

    if (!year || !month || !day) {
        return false;
    } else if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        // Leap year
        if (month == 2 && day > 29) {
            return false;
        }
    } else {
        // Non-leap year
        if (month == 2 && day > 28) {
            return false;
        }
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    return true;
}

bool BitcoinExchange::check_atof(std::string value)
{
    int point = 0;
	for(unsigned long i=0; i < value.size(); i++)
	{
		if (value[i] == '-' && i ==0)
			i++;
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
		{	
			std::cerr << "Error: bad value. " <<std::endl;
			return false;
		}
		else if (value[i] == '.' && i > 1)
		{
			point++;
			if (value[i -1] < '0' || value[i - 1] > '9' || point > 1 
				|| ((i < value.size() && ( value[i + 1] < '0' || value[i + 1] > '9'))))
			{
				std::cerr << "Error: bad value. " <<std::endl;
				return false;
			}
		}
	}
	return (true);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	(*this) = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	data = copy.data;
	return(*this);
}

BitcoinExchange::~BitcoinExchange() { 
    DataBase.close(); 
    inputFile.close();
}