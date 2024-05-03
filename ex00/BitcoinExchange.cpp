
#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void)
{
	//this->getData();
	return;
}
Bitcoin::Bitcoin(std::string NameAvOne,std::string NameAvTwo)
{
	_nameAvOne = NameAvOne;
	_nameAvTwo = NameAvTwo;
	this->getData();
	return;
}
Bitcoin::Bitcoin(Bitcoin const & src)
{
	*this = src;
	return;
}

Bitcoin::~Bitcoin(void)
{
	return;
}

Bitcoin & Bitcoin::operator=(Bitcoin const & rhs)
{
	this->_openFileName = rhs._openFileName;
	this->_dataCsv = rhs._dataCsv; 
	return *this;
}

void Bitcoin::getData()
{
	std::ifstream fd1 (_nameAvOne);
	if(fd1.fail())
		return;
	//std::cout << "_nameAvOne = " << _nameAvOne << std::endl;
	if (!fd1.is_open())
	{
		std::cerr << "Error opening file named " << _nameAvOne << std::endl;
		return;
	}

	std::string line;
	std::string date;
	std::string rate;

	std::getline(fd1, line); // skip first line
	while (std::getline(fd1, line))
	{
		date = line.substr(0, line.find(','));
		rate = line.substr(line.find(',') + 1, line.length());
		_dataCsv[date] = std::atof(rate.c_str());
	}
	fd1.close();
	calculateBalance();
}

void	Bitcoin::calculateBalance()
{

	std::ifstream file(_nameAvTwo);
	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	std::string line;
	std::string date;
	float amount;
	
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		if (line.empty() || line.length() < 12)
		{
			std::cout << "Error: Bad input => " << line << std::endl;
			continue;
		}
		size_t div = line.find_first_of(" |");
		date = line.substr(0, div);
		amount = std::atof(line.substr(line.find('|') + 2).c_str());
		if (!checkDate(date)){

			std::cout << "Error: Bad date => " << date << std::endl;
		}
		else if (amount < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (amount > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, float>::const_iterator it = this->_dataCsv.upper_bound(date);
			//std::cout << "date*: " << date << std::endl;
			if (it->first.compare(date) != 0)
				--it;
			std::cout << date << " => " << amount << " = " << it->second*amount << "\n";
		}
	}
	file.close();
}

/* checks if the date is between 0000-00-00 and 2024-01-01 */
bool	Bitcoin::checkDate(const std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);


	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return false;
	if (std::atoi(year.c_str()) < 0 || std::atoi(year.c_str()) > 2024)
		return false;
	if (std::atoi(month.c_str()) < 0 || std::atoi(month.c_str()) > 12)
		return false;
	if (std::atoi(day.c_str()) < 0 || std::atoi(day.c_str()) > 31)
		return false;
	return true;
}

void checkArguments(int ac,char **av)
{
    if(ac == 3)
	{
		std::string NameAvOne = std::string(av[1]);
		std::ifstream fd1 (NameAvOne);
		std::string NameAvTwo = std::string(av[2]);
		std::ifstream fd2(NameAvTwo);

		if (!fd1.is_open() || !fd2.is_open())
		{
			std::cout << "Error opening file" << std::endl;
			return ;
		}
		fd1.close();
		fd2.close();
		//if everything its OK call to contructor
		Bitcoin s(NameAvOne,NameAvTwo);
	}
	else
		std::cout << "Please, introduce the name of the file you like to read information and the name of file with your bitcoins." << std::endl;
}

