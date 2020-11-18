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
		l = new(line);
		t_token tok;
		while (line[i])
		{
			tok = next_token(&l);
			if (strcmp(tok.type, "EOF") == 0)
				break ;
			printf("Token Type: {%s}\nToken Literal: {%s}\n", tok.type, tok.literal);
			fflush(stdin);
			i++;
		}
		if (strcmp(line, "exit") == 0)
			break ;
		ft_putstr_fd(prompt, 0);
		free(line);
	}
	close(0);
	free(line);
}