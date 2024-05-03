#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <iostream>
# include <fstream>// para el open
# include <map>// pares de clave valor

# include <fstream>
# include <sstream>
# include <map>
# include <string>
/*
En este código, example es un map que 
mapea int a std::string. Puedes insertar 
pares clave-valor en el map usando la 
sintaxis example[key] = value, y puedes 
acceder a los valores usando la sintaxis 
example[key].
*/
class Bitcoin
{
	private:
	std::string _nameAvOne;
	std::string _nameAvTwo;
	std::ifstream _FdFileOne;
	std::ifstream _FdFileTwo;


	std::string _openFileName;
	std::map<std::string,float> _dataCsv;


	public:
		Bitcoin();
		Bitcoin(std::string NameAvOne,std::string NameAvTwo,std::ifstream &ifsFileOne);
		Bitcoin(Bitcoin const & src);
		~Bitcoin();
		Bitcoin & operator=(Bitcoin const & rhs);
		void getData(std::ifstream &ifsFileOne);
		void calculateBalance();
		bool checkDate(const std::string date);

		void printMap(const std::map<std::string, float>& _dataCsv);


};
void getInfo(const char *nameAvOne,const char *nameAvTwo,std::ifstream &ifsFileOne);
void checkArguments(int ac,char **av);
#endif
//1 map
//2 stack

