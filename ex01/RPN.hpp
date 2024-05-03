#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

//usaremos stack para este ejercicio
//ejemplo: 3 4 + RESULTADO 7 
/*
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
*/


#endif


/* class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN( void );
		RPN( RPN const & rhs );
		~RPN( void );

		RPN & operator=(RPN const & rhs);

		bool	operation(const char op);
		
		void 	pushNum(const int num);
		int		topStack(void) const;
		
}; */

