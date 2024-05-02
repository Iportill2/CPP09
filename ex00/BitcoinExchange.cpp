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
void Bitcoin::copyFileContent() 
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
}

void Bitcoin::fromDataToMap()
{

    std::ifstream file(_openFileName);
    std::map<std::string, std::string> myMap;

    if (!file) {
        std::cerr << "No se pudo abrir el archivo example.txt";
        return ;
    }

    std::string line;
    while (std::getline(file, line)) 
	{
        std::istringstream iss(line);
        std::string key, value;

        if (std::getline(iss, key, ',') && std::getline(iss, value)) 
		{
        	myMap[key] = value;
        }
    }

    file.close();
    return ;
}

void Bitcoin::fromInputToMap()
{
	
}