#include "string.h"
#include "libft.h"

const char *keys[]			= {
	"let",
	"fn",
	"true",
	"false",
	"if",
	"else",
	"return"
};
const char *g_illegal		= "ILLEGAL";
const char *g_eof			= "EOF";
const char *g_ident			= "IDENT";
const char *g_assign		= "=";
const char *g_int			= "INT";
const char *g_plus			= "+";
const char *g_comma			= ",";
const char *g_semmicolon	= ";";
const char *g_lparen		= "(";
const char *g_rparen		= ")";
const char *g_lbrace 		= "{";
const char *g_rbrace 		= "}";
const char *g_function 		= "FUNCTION";
const char *g_let 			= "LET";
const char *g_minus 		= "-";
const char *g_bang 			= "!";
const char *g_asterik 		= "*";
const char *g_slash 		= "/";
const char *g_lt 			= "<";
const char *g_gt 			= ">";
const char *g_true 			= "true";
const char *g_false 		= "false";
const char *g_if 			= "if";
const char *g_else 			= "else";
const char *g_return 		= "return";
const char *g_eq 			= "==";
const char *g_not_eq 		= "!=";

const char *get_key_type(const char *literal) {
	if (strcmp(literal, "let") == 0)
		return g_let;
	else if (strcmp(literal, "fn") == 0)
		return g_function;
	else if (strcmp(literal, "true") == 0)
		return g_true;
	else if (strcmp(literal, "false") == 0)
		return g_false;
	else if (strcmp(literal, "if") == 0)
		return g_if;
	else if (strcmp(literal, "else") == 0)
		return g_else;
	return g_return;
}

const char *lookup_ident(const char *literal)
{
	unsigned int	len;
	int						i;

	i = 0;
	len = sizeof(keys) / sizeof(*keys);
	while (i < len)
	{
		if (strcmp(literal, keys[i]) == 0)
			return get_key_type(literal);
		i++;
	}
	return (g_ident);
}