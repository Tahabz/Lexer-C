#include "lexer.h"
#include "globals.h"

t_lexer	new(const char *input)
{
	t_lexer l;
	l.input = input;
	l.read_char = &read_char;
	l.read_char(&l);
	return (l);
}

void	read_char(t_lexer *lexer)
{
	if (lexer->read_position >= strlen(lexer->input))
		lexer->ch = '\0';
	else
		lexer->ch = lexer->input[lexer->read_position];
	lexer->position = lexer->read_position;
	lexer->read_position += 1;
}

int		main(void)
{
	l = new("Hello World");
	printf("%s", l.input);
	return 1;
}