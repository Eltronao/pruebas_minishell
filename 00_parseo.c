/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parseo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:08:10 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/07 18:19:28 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include "fcntl.h"
#include <stdio.h>

char	*parse_file(char *s, int *n);
void	arg_init(t_complex *args);
int	take_in(char *s, t_complex *args);
int	take_out(char *s, t_complex *args);
int ft_is_space(int n);

t_complex	*parser(char *s)
{
	int			now;
	int			prev;
	t_complex	*args;

	
	now = 0;
	prev = 0;
	args = malloc(sizeof (t_complex));
	arg_init(args);
	while (s[now])
	{
		if (s[now] == '<' && s[now - 1] != '<')
			now += take_in(&s[now], args);
		else if (s[now] == '>' && s[now - 1] != '>')
			now += take_out(&s[now], args);
//		else if (s[now] == '$')
//			now += expand(&s[now + 1], args);
//		else if (ft_is_alph(&s[n]) )
		now++;
	}
	return(args);
}

//int expand

void	arg_init(t_complex *args)
{
	args->in_ty = 0;
	args->out_ty = 0;
	args->limit = NULL;
	args->cmd_cnt = 0;
}
int	take_in(char *s, t_complex *args)
{
	int		n;
	int		m;
	char	*name;

	n = 0;
	name = 0;
	if (s[n + 1] == '<')
	{
		args->in_ty = 2;
		n += 2;
		args->limit = parse_file(&s[n], &n);
	}
	else
	{
		args->in_ty = 1;
		n += 1;
		name = parse_file(&s[n], &n);
		args->in = open(name, O_RDONLY | O_TRUNC);
		if (args->in == -1)
			exit (1);
	}
	if (name)
	{
		printf("input file name detected: %s\n", name);
		free(name); 
	}
	else
		printf("heredoc input detected\n");
	return (n);
}
int	take_out(char *s, t_complex *args)
{
	int		n;
	int		m;
	char	*name;

	n = 0;
	if (s[n + 1] == '>')
	{
		args->out_ty = 2;
		n += 2;
		name = parse_file(&s[n], &n);
		args->out = open(name, O_WRONLY | O_CREAT | O_APPEND);
		if (args->out == -1)
			exit (-1);
	}
	else
	{
		args->out_ty = 1;
		n += 1;
		name = parse_file(&s[n], &n);
		args->out = open(name, O_WRONLY | O_CREAT| O_TRUNC);
		if (args->out == -1)
			exit(-1);
	}
	return (free(name), printf("output file name detected: %s. Output type %d \n", name, args->out_ty), n);
}

char	*parse_file(char *s, int *n)
{
	int		m;
	int		k;
	char	*name;
	
	k = 0;

	while (ft_is_space(s[k]))
		k++;
	
	if (s[k] == '\'')
		m = ft_strchr(&s[k + 1], '\'') - &s[k] + 1;//parsear con comilla simple
	else if (s[k] == '"')
		m = ft_strchr(&s[k + 1], '"') - &s[k] + 1;//parsear con comilla simple
	else if (s[k] == '$' || ft_isascii(s[k]))
		m = ft_strchr(&s[k + 1], ' ') - &s[k] + 1;//parsear con comilla simple
	if (s[k] == '\'' || s[k] == '"')
		name = ft_substr(s, k + 1, m - 2);
	else
		name = ft_substr(s, k, m);
	*n += k + m;
	return(name);
}

int	main(int argc, char **argv)
{
	parser(argv[1]);
	return (0);	
}
