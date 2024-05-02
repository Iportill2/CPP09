#include "BitcoinExchange.hpp"



int main(int ac,char **av) 
{
	if(ac == 2)
	{
		std::string file = std::string(av[1]);

		Bitcoin s(file);
    	s.copyFileContent();
	}
	else
		std::cout << "Please, introduce the name of the file you like to read information." << std::endl;
    return 0;
}