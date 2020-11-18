#include "globals.h"
#include "get_next_line.h"
#include "lexer.h"
#include "libft.h"

int		main(void)
{
	int 	i;
	char	*line;
	i = 0;
	char *prompt = "BAZ >>$ ";
	ft_putstr_fd(prompt, 0);
	while (get_next_line(0, &line) != 0)
	{
		if (strcmp(line, "exit") == 0)
			break ;
		t_token tok;
		l = new(line);
		while (1)
		{
			tok = next_token(&l);
			if (strcmp(tok.type, "EOF") == 0)
				break ;
			printf("Token Type: {%s}\nToken Literal: {%s}\n", tok.type, tok.literal);
			i++;
		}
		ft_putstr_fd(prompt, 0);
		free(line);
	}
	close(0);
	free(line);
}