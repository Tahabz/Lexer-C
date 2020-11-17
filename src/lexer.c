#include "globals.h"
#include "lexer.h"

t_lexer	new(const char *input)
{
	t_lexer l;
	l.input = input;
	l.read_position = 0;
	l.position = 0;
	l.read_char = &read_char;
	l.skip_white_spaces = &skip_white_spaces;
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

t_token	next_token(t_lexer *lexer)
{
	t_token tok;
	lexer->skip_white_spaces(lexer);
	if (lexer->ch == '=')
		tok = new_token(g_assign, "=");
	else if (lexer->ch == ';')
		tok = new_token(g_semmicolon, ";");
	else if (lexer->ch == '\0')
		tok = new_token(g_eof, "\0");
	l.read_char(lexer);
	return (tok);
}

t_token	new_token(const char *type, const char *literal)
{
	t_token tok;
	tok.literal = literal;
	tok.type = type;
	return (tok);
}

void			skip_white_spaces(t_lexer *lexer)
{
	while (l.ch == ' ' || l.ch == '\t' || l.ch == '\n' || l.ch == '\r')
		l.read_char(lexer);
}

int		main(void)
{
	int ok = 0;
	t_token tok;
	const char *input = "=;";
	t_token tests[] = {
		{g_assign, "="},
		{g_semmicolon, ";"},
		{g_eof, ""},
	};
	l = new(input);
	for (int i = 0; i < 3; i++)
	{
		tok = next_token(&l);
		if (strcmp(tok.literal, tests[i].literal) != 0) {
			printf("Test N: %d ERROR:\nToken Literal mismatch \nExpected:'%s'\nGot:	'%s'\n", i, tests[i].literal, tok.literal);
			ok = 1;
		}
		if (strcmp(tok.type, tests[i].type) != 0) {
			printf("Test N: %d ERROR:\nToken Type mismatch \nExpected:'%s'\nGot:	'%s'\n", i, tests[i].type, tok.type);
			ok = 1;
		}
	}
	if (ok == 0)
		printf("OK\n");
	return 1;
}