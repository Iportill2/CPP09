
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "Error" << std::endl;
	else
	{
		try
		{
			PmergeMe pm(argv);
			std::cout << "Before: ";
			pm.printVec();
			pm.algorithm();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
