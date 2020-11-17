#ifndef LEXER_H
# define LEXER_H
typedef struct	s_lexer {
	const char		*input;
	unsigned int	position;
	unsigned int	read_position;
	char			ch;
	void			(*read_char)(struct s_lexer *);
	void			(*next_token)(struct s_lexer *);
	void			(*skip_white_spaces)(struct s_lexer *);
}				t_lexer;
t_lexer			l;

void			read_char(t_lexer *lexer);
t_token			next_token(t_lexer *lexer);
void			skip_white_spaces(t_lexer *lexer);
t_token			new_token(const char *type, const char *literal);
#endif