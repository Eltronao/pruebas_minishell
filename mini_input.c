#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
# include<readline/readline.h>
# include<readline/history.h>
#include <unistd.h>
#include "minishell.h"

void	sigtstphandle(int sigint)
{
	sigint = 0;
	write(2, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", sigint);
    rl_redisplay();
}

void	siginthandle(int sigint)
{
	sigint = 0;
	write(2, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", sigint);
    rl_redisplay();
}

int	main(void)
{
	char	*s;
    int     eof;

	rl_catch_signals = 0;
    eof = 0;
	signal(SIGINT, siginthandle);
    signal (SIGTSTP, sigtstphandle);
	while(!eof)
	{
        s = readline(">>>");
		if (s && *s)
		{
			mini_split(s);
			add_history(s);
			free(s);
		}
        if (!s)
            eof = 1;
    }
	rl_clear_history();
	return (0);
}