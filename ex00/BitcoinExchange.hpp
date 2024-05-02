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
	std::string _openFileName;
	//std::string _index;
	//std::map<int,std::string>  _date;
	//std::map<int,std::string> _exchangeRate;

	std::map<std::string,float> _dataCsv;
	std::map<std::string,float> _inputTxt;

	public:
		Bitcoin();
		Bitcoin(std::string file);
		~Bitcoin();


	void copyFileContent(); 

	void fromDataToMap();
	void fromInputToMap();	



};
#endif
//1 map
//2 stack