#include "RPN.hpp"
rpn::rpn( void ) {}

rpn::rpn( rpn const & rhs ) { *this = rhs; }

rpn::~rpn( void ) {}

rpn & rpn::operator=(rpn const & rhs)
{
	this->_stack = rhs._stack;
	return *this;
}


bool	rpn::operation(const char op)
{
	int a;
	int b;

	if (this->_stack.size() < 2)
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	a = this->_stack.top();
	this->_stack.pop();
	b = this->_stack.top();
	this->_stack.pop();
	switch (op)
	{
		case '+':
			this->_stack.push(b + a);
			break;
		case '-':
			this->_stack.push(b - a);
			break;
		case '*':
			this->_stack.push(b * a);
			break;
		case '/':
			this->_stack.push(b / a);
			break;
	}
	return (true);
}

/* RPN::RPN( void ) {}

RPN::RPN( RPN const & rhs ) { *this = rhs; }

RPN::~RPN( void ) {}

RPN & RPN::operator=(RPN const & rhs)
{
	this->_stack = rhs._stack;
	return *this;
}

bool	RPN::operation(const char op)
{
	int a;
	int b;

	if (this->_stack.size() < 2)
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	a = this->_stack.top();
	this->_stack.pop();
	b = this->_stack.top();
	this->_stack.pop();
	switch (op)
	{
		case '+':
			this->_stack.push(b + a);
			break;
		case '-':
			this->_stack.push(b - a);
			break;
		case '*':
			this->_stack.push(b * a);
			break;
		case '/':
			this->_stack.push(b / a);
			break;
	}
	return (true);
}

void RPN::pushNum(const int num)
{
	this->_stack.push(num);
}

int		RPN::topStack(void) const
{
	return (this->_stack.top());
}
 */