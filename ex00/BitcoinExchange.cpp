

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->getData();
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
		this->_db = rhs._db;
	return *this;
}

void BitcoinExchange::getData()
{
	std::ifstream data("data.csv");

	if (!data.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return;
	}

	std::string line;
	std::string date;
	std::string rate;

	std::getline(data, line); 
	while (std::getline(data, line))
	{
		date = line.substr(0, line.find(','));
		rate = line.substr(line.find(',') + 1, line.length());
		_db[date] = std::atof(rate.c_str());
	}
	data.close();
}

void	BitcoinExchange::calculateBalance(const char *inFile)
{
	std::ifstream file(inFile);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::string date;
	std::string amountStr;
	float amount;
	
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		date = line.substr(0, pipePos);
		amountStr = line.substr(pipePos + 3);
		
		// Check for valid number format
		char *endptr;
		amount = std::strtof(amountStr.c_str(), &endptr);
		if (*endptr != '\0' && *endptr != '\n')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (!checkDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
		}
		else if (amount < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (amount > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, float>::const_iterator it = this->_db.lower_bound(date);
			if (it != this->_db.end() && it->first == date)
			{
				// Exact match found
				std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
			}
			else if (it != this->_db.begin())
			{
				// Use the previous date (most recent before the given date)
				--it;
				std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
			}
			else
			{
				std::cout << "Error: no data available for date => " << date << std::endl;
			}
		}
	}
	file.close();
}

/* checks if the date is between 2009-01-02 and 2022-03-29 */
bool	BitcoinExchange::checkDate(const std::string date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
		
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	// Check if all characters are digits
	for (size_t i = 0; i < year.length(); i++)
		if (!std::isdigit(year[i])) return false;
	for (size_t i = 0; i < month.length(); i++)
		if (!std::isdigit(month[i])) return false;
	for (size_t i = 0; i < day.length(); i++)
		if (!std::isdigit(day[i])) return false;

	int y = std::atoi(year.c_str());
	int m = std::atoi(month.c_str());
	int d = std::atoi(day.c_str());

	if (y < 2009 || y > 2022)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	
	// Check for months with 30 days
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return false;
	
	// Check for February
	if (m == 2) {
		bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
		if (d > (isLeap ? 29 : 28))
			return false;
	}
	
	return true;
}

