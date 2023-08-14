/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:50:20 by lagonzal          #+#    #+#             */
/*   Updated: 2023/06/01 15:39:56 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static char	*ft_depurate(char *save, int pos_lb);
static char	*ft_read_file(int fd, char *save);
static char	*ft_clean(char *s);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	if (ft_strchr(save, '\n') == NULL)
	{
		if (ft_strlen(save) == 0)
		{
			save = ft_clean(save);
			return (NULL);
		}
		ret = ft_strdup(save);
		save = ft_clean(save);
	}
	else
	{
		ret = ft_substr(save, 0, ft_strchr(save, '\n') - save + 1);
		save = ft_depurate(save, ft_strchr(save, '\n') - save + 1);
	}
	return (ret);
}

static char	*ft_read_file(int fd, char *left)
{
	int		readed;
	char	*reader;
	char	*holder;

	readed = 1;
	reader = malloc((BUFFER_SIZE + 1) * sizeof(char));
	reader[0] = 0;
	if (!reader)
		return (NULL);
	while (readed > 0 && ft_strchr(left, '\n') == NULL)
	{
		readed = read(fd, reader, BUFFER_SIZE);
		if (readed == -1)
			return (free(reader), ft_clean(left));
		reader[readed] = '\0';
		holder = ft_strjoin(left, reader);
		if (!holder)
			return (free(reader), ft_clean(left));
		if (left)
			left = ft_clean(left);
		left = holder;
	}
	return (free(reader), left);
}

static char	*ft_clean(char *s)
{
	if (s)
		free(s);
	s = NULL;
	return (s);
}

static char	*ft_depurate(char *save, int pos_lb)
{
	char	*dep;

	if ((int)(ft_strlen(save)) <= pos_lb)
		return (ft_clean(save));
	dep = ft_strdup(&save[pos_lb]);
	return (free(save), dep);
}

// int main(void)
// {
//  	int fd = open("prueba.txt", O_RDONLY);
// 	char *s;
// 	s = get_next_line(fd);
// 	while (s != NULL)
// 	{
//  		printf("%s\n",s);
// 		s = get_next_line(fd);	
// 	}
// 	return (0);
// }
