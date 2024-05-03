#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
std::cout << "Bitcoin created successfully!"  << std::endl;
}
Bitcoin::Bitcoin(std::string file) : _openFileName(file)
{
	std::cout << "Contructor Bitcoin created successfully! " << _openFileName << std::endl;
}	
Bitcoin::~Bitcoin()
{
	
}

void Bitcoin::fromDataToMap()
{
    std::string line;
    std::string date;
	std::string rate;

    std::ifstream file(_openFileName);

    if (!file) {
        std::cerr << "Error opening file " << _openFileName << std::endl;
        return ;
    }


    std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		date = line.substr(0, line.find(','));
		rate = line.substr(line.find(',') + 1, line.length());
		_dataCsv[date] = std::atof(rate.c_str());
	}
    //std::cout << "copiado el contenido en el map" << std::endl;
    //printMap(_dataCsv);
    file.close();
    return ;
}

void Bitcoin::printMap(const std::map<std::string, float>& _dataCsv) 
{
    //
    std::map<std::string, float>::const_iterator it;
    for (it = _dataCsv.begin(); it != _dataCsv.end(); ++it) 
    {
        std::cout << "Clave: " << it->first << ", Valor: " << it->second << std::endl;
    }
}
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
void	Bitcoin::calculateBalance(const char *inFile)
{
	std::ifstream file(inFile);
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
void checkArguments(int ac,char **av)
{
    if(ac == 3)
	{
		std::string file = std::string(av[1]);
		Bitcoin s(file);
		s.calculateBalance(av[2]);
	}
	else
		std::cout << "Please, introduce the name of the file you like to read information and the name of file with your bitcoins." << std::endl;
}

/* void Bitcoin::copyFileContent() 
{
    std::ifstream inputFile(_openFileName);
    std::ofstream outputFile("docu");

    if (!inputFile) 
	{
        std::cerr << "No se pudo abrir el archivo "<< _openFileName << std::endl;
        return;
    }

    if (!outputFile) 
	{
        std::cerr << "No se pudo abrir el archivo docu";
        return;
    }

    char ch;
    while (inputFile >> std::noskipws >> ch) 
	{
        outputFile << ch;
    }

    inputFile.close();
    outputFile.close();
} */