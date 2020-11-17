#ifndef LEXER_H
# define LEXER_H

typedef struct	s_lexer {
	const char		*input;
	unsigned int	position;
	unsigned int	read_position;
	char			ch;
	void			(*read_char)(struct s_lexer *);
}				t_lexer;
t_lexer			l;

void			read_char(t_lexer *lexer);
#endif