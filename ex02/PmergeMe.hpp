
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <string>
# include <climits>
# include <ctime>
# include <cstdlib>

class PmergeMe
{
	private:
		std::deque<int>		deq;
		std::vector<int>	vec;

		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

	public:
		PmergeMe(char **argv);
		~PmergeMe();
		const std::deque<int> &getDeq() const;
		const std::vector<int> &getVec() const;
		void	printVec() const;
		void	printDeq() const;
		void	throwExcep(void);
		void	algorithm(void);
		void	insertVec(std::vector<int> &vec);
		void	insertDeq(std::deque<int> &deq);
		void	mergeVec(std::vector<int> &vec);
		void	mergeDeq(std::deque<int> &deq);
};

#endif
