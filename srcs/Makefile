FLAGS = -Wall -Wextra -Werror
INCLUDES = ../includes
NAME = lexer
LIBS = ../libs/libft.a
SRCS = 	lexer.c \
		lexer_tests.c \
		token/token.c \

all : lib $(NAME)
	@echo "Building up the lexer.."

$(NAME): $(SRCS)
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIBS) -I $(INCLUDES)

lib: $(LIBS)
	cd libft; make

clean:
	rm -rf lexer

fclean: clean
	rm -rf lexer
	cd libft: make fclean

re: fclean all