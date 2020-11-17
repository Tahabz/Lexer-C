#include "globals.h"
#include "lexer.h"

t_lexer		new(const char *input)
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

void			read_char(t_lexer *lexer)
{
	if (lexer->read_position >= strlen(lexer->input))
		lexer->ch = '\0';
	else
		lexer->ch = lexer->input[lexer->read_position];
	lexer->position = lexer->read_position;
	lexer->read_position += 1;
}

t_token		next_token(t_lexer *lexer)
{
	t_token tok;
	lexer->skip_white_spaces(lexer);
	if (lexer->ch == '=')
		tok = new_token(g_assign, "=");
	else if (lexer->ch == ';')
		tok = new_token(g_semmicolon, ";");
	else if (lexer->ch == '(')
		tok = new_token(g_lparen, "(");
	else if (lexer->ch == ')')
		tok = new_token(g_rparen, ")");
	else if (lexer->ch == ',')
		tok = new_token(g_comma, ",");
	else if (lexer->ch == '+')
		tok = new_token(g_plus, "+");
	else if (lexer->ch == '-')
		tok = new_token(g_minus, "-");
	else if (lexer->ch == '{')
		tok = new_token(g_lbrace, "{");
	else if (lexer->ch == '}')
		tok = new_token(g_rbrace, "}");
	else if (lexer->ch == '!')
		tok = new_token(g_bang, "!");
	else if (lexer->ch == '/')
		tok = new_token(g_slash, "/");
	else if (lexer->ch == '*')
		tok = new_token(g_asterik, "*");
	else if (lexer->ch == '<')
		tok = new_token(g_lt, "<");
	else if (lexer->ch == '>')
		tok = new_token(g_gt, ">");
	else if (lexer->ch == '\0')
		tok = new_token(g_eof, "\0");
	l.read_char(lexer);
	return (tok);
}

t_token		new_token(const char *type, const char *literal)
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