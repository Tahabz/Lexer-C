#include "globals.h"
#include "lexer.h"

int			main(void)
{
	int ok = 0;
	t_token tok;
	const char *input = "=;(),+{}!/*<>-";
	t_token tests[] = {
		{g_assign, "="},
		{g_semmicolon, ";"},
		{g_lparen, "("},
		{g_rparen, ")"},
		{g_comma, ","},
		{g_plus, "+"},
		{g_lbrace, "{"},
		{g_rbrace, "}"},
		{g_bang, "!"},
		{g_slash, "/"},
		{g_asterik, "*"},
		{g_lt, "<"},
		{g_gt, ">"},
		{g_minus, "-"},
		{g_eof, ""},
	};
	l = new(input);
	for (int i = 0; i < 3; i++)
	{
		tok = next_token(&l);
		if (strcmp(tok.literal, tests[i].literal) != 0) {
			printf("Test [%d] ERROR:\nToken Literal mismatch \nExpected:'%s'\nGot:	'%s'\n", i, tests[i].literal, tok.literal);
			ok = 1;
		}
		if (strcmp(tok.type, tests[i].type) != 0) {
			printf("Test [%d] ERROR:\nToken Type mismatch \nExpected:'%s'\nGot:	'%s'\n", i, tests[i].type, tok.type);
			ok = 1;
		}
	}
	if (ok == 0)
		printf("OK\n");
	return 1;
}