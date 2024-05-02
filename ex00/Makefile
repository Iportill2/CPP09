NAME = btc


SRCS = 	main.cpp \
		BitcoinExchange.cpp
		


CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 
OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}

%.o: %.cpp
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} ${SRCS} -o ${NAME}
		@echo "\n$(GREEN) Created $(NAME) ✓ $(DEF_COLOR)\n"

all:	${NAME}

-include ${DEPS}

clean:
		@${RM} ${OBJS} ${DEPS}
		@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"
fclean:
		@${RM} ${OBJS} ${DEPS} ${NAME}
		@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re