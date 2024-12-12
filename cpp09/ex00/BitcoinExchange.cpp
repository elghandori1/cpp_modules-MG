#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) : DataBase("data.csv"), inputFile(filename.c_str())
{
    if (!DataBase.is_open() || !inputFile.is_open()) {
        throw std::runtime_error("Error: could not open files.");
    }
    process();
}

void BitcoinExchange::process()
{
    std::string file, key, value;
    while (std::getline(DataBase, file))
    {
        if (file != "date,exchange_rate" && !file.empty()) {
            key.insert(0, file, 0, 10);
            value.insert(0, file, 11, file.find('\n', 11));
            data[key] = value;
            key.clear();
            value.clear();
        }
        file.clear();
    }

    int i = 0;
    bool firstLine = true;
    bool dataFound = false;
    while (std::getline(inputFile, file))
    {
        if (file.empty()) {
            continue;
        }
        if (firstLine)
        {
            if (file != "date | value") {
                throw std::runtime_error("Missing the header \"date | value\"");
            }
            firstLine = false;
        } else {
            size_t pos = file.find(" | ");
            if (pos == std::string::npos) {
                key = file;
                value = "\0";
            } else {
                key = file.substr(0, pos);
                value = file.substr(pos + 3);
            }
            this->file[key] = value;
            dataFound = true;
            _File[i++] = std::make_pair(key, value);
            key.clear();
            value.clear();
        }
        file.clear();
    }
    if (!dataFound)
        throw std::runtime_error("The file does not contain any data after the header.");
    //seewdata();
}


// void BitcoinExchange::seewdata()
// {
//     std::map<int, std::pair<std::string, std::string> >::iterator it;
//     for (it = _File.begin(); it != _File.end(); ++it) {
//         std::cout << "Index: " << it->first << ", Date: " << it->second.first << ", Value: " << it->second.second << std::endl;
//     }
// }

void BitcoinExchange::processInputFile()
{
std::map<std::string , std::string>::iterator it_f;
std::map<int , std::pair<std::string, std::string> >::iterator it_2 = _File.begin();
std::map<std::string , std::string>::reverse_iterator i = data.rbegin();

    float x,y;
	while (it_2 != _File.end())
	{
		if (!check_file(it_2))
		{
			it_2++;
			continue ;
		}
		it_f = data.lower_bound(it_2->second.first);
		if ((it_f != data.end()) && it_f->first > it_2->second.first)
			it_f--;
		x = atof(it_f->second.c_str());
		y = atof(it_2->second.second.c_str());
		if (it_2->second.first > i->first)
		{
			x = atof(i->second.c_str());
			std::cout  << std::fixed << std::setprecision(2) << it_2->second.first << " => " << it_2->second.second << " = " << x * y <<std::endl;
		}
		else
			std::cout  << std::fixed << std::setprecision(2) << it_2->second.first << " => " << it_2->second.second << " = " << x * y <<std::endl;
		it_2++;
	}
}

bool BitcoinExchange::check_file(std::map<int , std::pair<std::string, std::string> >::iterator& it)
{
	std::string date = it->second.first;
	std::string value = it->second.second;

    // Check the date format
    if (!string_to_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    // Check the value format
    if (!check_atof(value))
        return false;

    float numValue = atof(value.c_str());

    // Validate range of the value
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

bool BitcoinExchange::string_to_date(const std::string &time)
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

    // Months with 30 days
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
		if ((value[i] < '0' || value[i] > '9') && value[i] != ' ' && value[i] != '.')
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

BitcoinExchange::~BitcoinExchange() {}