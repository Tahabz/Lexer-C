#ifndef GLOBALS_H
# define GLOBALS_H
# include <string.h>
# include <stdio.h>

extern const char	*g_illegal;
extern const char	*g_eof;
extern const char	*g_ident;
extern const char	*g_assign;
extern const char	*g_int;
extern const char	*g_plus;
extern const char	*g_comma;
extern const char	*g_semmicolon;
extern const char	*g_lparen;
extern const char	*g_rparen;
extern const char	*g_lbrace;
extern const char	*g_rbrace;
extern const char	*g_function;
extern const char	*g_let;
extern const char	*g_minus;
extern const char	*g_bang;
extern const char	*g_asterik;
extern const char	*g_slash;
extern const char	*g_lt;
extern const char	*g_gt;
extern const char	*g_true;
extern const char	*g_false;
extern const char	*g_if;
extern const char	*g_else;
extern const char	*g_return;
extern const char	*g_eq;
extern const char	*g_not_eq;
extern const char	*keys[];
typedef struct		s_token {
	const char *type;
	const char *literal;
}					t_token;
#endif
